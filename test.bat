@echo off
gcc test.c bin/cliz.lib -o bin/test.exe
cd bin
test.exe
cd ..