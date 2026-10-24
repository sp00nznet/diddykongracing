// Netplay: up to 4 players in deterministic lockstep over UDP, with the host as the hub.
//
// Every machine runs the game in ultramodern's deterministic mode, so identical inputs at identical
// retraces give identical games. At each virtual retrace every player samples their controller for
// retrace + delay. Joiners send that to the host; the host gathers all players' inputs for a
// retrace and sends the complete set to everyone as soon as it has it. Nobody lets the game see
// retrace r until they hold all inputs for r. The input delay hides the round trip to the host.
// Every 60 retraces everyone hashes game RAM; joiners send theirs to the host, the host sends its
// own back, and a mismatch is logged as a desync.
//
// Before the game starts, the host sends its save to each joiner (unlocks change the game, so all
// need the same one). Netplay runs from its own config folder (netplay/), so normal saves are
// untouched. Player 1 is the host; joiners are players 2 to 4 in the order they joined.

#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include "librecomp/game.hpp"
#include "ultramodern/error_handling.hpp"
#include "config.hpp"
#include "internal.hpp"

namespace fe::net {
namespace {

constexpr uint32_t kMagic = 0x4E363446; // "N64F"
constexpr uint32_t kVersion = 3;
constexpr int kMaxPlayers = 4;
constexpr int kRedundancy = 16;     // each input or frame packet repeats this many recent retraces
constexpr int kHashEvery = 60;      // retraces between desync checks
constexpr uint32_t kMaxSave = 4096; // ponytail: one datagram, enough for EEPROM; chunk it for SRAM/flash saves

enum PacketType : uint32_t {
    PKT_HELLO = 1,   // joiner -> host: let me in
    PKT_WELCOME = 2, // host -> joiner: your player number, the delay, the save
    PKT_ACK = 3,     // joiner -> host: got the welcome
    PKT_INPUT = 4,   // joiner -> host: my inputs for recent retraces
    PKT_HASH = 5,    // either way: a RAM hash for a retrace
    PKT_START = 6,   // host -> joiner: the game starts with this many players
    PKT_FRAMES = 7,  // host -> joiner: every player's inputs for recent retraces
};

struct Input { uint16_t buttons = 0; float x = 0, y = 0; };
using Frame = std::array<Input, kMaxPlayers>;

#pragma pack(push, 1)
struct Header { uint32_t magic, type, version, game; };
struct WelcomePacket { Header h; uint32_t delay; uint32_t player; uint32_t save_len; uint8_t save[kMaxSave]; };
struct StartPacket { Header h; uint32_t players; };
struct InputPacket { Header h; uint32_t player; uint64_t first; uint32_t count; Input inputs[kRedundancy]; };
struct FramesPacket { Header h; uint64_t first; uint32_t count; Frame frames[kRedundancy]; };
struct HashPacket { Header h; uint32_t player; uint64_t frame; uint64_t hash; };
#pragma pack(pop)
constexpr int kMaxPacket = sizeof(WelcomePacket);

struct Peer { sockaddr_in addr{}; int player = 0; bool acked = false; bool started = false; };

bool g_active = false;
bool g_is_host = false;
int g_player = 0;  // this machine's player number, 0-based
int g_players = 2; // players in the game
int g_delay = 2;
SOCKET g_sock = INVALID_SOCKET;
sockaddr_in g_host_addr{};  // joiner: where the host is
std::vector<Peer> g_peers;  // host: the joiners
std::atomic<int> g_connected = 1; // host: players in the lobby, for the UI thread
std::vector<uint8_t> g_save; // the shared save, written into netplay/ by begin()

std::map<uint64_t, Frame> g_frames;     // complete inputs by retrace (host: being gathered too)
std::map<uint64_t, Input> g_local;      // joiner: our own inputs by retrace
std::map<uint64_t, uint32_t> g_have;    // host: which players' inputs it has for a retrace (bits)
uint64_t g_complete = 0;                // host: retraces below this are complete and sent
std::map<uint64_t, uint64_t> g_my_hash; // our hash by retrace
std::map<std::pair<uint64_t, int>, uint64_t> g_their_hash; // (retrace, player) -> hash
Frame g_frame_inputs{};                 // what the game reads this retrace

std::mutex g_status_mutex;
std::string g_status;

void set_status(const std::string& s) {
    printf("[netplay] %s\n", s.c_str());
    std::lock_guard lock{ g_status_mutex };
    g_status = s;
}

// Identifies the game, so two different recomps never pair up.
uint32_t game_tag() {
    uint32_t h = 2166136261u;
    for (char8_t c : g_game.game_id) { h ^= (uint8_t)c; h *= 16777619u; }
    return h;
}

Header header(PacketType t) { return { kMagic, t, kVersion, game_tag() }; }

bool same(const sockaddr_in& a, const sockaddr_in& b) { return a.sin_addr.s_addr == b.sin_addr.s_addr && a.sin_port == b.sin_port; }

void send_to(const sockaddr_in& to, const void* data, int len) {
    sendto(g_sock, (const char*)data, len, 0, (const sockaddr*)&to, sizeof(to));
}

// Receives one packet from anyone (waiting up to `ms`).
int recv_raw(void* buf, int cap, int ms, sockaddr_in* from) {
    fd_set fds; FD_ZERO(&fds); FD_SET(g_sock, &fds);
    timeval tv{ ms / 1000, (ms % 1000) * 1000 };
    if (select(0, &fds, nullptr, nullptr, &tv) <= 0) return 0;
    int from_len = sizeof(*from);
    int n = recvfrom(g_sock, (char*)buf, cap, 0, (sockaddr*)from, &from_len);
    if (n < (int)sizeof(Header) || ((Header*)buf)->magic != kMagic) return 0;
    return n;
}

Peer* find_peer(const sockaddr_in& a) {
    for (Peer& p : g_peers) if (same(p.addr, a)) return &p;
    return nullptr;
}

// Host: send every joiner the newest complete retraces.
void broadcast_frames() {
    if (g_complete == 0) return;
    FramesPacket p{ header(PKT_FRAMES) };
    const uint64_t last = g_complete - 1;
    p.first = last >= kRedundancy - 1 ? last - (kRedundancy - 1) : 0;
    p.count = (uint32_t)(last - p.first + 1);
    for (uint32_t i = 0; i < p.count; i++) p.frames[i] = g_frames[p.first + i];
    for (const Peer& peer : g_peers) send_to(peer.addr, &p, (int)(offsetof(FramesPacket, frames) + p.count * sizeof(Frame)));
}

// Host: move g_complete past every retrace for which all inputs are in, and send them on.
void advance_complete() {
    const uint32_t all = (1u << g_players) - 1;
    bool moved = false;
    while (g_have[g_complete] == all) { g_have.erase(g_complete); g_complete++; moved = true; }
    if (moved) broadcast_frames();
}

void handle_packet(const uint8_t* buf, int n, const sockaddr_in& from) {
    const Header* h = (const Header*)buf;
    if (h->version != kVersion || h->game != game_tag()) return;
    if (h->type == PKT_INPUT && g_is_host && n >= (int)offsetof(InputPacket, inputs)) {
        const InputPacket* p = (const InputPacket*)buf;
        if (p->player == 0 || p->player >= (uint32_t)g_players || !find_peer(from)) return;
        for (uint32_t i = 0; i < p->count && i < kRedundancy; i++) {
            const uint64_t r = p->first + i;
            if (r < g_complete) continue;
            g_frames[r][p->player] = p->inputs[i];
            g_have[r] |= 1u << p->player;
        }
        advance_complete();
    } else if (h->type == PKT_FRAMES && !g_is_host && n >= (int)offsetof(FramesPacket, frames)) {
        const FramesPacket* p = (const FramesPacket*)buf;
        for (uint32_t i = 0; i < p->count && i < kRedundancy; i++) g_frames.emplace(p->first + i, p->frames[i]);
    } else if (h->type == PKT_HASH && n >= (int)sizeof(HashPacket)) {
        const HashPacket* p = (const HashPacket*)buf;
        g_their_hash[{ p->frame, (int)p->player }] = p->hash;
    }
}

void drain(int ms) {
    for (;;) {
        uint8_t buf[kMaxPacket]; sockaddr_in from{};
        int n = recv_raw(buf, sizeof(buf), ms, &from);
        if (n <= 0) return;
        handle_packet(buf, n, from);
        ms = 0;
    }
}

// Joiner: send the host our inputs for recent retraces.
void send_inputs(uint64_t newest) {
    InputPacket p{ header(PKT_INPUT) };
    p.player = (uint32_t)g_player;
    p.first = newest >= kRedundancy - 1 ? newest - (kRedundancy - 1) : 0;
    p.count = (uint32_t)(newest - p.first + 1);
    for (uint32_t i = 0; i < p.count; i++) {
        auto it = g_local.find(p.first + i);
        p.inputs[i] = it != g_local.end() ? it->second : Input{};
    }
    send_to(g_host_addr, &p, (int)(offsetof(InputPacket, inputs) + p.count * sizeof(Input)));
}

void check_hashes() {
    for (auto it = g_their_hash.begin(); it != g_their_hash.end();) {
        auto mine = g_my_hash.find(it->first.first);
        if (mine == g_my_hash.end()) { ++it; continue; }
        if (mine->second != it->second) {
            fprintf(stderr, "[netplay] DESYNC at retrace %llu with player %d (local %016llx, theirs %016llx)\n",
                    (unsigned long long)it->first.first, it->first.second + 1, (unsigned long long)mine->second, (unsigned long long)it->second);
        }
        it = g_their_hash.erase(it);
    }
    while (g_my_hash.size() > 8) g_my_hash.erase(g_my_hash.begin());
}

// The lockstep step, run by the deterministic scheduler at every retrace (on a game thread).
void on_retrace(uint64_t r) {
    Input local;
    sample_local_input(&local.buttons, &local.x, &local.y);
    const uint64_t target = r + g_delay;
    if (g_is_host) {
        g_frames[target][0] = local;
        g_have[target] |= 1u;
        // The first `delay` retraces have no input from anyone.
        while (g_complete < (uint64_t)g_delay) { g_frames[g_complete]; g_complete++; }
        advance_complete();
    } else {
        g_local[target] = local;
        send_inputs(target);
    }

    if (r % kHashEvery == 0) {
        const uint64_t h = det_hash_game_ram();
        g_my_hash[r] = h;
        HashPacket p{ header(PKT_HASH), (uint32_t)g_player, r, h };
        if (g_is_host) for (const Peer& peer : g_peers) send_to(peer.addr, &p, sizeof(p));
        else send_to(g_host_addr, &p, sizeof(p));
    }

    // Wait until every player's input for this retrace is here.
    auto start = std::chrono::steady_clock::now();
    auto last_note = start;
    while (g_is_host ? r >= g_complete : !g_frames.count(r)) {
        uint8_t buf[kMaxPacket]; sockaddr_in from{};
        int n = recv_raw(buf, sizeof(buf), 4, &from);
        if (n > 0) { handle_packet(buf, n, from); continue; }
        if (g_is_host) broadcast_frames(); else send_inputs(target);
        auto now = std::chrono::steady_clock::now();
        if (now - last_note > std::chrono::seconds(3)) {
            last_note = now;
            fprintf(stderr, "[netplay] waiting for the other players (retrace %llu)...\n", (unsigned long long)r);
        }
        if (now - start > std::chrono::seconds(30)) {
            ultramodern::error_handling::message_box("A player stopped responding. The game will close.");
            std::exit(1);
        }
    }
    drain(0);

    g_frame_inputs = g_frames[r];
    // Forget old retraces (kept for resends of the newest kRedundancy).
    if (r > 120) {
        g_frames.erase(g_frames.begin(), g_frames.lower_bound(r - 120));
        g_local.erase(g_local.begin(), g_local.lower_bound(r - 120));
    }
    check_hashes();
}

bool open_socket(int bind_port) {
    static bool wsa_started = false;
    WSADATA wsa;
    if (!wsa_started && WSAStartup(MAKEWORD(2, 2), &wsa) != 0) { set_status("Networking is unavailable."); return false; }
    wsa_started = true;
    if (g_sock != INVALID_SOCKET) closesocket(g_sock);
    g_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (g_sock == INVALID_SOCKET) { set_status("Couldn't open a UDP socket."); return false; }
    sockaddr_in addr{}; addr.sin_family = AF_INET; addr.sin_port = htons((u_short)bind_port); addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(g_sock, (sockaddr*)&addr, sizeof(addr)) != 0) {
        set_status("UDP port " + std::to_string(bind_port) + " is in use.");
        return false;
    }
    return true;
}

void close_socket() {
    if (g_sock != INVALID_SOCKET) closesocket(g_sock);
    g_sock = INVALID_SOCKET;
}

std::filesystem::path save_path(const std::filesystem::path& dir) {
    return dir / "saves" / (std::filesystem::path(g_game.game_id).string() + ".bin");
}

std::vector<uint8_t> read_file(const std::filesystem::path& p) {
    std::ifstream f(p, std::ios::binary);
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(f)), {});
}

int max_players() { return std::clamp(g_game.players, 2, kMaxPlayers); }

std::string players_status() {
    std::string s = std::to_string(g_peers.size() + 1) + " of up to " + std::to_string(max_players()) + " players";
    return g_peers.empty() ? "Waiting for players (" + s + ")..." : s + " connected.";
}

} // namespace

bool active() { return g_active; }
bool is_host() { return g_is_host; }
int delay() { return g_delay; }
int player() { return g_player; }
int players() { return g_players; }
int connected() { return g_connected; }

std::string status() {
    std::lock_guard lock{ g_status_mutex };
    return g_status;
}

// Takes joiners until `start` is set (with at least one joiner), `want` players are in, or `cancel`.
bool host(int port, const std::atomic<bool>& cancel, const std::atomic<bool>& start, int want) {
    if (!open_socket(port)) return false;
    g_is_host = true;
    g_player = 0;
    g_peers.clear();
    g_connected = 1;
    g_delay = g_config.netplayInputDelay;
    want = std::clamp(want, 2, max_players());
    g_save = read_file(save_path(base_dir()));
    if (g_save.size() > kMaxSave) {
        set_status("This game's save is too big to share; the others start without it.");
        g_save.clear();
    }
    set_status(players_status());
    WelcomePacket w{ header(PKT_WELCOME), (uint32_t)g_delay, 0, (uint32_t)g_save.size() };
    std::memcpy(w.save, g_save.data(), g_save.size());
    const int welcome_len = (int)(offsetof(WelcomePacket, save) + g_save.size());

    auto all_acked = [] { for (const Peer& p : g_peers) if (!p.acked) return false; return true; };
    // Lobby.
    while (!cancel && !((start || (int)g_peers.size() + 1 >= want) && !g_peers.empty() && all_acked())) {
        uint8_t buf[kMaxPacket]; sockaddr_in from{};
        int n = recv_raw(buf, sizeof(buf), 50, &from);
        if (n <= 0) {
            for (const Peer& p : g_peers) if (!p.acked) { w.player = (uint32_t)p.player; send_to(p.addr, &w, welcome_len); }
            continue;
        }
        const Header* h = (const Header*)buf;
        if (h->version != kVersion || h->game != game_tag()) { set_status("Someone tried to join with a different game or build."); continue; }
        Peer* peer = find_peer(from);
        if (h->type == PKT_HELLO) {
            if (!peer) {
                if ((int)g_peers.size() + 1 >= max_players()) continue; // full
                g_peers.push_back({ from, (int)g_peers.size() + 1 });
                peer = &g_peers.back();
                g_connected = (int)g_peers.size() + 1;
                set_status(players_status());
            }
            w.player = (uint32_t)peer->player;
            send_to(peer->addr, &w, welcome_len);
        } else if (h->type == PKT_ACK && peer) {
            peer->acked = true;
        }
    }
    if (cancel) { close_socket(); set_status("Cancelled."); return false; }

    // Start: tell everyone how many are playing, until each has started (their first input arrives).
    g_players = (int)g_peers.size() + 1;
    StartPacket sp{ header(PKT_START), (uint32_t)g_players };
    auto t0 = std::chrono::steady_clock::now();
    for (;;) {
        bool all = true;
        for (Peer& p : g_peers) { if (!p.started) { all = false; send_to(p.addr, &sp, sizeof(sp)); } }
        if (all) break;
        if (std::chrono::steady_clock::now() - t0 > std::chrono::seconds(30)) { close_socket(); set_status("A player didn't answer the start."); return false; }
        uint8_t buf[kMaxPacket]; sockaddr_in from{};
        int n = recv_raw(buf, sizeof(buf), 50, &from);
        if (n <= 0) continue;
        Peer* peer = find_peer(from);
        if (peer && ((Header*)buf)->type == PKT_INPUT) { peer->started = true; handle_packet(buf, n, from); }
    }
    set_status("Starting with " + std::to_string(g_players) + " players; input delay " + std::to_string(g_delay) + " frames.");
    return true;
}

bool join(const std::string& address, const std::atomic<bool>& cancel) {
    std::string addr = address, port = std::to_string(g_config.netplayPort);
    if (auto c = addr.rfind(':'); c != std::string::npos) { port = addr.substr(c + 1); addr = addr.substr(0, c); }
    if (!open_socket(0)) return false;
    g_is_host = false;
    addrinfo hints{}; hints.ai_family = AF_INET; hints.ai_socktype = SOCK_DGRAM;
    addrinfo* res = nullptr;
    if (getaddrinfo(addr.c_str(), port.c_str(), &hints, &res) != 0 || !res) {
        set_status("Can't find " + addr + ".");
        close_socket();
        return false;
    }
    std::memcpy(&g_host_addr, res->ai_addr, sizeof(g_host_addr));
    freeaddrinfo(res);
    set_status("Joining " + addr + ":" + port + "...");
    Header hello = header(PKT_HELLO), ack = header(PKT_ACK);
    bool welcomed = false;
    auto start = std::chrono::steady_clock::now();
    for (;;) {
        if (cancel) { close_socket(); set_status("Cancelled."); return false; }
        if (!welcomed && std::chrono::steady_clock::now() - start > std::chrono::seconds(30)) {
            close_socket();
            set_status("No answer from " + addr + ":" + port + ". Is the host waiting, and is UDP port " + port + " reachable?");
            return false;
        }
        if (!welcomed) send_to(g_host_addr, &hello, sizeof(hello));
        uint8_t buf[kMaxPacket]; sockaddr_in from{};
        int n = recv_raw(buf, sizeof(buf), 200, &from);
        if (n <= 0 || !same(from, g_host_addr)) continue;
        const Header* h = (const Header*)buf;
        if (h->version != kVersion || h->game != game_tag()) {
            close_socket();
            set_status("The host is running a different game or build.");
            return false;
        }
        if (h->type == PKT_WELCOME && n >= (int)offsetof(WelcomePacket, save)) {
            const WelcomePacket* w = (const WelcomePacket*)buf;
            g_delay = (int)w->delay;
            g_player = (int)w->player;
            uint32_t len = std::min<uint32_t>(w->save_len, (uint32_t)(n - offsetof(WelcomePacket, save)));
            g_save.assign(w->save, w->save + len);
            send_to(g_host_addr, &ack, sizeof(ack));
            if (!welcomed) set_status("Connected as player " + std::to_string(g_player + 1) + "; waiting for the host to start...");
            welcomed = true;
        } else if (h->type == PKT_START && welcomed && n >= (int)sizeof(StartPacket)) {
            g_players = std::clamp((int)((const StartPacket*)buf)->players, 2, kMaxPlayers);
            break;
        }
    }
    set_status("Starting as player " + std::to_string(g_player + 1) + " of " + std::to_string(g_players) +
               "; input delay " + std::to_string(g_delay) + " frames.");
    return true;
}

// netplay/ gets the stored ROM (copied once) and the shared save; the game then runs from there
// in deterministic mode.
void begin() {
    find_rom(); // stores the ROM in the normal folder first, so there's one to copy
    const std::filesystem::path base = base_dir(), dir = base / "netplay";
    std::filesystem::create_directories(dir / "saves");
    const std::filesystem::path rom = std::filesystem::path(g_game.game_id).string() + ".z64";
    std::error_code ec;
    std::filesystem::copy_file(base / rom, dir / rom, std::filesystem::copy_options::skip_existing, ec);
    if (!g_save.empty()) std::ofstream(save_path(dir), std::ios::binary).write((const char*)g_save.data(), g_save.size());
    else std::filesystem::remove(save_path(dir), ec);
    recomp::register_config_path(dir);
    g_active = true;
    det_start(on_retrace);
    // A joiner's first input tells the host it started.
    if (!g_is_host) send_inputs(0);
}

// The game's controller reads while netplay is active: port N is player N + 1.
bool get_input(int port, uint16_t* buttons, float* x, float* y) {
    *buttons = 0; *x = *y = 0;
    if (port < 0 || port >= g_players) return false;
    *buttons = g_frame_inputs[port].buttons; *x = g_frame_inputs[port].x; *y = g_frame_inputs[port].y;
    return true;
}

ultramodern::input::connected_device_info_t device_info(int port) {
    if (port >= 0 && port < g_players) return { ultramodern::input::Device::Controller, ultramodern::input::Pak::None };
    return { ultramodern::input::Device::None, ultramodern::input::Pak::None };
}

std::vector<std::string> local_addresses() {
    std::vector<std::string> out;
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return out;
    char name[256];
    if (gethostname(name, sizeof(name)) == 0) {
        addrinfo hints{}; hints.ai_family = AF_INET;
        addrinfo* res = nullptr;
        if (getaddrinfo(name, nullptr, &hints, &res) == 0) {
            for (addrinfo* a = res; a; a = a->ai_next) {
                char ip[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &((sockaddr_in*)a->ai_addr)->sin_addr, ip, sizeof(ip));
                if (std::find(out.begin(), out.end(), ip) == out.end()) out.push_back(ip);
            }
            freeaddrinfo(res);
        }
    }
    WSACleanup();
    return out;
}

} // namespace fe::net
