// Tools for unattended runs and debugging: crash reports with recompiled function names, stack
// dumps, RDRAM peeks and write watches, timed screenshots, quitting after a while, and
// --record <file.mp4> (the window's frames piped to ffmpeg). All switches are <prefix>NAME
// environment variables (README, Usage); none of them does anything unless set.
//
// Captures use PrintWindow's full-content mode, which also reads the D3D12 swap chain and works
// while --headless keeps the window off every monitor. Over RDP that still renders, so it never
// takes over the screen.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <dbghelp.h>
#include <tlhelp32.h>

#include <SDL.h>
#include <SDL_syswm.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "config.hpp"
#include "internal.hpp"

namespace fe {
namespace {

const char* env(const char* name) { return std::getenv((g_game.env_prefix + name).c_str()); }

// The linker map names every recompiled function; the PDB doesn't (they're one big static lib).
struct MapSym { uint32_t rva; std::string name; };
std::vector<MapSym> g_syms;

void load_map() {
    wchar_t exe[MAX_PATH];
    GetModuleFileNameW(nullptr, exe, MAX_PATH);
    std::ifstream f(std::filesystem::path(exe).replace_extension(".map"));
    // Symbol lines: " 0001:00025e00   name   0000000140026e00 f obj"
    for (std::string line; std::getline(f, line); ) {
        std::istringstream ss(line);
        std::vector<std::string> t;
        for (std::string w; ss >> w; ) t.push_back(w);
        if (t.size() < 3 || t[0].size() != 13 || t[0][4] != ':') continue;
        if (t[2].size() == 16 && t[2].compare(0, 8, "00000001") == 0)
            g_syms.push_back({ (uint32_t)(strtoull(t[2].c_str(), nullptr, 16) - 0x140000000ull), t[1] });
    }
    std::sort(g_syms.begin(), g_syms.end(), [](auto& a, auto& b) { return a.rva < b.rva; });
}

std::string symbolize(uint64_t pc) {
    uintptr_t base = (uintptr_t)GetModuleHandleW(nullptr);
    const auto* nt = (const IMAGE_NT_HEADERS*)(base + ((const IMAGE_DOS_HEADER*)base)->e_lfanew);
    if (pc < base || pc >= base + nt->OptionalHeader.SizeOfImage || g_syms.empty()) {
        // Outside the exe (system DLLs): ask dbghelp.
        alignas(SYMBOL_INFO) char buf[sizeof(SYMBOL_INFO) + 256] = {};
        auto* sym = (SYMBOL_INFO*)buf;
        sym->SizeOfStruct = sizeof(SYMBOL_INFO);
        sym->MaxNameLen = 255;
        DWORD64 disp = 0;
        return SymFromAddr(GetCurrentProcess(), pc, &disp, sym) ? std::string(sym->Name) : std::string();
    }
    uint32_t rva = (uint32_t)(pc - base);
    auto it = std::upper_bound(g_syms.begin(), g_syms.end(), rva, [](uint32_t v, const MapSym& m) { return v < m.rva; });
    if (it == g_syms.begin()) return {};
    --it;
    return it->name + " + 0x" + (std::stringstream{} << std::hex << (rva - it->rva)).str();
}

void print_stack(HANDLE thread, CONTEXT ctx, int max_frames) {
    static bool sym_init = SymInitialize(GetCurrentProcess(), nullptr, TRUE);
    (void)sym_init;
    STACKFRAME64 frame{};
    frame.AddrPC = { ctx.Rip, 0, AddrModeFlat };
    frame.AddrStack = { ctx.Rsp, 0, AddrModeFlat };
    frame.AddrFrame = { ctx.Rbp, 0, AddrModeFlat };
    for (int i = 0; i < max_frames; i++) {
        if (!StackWalk64(IMAGE_FILE_MACHINE_AMD64, GetCurrentProcess(), thread, &frame, &ctx, nullptr,
                         SymFunctionTableAccess64, SymGetModuleBase64, nullptr)) break;
        uint64_t pc = frame.AddrPC.Offset;
        std::string name = symbolize(pc);
        IMAGEHLP_LINE64 line{ sizeof(line) };
        DWORD disp = 0;
        if (SymGetLineFromAddr64(GetCurrentProcess(), pc, &disp, &line))
            fprintf(stderr, "  [%d] %s (%s:%lu)\n", i, name.c_str(), line.FileName, line.LineNumber);
        else
            fprintf(stderr, "  [%d] %s (0x%llX)\n", i, name.c_str(), (unsigned long long)pc);
    }
}

// <prefix>PEEK=0x801234A0,...: RDRAM words printed with a stack dump or crash.
void print_peeks() {
    const char* p = env("PEEK");
    if (!p || !g_rdram) return;
    for (char* end; *p; p = *end ? end + 1 : end) {
        uint32_t a = (uint32_t)strtoul(p, &end, 16);
        if (end == p) break;
        fprintf(stderr, "[peek] 0x%08X = 0x%08X\n", a, *(uint32_t*)(g_rdram + (a - 0x80000000u)));
    }
}

LONG WINAPI crash_handler(EXCEPTION_POINTERS* ep) {
    // ponytail: game threads can still touch RDRAM after the runtime frees it on the way out.
    // Once quitting, that's not worth a report; the fix is a shutdown order in N64ModernRuntime.
    if (g_quitting) TerminateProcess(GetCurrentProcess(), 0);
    fprintf(stderr, "\n[crash] exception 0x%08lX at %s (0x%p)\n", ep->ExceptionRecord->ExceptionCode,
            symbolize((uint64_t)ep->ExceptionRecord->ExceptionAddress).c_str(), ep->ExceptionRecord->ExceptionAddress);
    if (ep->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION && g_rdram) {
        int64_t off = (int64_t)(ep->ExceptionRecord->ExceptionInformation[1] - (uintptr_t)g_rdram);
        fprintf(stderr, "[crash] %s RDRAM offset %+lld (N64 address ~0x%08X)\n",
                ep->ExceptionRecord->ExceptionInformation[0] ? "writing" : "reading", (long long)off, (uint32_t)(off + 0x80000000));
    }
    print_stack(GetCurrentThread(), *ep->ContextRecord, 24);
    print_peeks();
    return EXCEPTION_EXECUTE_HANDLER;
}

template <typename F> void for_each_other_thread(F f) {
    DWORD self = GetCurrentThreadId(), pid = GetCurrentProcessId();
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    THREADENTRY32 te{ sizeof(te) };
    for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
        if (te.th32OwnerProcessID != pid || te.th32ThreadID == self) continue;
        HANDLE th = OpenThread(THREAD_ALL_ACCESS, FALSE, te.th32ThreadID);
        if (!th) continue;
        SuspendThread(th);
        f(th, te.th32ThreadID);
        ResumeThread(th);
        CloseHandle(th);
    }
    CloseHandle(snap);
}

// <prefix>STACKDUMP=<sec>: every thread's stack at that time, for hangs.
void dump_stacks() {
    for_each_other_thread([](HANDLE th, DWORD id) {
        CONTEXT ctx{};
        ctx.ContextFlags = CONTEXT_FULL;
        if (!GetThreadContext(th, &ctx)) return;
        fprintf(stderr, "[stack] thread %lu:\n", id);
        print_stack(th, ctx, 12);
    });
    print_peeks();
}

// <prefix>WATCH=<addr>@<sec>: a hardware write watchpoint on that RDRAM word; the first write
// lands in crash_handler with the writer's stack.
void watch(uint32_t addr, int seconds) {
    Sleep(seconds * 1000);
    if (!g_rdram) return;
    DWORD64 native = (DWORD64)(g_rdram + (addr - 0x80000000u));
    fprintf(stderr, "[watch] armed on 0x%08X\n", addr);
    for (;;) { // re-armed so threads started later are covered too
        for_each_other_thread([native](HANDLE th, DWORD) {
            CONTEXT ctx{};
            ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
            if (GetThreadContext(th, &ctx) && ctx.Dr0 != native) {
                ctx.Dr0 = native;
                ctx.Dr7 = 0x000D0001; // local enable 0, break on write, 4 bytes
                SetThreadContext(th, &ctx);
            }
        });
        Sleep(10);
    }
}

// The window's client area as bottom-up BGR rows (BMP layout).
bool grab(std::vector<uint8_t>& pixels, int& w, int& h) {
    SDL_SysWMinfo wm;
    SDL_VERSION(&wm.version);
    if (!window() || !SDL_GetWindowWMInfo(window(), &wm)) return false;
    HWND hwnd = wm.info.win.window;
    RECT rc;
    GetClientRect(hwnd, &rc);
    w = rc.right & ~1; h = rc.bottom & ~1; // even, for the encoder
    if (w <= 0 || h <= 0) return false;
    HDC wdc = GetDC(hwnd), mdc = CreateCompatibleDC(wdc);
    HBITMAP bmp = CreateCompatibleBitmap(wdc, w, h);
    HGDIOBJ old = SelectObject(mdc, bmp);
    PrintWindow(hwnd, mdc, PW_CLIENTONLY | PW_RENDERFULLCONTENT);
    BITMAPINFOHEADER bi{ sizeof(bi), w, h, 1, 24, BI_RGB };
    pixels.resize((size_t)((w * 3 + 3) & ~3) * h);
    GetDIBits(mdc, bmp, 0, h, pixels.data(), (BITMAPINFO*)&bi, DIB_RGB_COLORS);
    SelectObject(mdc, old);
    DeleteObject(bmp);
    DeleteDC(mdc);
    ReleaseDC(hwnd, wdc);
    return true;
}

void save_bmp(const std::string& path) {
    std::vector<uint8_t> px;
    int w, h;
    if (!grab(px, w, h)) return;
    BITMAPINFOHEADER bi{ sizeof(bi), w, h, 1, 24, BI_RGB };
    BITMAPFILEHEADER bf{ 0x4D42, (DWORD)(sizeof(bf) + sizeof(bi) + px.size()), 0, 0, sizeof(bf) + sizeof(bi) };
    std::ofstream f(path, std::ios::binary);
    f.write((const char*)&bf, sizeof(bf));
    f.write((const char*)&bi, sizeof(bi));
    f.write((const char*)px.data(), px.size());
    printf("%s saved %s (%dx%d)\n", log_prefix().c_str(), path.c_str(), w, h);
}

// --record <file>: 30 fps of the window into ffmpeg (on PATH) until quit. The size is fixed by the
// first frame. ponytail: a wall-clock 30 fps grab, so a stall shows as repeated frames.
FILE* g_ffmpeg = nullptr;

void record(std::string path) {
    std::vector<uint8_t> px;
    int w = 0, h = 0;
    while (!grab(px, w, h)) Sleep(100);
    std::string cmd = "ffmpeg -loglevel error -y -f rawvideo -pix_fmt bgr24 -s " + std::to_string(w) + "x" + std::to_string(h) +
        " -r 30 -i - -vf vflip -c:v libx264 -preset veryfast -pix_fmt yuv420p \"" + path + "\"";
    g_ffmpeg = _popen(cmd.c_str(), "wb");
    if (!g_ffmpeg) { fprintf(stderr, "%s --record: couldn't start ffmpeg\n", log_prefix().c_str()); return; }
    printf("%s recording %dx%d to %s\n", log_prefix().c_str(), w, h, path.c_str());
    const size_t stride = (size_t)w * 3, padded = (stride + 3) & ~(size_t)3;
    for (uint64_t next = GetTickCount64(); g_ffmpeg; next += 33) {
        int fw, fh;
        if (grab(px, fw, fh) && fw == w && fh == h) {
            for (int y = 0; y < h && g_ffmpeg; y++) fwrite(px.data() + y * padded, 1, stride, g_ffmpeg);
        }
        uint64_t now = GetTickCount64();
        if (next > now) Sleep((DWORD)(next - now));
    }
}

} // namespace

void debug_finish() {
    if (FILE* f = g_ffmpeg) { g_ffmpeg = nullptr; Sleep(50); _pclose(f); }
}

void debug_init(const std::string& record_path) {
    // Unbuffered, so a log ends where the program did (a forced exit drops buffered output).
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);
    load_map();
    SetUnhandledExceptionFilter(crash_handler);
    if (const char* s = env("STACKDUMP")) std::thread([n = atoi(s)] { Sleep(n * 1000); dump_stacks(); }).detach();
    if (const char* w = env("WATCH")) {
        const char* at = strchr(w, '@');
        std::thread(watch, (uint32_t)strtoul(w, nullptr, 16), at ? atoi(at + 1) : 0).detach();
    }
    // <prefix>SHOT=10:title.bmp,30:race.bmp: save the window at those times (seconds).
    if (const char* s = env("SHOT")) {
        std::thread([spec = std::string(s)] {
            double elapsed = 0;
            std::stringstream ss(spec);
            for (std::string item; std::getline(ss, item, ','); ) {
                size_t colon = item.find(':');
                if (colon == std::string::npos) continue;
                double t = atof(item.c_str());
                if (t > elapsed) Sleep((DWORD)((t - elapsed) * 1000));
                elapsed = std::max(elapsed, t);
                save_bmp(item.substr(colon + 1));
            }
        }).detach();
    }
    // <prefix>QUIT_AFTER=<sec>: exit on its own, for scripted and recorded runs.
    if (const char* q = env("QUIT_AFTER")) {
        std::thread([n = atoi(q)] {
            Sleep(n * 1000);
            debug_finish();
            quit();
            Sleep(5000);
            fprintf(stderr, "%s did not quit cleanly; exiting\n", log_prefix().c_str());
            TerminateProcess(GetCurrentProcess(), 0);
        }).detach();
    }
    if (!record_path.empty()) std::thread(record, record_path).detach();
}

} // namespace fe
