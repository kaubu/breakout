@echo off
set TZ=UTC

if not exist ..\build mkdir ..\build
pushd build
del *.pdb > NUL 2> NUL
echo WAITING FOR PDB > lock.tmp

@REM -Zi is a debugging flag
cl -nologo -Zi -FC ..\src\win32_platform.c /link user32.lib gdi32.lib -incremental:no -opt:ref

del lock.tmp
if exist *.obj del *.obj

popd
