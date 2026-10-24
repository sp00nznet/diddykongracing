cmake_minimum_required(VERSION 3.20)

project(DKRRecompiled VERSION 0.3.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# Toolkits: deps/ when tools/setup.ps1 fetched them there, else sibling checkouts (docs/building.md).
foreach(dep N64ModernRuntime rt64)
    if(EXISTS "${CMAKE_SOURCE_DIR}/deps/${dep}/CMakeLists.txt")
        set(default_${dep} "${CMAKE_SOURCE_DIR}/deps/${dep}")
    else()
        set(default_${dep} "${CMAKE_SOURCE_DIR}/../${dep}")
    endif()
endforeach()
set(N64_MODERN_RUNTIME_DIR "${default_N64ModernRuntime}" CACHE PATH "Path to N64ModernRuntime")
set(RT64_DIR "${default_rt64}" CACHE PATH "Path to RT64 (with F3DDKR support)")

foreach(generated RecompiledFuncs/funcs.h rsp/aspMain.cpp)
    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/${generated}")
        message(FATAL_ERROR "${generated} is missing: recompile your ROM first (README, Step by step; Setup.cmd does it).")
    endif()
endforeach()

# SDL2: the Windows build RT64 ships (RT64 links it by bare name from this folder).
set(SDL2_DIR_WIN "${RT64_DIR}/src/contrib/mupen64plus-win32-deps/SDL2-2.26.3")
link_directories("${SDL2_DIR_WIN}/lib/x64")
add_library(SDL2::SDL2 SHARED IMPORTED)
set_target_properties(SDL2::SDL2 PROPERTIES
    IMPORTED_LOCATION "${SDL2_DIR_WIN}/lib/x64/SDL2.dll"
    IMPORTED_IMPLIB "${SDL2_DIR_WIN}/lib/x64/SDL2.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${SDL2_DIR_WIN}/include")
add_library(SDL2::SDL2main STATIC IMPORTED)
set_target_properties(SDL2::SDL2main PROPERTIES IMPORTED_LOCATION "${SDL2_DIR_WIN}/lib/x64/SDL2main.lib")

set(RT64_STATIC ON CACHE BOOL "Build RT64 as static library" FORCE)
add_subdirectory(${RT64_DIR} ${CMAKE_BINARY_DIR}/rt64)

add_subdirectory(${N64_MODERN_RUNTIME_DIR} ${CMAKE_BINARY_DIR}/N64ModernRuntime)
# The anti-piracy checks read RSP memory, low RDRAM and cart ROM through KSEG1 (0xA0000000 to
# 0xB0000574), which the recompiled code maps 512 to 768 MB past RDRAM. Commit that far so those
# reads land in memory src/main.cpp seeds (docs/game-fixes.md).
target_compile_definitions(librecomp PUBLIC RECOMP_MEM_SIZE_MB=784)

# The game's code, recompiled from your ROM (tools/setup.ps1 or the README's steps). Never committed.
file(GLOB RECOMP_SOURCES "RecompiledFuncs/*.c")
add_library(RecompiledFuncs STATIC ${RECOMP_SOURCES})
target_include_directories(RecompiledFuncs PRIVATE ${N64_MODERN_RUNTIME_DIR}/N64Recomp/include RecompiledFuncs)
if(MSVC)
    target_compile_options(RecompiledFuncs PRIVATE /w)
else()
    target_compile_options(RecompiledFuncs PRIVATE -fno-strict-aliasing -w)
endif()

add_subdirectory(frontend)

add_executable(DKRRecompiled
    src/main.cpp
    src/dkr_stubs.c
    rsp/aspMain.cpp
)
target_include_directories(DKRRecompiled PRIVATE
    ${N64_MODERN_RUNTIME_DIR}/N64Recomp/include
    ${N64_MODERN_RUNTIME_DIR}/librecomp/include
    ${N64_MODERN_RUNTIME_DIR}/ultramodern/include
    RecompiledFuncs
)
target_compile_definitions(DKRRecompiled PRIVATE NOMINMAX DKR_VERSION="${PROJECT_VERSION}")
target_link_libraries(DKRRecompiled PRIVATE RecompiledFuncs librecomp ultramodern n64frontend rt64 SDL2::SDL2 SDL2::SDL2main)

if(WIN32)
    target_link_libraries(DKRRecompiled PRIVATE dxgi d3d12 d3dcompiler dbghelp ws2_32)
    target_link_options(DKRRecompiled PRIVATE /MAP)
    # RT64 loads the DXC runtime from next to the exe; without it, setup silently skips init.
    add_custom_command(TARGET DKRRecompiled POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${RT64_DIR}/src/contrib/dxc/bin/x64/dxil.dll ${RT64_DIR}/src/contrib/dxc/bin/x64/dxcompiler.dll
        ${SDL2_DIR_WIN}/lib/x64/SDL2.dll
        $<TARGET_FILE_DIR:DKRRecompiled>)
endif()
