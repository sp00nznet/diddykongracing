# Building

The README's Getting Started has the two routes (Setup.cmd, and step by step). This is what each
step makes and why, for when something goes wrong or you want your own toolkit checkouts.

## Toolkits

DKR builds against sp00nznet's forks, which carry fixes not yet upstream:

| Toolkit | Branch | Why this branch |
|---|---|---|
| [N64Recomp](https://github.com/sp00nznet/N64Recomp) | `fix/fallthrough-tail-call` | follows code that runs off a function's end into the next one (DKR's cosine falls into its sine); [sp00nznet/N64Recomp#1](https://github.com/sp00nznet/N64Recomp/pull/1) |
| [N64ModernRuntime](https://github.com/sp00nznet/N64ModernRuntime) | `feat/synchronous-rsp-tasks` | the `synchronous_rsp_tasks` option DKR turns on; [sp00nznet/N64ModernRuntime#11](https://github.com/sp00nznet/N64ModernRuntime/pull/11) |
| [rt64](https://github.com/sp00nznet/rt64) | `feat/f3ddkr` | DKR's graphics microcode (F3DDKR); [sp00nznet/rt64#4](https://github.com/sp00nznet/rt64/pull/4) |

Once those PRs merge, the branches become `main` here and in `tools/setup.ps1`. Why each one is
needed is in [game-fixes.md](game-fixes.md).

CMake looks for N64ModernRuntime and rt64 in `deps/` (where Setup puts them), then next to this
repo (`../N64ModernRuntime`, `../rt64`). Point it anywhere else with
`-DN64_MODERN_RUNTIME_DIR=<path> -DRT64_DIR=<path>`.

## Generated code

Nothing derived from the ROM is in this repository. Two tools make it from your copy:

| Command | Reads | Writes |
|---|---|---|
| `N64Recomp dkr.recomp.toml` | `baserom.us.z64`, `dkr.us.syms.toml` | `RecompiledFuncs/` (37 C files, `funcs.h`, `recomp_overlays.inl`) |
| `RSPRecomp rsp\aspMain.toml` | `baserom.us.z64` | `rsp/aspMain.cpp` (the audio microcode as C++) |

Both outputs are gitignored. CMake stops with a message if they're missing.

`dkr.us.syms.toml` (function names, addresses and sizes) comes from the
[DKR decompilation](https://github.com/DavidSM64/Diddy-Kong-Racing)'s `symbol_addrs.us.v80.txt`,
which is CC0. `tools/generate_symbols.js` rebuilds it from a decomp checkout next to this repo
(`node tools/generate_symbols.js`, Node 18+); you only need it to pick up new names from the decomp.

## Build

```
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config RelWithDebInfo --target DKRRecompiled --parallel
```

The first build compiles RT64 and its shaders and takes 20 to 40 minutes; after that, a change to
`src/` rebuilds in seconds and a regenerated `RecompiledFuncs/` in a few minutes. The exe lands in
`build\RelWithDebInfo\` with `SDL2.dll`, `dxil.dll` and `dxcompiler.dll` copied next to it (RT64
silently skips its setup without the last two).

## netlab

recomp-netlab has no N64 builder yet (it needs DXC and RT64's bundled SDL2 on the clang-cl
builder), so DKR, like Rampage and Racer, builds on the workstation for now. That gap is on
[ROADMAP.md](../ROADMAP.md).
