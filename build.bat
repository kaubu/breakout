@echo off
@REM -Zi is a debugging flag
pushd build
cl -nologo -Zi ..\code\win32_platform.c user32.lib
popd
