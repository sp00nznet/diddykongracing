#include <memory>
#include <cstdio>

#ifdef _WIN32
#include <Windows.h>
#include <unknwn.h>
#endif

#include "ultramodern/renderer_context.hpp"
#include "hle/rt64_application.h"

static uint32_t MI_INTR_REG = 0;
static uint32_t DPC_START_REG = 0;
static uint32_t DPC_END_REG = 0;
static uint32_t DPC_CURRENT_REG = 0;
static uint32_t DPC_STATUS_REG = 0;
static uint32_t DPC_CLOCK_REG = 0;
static uint32_t DPC_BUFBUSY_REG = 0;
static uint32_t DPC_PIPEBUSY_REG = 0;
static uint32_t DPC_TMEM_REG = 0;

// Defined in librecomp/src/rsp.cpp
extern uint8_t dmem[];
// IMEM - not used by HLE but RT64 needs a valid pointer
uint8_t imem[0x1000];

// RT64 calls this after DP/SP interrupt events
static void check_interrupts() {
    // In the recomp runtime, interrupts are handled by ultramodern's event system.
    // This callback satisfies RT64's requirement but the actual interrupt processing
    // happens through the ultramodern scheduler.
}

class RT64Context : public ultramodern::renderer::RendererContext {
public:
    RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
        auto* vi_regs = ultramodern::renderer::get_vi_regs();

        RT64::Application::Core core{};
        core.window = window_handle.window;
        core.HEADER = rdram;
        core.RDRAM = rdram;
        core.DMEM = dmem;
        core.IMEM = imem;
        core.MI_INTR_REG = &MI_INTR_REG;
        core.DPC_START_REG = &DPC_START_REG;
        core.DPC_END_REG = &DPC_END_REG;
        core.DPC_CURRENT_REG = &DPC_CURRENT_REG;
        core.DPC_STATUS_REG = &DPC_STATUS_REG;
        core.DPC_CLOCK_REG = &DPC_CLOCK_REG;
        core.DPC_BUFBUSY_REG = &DPC_BUFBUSY_REG;
        core.DPC_PIPEBUSY_REG = &DPC_PIPEBUSY_REG;
        core.DPC_TMEM_REG = &DPC_TMEM_REG;
        core.VI_STATUS_REG = &vi_regs->VI_STATUS_REG;
        core.VI_ORIGIN_REG = &vi_regs->VI_ORIGIN_REG;
        core.VI_WIDTH_REG = &vi_regs->VI_WIDTH_REG;
        core.VI_INTR_REG = &vi_regs->VI_INTR_REG;
        core.VI_V_CURRENT_LINE_REG = &vi_regs->VI_V_CURRENT_LINE_REG;
        core.VI_TIMING_REG = &vi_regs->VI_TIMING_REG;
        core.VI_V_SYNC_REG = &vi_regs->VI_V_SYNC_REG;
        core.VI_H_SYNC_REG = &vi_regs->VI_H_SYNC_REG;
        core.VI_LEAP_REG = &vi_regs->VI_LEAP_REG;
        core.VI_H_START_REG = &vi_regs->VI_H_START_REG;
        core.VI_V_START_REG = &vi_regs->VI_V_START_REG;
        core.VI_V_BURST_REG = &vi_regs->VI_V_BURST_REG;
        core.VI_X_SCALE_REG = &vi_regs->VI_X_SCALE_REG;
        core.VI_Y_SCALE_REG = &vi_regs->VI_Y_SCALE_REG;
        core.checkInterrupts = check_interrupts;

        RT64::ApplicationConfiguration app_config{};
        app_config.appId = "DKRRecompiled";

        app = std::make_unique<RT64::Application>(core, app_config);
        auto result = app->setup(window_handle.thread_id);
        switch (result) {
            case RT64::Application::SetupResult::Success:
                setup_result = ultramodern::renderer::SetupResult::Success;
                break;
            case RT64::Application::SetupResult::DynamicLibrariesNotFound:
                setup_result = ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
                break;
            case RT64::Application::SetupResult::InvalidGraphicsAPI:
                setup_result = ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
                break;
            case RT64::Application::SetupResult::GraphicsAPINotFound:
                setup_result = ultramodern::renderer::SetupResult::GraphicsAPINotFound;
                break;
            case RT64::Application::SetupResult::GraphicsDeviceNotFound:
                setup_result = ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
                break;
        }
    }

    ~RT64Context() override = default;

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
        app->processDisplayLists(
            app->core.RDRAM,
            task->t.data_ptr,
            task->t.data_size,
            true
        );
    }

    void update_screen() override {
        app->updateScreen();
    }

    void shutdown() override {
        app->end();
    }

    uint32_t get_display_framerate() const override {
        return 60;
    }

    float get_resolution_scale() const override {
        return 1.0f;
    }

private:
    std::unique_ptr<RT64::Application> app;
};

std::unique_ptr<ultramodern::renderer::RendererContext> create_rt64_render_context(
    uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
    return std::make_unique<RT64Context>(rdram, window_handle, developer_mode);
}
