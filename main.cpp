#include <QApplication>
#include <QQmlApplicationEngine>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // 设置应用程序信息
    app.setApplicationName("Qt UI演示程序");
    app.setApplicationVersion("1.0");
    app.setOrganizationName("Qt学习演示");
    
    // 创建主窗口
    MainWindow window;
    window.show();
    
    return app.exec();
}