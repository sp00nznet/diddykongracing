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

# RT64 renderer - disabled for now (f3ddkr microcode not supported)
# Using software framebuffer display via SDL instead.
# set(RT64_STATIC TRUE CACHE BOOL "Build RT64 as static library" FORCE)
# set(RT64_SDL_WINDOW_VULKAN TRUE CACHE BOOL "SDL Vulkan window support" FORCE)
# add_subdirectory(lib/rt64)

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

# Main executable
add_executable(DKRRecompiled
    src/main.cpp
    src/register_overlays.cpp
    src/rt64_render_context.cpp
    src/f3ddkr.cpp
    src/stubs.cpp
    src/audio_diag.cpp
    rsp/aspMain.cpp
)

target_include_directories(DKRRecompiled PRIVATE
    include
    RecompiledFuncs
    lib/N64ModernRuntime/ultramodern/include
    lib/N64ModernRuntime/librecomp/include
    lib/N64ModernRuntime/N64Recomp/include
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
