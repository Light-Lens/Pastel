@echo off

if "%1" == "clean" (
    if exist bin (
        rmdir bin /S /Q
    )

    if exist src\pastelpch.h.gch (
        del src\pastelpch.h.gch
    )
)

if not exist src/pastelpch.h.gch (
    g++ src/pastelpch.h
)

if not exist bin (
    mkdir bin
)

g++ src/*.cpp src/utils/*.cpp src/Pastel/*.cpp -Isrc/ -o bin/pastel.exe
