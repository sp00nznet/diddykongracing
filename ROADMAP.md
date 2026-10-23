# Roadmap

## Next

- **Play it through.** Races (Adventure and Tracks mode), boss races, the trophy races and
  multiplayer (2 to 4 players, split screen) haven't been played yet. Scripted headless runs that
  reach a race and finish it, kept as a regression check.
- **Controller pak.** DKR stores ghosts and time-trial data on a pak and is told none is plugged
  in. Emulate one (a file per player) in N64ModernRuntime, which Rampage needs too.
- **Saves.** EEPROM data is written; check that Adventure progress and times reload.
- **Merge the toolkit PRs** ([N64Recomp#1](https://github.com/sp00nznet/N64Recomp/pull/1),
  [N64ModernRuntime#11](https://github.com/sp00nznet/N64ModernRuntime/pull/11),
  [rt64#4](https://github.com/sp00nznet/rt64/pull/4)) and point Setup back at `main`.
- **netlab.** An N64 builder (DXC, RT64's bundled SDL2) so builds and headless runs move off the
  workstation, shared with Racer and Rampage.

## Later

- A conformance check: headless runs to fixed points (title, character select, the hub, a race
  start) compared against stored frame hashes, run on netlab.
- Widescreen that also widens DKR's HUD and 2D layers, and frame interpolation for 60 fps.
- An N64ModernRuntime shutdown order that stops game threads before RDRAM is freed, then drop
  the quit-time fault guard in `frontend/src/debug.cpp`; the same for RT64's destructor, which
  `frontend/src/rt64_context.cpp` currently skips.
- The rare garbage texture load still seen once in testing (now skipped instead of crashing):
  find which display list runs into data.
- Linux build.
- The PAL and Japanese versions, and USA v1.0 (`tools/generate_symbols.js` reads the decomp's
  per-version symbol files).

## Out of scope

- Distributing anything from the game: the ROM, generated code, or builds made from it.
- Code from GPL projects (mupen64plus, GLideN64, DinosaurPlanetRecomp, Zelda64Recomp). The old
  build's pieces derived from them were removed in 0.2.0.
