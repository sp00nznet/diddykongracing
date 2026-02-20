# DKR Recompiled

Static recompilation of **Diddy Kong Racing** (N64, US v1.1) for Windows 11 using [N64Recomp](https://github.com/N64Recomp/N64Recomp).

## Status

- **Build**: Compiles successfully (MSVC, x64, Release)
- **Runtime**: Stable, no crashes (30+ second sessions)
- **Functions**: 1956 recompiled functions + aspMain RSP microcode
- **Display**: Software framebuffer via SDL2 (320x237, RGBA5551)
- **f3ddkr HLE**: Custom microcode interpreter — rendering working (logos + 3D scene)
- **Audio**: aspMain processes 1 task then stalls (scheduler issue)
- **RT64**: Removed from build (DKR's f3ddkr microcode not supported)

### Rendering Progress
- **Logo screens**: N64/Rareware golden logos render via TEXRECT (RGBA32 textures)
- **Sky**: Blue sky renders correctly via textured triangles (RGBA16)
- **Terrain**: Island geometry renders but vertex colors are dark (CPU lighting not fully running)
- **Alpha test**: Transparent pixels correctly skipped
- **RGBA32 TMEM interleaving**: Properly splits R,G and B,A across TMEM banks

### f3ddkr HLE Features
- Display list parser with recursive sub-DL support (G_DL, G_DMADL)
- Segment address resolution
- N64 fixed-point matrix loading (s15.16)
- Vertex transform with N64-standard viewport (preserves scale sign)
- Scanline triangle rasterizer with Z-buffer, backface culling, scissor
- Texture loading: LOADBLOCK, LOADTILE, LOADTLUT (with RGBA32 interleaving)
- Texture sampling: RGBA16/32, CI4/8, IA4/8/16, I4/8
- TEXRECT with copy and 1-cycle modes
- Fill rect in fill/1-cycle/2-cycle modes
- Alpha test (skip alpha=0 pixels)

## Building

### Prerequisites
- Visual Studio 2022 (MSVC toolchain)
- CMake 3.20+
- N64Recomp tool (for regenerating recompiled functions)

### Build
```bash
cd tracking/build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
```

### Post-build
SDL2.dll must be copied manually after clean builds:
```powershell
Copy-Item 'build\_deps\sdl2-build\Release\SDL2.dll' 'build\Release\SDL2.dll'
```

## Running

Place your ROM as `build/Release/baserom.us.z64` or pass it as argument:
```
DKRRecompiled.exe "path/to/Diddy Kong Racing (U) [!].z64"
```

Or use the run script:
```powershell
powershell -ExecutionPolicy Bypass -File build\Release\run_dkr.ps1
```

### ROM Requirements
- Diddy Kong Racing (US) v1.1 (v80)
- SHA1: `6d96743d46f8c0cd0edb0ec5600b003c89b93755`

## Architecture

```
tracking/
  CMakeLists.txt          # Build configuration
  dkr.recomp.toml         # N64Recomp configuration
  dkr.us.syms.toml        # Symbol definitions (1956 functions)
  include/
    f3ddkr.h              # f3ddkr microcode definitions and state
  src/
    main.cpp              # Entry point, SDL init, game lifecycle
    rt64_render_context.cpp  # Software renderer + f3ddkr HLE bridge
    f3ddkr.cpp            # f3ddkr HLE implementation (~1650 lines)
    stubs.cpp             # Stub functions for unresolved symbols
    register_overlays.cpp # Overlay registration (none for DKR)
  rsp/
    aspMain.cpp           # aspMain audio RSP microcode HLE
  lib/
    N64ModernRuntime/     # ultramodern + librecomp runtime
```

## Known Issues

1. **Audio stalls after 1 task**: DKR's custom scheduler forwards only 1 VI retrace to the audio thread
2. **SDL2.dll post-build copy fails**: `pwsh.exe` not found in MSVC build environment
3. **Dark terrain**: Island geometry has (0,0,0) vertex colors — CPU lighting may not be running fully
4. **No color combiner**: Using shade*tex for triangles and tex-direct for TEXRECT (not proper N64 combiner)
5. **No fog/blending**: Distance fog and alpha blending not yet implemented

## Credits

Built with [N64Recomp](https://github.com/N64Recomp/N64Recomp) and [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime).
DKR decomp reference: [Diddy-Kong-Racing](https://github.com/DavidSM64/Diddy-Kong-Racing).
