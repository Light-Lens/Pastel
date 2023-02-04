@echo off
title Starting build

if "%cd:~-7%" == "scripts" (
    cd ..
)

@REM Compile pastel
g++ -Iincludes/ src/*.cpp -o bin\pastel
