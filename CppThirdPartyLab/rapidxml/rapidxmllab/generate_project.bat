@echo off

MD vsbuild > nul 2>&1
CD vsbuild
cmake ..

PAUSE