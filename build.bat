@echo off

if not exist src/pastelpch.h.gch (
    g++ src/pastelpch.h
)

if not exist bin/ (
    mkdir bin
)

g++ src/*.cpp src/utils/*.cpp -o bin/pastel.exe
