#include <cstdio>
#include <filesystem>
#include <fstream>
#include <memory>
#include <thread>
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <timeapi.h>
#include <DbgHelp.h>

#include <SDL.h>
#include <SDL_syswm.h>

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

// RSP microcode (C++ linkage - matches aspMain.cpp)
RspExitReason aspMain(uint8_t* rdram, uint32_t ucode_addr);

// Wrapper around aspMain that adds diagnostics
extern uint8_t dmem[];
static int audio_task_count = 0;
RspExitReason aspMain_wrapper(uint8_t* rdram, uint32_t ucode_addr) {
    audio_task_count++;
    fprintf(stderr, "[DKR] Audio task #%d\n", audio_task_count);
    fflush(stderr);

    RspExitReason result = aspMain(rdram, ucode_addr);
    if (result != RspExitReason::Broke) {
        fprintf(stderr, "[DKR] aspMain FAILED with reason %d (task #%d)\n",
            (int)result, audio_task_count);
        fflush(stderr);
        return RspExitReason::Broke;
    }
    return result;
}

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

// Auto-advance: simulate Start/A presses to get past boot screens
static uint32_t input_start_ticks = 0;

bool get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    if (controller_num != 0) return false;

    *buttons = 0;
    *x = 0.0f;
    *y = 0.0f;

    // Auto-press Start/A to advance past boot screens
    // DKR boot: Nintendo logo (~3s) → Rareware logo (~3s) → title screen (needs Start)
    if (input_start_ticks == 0) input_start_ticks = SDL_GetTicks();
    uint32_t elapsed_ms = SDL_GetTicks() - input_start_ticks;
    auto auto_press = [&](uint32_t at_ms, uint16_t btn) {
        if (elapsed_ms >= at_ms && elapsed_ms < at_ms + 200) *buttons |= btn;
    };
    auto_press(4000, 0x1000);  // Start at 4s (skip Nintendo logo)
    auto_press(8000, 0x1000);  // Start at 8s (skip Rareware logo)
    auto_press(12000, 0x1000); // Start at 12s (advance title screen)

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
    // task_type 1 = graphics (handled by RT64 - but f3ddkr not supported yet)
    if (task->t.type == 2) {
        return aspMain_wrapper;
    }
    if (task->t.type == 1) {
        // Return nullptr to send to RT64 (which will be a no-op via our send_dl stub)
        return nullptr;
    }
    fprintf(stderr, "[DKR] Unknown RSP task type: %u\n", task->t.type);
    return nullptr;
}

// -----------------------------------------------
// GFX callbacks (SDL window management)
// -----------------------------------------------
static SDL_Window* sdl_window = nullptr;

// Exported for rt64_render_context.cpp software framebuffer display
SDL_Window* get_sdl_window() {
    return sdl_window;
}

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
// ROM loading
// -----------------------------------------------
static std::vector<uint8_t> read_rom_file(const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) return {};
    auto size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<uint8_t> data(size);
    file.read(reinterpret_cast<char*>(data.data()), size);
    return data;
}

static std::filesystem::path find_rom() {
    const char* rom_names[] = {
        "baserom.us.z64",
        "dkr.z64",
        "Diddy Kong Racing (U) [!].z64",
    };
    // Check current working directory
    for (const char* name : rom_names) {
        if (std::filesystem::exists(name)) return name;
    }
    // Check next to executable
    char exe_path_buf[MAX_PATH];
    GetModuleFileNameA(nullptr, exe_path_buf, MAX_PATH);
    std::filesystem::path exe_dir = std::filesystem::path(exe_path_buf).parent_path();
    for (const char* name : rom_names) {
        auto p = exe_dir / name;
        if (std::filesystem::exists(p)) return p;
    }
    return {};
}

// -----------------------------------------------
// Main
// -----------------------------------------------
// Crash handler - writes to both stderr and a file
static LONG WINAPI crash_handler(EXCEPTION_POINTERS* ep) {
    // Open crash log file next to exe
    char exe_path[MAX_PATH];
    GetModuleFileNameA(nullptr, exe_path, MAX_PATH);
    std::filesystem::path log_path = std::filesystem::path(exe_path).parent_path() / "dkr_crash.log";
    FILE* logf = fopen(log_path.string().c_str(), "w");

    // Helper macro to write to both stderr and file
    #define CRASH_LOG(fmt, ...) do { \
        fprintf(stderr, fmt, ##__VA_ARGS__); fflush(stderr); \
        if (logf) { fprintf(logf, fmt, ##__VA_ARGS__); fflush(logf); } \
    } while(0)

    CRASH_LOG("\n========== DKR CRASH REPORT ==========\n");
    CRASH_LOG("[DKR] Exception code: 0x%08lX\n", ep->ExceptionRecord->ExceptionCode);
    CRASH_LOG("[DKR] Crash address: 0x%p\n", ep->ExceptionRecord->ExceptionAddress);
    if (ep->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION) {
        ULONG_PTR fault_addr = ep->ExceptionRecord->ExceptionInformation[1];
        CRASH_LOG("[DKR] Access violation %s address 0x%016llX\n",
            ep->ExceptionRecord->ExceptionInformation[0] == 0 ? "reading" : "writing",
            (unsigned long long)fault_addr);
    }

    HMODULE hmod = GetModuleHandleA(nullptr);
    uintptr_t base = (uintptr_t)hmod;
    CRASH_LOG("[DKR] Module base=0x%p, crash offset=0x%llX\n",
        hmod, (unsigned long long)((uintptr_t)ep->ExceptionRecord->ExceptionAddress - base));

    // Dump x64 register context
    auto* c = ep->ContextRecord;
    CRASH_LOG("[DKR] Registers: RAX=%016llX RBX=%016llX RCX=%016llX RDX=%016llX\n",
        (unsigned long long)c->Rax, (unsigned long long)c->Rbx,
        (unsigned long long)c->Rcx, (unsigned long long)c->Rdx);
    CRASH_LOG("[DKR] RSI=%016llX RDI=%016llX RBP=%016llX RSP=%016llX\n",
        (unsigned long long)c->Rsi, (unsigned long long)c->Rdi,
        (unsigned long long)c->Rbp, (unsigned long long)c->Rsp);
    CRASH_LOG("[DKR] R8=%016llX R9=%016llX R10=%016llX R11=%016llX\n",
        (unsigned long long)c->R8, (unsigned long long)c->R9,
        (unsigned long long)c->R10, (unsigned long long)c->R11);
    CRASH_LOG("[DKR] R12=%016llX R13=%016llX R14=%016llX R15=%016llX\n",
        (unsigned long long)c->R12, (unsigned long long)c->R13,
        (unsigned long long)c->R14, (unsigned long long)c->R15);
    CRASH_LOG("[DKR] RIP=%016llX\n", (unsigned long long)c->Rip);

    // Symbol resolution for the crashing RIP
    CRASH_LOG("[DKR] Initializing symbols...\n");
    HANDLE process = GetCurrentProcess();
    HANDLE thread = GetCurrentThread();
    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
    BOOL sym_ok = SymInitialize(process, NULL, TRUE);
    CRASH_LOG("[DKR] SymInitialize: %s\n", sym_ok ? "OK" : "FAILED");

    if (sym_ok) {
        char sym_buf[sizeof(SYMBOL_INFO) + 512];
        SYMBOL_INFO* sym = (SYMBOL_INFO*)sym_buf;

        // First resolve the crashing RIP
        memset(sym_buf, 0, sizeof(sym_buf));
        sym->SizeOfStruct = sizeof(SYMBOL_INFO);
        sym->MaxNameLen = 512;
        DWORD64 disp = 0;
        CRASH_LOG("\n[DKR] Crashing function (RIP):\n");
        if (SymFromAddr(process, c->Rip, &disp, sym)) {
            CRASH_LOG("  -> %s+0x%llX\n", sym->Name, (unsigned long long)disp);
        } else {
            CRASH_LOG("  -> (unknown, module+0x%llX, err=%lu)\n",
                (unsigned long long)(c->Rip - base), GetLastError());
        }

        // Stack trace using StackWalk64 with the exception context
        CONTEXT ctx_copy = *c;
        STACKFRAME64 frame{};
        frame.AddrPC.Offset = c->Rip;
        frame.AddrPC.Mode = AddrModeFlat;
        frame.AddrFrame.Offset = c->Rbp;
        frame.AddrFrame.Mode = AddrModeFlat;
        frame.AddrStack.Offset = c->Rsp;
        frame.AddrStack.Mode = AddrModeFlat;

        CRASH_LOG("\n[DKR] Stack trace:\n");
        for (int i = 0; i < 64; i++) {
            if (!StackWalk64(IMAGE_FILE_MACHINE_AMD64, process, thread,
                             &frame, &ctx_copy, NULL,
                             SymFunctionTableAccess64, SymGetModuleBase64, NULL)) {
                CRASH_LOG("  (StackWalk64 failed at frame %d, err=%lu)\n", i, GetLastError());
                break;
            }
            if (frame.AddrPC.Offset == 0) break;

            memset(sym_buf, 0, sizeof(sym_buf));
            sym->SizeOfStruct = sizeof(SYMBOL_INFO);
            sym->MaxNameLen = 512;
            DWORD64 displacement = 0;

            if (SymFromAddr(process, frame.AddrPC.Offset, &displacement, sym)) {
                CRASH_LOG("  [%2d] %s+0x%llX\n", i, sym->Name, (unsigned long long)displacement);
            } else {
                CRASH_LOG("  [%2d] 0x%016llX (module+0x%llX)\n", i,
                    (unsigned long long)frame.AddrPC.Offset,
                    (unsigned long long)(frame.AddrPC.Offset - base));
            }
        }

        SymCleanup(process);
    }

    CRASH_LOG("========== END CRASH REPORT ==========\n");
    if (logf) fclose(logf);
    #undef CRASH_LOG
    return EXCEPTION_EXECUTE_HANDLER;
}

int main(int argc, char* argv[]) {
    SetUnhandledExceptionFilter(crash_handler);
    fprintf(stderr, "[DKR] Starting up...\n"); fflush(stderr);

    // Windows timer precision
    timeBeginPeriod(1);

    // Initialize SDL
    fprintf(stderr, "[DKR] Initializing SDL...\n"); fflush(stderr);
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) != 0) {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }
    fprintf(stderr, "[DKR] SDL initialized\n"); fflush(stderr);

    // Set up config path
    auto app_path = get_app_folder_path();
    fprintf(stderr, "[DKR] Config path: %s\n", app_path.string().c_str()); fflush(stderr);
    recomp::register_config_path(app_path);

    // Find and load ROM to compute hash
    std::filesystem::path rom_path = (argc > 1) ? argv[1] : find_rom();
    if (rom_path.empty() || !std::filesystem::exists(rom_path)) {
        MessageBoxA(nullptr,
            "Could not find ROM file.\n\n"
            "Place 'baserom.us.z64' (Diddy Kong Racing US v1.1) next to the executable,\n"
            "or pass the ROM path as a command line argument.",
            "DKR Recompiled - ROM Not Found", MB_OK | MB_ICONERROR);
        SDL_Quit();
        return 1;
    }

    fprintf(stderr, "[DKR] Loading ROM: %s\n", rom_path.string().c_str()); fflush(stderr);
    std::vector<uint8_t> rom_data = read_rom_file(rom_path);
    if (rom_data.empty()) {
        MessageBoxA(nullptr, "Failed to read ROM file.", "DKR Recompiled - Error", MB_OK | MB_ICONERROR);
        SDL_Quit();
        return 1;
    }

    // Compute XXH3 hash of the ROM
    uint64_t rom_hash = XXH3_64bits(rom_data.data(), rom_data.size());
    fprintf(stderr, "[DKR] ROM hash: 0x%016llX\n", (unsigned long long)rom_hash); fflush(stderr);

    // Store the ROM in the config directory for librecomp
    std::u8string game_id = u8"dkr-us";
    std::filesystem::path stored_rom_path = app_path / (std::string(game_id.begin(), game_id.end()) + ".z64");
    {
        std::ofstream out(stored_rom_path, std::ios::binary);
        out.write(reinterpret_cast<const char*>(rom_data.data()), rom_data.size());
    }
    rom_data.clear(); // Free memory

    // Register DKR game entry
    recomp::GameEntry dkr_entry{};
    dkr_entry.rom_hash = rom_hash;
    dkr_entry.internal_name = "Diddy Kong Racin";  // First 16 chars from ROM header
    dkr_entry.game_id = game_id;
    dkr_entry.mod_game_id = "dkr-us";
    dkr_entry.save_type = recomp::SaveType::Eep4k;
    dkr_entry.is_enabled = true;
    dkr_entry.has_compressed_code = false;
    dkr_entry.entrypoint_address = (gpr)(int32_t)0x80000400u;
    dkr_entry.entrypoint = recomp_entrypoint;
    dkr_entry.on_init_callback = [](uint8_t* rdram, recomp_context* ctx) {
        fprintf(stderr, "[DKR] ROM loaded and init complete, about to call entrypoint\n");
        fprintf(stderr, "[DKR] RDRAM base: 0x%p\n", rdram);
        fprintf(stderr, "[DKR] r29(SP): 0x%llX, r8: 0x%llX\n",
            (unsigned long long)ctx->r29, (unsigned long long)ctx->r8);
        fflush(stderr);
    };

    recomp::register_game(dkr_entry);
    fprintf(stderr, "[DKR] Game registered\n"); fflush(stderr);

    // Register overlays
    register_overlays();
    fprintf(stderr, "[DKR] Overlays registered\n"); fflush(stderr);

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

    fprintf(stderr, "[DKR] All callbacks set up, launching game...\n"); fflush(stderr);

    // Launch a thread to start the game once the runtime is ready
    std::thread start_thread([&game_id]() {
        // Wait briefly for recomp::start() to initialize
        Sleep(1000);
        fprintf(stderr, "[DKR] Calling start_game...\n"); fflush(stderr);
        recomp::start_game(game_id);
    });
    start_thread.detach();

    // Start the recomp runtime (blocks until game exits)
    fprintf(stderr, "[DKR] Calling recomp::start()...\n"); fflush(stderr);
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
