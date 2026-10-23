# Changelog

All notable changes, newest first. Format: [Keep a Changelog](https://keepachangelog.com/);
versions: [SemVer](https://semver.org/).

## [Unreleased]

## [0.2.0] - 2026-10-23

Rebuilt on current N64Recomp, N64ModernRuntime and RT64 (sp00nznet's forks), with the shared
frontend from Racer. The game now renders through RT64 and plays from boot into Adventure mode.

### Added
- RT64 rendering of DKR's graphics microcode (F3DDKR), at any resolution, with MSAA, a widescreen
  option and texture packs ([sp00nznet/rt64#4](https://github.com/sp00nznet/rt64/pull/4)).
- The shared frontend: launcher, in-game menu (Esc), up to 4 controllers plus keyboard with
  rebinding, `dkr.json` settings, F11 fullscreen.
- `Setup.cmd` quick start: checks and offers to install the prerequisites, finds your ROM, fetches
  the toolkits, recompiles and builds, and leaves `Diddy Kong Racing (recomp).cmd`.
- `--headless`, `--record out.mp4`, and the `DKR_QUIT_AFTER`, `DKR_SHOT`, `DKR_AUTOPRESS`,
  `DKR_AUDIODUMP`, `DKR_STACKDUMP`, `DKR_PEEK`, `DKR_WATCH` switches for unattended runs and
  debugging; crash reports name the recompiled function.
- `launcher/launcher.json` and the installer workflow for recomp-launcher.
- Docs: architecture, building, game fixes. LICENSE (MIT), CONTRIBUTING, ROADMAP.

### Changed
- In-game fixes are `[[patches.hook]]` entries in `dkr.recomp.toml` and seeds in `src/main.cpp`,
  instead of edits to generated code ([docs/game-fixes.md](docs/game-fixes.md)).
- Toolkits come from `deps/` (Setup) or sibling checkouts instead of git submodules.
- The audio microcode is recompiled for IMEM `0x1080`, where it runs; with that, RSPRecomp's output
  plays unmodified.

### Fixed
- 3D geometry missing, doubly projected, or stretched into spikes: matrix slots, 2-byte-aligned
  vertices, billboards and per-triangle culling in F3DDKR.
- Every rotation zero (flat or invisible scenes): the cosine routine falls through into the sine
  routine, which the recompiler now follows
  ([sp00nznet/N64Recomp#1](https://github.com/sp00nznet/N64Recomp/pull/1)).
- Freezes and crashes at the title screen and at level loads: RSP tasks now run in hardware order
  ([sp00nznet/N64ModernRuntime#11](https://github.com/sp00nznet/N64ModernRuntime/pull/11)), and the
  scheduler's hung-RCP watchdog no longer fires on slow PC frames.
- Crash a few seconds in when the host audio queue grew past one frame.
- Upside-down screen, uncollectable golden balloons and the race-finish check: every anti-piracy
  read now gets the value a console returns.
- Crashes on quit.

### Removed
- Recompiled game code and the recompiled audio microcode from the repository: they're generated
  from your ROM now.
- The software renderer, its ImGui copy (`third_party/imgui`), and the old build's hand-written
  audio HLE, which was partly based on mupen64plus (GPL). Also a scheduler workaround credited to
  DinosaurPlanetRecomp (GPL-3.0).
- `run_dkr.bat`, the mupen64plus debugger scripts (`tools/m64p_debug`), and old progress
  screenshots.

## [0.1.0] - 2026-05-29

Boots to the Adventure hub on a software renderer of this project's own, with sound through a
patched audio microcode. Built on N64ModernRuntime and RT64 branches with DKR-specific changes;
recompiled code committed.
