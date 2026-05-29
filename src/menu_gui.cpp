#include "menu_gui.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#include <commdlg.h>
#include <shlobj.h>
#include <direct.h>
#endif

#include "stb_image_write.h"

// Stored renderer/window references
static SDL_Renderer* g_renderer = nullptr;
static SDL_Window* g_window = nullptr;

// Quit callback
static void (*g_quit_callback)() = nullptr;

// ROM path callback
static void (*g_rom_path_callback)(const char* path) = nullptr;

// Menu state
static struct {
    bool initialized = false;
    bool show_settings = false;
    bool show_debug = false;
    bool show_help = false;
    bool show_menu_bar = true;
    int settings_tab = 0;

    // ROM path
    char rom_path[512] = "";
    bool rom_path_changed = false;

    // Display settings
    bool fullscreen = false;
    int window_scale = 1;  // index: 0=1x, 1=2x, 2=3x, 3=4x

    // Audio settings
    float master_volume = 1.0f;
    bool audio_enabled = true;

    // Debug state
    float fps_history[120] = {};
    int fps_history_idx = 0;
    uint32_t last_fps_time = 0;
    int frame_count = 0;
    float current_fps = 0.0f;

    // Screenshot state
    bool screenshot_requested = false;
    int screenshot_counter = 0;   // next sequential number
    char screenshot_dir[512] = "";
    bool screenshot_dir_init = false;

    // Toast notification
    bool toast_active = false;
    uint32_t toast_start_time = 0;
    char toast_text[256] = "";
    float toast_duration = 2.0f;  // seconds
} g_menu;

#ifdef _WIN32
static bool open_file_dialog(char* out_path, int out_size) {
    OPENFILENAMEA ofn = {};
    char file[512] = "";

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = nullptr;
    ofn.lpstrFilter = "N64 ROM Files\0*.z64;*.n64;*.v64\0All Files\0*.*\0";
    ofn.lpstrFile = file;
    ofn.nMaxFile = sizeof(file);
    ofn.lpstrTitle = "Select Diddy Kong Racing ROM";
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;

    if (GetOpenFileNameA(&ofn)) {
        strncpy(out_path, file, out_size - 1);
        out_path[out_size - 1] = '\0';
        return true;
    }
    return false;
}
#endif

// xemu-inspired dark green theme
static void apply_theme() {
    ImGuiStyle& style = ImGui::GetStyle();

    style.WindowRounding = 6.0f;
    style.FrameRounding = 4.0f;
    style.GrabRounding = 4.0f;
    style.TabRounding = 4.0f;
    style.ScrollbarRounding = 4.0f;
    style.WindowBorderSize = 1.0f;
    style.FrameBorderSize = 0.0f;
    style.WindowPadding = ImVec2(12, 12);
    style.FramePadding = ImVec2(8, 4);
    style.ItemSpacing = ImVec2(8, 6);

    ImVec4* c = style.Colors;
    c[ImGuiCol_Text]                  = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
    c[ImGuiCol_TextDisabled]          = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    c[ImGuiCol_WindowBg]              = ImVec4(0.10f, 0.10f, 0.10f, 0.95f);
    c[ImGuiCol_ChildBg]               = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
    c[ImGuiCol_PopupBg]               = ImVec4(0.12f, 0.12f, 0.12f, 0.95f);
    c[ImGuiCol_Border]                = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
    c[ImGuiCol_FrameBg]               = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
    c[ImGuiCol_FrameBgHovered]        = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
    c[ImGuiCol_FrameBgActive]         = ImVec4(0.15f, 0.50f, 0.15f, 1.00f);
    c[ImGuiCol_TitleBg]               = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
    c[ImGuiCol_TitleBgActive]         = ImVec4(0.12f, 0.35f, 0.12f, 1.00f);
    c[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.08f, 0.08f, 0.08f, 0.75f);
    c[ImGuiCol_MenuBarBg]             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    c[ImGuiCol_ScrollbarBg]           = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
    c[ImGuiCol_ScrollbarGrab]         = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
    c[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
    c[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.20f, 0.60f, 0.20f, 1.00f);
    c[ImGuiCol_CheckMark]             = ImVec4(0.20f, 0.80f, 0.20f, 1.00f);
    c[ImGuiCol_SliderGrab]            = ImVec4(0.20f, 0.60f, 0.20f, 1.00f);
    c[ImGuiCol_SliderGrabActive]      = ImVec4(0.20f, 0.80f, 0.20f, 1.00f);
    c[ImGuiCol_Button]                = ImVec4(0.18f, 0.40f, 0.18f, 1.00f);
    c[ImGuiCol_ButtonHovered]         = ImVec4(0.20f, 0.55f, 0.20f, 1.00f);
    c[ImGuiCol_ButtonActive]          = ImVec4(0.15f, 0.70f, 0.15f, 1.00f);
    c[ImGuiCol_Header]                = ImVec4(0.18f, 0.40f, 0.18f, 1.00f);
    c[ImGuiCol_HeaderHovered]         = ImVec4(0.20f, 0.55f, 0.20f, 1.00f);
    c[ImGuiCol_HeaderActive]          = ImVec4(0.15f, 0.70f, 0.15f, 1.00f);
    c[ImGuiCol_Separator]             = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
    c[ImGuiCol_Tab]                   = ImVec4(0.15f, 0.30f, 0.15f, 1.00f);
    c[ImGuiCol_TabHovered]            = ImVec4(0.20f, 0.55f, 0.20f, 1.00f);
    // ImGuiCol_TabSelected was named ImGuiCol_TabActive before 1.91. RT64
    // ships 1.90.4, our vendored copy is newer. IMGUI_VERSION_NUM 19100 is
    // the breakpoint.
#if IMGUI_VERSION_NUM >= 19100
    c[ImGuiCol_TabSelected]           = ImVec4(0.18f, 0.45f, 0.18f, 1.00f);
#else
    c[ImGuiCol_TabActive]             = ImVec4(0.18f, 0.45f, 0.18f, 1.00f);
#endif
    c[ImGuiCol_ResizeGrip]            = ImVec4(0.20f, 0.60f, 0.20f, 0.25f);
    c[ImGuiCol_ResizeGripHovered]     = ImVec4(0.20f, 0.60f, 0.20f, 0.67f);
    c[ImGuiCol_ResizeGripActive]      = ImVec4(0.20f, 0.80f, 0.20f, 0.95f);
}

// Initialize screenshot directory (screenshots/ next to exe)
static void init_screenshot_dir() {
    if (g_menu.screenshot_dir_init) return;
    g_menu.screenshot_dir_init = true;

#ifdef _WIN32
    // Put screenshots in ./screenshots/ relative to working directory
    _mkdir("screenshots");
#endif
    snprintf(g_menu.screenshot_dir, sizeof(g_menu.screenshot_dir), "screenshots");

    // Scan for existing screenshots to find the next counter value
    for (int i = 0; i < 100000; i++) {
        char path[600];
        snprintf(path, sizeof(path), "%s/dkr_%05d.png", g_menu.screenshot_dir, i);
        FILE* f = fopen(path, "rb");
        if (!f) {
            g_menu.screenshot_counter = i;
            break;
        }
        fclose(f);
    }
    fprintf(stderr, "[DKR-GUI] Screenshot dir: %s, next counter: %d\n",
            g_menu.screenshot_dir, g_menu.screenshot_counter);
    fflush(stderr);
}

static void show_toast(const char* text) {
    snprintf(g_menu.toast_text, sizeof(g_menu.toast_text), "%s", text);
    g_menu.toast_active = true;
    g_menu.toast_start_time = SDL_GetTicks();
}

static void draw_toast() {
    if (!g_menu.toast_active) return;

    uint32_t elapsed = SDL_GetTicks() - g_menu.toast_start_time;
    float duration_ms = g_menu.toast_duration * 1000.0f;
    if (elapsed > (uint32_t)duration_ms) {
        g_menu.toast_active = false;
        return;
    }

    // Fade out in the last 0.5s
    float alpha = 1.0f;
    float fade_ms = 500.0f;
    if (elapsed > (uint32_t)(duration_ms - fade_ms)) {
        alpha = (duration_ms - (float)elapsed) / fade_ms;
    }
    // Fade in during first 0.15s
    if (elapsed < 150) {
        alpha = (float)elapsed / 150.0f;
    }

    ImGuiIO& io = ImGui::GetIO();
    float pad = 16.0f;
    ImVec2 pos(io.DisplaySize.x - pad, io.DisplaySize.y - pad);
    ImGui::SetNextWindowPos(pos, ImGuiCond_Always, ImVec2(1.0f, 1.0f));
    ImGui::SetNextWindowBgAlpha(0.75f * alpha);

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove |
                             ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoFocusOnAppearing |
                             ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize |
                             ImGuiWindowFlags_NoInputs;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(12, 8));
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, alpha));

    if (ImGui::Begin("##toast", nullptr, flags)) {
        ImGui::Text("%s", g_menu.toast_text);
    }
    ImGui::End();

    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
}

static void draw_menu_bar() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Quit", "Alt+F4")) {
                if (g_quit_callback) g_quit_callback();
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Config")) {
            if (ImGui::MenuItem("Settings...", "F1")) {
                g_menu.show_settings = true;
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("About")) {
            if (ImGui::MenuItem("Help")) {
                g_menu.show_help = true;
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

static void draw_settings_window() {
    ImGuiIO& io = ImGui::GetIO();
    ImVec2 center(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(520, 400), ImGuiCond_Always);

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                             ImGuiWindowFlags_NoCollapse;

    if (!ImGui::Begin("Settings", &g_menu.show_settings, flags)) {
        ImGui::End();
        return;
    }

    if (ImGui::BeginTabBar("SettingsTabs")) {
        // General tab
        if (ImGui::BeginTabItem("General")) {
            ImGui::TextWrapped("DKR Recompiled v0.1.0");
            ImGui::Separator();
            ImGui::Spacing();

            ImGui::Text("ROM File:");
            ImGui::PushItemWidth(-80);
            ImGui::InputText("##rom_path", g_menu.rom_path, sizeof(g_menu.rom_path),
                             ImGuiInputTextFlags_ReadOnly);
            ImGui::PopItemWidth();
            ImGui::SameLine();
#ifdef _WIN32
            if (ImGui::Button("Browse")) {
                char new_path[512];
                if (open_file_dialog(new_path, sizeof(new_path))) {
                    strncpy(g_menu.rom_path, new_path, sizeof(g_menu.rom_path) - 1);
                    g_menu.rom_path[sizeof(g_menu.rom_path) - 1] = '\0';
                    g_menu.rom_path_changed = true;
                    if (g_rom_path_callback) {
                        g_rom_path_callback(g_menu.rom_path);
                    }
                }
            }
#else
            ImGui::TextDisabled("(N/A)");
#endif
            if (g_menu.rom_path[0] != '\0') {
                ImGui::TextColored(ImVec4(0.4f, 0.8f, 0.4f, 1.0f), "ROM loaded");
            } else {
                ImGui::TextColored(ImVec4(0.8f, 0.4f, 0.4f, 1.0f), "No ROM selected");
            }

            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Text("Game: Diddy Kong Racing (US v1.1)");
            ImGui::Text("ROM: US v80 (EEPROM 4K)");
            ImGui::Text("Renderer: Software (f3ddkr HLE)");
            ImGui::Text("Audio: aspMain HLE (22050 Hz stereo)");
            ImGui::EndTabItem();
        }

        // Display tab
        if (ImGui::BeginTabItem("Display")) {
            const char* scales[] = { "1x (320x240)", "2x (640x480)", "3x (960x720)", "4x (1280x960)" };
            int prev_scale = g_menu.window_scale;
            ImGui::Combo("Window Scale", &g_menu.window_scale, scales, 4);
            if (g_menu.window_scale != prev_scale && g_window) {
                int w = 320 * (g_menu.window_scale + 1);
                int h = 240 * (g_menu.window_scale + 1);
                SDL_SetWindowSize(g_window, w, h);
                SDL_SetWindowPosition(g_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
            }
            ImGui::Checkbox("Fullscreen", &g_menu.fullscreen);
            ImGui::EndTabItem();
        }

        // Input tab
        if (ImGui::BeginTabItem("Input")) {
            ImGui::Text("Keyboard Controls:");
            ImGui::Separator();
            ImGui::Columns(2, "kb_cols", true);
            ImGui::Text("Return/Space"); ImGui::NextColumn(); ImGui::Text("A Button"); ImGui::NextColumn();
            ImGui::Text("LShift"); ImGui::NextColumn(); ImGui::Text("B Button"); ImGui::NextColumn();
            ImGui::Text("Z"); ImGui::NextColumn(); ImGui::Text("Z Trigger"); ImGui::NextColumn();
            ImGui::Text("Escape"); ImGui::NextColumn(); ImGui::Text("Start"); ImGui::NextColumn();
            ImGui::Text("Q"); ImGui::NextColumn(); ImGui::Text("L Trigger"); ImGui::NextColumn();
            ImGui::Text("E"); ImGui::NextColumn(); ImGui::Text("R Trigger"); ImGui::NextColumn();
            ImGui::Text("Arrow Keys"); ImGui::NextColumn(); ImGui::Text("D-Pad"); ImGui::NextColumn();
            ImGui::Text("I/K/J/L"); ImGui::NextColumn(); ImGui::Text("C Buttons"); ImGui::NextColumn();
            ImGui::Text("F12"); ImGui::NextColumn(); ImGui::Text("Screenshot"); ImGui::NextColumn();
            ImGui::Columns(1);

            ImGui::Spacing();
            ImGui::Text("Gamepad: Xbox-style controller supported");
            ImGui::Text("  A = A, B/X/Y = B, Start = Start");
            ImGui::Text("  Left Trigger = Z, Right Trigger = R");
            ImGui::Text("  LB = L, RB = R");
            ImGui::Text("  Left Stick = Analog, Right Stick = C-Buttons");
            ImGui::EndTabItem();
        }

        // Audio tab
        if (ImGui::BeginTabItem("Audio")) {
            ImGui::SliderFloat("Master Volume", &g_menu.master_volume, 0.0f, 1.0f, "%.2f");
            ImGui::Checkbox("Audio Enabled", &g_menu.audio_enabled);
            ImGui::Separator();
            ImGui::Text("Audio Backend: SDL2 (22050 Hz, stereo)");
            ImGui::Text("RSP Microcode: aspMain HLE (14 opcodes)");
            ImGui::TextWrapped("Note: Reverb FX re-enabled with safety guards. SAVEBUFF/LOADBUFF bypassed.");
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::End();
}

static void draw_help_window() {
    ImGuiIO& io = ImGui::GetIO();
    ImVec2 center(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(480, 320), ImGuiCond_Always);

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                             ImGuiWindowFlags_NoCollapse;

    if (!ImGui::Begin("Help", &g_menu.show_help, flags)) {
        ImGui::End();
        return;
    }

    ImGui::Text("DKR Recompiled v0.1.0");
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::TextWrapped(
        "Static recompilation of Diddy Kong Racing (N64, US v1.1) for Windows 11 "
        "using N64Recomp and N64ModernRuntime."
    );

    ImGui::Spacing();
    ImGui::Text("Repository:");
    ImGui::Indent();
    ImGui::TextColored(ImVec4(0.4f, 0.8f, 0.4f, 1.0f), "https://github.com/sp00nznet/diddykongracing");
    ImGui::Unindent();

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::Text("Built with:");
    ImGui::BulletText("N64Recomp - Static recompilation framework");
    ImGui::BulletText("N64ModernRuntime - ultramodern + librecomp");
    ImGui::BulletText("SDL2 - Window, input, audio");
    ImGui::BulletText("Dear ImGui - UI overlay");

    ImGui::Spacing();
    ImGui::Text("DKR decomp reference:");
    ImGui::BulletText("github.com/DavidSM64/Diddy-Kong-Racing");

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Text("Shortcuts: F1 = Settings, F2 = Debug, F12 = Screenshot");

    ImGui::End();
}

static void draw_debug_window() {
    // Update FPS
    uint32_t now = SDL_GetTicks();
    g_menu.frame_count++;
    if (now - g_menu.last_fps_time >= 1000) {
        g_menu.current_fps = (float)g_menu.frame_count * 1000.0f / (float)(now - g_menu.last_fps_time);
        g_menu.fps_history[g_menu.fps_history_idx] = g_menu.current_fps;
        g_menu.fps_history_idx = (g_menu.fps_history_idx + 1) % 120;
        g_menu.frame_count = 0;
        g_menu.last_fps_time = now;
    }

    ImGuiIO& io = ImGui::GetIO();
    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x - 310, 30), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_FirstUseEver);

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse;

    if (!ImGui::Begin("Debug", &g_menu.show_debug, flags)) {
        ImGui::End();
        return;
    }

    ImGui::Text("FPS: %.1f", g_menu.current_fps);
    ImGui::PlotLines("##fps", g_menu.fps_history, 120, g_menu.fps_history_idx,
                     nullptr, 0.0f, 120.0f, ImVec2(0, 50));

    ImGui::Separator();
    ImGui::Text("Display: %.0fx%.0f", io.DisplaySize.x, io.DisplaySize.y);
    ImGui::Text("Renderer: Software (f3ddkr HLE)");

    ImGui::End();
}

// Public API

int menu_gui_init(SDL_Window* window, SDL_Renderer* renderer) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.IniFilename = nullptr;  // Don't save layout to disk

    apply_theme();

    g_renderer = renderer;
    g_window = window;
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    g_menu.initialized = true;
    g_menu.last_fps_time = SDL_GetTicks();

    fprintf(stderr, "[DKR-GUI] ImGui initialized\n");
    fflush(stderr);
    return 0;
}

void menu_gui_shutdown() {
    if (!g_menu.initialized) return;
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    g_menu.initialized = false;
}

void menu_gui_set_quit_callback(void (*callback)()) {
    g_quit_callback = callback;
}

bool menu_gui_process_event(const SDL_Event* event) {
    if (!g_menu.initialized) return false;

    // Handle hotkeys before passing to ImGui
    if (event->type == SDL_KEYDOWN && !event->key.repeat) {
        switch (event->key.keysym.sym) {
            case SDLK_F1:
                menu_gui_toggle_settings();
                return true;
            case SDLK_F2:
                menu_gui_toggle_debug();
                return true;
            case SDLK_F12:
                g_menu.screenshot_requested = true;
                return true;
            case SDLK_ESCAPE:
                if (g_menu.show_settings || g_menu.show_debug || g_menu.show_help) {
                    g_menu.show_settings = false;
                    g_menu.show_debug = false;
                    g_menu.show_help = false;
                    return true;
                }
                break;
        }
    }

    ImGui_ImplSDL2_ProcessEvent(event);

    // Block game input when menus are active
    if (menu_gui_is_active()) {
        ImGuiIO& io = ImGui::GetIO();
        if (io.WantCaptureKeyboard || io.WantCaptureMouse) {
            return true;
        }
    }

    return false;
}

void menu_gui_begin_frame() {
    if (!g_menu.initialized) return;
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void menu_gui_render() {
    if (!g_menu.initialized) return;

    // Always draw the menu bar
    draw_menu_bar();

    if (g_menu.show_settings) draw_settings_window();
    if (g_menu.show_debug) draw_debug_window();
    if (g_menu.show_help) draw_help_window();
    draw_toast();

    ImGui::Render();
    // 1.91.x added the renderer arg. 1.90.4 (RT64's vendored copy) takes only draw data.
#if IMGUI_VERSION_NUM >= 19100
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), g_renderer);
#else
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
#endif
}

void menu_gui_toggle_settings() {
    g_menu.show_settings = !g_menu.show_settings;
}

void menu_gui_toggle_debug() {
    g_menu.show_debug = !g_menu.show_debug;
}

bool menu_gui_is_active() {
    return g_menu.show_settings || g_menu.show_debug || g_menu.show_help;
}

void menu_gui_set_rom_path(const char* path) {
    if (path) {
        strncpy(g_menu.rom_path, path, sizeof(g_menu.rom_path) - 1);
        g_menu.rom_path[sizeof(g_menu.rom_path) - 1] = '\0';
    }
}

const char* menu_gui_get_rom_path() {
    return g_menu.rom_path;
}

void menu_gui_set_rom_callback(void (*callback)(const char* path)) {
    g_rom_path_callback = callback;
}

bool menu_gui_screenshot_requested() {
    if (g_menu.screenshot_requested) {
        g_menu.screenshot_requested = false;
        return true;
    }
    return false;
}

void menu_gui_take_screenshot(SDL_Renderer* renderer, int fb_width, int fb_height) {
    init_screenshot_dir();

    if (!renderer || fb_width <= 0 || fb_height <= 0) {
        show_toast("Screenshot failed: no framebuffer");
        return;
    }

    // Read pixels from the SDL renderer
    int w = 0, h = 0;
    SDL_GetRendererOutputSize(renderer, &w, &h);
    if (w <= 0 || h <= 0) {
        show_toast("Screenshot failed: bad renderer size");
        return;
    }

    std::vector<uint8_t> pixels(w * h * 4);
    SDL_Rect rect = { 0, 0, w, h };
    if (SDL_RenderReadPixels(renderer, &rect, SDL_PIXELFORMAT_ABGR8888,
                             pixels.data(), w * 4) != 0) {
        show_toast("Screenshot failed: read error");
        fprintf(stderr, "[DKR-GUI] Screenshot RenderReadPixels failed: %s\n", SDL_GetError());
        fflush(stderr);
        return;
    }

    // Build filename
    char path[600];
    snprintf(path, sizeof(path), "%s/dkr_%05d.png",
             g_menu.screenshot_dir, g_menu.screenshot_counter);

    // Write PNG via stb_image_write
    int ok = stbi_write_png(path, w, h, 4, pixels.data(), w * 4);
    if (ok) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Screenshot saved: dkr_%05d.png", g_menu.screenshot_counter);
        show_toast(msg);
        fprintf(stderr, "[DKR-GUI] %s (%dx%d)\n", msg, w, h);
        fflush(stderr);
        g_menu.screenshot_counter++;
    } else {
        show_toast("Screenshot failed: write error");
        fprintf(stderr, "[DKR-GUI] Screenshot write failed: %s\n", path);
        fflush(stderr);
    }
}
