@echo off
rem Diddy Kong Racing Recompiled: builds the game from your own ROM. See README.md, Getting Started.
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0tools\setup.ps1" %*
set RC=%ERRORLEVEL%
if not defined RECOMP_LAUNCHER pause
exit /b %RC%
