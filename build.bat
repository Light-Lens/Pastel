@echo off

@REM if "%1" == "clean" (
@REM     if exist bin (
@REM         rmdir bin /S /Q
@REM     )

@REM     if exist src\pastelpch.h.gch (
@REM         del src\pastelpch.h.gch
@REM     )
@REM )

if not exist src/pastelpch.h.gch (
    g++ src/pastelpch.h
)

if not exist bin (
    mkdir bin
)

g++ src/*.cpp src/utils/Argparse/*.cpp src/utils/FileIO/*.cpp src/utils/Utils/*.cpp src/utils/Console/*.cpp src/Pastel/*.cpp -Isrc/ -o bin/pastel.exe
