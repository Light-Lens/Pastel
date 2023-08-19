@echo off

if "%1" == "clean" (
    rmdir bin /S /Q
    del src/pastelpch.h
)

if not exist src/pastelpch.h.gch (
    g++ src/pastelpch.h
)

if not exist bin/ (
    mkdir bin
)

g++ src/*.cpp src/utils/*.cpp src/Pastel/*.cpp -o bin/pastel.exe
