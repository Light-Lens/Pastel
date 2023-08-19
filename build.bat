@echo off

if not exist src/pastelpch.h.gch (
    g++ src/pastelpch.h
)

g++ src/*.cpp src/utils/*.cpp -o bin/pastel.exe
