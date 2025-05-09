@echo off
gcc test.c bin/libcliz.lib -o bin/test.exe
cd bin
test.exe
cd ..