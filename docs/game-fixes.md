# Game fixes

What Diddy Kong Racing needs beyond a correct symbol file, and why. Nothing here edits generated
code: a fix inside a function is a `[[patches.hook]]` in `dkr.recomp.toml` (N64Recomp inserts the
hook's text before the instruction at `before_vram`), hardware values are seeded in
`src/main.cpp`, and anything another title could hit went to the toolkits as a PR.

## In this repo

| Fix | Where | Why |
|---|---|---|
| Audio microcode loads at IMEM `0x1080` | `rsp/aspMain.toml` (`text_address`) | Every libultra audio microcode runs from `0x1080`; rspboot sits at `0x1000`. The old config said `0x1000`, so every jump landed 0x80 bytes off: handlers "entered mid-loop", and the old build patched the generated C by hand (partly from mupen64plus's GPL audio HLE, now gone). With the right address RSPRecomp's output works unmodified. |
| Empty audio tasks are completed without running | `get_rsp_microcode`, `src/main.cpp` | DKR sometimes submits an audio command list of length 0 (`alAudioFrame` with nothing to play). aspMain starts on the first command without checking the length, so it would run whatever the last task left in DMEM. An empty list makes no sound. |
| Audio frame size: clamp `osAiGetLength` to one frame | hook in `__amHandleFrameMsg` at `0x80002C84` | DKR sizes each audio frame as `frameSize - osAiGetLength()/4 + margin`, which assumes the length never exceeds one buffer, as on hardware. The runtime reports the whole host audio queue, so the size went negative (`0xFF80`) and the game queued a garbage buffer: a crash a few seconds in. |
| Scheduler watchdog off | hook at the start of `__scHandleRetrace` (`0x80079C68`) | A task still running after 10 retraces is taken as a hung RCP: halted, dropped, and its late completion then hits a NULL task (crash in `__scHandleRSP`) or is lost (the game freezes). On a PC a frame can take that long (RT64 compiling shaders at a scene change). The hook keeps `gCurRSPTaskCounter`/`gCurRDPTaskCounter` (`0x800DECD4`/`D8`) at zero. |
| Anti-piracy checks get the values a console returns | `on_init`, `src/main.cpp` | Reads of SP DMEM/IMEM, low RDRAM, the cart ROM and `osCicId` through KSEG1. Wrong values flip the screen upside down (`gAntiPiracyViewport`, cart ROM `0x578`), press Start every frame (IMEM), busy-loop every frame (DMEM), mirror the tracks (RDRAM `0x200`), make golden balloons uncollectable (RDRAM `0x284`) and break the race finish (cart ROM `0x574`). The cart ROM's first 4 KB are mirrored at `0xB0000000`. The checksum checks over the game's own code pass by themselves: the runtime copies the code into RDRAM as IPL3 does. |
| Memory committed up to 784 MB | `CMakeLists.txt` (`RECOMP_MEM_SIZE_MB`) | The recompiled code reaches KSEG1 addresses 512 to 768 MB past RDRAM's base, so the seeds above need memory there. |
| libultra internals the runtime lacks | `src/dkr_stubs.c` | `rmonPrintf`, `__osSpSetStatus`, SI access and the controller pak routines are on N64Recomp's ignore list but still called. The pak ones answer "no pak". |
| Hardware-ordered RSP tasks | `cfg.synchronous_rsp_tasks`, `src/main.cpp` | DKR frees and reloads assets (textures, sprite display lists) right after submitting a frame, and rebuilds vertices and matrices once the RSP reports done. Game threads here only switch when one blocks, so RT64 read reused memory, ran off the end of display lists into texture data, and the game froze or crashed (mostly at the title screen and at level loads). See the N64ModernRuntime PR below. |

## In the toolkits

| Toolkit | Change | Why DKR needed it |
|---|---|---|
| N64Recomp | [sp00nznet/N64Recomp#1](https://github.com/sp00nznet/N64Recomp/pull/1): tail-call the next function when code runs off a function's end | `coss_s16` adds a quarter turn and falls through into `sins_s16` (and `coss_2` into `sins_2`). Recompiled separately, cosine returned without computing anything, every rotation came out zero, and 3D scenes were flat or invisible. |
| N64ModernRuntime | [sp00nznet/N64ModernRuntime#11](https://github.com/sp00nznet/N64ModernRuntime/pull/11): opt-in `synchronous_rsp_tasks` | See above. |
| RT64 | [sp00nznet/rt64#4](https://github.com/sp00nznet/rt64/pull/4): F3DDKR | DKR's graphics microcode, following the decompilation's `include/f3ddkr.h`: four full-MVP matrix slots, 10-byte 2-byte-aligned vertices, per-triangle texture coordinates and cull flag, billboards, `G_DMADL`. Plus two generic fixes: screen-position overrides survive vertex copies, and loads past RDRAM are skipped instead of faulting. |

## Removed from the old build

Kept here so nobody re-adds them:

- **The software renderer** (`src/f3ddkr.cpp`). RT64 draws the game now. Its matrix "multiply
  flag" came from GLideN64 (GPL) and the game never sets it.
- **Hand edits to generated code** (`RecompiledFuncs/`, `rsp/aspMain.cpp`): the fallthroughs are
  the recompiler's job now, the audio patches were symptoms of the IMEM address, and the gzip
  "pointer validation" guards hid the display-list race.
- **Zeroing the scheduler counters from the VI callback**, an idea taken from DinosaurPlanetRecomp
  (GPL-3.0). The watchdog hook above does the same job from DKR's own decompilation.
- **The cinematic auto-skip** (forcing the new-game cutscene to "done"). It worked around the
  synchronous-task deadlock in the old runtime branch; the intro now plays.
- **`requeue_si = false`.** It made boot hang in some runs; the freezes it was meant for were the
  display-list race.
- **The old runtime's `dkr-fixes` branch** (synchronous tasks hard-wired for DKR, a global
  `g_dkr_use_rt64_gfx_path`): game-specific code in the runtime, replaced by the opt-in above.
