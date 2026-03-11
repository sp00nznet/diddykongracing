@echo off
REM DKR Recompiled - Launch script
REM Usage: run_dkr.bat [rom_path]

cd /d "%~dp0build\Release"

REM Copy SDL2.dll if missing
if not exist "SDL2.dll" (
    if exist "..\_deps\sdl2-build\Release\SDL2.dll" (
        copy /y "..\_deps\sdl2-build\Release\SDL2.dll" . >NUL 2>NUL
    )
)

REM Determine ROM path
set "ROM=%~1"
if "%ROM%"=="" (
    if exist "baserom.us.z64" (
        set "ROM=baserom.us.z64"
    ) else if exist "D:\diddy\Diddy Kong Racing (U) [!].z64" (
        set "ROM=D:\diddy\Diddy Kong Racing (U) [!].z64"
    )
)

if "%ROM%"=="" (
    echo ERROR: ROM not found. Place baserom.us.z64 in build\Release or pass path as argument.
    pause
    exit /b 1
)

DKRRecompiled.exe "%ROM%"
