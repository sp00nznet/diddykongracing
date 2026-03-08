@echo off
REM DKR Recompiled - Launch script
REM Usage: run_dkr.bat [rom_path]
REM   If no ROM path given, the exe searches for baserom.us.z64 / dkr.z64 in its directory.

cd /d "%~dp0build\Release"

REM Copy SDL2.dll if missing
if not exist "SDL2.dll" (
    if exist "..\..\_deps\sdl2-build\Release\SDL2.dll" (
        copy /y "..\..\build\_deps\sdl2-build\Release\SDL2.dll" . >NUL 2>NUL
    )
)

if "%~1"=="" (
    DKRRecompiled.exe
) else (
    DKRRecompiled.exe "%~1"
)
