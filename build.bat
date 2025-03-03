@echo off
set TZ=UTC
pushd build
@REM -Zi is a debugging flag
cl -nologo -Zi ..\code\win32_platform.c user32.lib
popd
