TEMPLATE = app 
TARGET = QtUiDemo 
CONFIG += c++17 
QT += core widgets qml quick quickwidgets 
SOURCES += main.cpp mainwindow.cpp widgetsdemo.cpp 
HEADERS += mainwindow.h widgetsdemo.h 
RESOURCES += qml_resources.qrc 
win32:CONFIG += console