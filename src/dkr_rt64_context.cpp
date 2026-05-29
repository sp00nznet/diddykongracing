// RT64-backed renderer for DKR. Stage 1: wire up RT64 init/teardown and
// hand display lists to RT64's interpreter. F3DDKR microcode is not yet
// in RT64's GBI database, so loadUCodeGBI will fail to identify it and
// nothing will render — but RT64 should initialize, show a black window,
// and not crash. That validates the build/plumbing for stages 2+.
//
// Modeled on DinoRecomp's src/renderer/renderer.cpp, simplified: no
// texture packs, no mod system, no debug UI hooks, no high-precision FB.
//
// Built only when DKR_USE_RT64=ON. The default software renderer in
// rt64_render_context.cpp remains the default.

// HLSL_CPU is set as a compile definition when DKR_USE_RT64 is on.
#include "hle/rt64_application.h"

#include <cstdio>
#include <memory>

#include "ultramodern/renderer_context.hpp"

// Globals N64ModernRuntime references as externs from the renderer side.
// They mirror MIPS interface / DPC / VI register state.
unsigned int MI_INTR_REG = 0;
unsigned int DPC_START_REG = 0;
unsigned int DPC_END_REG = 0;
unsigned int DPC_CURRENT_REG = 0;
unsigned int DPC_STATUS_REG = 0;
unsigned int DPC_CLOCK_REG = 0;
unsigned int DPC_BUFBUSY_REG = 0;
unsigned int DPC_PIPEBUSY_REG = 0;
unsigned int DPC_TMEM_REG = 0;

extern uint8_t* get_rdram_base();
extern "C" void f3ddkr_process_dl(uint8_t* rdram, uint32_t dl_addr, uint32_t dl_size);

namespace {

// One-shot DMEM/IMEM scratch — RT64 just needs valid backing memory it can
// hash for ucode identification. Contents don't matter; DKR doesn't HLE the
// task->ucode pointers through DMEM/IMEM.
uint8_t s_dmem[0x1000];
uint8_t s_imem[0x1000];

void dummy_check_interrupts() {}

class RT64Context : public ultramodern::renderer::RendererContext {
public:
    RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool debug)
        : rdram_(rdram) {
        static unsigned char dummy_rom_header[0x40];

        RT64::Application::Core appCore{};
#if defined(_WIN32)
        appCore.window = window_handle.window;
#endif
        appCore.checkInterrupts = dummy_check_interrupts;
        appCore.HEADER = dummy_rom_header;
        appCore.RDRAM = rdram;
        appCore.DMEM = s_dmem;
        appCore.IMEM = s_imem;

        appCore.MI_INTR_REG = &MI_INTR_REG;
        appCore.DPC_START_REG = &DPC_START_REG;
        appCore.DPC_END_REG = &DPC_END_REG;
        appCore.DPC_CURRENT_REG = &DPC_CURRENT_REG;
        appCore.DPC_STATUS_REG = &DPC_STATUS_REG;
        appCore.DPC_CLOCK_REG = &DPC_CLOCK_REG;
        appCore.DPC_BUFBUSY_REG = &DPC_BUFBUSY_REG;
        appCore.DPC_PIPEBUSY_REG = &DPC_PIPEBUSY_REG;
        appCore.DPC_TMEM_REG = &DPC_TMEM_REG;

        ultramodern::renderer::ViRegs* vi_regs = ultramodern::renderer::get_vi_regs();
        appCore.VI_STATUS_REG = &vi_regs->VI_STATUS_REG;
        appCore.VI_ORIGIN_REG = &vi_regs->VI_ORIGIN_REG;
        appCore.VI_WIDTH_REG = &vi_regs->VI_WIDTH_REG;
        appCore.VI_INTR_REG = &vi_regs->VI_INTR_REG;
        appCore.VI_V_CURRENT_LINE_REG = &vi_regs->VI_V_CURRENT_LINE_REG;
        appCore.VI_TIMING_REG = &vi_regs->VI_TIMING_REG;
        appCore.VI_V_SYNC_REG = &vi_regs->VI_V_SYNC_REG;
        appCore.VI_H_SYNC_REG = &vi_regs->VI_H_SYNC_REG;
        appCore.VI_LEAP_REG = &vi_regs->VI_LEAP_REG;
        appCore.VI_H_START_REG = &vi_regs->VI_H_START_REG;
        appCore.VI_V_START_REG = &vi_regs->VI_V_START_REG;
        appCore.VI_V_BURST_REG = &vi_regs->VI_V_BURST_REG;
        appCore.VI_X_SCALE_REG = &vi_regs->VI_X_SCALE_REG;
        appCore.VI_Y_SCALE_REG = &vi_regs->VI_Y_SCALE_REG;

        RT64::ApplicationConfiguration appConfig;
        appConfig.useConfigurationFile = false;

        app_ = std::make_unique<RT64::Application>(appCore, appConfig);

        // Conservative defaults for stage 1. WindowIntegerScale matches our
        // 2x default. Triple-buffered presentation matches DinoRecomp.
        app_->userConfig.resolution = RT64::UserConfiguration::Resolution::WindowIntegerScale;
        app_->userConfig.downsampleMultiplier = 1;
        app_->userConfig.aspectRatio = RT64::UserConfiguration::AspectRatio::Original;
        app_->userConfig.antialiasing = RT64::UserConfiguration::Antialiasing::None;
        app_->userConfig.refreshRate = RT64::UserConfiguration::RefreshRate::Display;
        app_->userConfig.displayBuffering = RT64::UserConfiguration::DisplayBuffering::Triple;
        app_->userConfig.filtering = RT64::UserConfiguration::Filtering::AntiAliasedPixelScaling;
        app_->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Automatic;
        app_->userConfig.developerMode = debug;

        // DKR text rendering may be sensitive to RT64's rectangle coord auto-fix
        // the same way Dino's font code is.
        app_->enhancementConfig.rect.fixRectLR = false;

        uint32_t thread_id = 0;
#ifdef _WIN32
        thread_id = window_handle.thread_id;
#endif
        auto rt64_setup = app_->setup(thread_id);
        if (rt64_setup != RT64::Application::SetupResult::Success) {
            fprintf(stderr, "[DKR-RT64] Setup failed: %d\n", (int)rt64_setup);
            fflush(stderr);
            app_.reset();
            setup_result = ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
            return;
        }
        setup_result = ultramodern::renderer::SetupResult::Success;

        fprintf(stderr, "[DKR-RT64] Initialized (API=%d)\n", (int)app_->chosenGraphicsAPI);
        fflush(stderr);
    }

    ~RT64Context() override = default;

    bool valid() override {
        return app_ != nullptr;
    }

    bool update_config(const ultramodern::renderer::GraphicsConfig& old_config,
                       const ultramodern::renderer::GraphicsConfig& new_config) override {
        return true;
    }

    void enable_instant_present() override {
        if (!app_) return;
        app_->enhancementConfig.presentation.mode =
            RT64::EnhancementConfiguration::Presentation::Mode::PresentEarly;
        app_->updateEnhancementConfig();
    }

    void send_dl(const OSTask* task) override {
        if (!app_) return;
        dl_count_++;
        if (dl_count_ <= 10 || dl_count_ % 500 == 0) {
            fprintf(stderr, "[DKR-RT64] send_dl #%d: ucode=0x%08X ucode_data=0x%08X data_ptr=0x%08X\n",
                dl_count_, task->t.ucode, task->t.ucode_data, task->t.data_ptr);
            fflush(stderr);
        }
        // Try RT64's interpreter. Stage 1: F3DDKR microcode hash won't match
        // any known GBI in RT64's database, so loadUCodeGBI will log
        // "Unable to find a matching GBI" and processDisplayLists will skip.
        // That's the expected stage-1 behavior — we're just verifying the
        // plumbing.
        app_->state->rsp->reset();
        app_->interpreter->loadUCodeGBI(task->t.ucode & 0x3FFFFFF, task->t.ucode_data & 0x3FFFFFF, true);
        app_->processDisplayLists(app_->core.RDRAM, task->t.data_ptr & 0x3FFFFFF, 0, true);
    }

    void update_screen() override {
        if (!app_) return;
        screen_count_++;
        if (screen_count_ <= 5 || (screen_count_ % 120 == 0)) {
            ultramodern::renderer::ViRegs* vi = ultramodern::renderer::get_vi_regs();
            fprintf(stderr,
                "[DKR-RT64] update_screen #%d VI_STATUS=0x%08X VI_ORIGIN=0x%08X VI_WIDTH=%u VI_V_START=0x%08X VI_X_SCALE=0x%X VI_Y_SCALE=0x%X\n",
                screen_count_, vi->VI_STATUS_REG, vi->VI_ORIGIN_REG, vi->VI_WIDTH_REG,
                vi->VI_V_START_REG, vi->VI_X_SCALE_REG, vi->VI_Y_SCALE_REG);
            fflush(stderr);
        }
        app_->updateScreen();
    }

    void shutdown() override {
        if (app_) app_->end();
    }

    uint32_t get_display_framerate() const override {
        if (!app_) return 60;
        return app_->presentQueue->ext.sharedResources->swapChainRate;
    }

    float get_resolution_scale() const override {
        if (!app_) return 1.0f;
        if (app_->userConfig.resolution == RT64::UserConfiguration::Resolution::Manual) {
            return float(app_->userConfig.resolutionMultiplier);
        }
        return 1.0f;
    }

private:
    uint8_t* rdram_ = nullptr;
    std::unique_ptr<RT64::Application> app_;
    int dl_count_ = 0;
    int screen_count_ = 0;
};

}  // namespace

std::unique_ptr<ultramodern::renderer::RendererContext> create_rt64_render_context_real(
    uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
    return std::make_unique<RT64Context>(rdram, window_handle, developer_mode);
}
