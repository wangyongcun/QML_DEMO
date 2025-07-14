@echo off
echo ===============================
echo      简化构建脚本
echo ===============================
echo.

cd /d %~dp0

echo [1/5] 检查构建目录...
if exist "build" (
    echo 删除旧的构建目录...
    rmdir /s /q "build" 2>nul
)
mkdir "build"
echo 构建目录已准备好

echo.
echo [2/5] 配置CMake项目...
cd build
C:\Qt\Tools\CMake_64\bin\cmake.exe -G "Visual Studio 17 2022" -A x64 .. > cmake_config.log 2>&1
if %errorlevel% neq 0 (
    echo 错误：CMake配置失败！
    echo 查看日志：build\cmake_config.log
    pause
    exit /b 1
)
echo CMake配置完成

echo.
echo [3/5] 编译项目...
C:\Qt\Tools\CMake_64\bin\cmake.exe --build . --config Release > cmake_build.log 2>&1
if %errorlevel% neq 0 (
    echo 错误：编译失败！
    echo 查看日志：build\cmake_build.log
    pause
    exit /b 1
)
echo 编译完成

echo.
echo [4/5] 检查可执行文件...
if not exist "Release\QtUiDemo.exe" (
    echo 错误：未找到可执行文件！
    pause
    exit /b 1
)
echo 可执行文件生成成功

echo.
echo [5/5] 部署Qt依赖...
cd ..
C:\Qt\6.9.0\msvc2022_64\bin\windeployqt.exe --qmldir qml build\Release\QtUiDemo.exe > deploy.log 2>&1
if %errorlevel% neq 0 (
    echo 警告：依赖部署可能未完全成功
    echo 查看日志：deploy.log
) else (
    echo 依赖部署完成
)

echo.
echo ===============================
echo      构建完成！
echo ===============================
echo.
echo 可执行文件位置：build\Release\QtUiDemo.exe
echo 启动程序：run.bat
echo.
echo 如有问题，请查看日志文件：
echo - cmake_config.log ^(CMake配置^)
echo - cmake_build.log ^(编译过程^)  
echo - deploy.log ^(依赖部署^)
echo.

pause