@echo off
echo ===============================
echo      Qt应用程序部署工具
echo ===============================
echo.

cd /d %~dp0

if not exist "build\Release\QtUiDemo.exe" (
    echo 错误：找不到可执行文件 QtUiDemo.exe
    echo 请先构建项目！
    echo.
    pause
    exit /b 1
)

echo 正在部署Qt运行时库和依赖项...
echo.

REM 使用windeployqt工具自动部署
C:\Qt\6.9.0\msvc2022_64\bin\windeployqt.exe --qmldir qml build\Release\QtUiDemo.exe

if %errorlevel% equ 0 (
    echo.
    echo ===============================
    echo      部署完成！
    echo ===============================
    echo.
    echo 已成功部署以下组件：
    echo - Qt核心库 ^(Core, Gui, Widgets^)
    echo - QML运行时库
    echo - Qt Quick库和控件
    echo - 样式插件和图像格式支持
    echo - 语言翻译文件
    echo.
    echo 现在可以运行程序：
    echo   build\Release\QtUiDemo.exe
    echo.
    echo 或使用启动脚本：
    echo   run.bat
    echo.
) else (
    echo.
    echo 部署失败！请检查Qt安装路径。
    echo.
)

pause