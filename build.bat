@echo off

if not exist "obj" mkdir "obj"
if not exist "bin" mkdir "bin"

for %%f in ("src\*.c") do (
    set "filename=%%~nf"
    set "output_obj=obj\%filename%.o"
    echo Compiling: "%%f" -> "%output_obj%"
    gcc -c "%%f" -o "%output_obj%"
    if errorlevel 1 (
        echo Error compiling "%%f". Exiting.
        exit /b 1
    )
)

ar rcs bin/libcliz.lib obj/*.o