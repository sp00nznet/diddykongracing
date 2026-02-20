#include <algorithm>
#include <cstdio>
#include <cstring>
#include <memory>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#endif

#include <SDL.h>

#include "ultramodern/renderer_context.hpp"
#include "f3ddkr.h"

// SDL window from main.cpp
extern SDL_Window* get_sdl_window();

// Pure software framebuffer renderer - reads N64 framebuffer from RDRAM via VI registers
// and displays it using SDL window surface (no GPU renderer needed).
class SoftwareRendererContext : public ultramodern::renderer::RendererContext {
public:
    SoftwareRendererContext(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode)
        : rdram_(rdram) {
        vi_regs_ = ultramodern::renderer::get_vi_regs();
        setup_result = ultramodern::renderer::SetupResult::Success;

        window_ = get_sdl_window();
        fprintf(stderr, "[DKR-GFX] Software renderer init, RDRAM=0x%p, window=%p\n", rdram, window_);
        fflush(stderr);
    }

    ~SoftwareRendererContext() override {
    }

    bool valid() override {
        return setup_result == ultramodern::renderer::SetupResult::Success;
    }

    bool update_config(const ultramodern::renderer::GraphicsConfig& old_config,
                       const ultramodern::renderer::GraphicsConfig& new_config) override {
        return true;
    }

    void enable_instant_present() override {
    }

    void send_dl(const OSTask* task) override {
        dl_count_++;
        if (dl_count_ <= 20 || (dl_count_ <= 200 && dl_count_ % 50 == 0)) {
            fprintf(stderr, "[DKR-GFX] send_dl #%d: data_ptr=0x%08X data_size=0x%08X\n",
                dl_count_, task->t.data_ptr, task->t.data_size);
            fflush(stderr);
        }
        f3ddkr_process_dl(rdram_, task->t.data_ptr, task->t.data_size);
    }

    void update_screen() override {
        if (!window_ || !rdram_) return;

        screen_count_++;

        // Read VI registers
        uint32_t vi_status = vi_regs_->VI_STATUS_REG;
        uint32_t vi_origin = vi_regs_->VI_ORIGIN_REG;
        uint32_t vi_width  = vi_regs_->VI_WIDTH_REG;
        uint32_t vi_v_start = vi_regs_->VI_V_START_REG;
        uint32_t vi_h_start = vi_regs_->VI_H_START_REG;
        uint32_t vi_x_scale = vi_regs_->VI_X_SCALE_REG;
        uint32_t vi_y_scale = vi_regs_->VI_Y_SCALE_REG;

        // Log meaningful VI state changes (ignore origin alternation from double-buffering)
        if (vi_status != last_vi_status_ || vi_width != last_vi_width_ ||
            vi_v_start != last_vi_v_start_ || vi_h_start != last_vi_h_start_) {
            fprintf(stderr, "[DKR-GFX] VI mode changed (screen#%d): status=0x%08X origin=0x%08X "
                "width=%u v_start=0x%08X h_start=0x%08X x_scale=0x%03X y_scale=0x%03X\n",
                screen_count_, vi_status, vi_origin, vi_width,
                vi_v_start, vi_h_start, vi_x_scale & 0xFFF, vi_y_scale & 0xFFF);
            fflush(stderr);
            last_vi_status_ = vi_status;
            last_vi_width_ = vi_width;
            last_vi_v_start_ = vi_v_start;
            last_vi_h_start_ = vi_h_start;
        }
        // Periodic status every 300 frames
        if (screen_count_ % 300 == 0) {
            fprintf(stderr, "[DKR-GFX] Status: screen#%d, %d DLs, origin=0x%08X\n",
                screen_count_, dl_count_, vi_origin);
            fflush(stderr);
        }

        // Extract pixel format: bits 0-1 of VI_STATUS
        // 0 = blank, 2 = 16-bit (RGBA5551), 3 = 32-bit (RGBA8888)
        uint32_t pixel_size = vi_status & 0x3;
        if (pixel_size < 2 || vi_origin == 0 || vi_width == 0) {
            return;
        }

        // Calculate display dimensions from VI registers
        uint32_t v_start = (vi_v_start >> 16) & 0x3FF;
        uint32_t v_end = vi_v_start & 0x3FF;
        uint32_t y_scale_raw = vi_y_scale & 0xFFF;

        uint32_t screen_width = vi_width;
        uint32_t screen_height = 0;

        if (y_scale_raw > 0 && v_end > v_start) {
            uint32_t v_range = (v_end - v_start) / 2;
            screen_height = (v_range * y_scale_raw) / 1024;
        }
        if (screen_height == 0) screen_height = 240;
        if (screen_width == 0) screen_width = 320;
        if (screen_width > 640) screen_width = 640;
        if (screen_height > 480) screen_height = 480;

        // Use the HLE CI address instead of VI_ORIGIN to avoid double-buffer artifacts.
        // The game may not properly alternate framebuffers, and VI_ORIGIN can point to
        // a stale buffer that wasn't rendered by our HLE.
        uint32_t hle_ci = f3ddkr_get_last_ci_addr();
        uint32_t fb_offset;
        if (hle_ci != 0) {
            fb_offset = hle_ci & 0x7FFFFF;
            // Override width from HLE if available
            uint16_t hle_width = f3ddkr_get_last_ci_width();
            if (hle_width > 0) screen_width = hle_width;
        } else {
            fb_offset = vi_origin & 0x7FFFFF;
        }

        uint32_t bytes_per_pixel = (pixel_size == 3) ? 4 : 2;
        uint32_t fb_size = screen_width * screen_height * bytes_per_pixel;

        if (fb_offset + fb_size > 0x800000) {
            return;
        }

        // Ensure our conversion buffer is big enough
        uint32_t needed = screen_width * screen_height * 4;
        if (conv_buffer_.size() < needed) {
            conv_buffer_.resize(needed);
        }

        // Convert N64 framebuffer to RGBA8888 (native byte order)
        uint32_t* dst = (uint32_t*)conv_buffer_.data();

        if (pixel_size == 2) {
            // 16-bit RGBA5551
            for (uint32_t y = 0; y < screen_height; y++) {
                for (uint32_t x = 0; x < screen_width; x++) {
                    uint32_t pixel_offset = fb_offset + (y * screen_width + x) * 2;
                    uint8_t hi = rdram_[pixel_offset ^ 3];
                    uint8_t lo = rdram_[(pixel_offset + 1) ^ 3];
                    uint16_t pixel = (hi << 8) | lo;

                    uint8_t r = (pixel >> 11) & 0x1F;
                    uint8_t g = (pixel >> 6) & 0x1F;
                    uint8_t b = (pixel >> 1) & 0x1F;

                    r = (r << 3) | (r >> 2);
                    g = (g << 3) | (g >> 2);
                    b = (b << 3) | (b >> 2);

                    dst[y * screen_width + x] = (0xFF << 24) | (r << 16) | (g << 8) | b;
                }
            }
        } else if (pixel_size == 3) {
            // 32-bit RGBA8888
            for (uint32_t y = 0; y < screen_height; y++) {
                for (uint32_t x = 0; x < screen_width; x++) {
                    uint32_t pixel_offset = fb_offset + (y * screen_width + x) * 4;
                    uint8_t r = rdram_[pixel_offset ^ 3];
                    uint8_t g = rdram_[(pixel_offset + 1) ^ 3];
                    uint8_t b = rdram_[(pixel_offset + 2) ^ 3];

                    dst[y * screen_width + x] = (0xFF << 24) | (r << 16) | (g << 8) | b;
                }
            }
        }

        // Blit to window surface
        SDL_Surface* window_surface = SDL_GetWindowSurface(window_);
        if (!window_surface) {
            if (screen_count_ <= 5) {
                fprintf(stderr, "[DKR-GFX] SDL_GetWindowSurface failed: %s\n", SDL_GetError());
                fflush(stderr);
            }
            return;
        }

        // Create an SDL surface from our converted buffer
        SDL_Surface* fb_surface = SDL_CreateRGBSurfaceFrom(
            conv_buffer_.data(),
            screen_width, screen_height,
            32,
            screen_width * 4,
            0x00FF0000,  // R mask
            0x0000FF00,  // G mask
            0x000000FF,  // B mask
            0xFF000000   // A mask
        );

        if (fb_surface) {
            // Clear window surface to black before blit to prevent stale content
            // from previous frames showing through (fixes double-buffer artifact
            // when game's scissor-clipped fill_rect doesn't clear the entire screen)
            SDL_FillRect(window_surface, nullptr, SDL_MapRGB(window_surface->format, 0, 0, 0));

            // Scale blit to fill window
            SDL_BlitScaled(fb_surface, nullptr, window_surface, nullptr);
            SDL_FreeSurface(fb_surface);
        }

        SDL_UpdateWindowSurface(window_);

        // Periodically log framebuffer content check
        if (screen_count_ <= 5 || screen_count_ == 100 || screen_count_ == 200 || screen_count_ % 500 == 0) {
            // Scan entire framebuffer for non-fill pixels
            int non_fill = 0;
            int non_zero = 0;
            uint16_t first_nonfill_val = 0;
            int first_nonfill_x = -1, first_nonfill_y = -1;
            if (pixel_size == 2) {
                for (uint32_t y = 0; y < screen_height; y++) {
                    for (uint32_t x = 0; x < screen_width; x++) {
                        uint32_t off = fb_offset + (y * screen_width + x) * 2;
                        if (off + 1 >= 0x800000) break;
                        uint8_t hi = rdram_[off ^ 3];
                        uint8_t lo = rdram_[(off + 1) ^ 3];
                        uint16_t px = (hi << 8) | lo;
                        if (px != 0) non_zero++;
                        if (px > 0x0001 && px != 0xFFFC) { // not zero, not fill black (0x0001), not z-fill (0xFFFC)
                            non_fill++;
                            if (non_fill == 1) {
                                first_nonfill_val = px;
                                first_nonfill_x = x;
                                first_nonfill_y = y;
                            }
                        }
                    }
                }
            }
            fprintf(stderr, "[DKR-GFX] FB check screen#%d: origin=0x%06X %ux%u non_zero=%d non_fill=%d",
                    screen_count_, fb_offset, screen_width, screen_height, non_zero, non_fill);
            if (first_nonfill_x >= 0) {
                fprintf(stderr, " first=0x%04X@(%d,%d)", first_nonfill_val, first_nonfill_x, first_nonfill_y);
            }
            fprintf(stderr, "\n");
            fflush(stderr);
        }
    }

    void shutdown() override {
        fprintf(stderr, "[DKR-GFX] Shutdown: %d DLs, %d screen updates\n", dl_count_, screen_count_);
        fflush(stderr);
    }

    uint32_t get_display_framerate() const override {
        return 60;
    }

    float get_resolution_scale() const override {
        return 1.0f;
    }

private:
    uint8_t* rdram_ = nullptr;
    ultramodern::renderer::ViRegs* vi_regs_ = nullptr;
    SDL_Window* window_ = nullptr;
    std::vector<uint8_t> conv_buffer_;
    int dl_count_ = 0;
    int screen_count_ = 0;

    uint32_t last_vi_status_ = 0xFFFFFFFF;
    uint32_t last_vi_width_ = 0xFFFFFFFF;
    uint32_t last_vi_v_start_ = 0xFFFFFFFF;
    uint32_t last_vi_h_start_ = 0xFFFFFFFF;
};

std::unique_ptr<ultramodern::renderer::RendererContext> create_rt64_render_context(
    uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
    return std::make_unique<SoftwareRendererContext>(rdram, window_handle, developer_mode);
}
