@echo off
echo ====================
echo Qt UI演示程序构建脚本
echo ====================

echo 请确保已安装Qt Creator和Qt 6.9
echo.

echo 方案1: 使用Qt Creator构建
echo 1. 打开Qt Creator
echo 2. 打开项目文件 CMakeLists.txt
echo 3. 选择Qt 6.9 MinGW 64-bit kit
echo 4. 点击构建按钮
echo.

echo 方案2: 使用qmake构建
echo 生成qmake项目文件...

echo TEMPLATE = app > QtUiDemo.pro
echo TARGET = QtUiDemo >> QtUiDemo.pro
echo CONFIG += c++17 >> QtUiDemo.pro
echo QT += core widgets qml quick quickwidgets >> QtUiDemo.pro
echo.
echo SOURCES += main.cpp mainwindow.cpp widgetsdemo.cpp >> QtUiDemo.pro
echo HEADERS += mainwindow.h widgetsdemo.h >> QtUiDemo.pro
echo RESOURCES += qml_resources.qrc >> QtUiDemo.pro
echo.
echo win32:CONFIG += console >> QtUiDemo.pro

echo.
echo qmake项目文件已创建: QtUiDemo.pro
echo.
echo 要使用qmake构建，请运行：
echo C:\Qt\6.9.0\mingw_64\bin\qmake.exe QtUiDemo.pro
echo C:\Qt\Tools\mingw1120_64\bin\mingw32-make.exe
echo.

echo 请选择适合您的构建方案
pause