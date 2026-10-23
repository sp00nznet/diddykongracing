# Architecture

Diddy Kong Racing Recompiled is one executable built from four parts. Two of them are made from
your ROM on your machine and never leave it.

```
 your ROM ──N64Recomp──> RecompiledFuncs/*.c ──┐          (the game's MIPS code as C)
         └─RSPRecomp───> rsp/aspMain.cpp ──────┤          (its audio microcode as C++)
                                               ├─> DKRRecompiled.exe
 src/        game glue: registration, hardware ┤
             seeds, RSP task routing           │
 frontend/   window, input, config, launcher,  ┤
             menu, netplay, debug switches     │
 N64ModernRuntime (librecomp + ultramodern) ───┤          (libultra, threads, VI/AI, saves)
 RT64 ─────────────────────────────────────────┘          (graphics, D3D12)
```

## What each part owns

| Part | Owns | Where |
|---|---|---|
| Recompiled game | Everything the cartridge's CPU code does: game logic, DKR's own scheduler, audio manager, asset loading. Calls into libultra land in the runtime. | `RecompiledFuncs/` (generated), `dkr.us.syms.toml` (function boundaries, from the decomp), `dkr.recomp.toml` (hooks) |
| Audio microcode | Turning DKR's audio command lists into samples, as the RSP would. | `rsp/aspMain.cpp` (generated), `rsp/aspMain.toml` |
| Game glue | Registering the game with the runtime, the values DKR's anti-piracy checks expect, which RSP tasks run what, libultra internals the runtime doesn't provide. | `src/main.cpp`, `src/dkr_stubs.c` |
| Frontend | The window, controllers and keyboard, `dkr.json`, the launcher and in-game menu (ImGui over RT64), audio output, netplay, and the `--headless`/`--record`/`DKR_*` debug switches. Shared with sp00nznet's other N64 recomps; this is a copy of Racer's, plus `src/debug.cpp`. | `frontend/` |
| N64ModernRuntime | libultra reimplemented: threads (one game thread runs at a time; they switch when one blocks), message queues, VI retraces, audio interface, PI DMA from the ROM, EEPROM saves. | toolkit |
| RT64 | Interpreting DKR's display lists (the F3DDKR microcode) and drawing them with D3D12, at any resolution. | toolkit |

## How a frame flows

1. The VI thread (runtime) posts a retrace message every 1/60 s to DKR's scheduler thread.
2. DKR's main thread builds a display list, its audio thread a command list, and both hand them to
   DKR's scheduler, which starts them on the "RSP" with `osSpTaskStartGo`.
3. With `synchronous_rsp_tasks` on (DKR sets it, [game-fixes.md](game-fixes.md)): an audio task
   runs `aspMain` right there and reports done; a graphics task waits until RT64 has parsed the
   display list on its graphics thread, then reports done. RT64 renders on its own.
4. The audio manager queues the finished samples with `osAiSetNextBuffer`; the frontend sends
   them to SDL.
5. `osViSwapBuffer` tells the runtime which framebuffer to show; RT64 presents it at the next
   retrace.

## Why it's built this way

- **Generated code is not committed.** It's derived from the game. N64Recomp and RSPRecomp make
  it from your ROM in a minute or two (`tools/setup.ps1`).
- **Fixes go where they belong.** A wrong function boundary is a symbol-file fix; a fix inside a
  function is a recompiler hook; hardware behaviour every title shares goes to the toolkits as a
  PR. Nothing edits generated code, so a re-run of the recompiler loses nothing.
- **RT64 over a hand-written renderer.** The old build drew DKR with its own software rasterizer.
  RT64 gives any resolution, MSAA, texture packs and widescreen, and DKR's microcode is a few
  hundred lines in it.
