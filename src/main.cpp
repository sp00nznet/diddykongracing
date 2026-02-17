#include <cstdio>
#include <filesystem>
#include <memory>
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <timeapi.h>

#include <SDL.h>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "librecomp/overlays.hpp"
#include "librecomp/rsp.hpp"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/error_handling.hpp"

// Declare the recompiled entrypoint
extern "C" void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx);

// Forward declarations
extern void register_overlays();
std::unique_ptr<ultramodern::renderer::RendererContext> create_rt64_render_context(
    uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode);

// RSP microcode
extern "C" RspExitReason aspMain(uint8_t* rdram, uint32_t ucode_addr);

// xxHash3 for ROM hash computation
#include "xxHash/xxh3.h"

// -----------------------------------------------
// SDL Audio
// -----------------------------------------------
static SDL_AudioDeviceID audio_device = 0;

void queue_audio_samples(int16_t* samples, size_t num_samples) {
    if (audio_device != 0) {
        SDL_QueueAudio(audio_device, samples, (Uint32)(num_samples * sizeof(int16_t)));
    }
}

size_t get_audio_frames_remaining() {
    if (audio_device != 0) {
        return SDL_GetQueuedAudioSize(audio_device) / (2 * sizeof(int16_t)); // stereo frames
    }
    return 0;
}

void set_audio_frequency(uint32_t freq) {
    if (audio_device != 0) {
        SDL_CloseAudioDevice(audio_device);
    }
    SDL_AudioSpec desired{};
    desired.freq = (int)freq;
    desired.format = AUDIO_S16SYS;
    desired.channels = 2;
    desired.samples = 1024;
    desired.callback = nullptr;
    SDL_AudioSpec obtained{};
    audio_device = SDL_OpenAudioDevice(nullptr, 0, &desired, &obtained, 0);
    if (audio_device != 0) {
        SDL_PauseAudioDevice(audio_device, 0);
    }
}

// -----------------------------------------------
// SDL Input
// -----------------------------------------------
static SDL_GameController* controller = nullptr;

void poll_input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                ultramodern::quit();
                break;
            case SDL_CONTROLLERDEVICEADDED:
                if (!controller) {
                    controller = SDL_GameControllerOpen(event.cdevice.which);
                }
                break;
            case SDL_CONTROLLERDEVICEREMOVED:
                if (controller && event.cdevice.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller))) {
                    SDL_GameControllerClose(controller);
                    controller = nullptr;
                }
                break;
        }
    }
}

bool get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    if (controller_num != 0) return false;

    *buttons = 0;
    *x = 0.0f;
    *y = 0.0f;

    const Uint8* keys = SDL_GetKeyboardState(nullptr);

    // Keyboard mappings
    if (keys[SDL_SCANCODE_RETURN] || keys[SDL_SCANCODE_SPACE]) *buttons |= 0x8000; // A
    if (keys[SDL_SCANCODE_LSHIFT])   *buttons |= 0x4000; // B
    if (keys[SDL_SCANCODE_Z])        *buttons |= 0x2000; // Z
    if (keys[SDL_SCANCODE_ESCAPE])   *buttons |= 0x1000; // Start
    if (keys[SDL_SCANCODE_UP])       *buttons |= 0x0800; // D-Up
    if (keys[SDL_SCANCODE_DOWN])     *buttons |= 0x0400; // D-Down
    if (keys[SDL_SCANCODE_LEFT])     *buttons |= 0x0200; // D-Left
    if (keys[SDL_SCANCODE_RIGHT])    *buttons |= 0x0100; // D-Right
    if (keys[SDL_SCANCODE_Q])        *buttons |= 0x0020; // L
    if (keys[SDL_SCANCODE_E])        *buttons |= 0x0010; // R
    if (keys[SDL_SCANCODE_I])        *buttons |= 0x0008; // C-Up
    if (keys[SDL_SCANCODE_K])        *buttons |= 0x0004; // C-Down
    if (keys[SDL_SCANCODE_J])        *buttons |= 0x0002; // C-Left
    if (keys[SDL_SCANCODE_L])        *buttons |= 0x0001; // C-Right

    // Analog stick from WASD
    float analog_x = 0.0f, analog_y = 0.0f;
    if (keys[SDL_SCANCODE_W]) analog_y += 1.0f;
    if (keys[SDL_SCANCODE_S]) analog_y -= 1.0f;
    if (keys[SDL_SCANCODE_A]) analog_x -= 1.0f;
    if (keys[SDL_SCANCODE_D]) analog_x += 1.0f;

    // Controller input (overlay on top of keyboard)
    if (controller) {
        float cx = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX) / 32767.0f;
        float cy = -SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY) / 32767.0f;
        if (fabsf(cx) > fabsf(analog_x)) analog_x = cx;
        if (fabsf(cy) > fabsf(analog_y)) analog_y = cy;

        if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A)) *buttons |= 0x8000;
        if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X)) *buttons |= 0x4000;
        if (SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_TRIGGERLEFT) > 16384) *buttons |= 0x2000;
        if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START)) *buttons |= 0x1000;
        if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP)) *buttons |= 0x0800;
        if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN)) *buttons |= 0x0400;
        if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT)) *buttons |= 0x0200;
        if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) *buttons |= 0x0100;
        if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER)) *buttons |= 0x0020;
        if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)) *buttons |= 0x0010;
        if (SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 16384) *buttons |= 0x0010;
    }

    *x = analog_x;
    *y = analog_y;
    return true;
}

void set_rumble(int controller_num, bool rumble) {
    if (controller_num == 0 && controller) {
        SDL_GameControllerRumble(controller, rumble ? 0xFFFF : 0, rumble ? 0xFFFF : 0, 100);
    }
}

ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num) {
    if (controller_num == 0) {
        return { ultramodern::input::Device::Controller, ultramodern::input::Pak::RumblePak };
    }
    return { ultramodern::input::Device::None, ultramodern::input::Pak::None };
}

// -----------------------------------------------
// RSP callbacks
// -----------------------------------------------
RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
    // DKR uses aspMain for audio
    // task_type 2 = audio
    // task_type 1 = graphics (handled by RT64)
    if (task->t.type == 2) {
        return aspMain;
    }
    return nullptr;
}

// -----------------------------------------------
// GFX callbacks (SDL window management)
// -----------------------------------------------
static SDL_Window* sdl_window = nullptr;

void* create_gfx() {
    sdl_window = SDL_CreateWindow(
        "Diddy Kong Racing Recompiled",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 960,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );
    return sdl_window;
}

ultramodern::renderer::WindowHandle create_window(void* gfx_data) {
    SDL_SysWMinfo wminfo{};
    SDL_VERSION(&wminfo.version);
    SDL_GetWindowWMInfo(sdl_window, &wminfo);
    return ultramodern::renderer::WindowHandle{ wminfo.info.win.window, GetCurrentThreadId() };
}

void update_gfx(void* gfx_data) {
    poll_input();
}

// -----------------------------------------------
// Error handling
// -----------------------------------------------
void show_message_box(const char* msg) {
    MessageBoxA(nullptr, msg, "DKR Recompiled - Error", MB_OK | MB_ICONERROR);
}

// -----------------------------------------------
// Events
// -----------------------------------------------
void vi_callback() {
    // Could be used for FPS counting or frame pacing
}

void gfx_init_callback() {
    // Called before entering the GFX main loop
}

// -----------------------------------------------
// Thread naming
// -----------------------------------------------
std::string get_game_thread_name(const OSThread* t) {
    return "DKR-Thread-" + std::to_string(t->id);
}

// -----------------------------------------------
// Config path
// -----------------------------------------------
std::filesystem::path get_app_folder_path() {
    char* appdata = nullptr;
    size_t len = 0;
    _dupenv_s(&appdata, &len, "LOCALAPPDATA");
    std::filesystem::path path = std::filesystem::path(appdata ? appdata : ".") / "DKRRecompiled";
    free(appdata);
    std::filesystem::create_directories(path);
    return path;
}

// -----------------------------------------------
// Main
// -----------------------------------------------
int main(int argc, char* argv[]) {
    // Windows timer precision
    timeBeginPeriod(1);

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) != 0) {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    // Set up config path
    recomp::register_config_path(get_app_folder_path());

    // Register DKR game entry
    recomp::GameEntry dkr_entry{};
    dkr_entry.rom_hash = 0; // Will be computed from ROM
    dkr_entry.internal_name = "Diddy Kong Racin";  // First 16 chars from ROM header
    dkr_entry.game_id = u8"dkr-us";
    dkr_entry.mod_game_id = "dkr-us";
    dkr_entry.save_type = recomp::SaveType::Eep4k;
    dkr_entry.is_enabled = true;
    dkr_entry.has_compressed_code = false;
    dkr_entry.entrypoint_address = (gpr)(int32_t)0x80000400u;
    dkr_entry.entrypoint = recomp_entrypoint;

    recomp::register_game(dkr_entry);

    // Register overlays
    register_overlays();

    // Set up callbacks
    recomp::rsp::callbacks_t rsp_callbacks{};
    rsp_callbacks.get_rsp_microcode = get_rsp_microcode;

    ultramodern::renderer::callbacks_t renderer_callbacks{};
    renderer_callbacks.create_render_context = create_rt64_render_context;

    ultramodern::audio_callbacks_t audio_cbs{};
    audio_cbs.queue_samples = queue_audio_samples;
    audio_cbs.get_frames_remaining = get_audio_frames_remaining;
    audio_cbs.set_frequency = set_audio_frequency;

    ultramodern::input::callbacks_t input_cbs{};
    input_cbs.poll_input = poll_input;
    input_cbs.get_input = get_input;
    input_cbs.set_rumble = set_rumble;
    input_cbs.get_connected_device_info = get_connected_device_info;

    ultramodern::gfx_callbacks_t gfx_cbs{};
    gfx_cbs.create_gfx = create_gfx;
    gfx_cbs.create_window = create_window;
    gfx_cbs.update_gfx = update_gfx;

    ultramodern::events::callbacks_t events_cbs{};
    events_cbs.vi_callback = vi_callback;
    events_cbs.gfx_init_callback = gfx_init_callback;

    ultramodern::error_handling::callbacks_t error_cbs{};
    error_cbs.message_box = show_message_box;

    ultramodern::threads::callbacks_t thread_cbs{};
    thread_cbs.get_game_thread_name = get_game_thread_name;

    // Start the recomp runtime
    recomp::Configuration config{};
    config.project_version = { 0, 1, 0 };
    config.rsp_callbacks = rsp_callbacks;
    config.renderer_callbacks = renderer_callbacks;
    config.audio_callbacks = audio_cbs;
    config.input_callbacks = input_cbs;
    config.gfx_callbacks = gfx_cbs;
    config.events_callbacks = events_cbs;
    config.error_handling_callbacks = error_cbs;
    config.threads_callbacks = thread_cbs;

    recomp::start(config);

    // Cleanup
    if (audio_device) SDL_CloseAudioDevice(audio_device);
    if (controller) SDL_GameControllerClose(controller);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
    timeEndPeriod(1);

    return 0;
}
