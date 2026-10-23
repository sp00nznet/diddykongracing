# Contributing

Bug reports, test runs and fixes are welcome.

## Reporting a problem

Open an issue with what you did, what happened, and the console output. A hang is much easier to
find with a stack dump: run with `DKR_STACKDUMP=<seconds>` set and paste the `[stack]` lines
(README, Usage). A short `--record` clip of the problem helps too.

## Changing code

- Never commit anything from the game: no ROMs, nothing from `RecompiledFuncs/` or
  `rsp/aspMain.cpp`, no recompiled or disassembled code, no extracted assets.
- Fix the cause, in the right place ([docs/game-fixes.md](docs/game-fixes.md)): a wrong function
  boundary or name in `dkr.us.syms.toml`, a fix inside a function as a `[[patches.hook]]` in
  `dkr.recomp.toml`, a value the hardware would supply in `src/main.cpp`. Something every N64
  title could hit belongs in N64Recomp, N64ModernRuntime or RT64; open it there and link it here.
- Before sending a change, check the game still boots and races: `--headless --record` with
  `DKR_AUTOPRESS` and `DKR_QUIT_AFTER` makes that one command (README, Usage).

## Where your code comes from

This repo is MIT. Code derived from a copyleft project can't come in, even rewritten, and that
includes reading one emulator's source and writing "our own" version. The ones most likely to be
open when working on N64 code: **mupen64plus** and its HLE audio and video plugins, **Project64**,
**simple64**, **angrylion-rdp**, **GLideN64**, and the GPL recomp projects (**Zelda64Recomp**,
**DinosaurPlanetRecomp**, **Starfox64Recomp**). Hardware documentation (n64brew), measuring the game
itself, running an emulator as a black box to compare its output, the
[DKR decompilation](https://github.com/DavidSM64/Diddy-Kong-Racing) (CC0), and permissively
licensed code with its notice kept (N64Recomp and RT64 are MIT) are fine. N64ModernRuntime is
GPL-3.0: this repo links it but takes no code from it, and changes to it go to its repo. Say where
unusual knowledge came from in the PR.

AI-assisted contributions are welcome, as long as a person understood and checked the change.
