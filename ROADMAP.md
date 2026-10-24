# Roadmap

## Next

- **Play it through.** A Tracks-mode race starts and drives (Ancient Lake), alone and with 4
  players over netplay; whole races, the other tracks, Adventure's doors and races, boss races,
  trophy races and local split screen with several pads haven't been played yet. Scripted headless runs that finish a race, kept as a
  regression check.
- **Controller pak.** DKR stores ghosts and time-trial data on a pak and is told none is plugged
  in. Emulate one (a file per player) in N64ModernRuntime, which Rampage needs too.
- **Saves.** EEPROM data is written; check that Adventure progress and times reload.
- **Merge the toolkit PRs** ([N64Recomp#1](https://github.com/sp00nznet/N64Recomp/pull/1),
  [N64ModernRuntime#11](https://github.com/sp00nznet/N64ModernRuntime/pull/11),
  [rt64#4](https://github.com/sp00nznet/rt64/pull/4)) and point Setup back at `main`.
- **netlab.** An N64 builder (DXC, RT64's bundled SDL2) so builds and headless runs move off the
  workstation, shared with Racer and Rampage.

- **Netplay across real machines.** Tested as 4 instances on one PC over loopback. Check two
  machines with different GPUs (RT64 writing framebuffers back into RDRAM could differ and show
  up as a desync) and over the internet.

## Later

- Netplay: each player sees only their own view full-screen instead of the N64's split screen;
  two local players on one machine; rejoining after a dropped connection.

- A conformance check: headless runs to fixed points (title, character select, the hub, a race
  start) compared against stored frame hashes, run on netlab.
- Widescreen HUD: the 3D already fills 16:9; the HUD and menus stay in the middle 4:3. Frame
  interpolation for 60 fps.
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
