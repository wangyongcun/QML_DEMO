cmake_minimum_required(VERSION 3.16)
project(QtUiDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt路径设置（基于用户的Qt 6.9安装路径）
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/msvc2022_64")

# 查找Qt组件
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Qml Quick QuickWidgets)

# 自动处理MOC、UIC、RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 源文件
set(SOURCES
    main.cpp
    mainwindow.cpp
    widgetsdemo.cpp
)

# 头文件
set(HEADERS
    mainwindow.h
    widgetsdemo.h
)

# QML资源文件
set(QML_SOURCES
    qml_resources.qrc
)

# 创建可执行文件
add_executable(QtUiDemo ${SOURCES} ${HEADERS} ${QML_SOURCES})

# 链接Qt库
target_link_libraries(QtUiDemo
    Qt6::Core
    Qt6::Widgets
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickWidgets
)

# Windows特定设置
if(WIN32)
    set_target_properties(QtUiDemo PROPERTIES WIN32_EXECUTABLE TRUE)
    # 设置MSVC编译器的C++17支持
    if(MSVC)
        target_compile_options(QtUiDemo PRIVATE /Zc:__cplusplus /utf-8 /permissive-)
    endif()
endif()