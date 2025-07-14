@echo off
echo ===============================
echo      Qt UI演示程序
echo ===============================
echo.

cd /d %~dp0
if exist "build\Release\QtUiDemo.exe" (
    echo 检查Qt库依赖...
    
    REM 检查是否需要部署Qt库
    if not exist "build\Release\Qt6QuickWidgets.dll" (
        echo 正在部署Qt运行时库...
        C:\Qt\6.9.0\msvc2022_64\bin\windeployqt.exe --qmldir qml build\Release\QtUiDemo.exe
        echo 部署完成！
        echo.
    )
    
    echo 启动程序: QtUiDemo.exe
    echo.
    build\Release\QtUiDemo.exe
) else (
    echo 错误：找不到可执行文件 QtUiDemo.exe
    echo 请先运行以下命令构建项目：
    echo.
    echo mkdir build
    echo cd build
    echo cmake .. -G "Visual Studio 17 2022" -A x64
    echo cmake --build . --config Release
    echo.
    pause
)