cmake_minimum_required(VERSION 3.20)
project(DKRRecompiled LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# Fetch SDL2
include(FetchContent)
FetchContent_Declare(
    SDL2
    URL https://github.com/libsdl-org/SDL/releases/download/release-2.30.3/SDL2-2.30.3.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(SDL2)

# RT64 renderer — Stage 1 of the swap. F3DDKR microcode isn't in RT64's
# GBI database yet, so DLs won't actually render. We're just validating
# the build/plumbing; SW renderer remains the default fallback.
option(DKR_USE_RT64 "Build with RT64 renderer (stage 1: init only, no DKR microcode support)" OFF)
if (DKR_USE_RT64)
    set(RT64_STATIC TRUE CACHE BOOL "Build RT64 as static library" FORCE)
    add_compile_definitions(HLSL_CPU DKR_USE_RT64)
    add_subdirectory(lib/rt64)
endif()

# N64ModernRuntime (ultramodern + librecomp)
add_subdirectory(lib/N64ModernRuntime)

# Recompiled functions static library
file(GLOB RECOMP_SOURCES "RecompiledFuncs/*.c" "RecompiledFuncs/*.cpp")
add_library(RecompiledFuncs STATIC ${RECOMP_SOURCES})
target_include_directories(RecompiledFuncs PRIVATE
    include
    lib/N64ModernRuntime/ultramodern/include
    lib/N64ModernRuntime/librecomp/include
    lib/N64ModernRuntime/N64Recomp/include
)
target_compile_options(RecompiledFuncs PRIVATE
    $<$<C_COMPILER_ID:MSVC>:/w>
    $<$<C_COMPILER_ID:Clang>:-fno-strict-aliasing -Wno-unused-variable -Wno-implicit-function-declaration>
    $<$<C_COMPILER_ID:GNU>:-fno-strict-aliasing -Wno-unused-variable -Wno-implicit-function-declaration>
)
if (MSVC)
    target_compile_options(RecompiledFuncs PRIVATE /w /Zi)
endif()

# Dear ImGui — when DKR_USE_RT64=ON, take it from RT64's contrib (and let
# rt64.lib provide the core/SDL2/DX12/Vulkan backend symbols). We only build
# the SDL_Renderer2 backend ourselves since RT64 doesn't compile that one.
# Otherwise use our vendored copy in third_party.
if (DKR_USE_RT64)
    set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/imgui")
    set(IMGUI_SOURCES
        ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer2.cpp
    )
else()
    set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/third_party/imgui")
    set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
        ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer2.cpp
    )
endif()

# Main executable
add_executable(DKRRecompiled
    src/main.cpp
    src/register_overlays.cpp
    src/rt64_render_context.cpp
    src/f3ddkr.cpp
    src/stubs.cpp
    src/audio_diag.cpp
    src/menu_gui.cpp
    src/stb_image_write_impl.c
    rsp/aspMain.cpp
    ${IMGUI_SOURCES}
)

if (DKR_USE_RT64)
    target_sources(DKRRecompiled PRIVATE src/dkr_rt64_context.cpp)
    target_link_libraries(DKRRecompiled PRIVATE rt64)
    target_include_directories(DKRRecompiled PRIVATE
        lib/rt64/src
        lib/rt64/src/contrib
        lib/rt64/src/contrib/hlslpp/include
        ${CMAKE_BINARY_DIR}/rt64/src
    )
endif()

target_include_directories(DKRRecompiled PRIVATE
    include
    RecompiledFuncs
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    lib/N64ModernRuntime/ultramodern/include
    lib/N64ModernRuntime/librecomp/include
    lib/N64ModernRuntime/N64Recomp/include
    lib/rt64/src/contrib/stb
)

target_link_libraries(DKRRecompiled PRIVATE
    RecompiledFuncs
    librecomp
    ultramodern
    SDL2::SDL2
    SDL2::SDL2main
)

if (WIN32)
    target_link_libraries(DKRRecompiled PRIVATE Winmm.lib Dbghelp.lib)
    # Generate PDB and MAP in Release for crash diagnostics
    target_compile_options(DKRRecompiled PRIVATE /Zi)
    target_link_options(DKRRecompiled PRIVATE $<$<CONFIG:Release>:/DEBUG /OPT:REF /OPT:ICF /MAP>)
    set_target_properties(DKRRecompiled PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
    # Copy SDL2.dll
    add_custom_command(TARGET DKRRecompiled POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE_DIR:SDL2::SDL2>/SDL2.dll"
            "$<TARGET_FILE_DIR:DKRRecompiled>/SDL2.dll"
    )
endif()

target_compile_definitions(DKRRecompiled PRIVATE
    DKR_VERSION_MAJOR=0
    DKR_VERSION_MINOR=1
    DKR_VERSION_PATCH=0
    NOMINMAX
)
