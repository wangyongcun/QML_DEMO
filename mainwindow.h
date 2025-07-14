#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStackedWidget>
#include <QAction>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QQuickWidget>
#include <QQmlEngine>
#include <QQmlContext>

class WidgetsDemo;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showWidgetsDemo();
    void showQmlDemo();
    void showQuickDemo();
    void showComparison();

private:
    void setupMenuBar();
    void setupUI();
    void createComparisonWidget();
    
    QStackedWidget *m_stackedWidget;
    QWidget *m_welcomeWidget;
    QWidget *m_comparisonWidget;
    QWidget *m_widgetsDemo;
    QQuickWidget *m_qmlDemo;
    QQuickWidget *m_quickDemo;
    
    QAction *m_widgetsAction;
    QAction *m_qmlAction;
    QAction *m_quickAction;
    QAction *m_comparisonAction;
    
    QTextEdit *m_comparisonText;
};

#endif // MAINWINDOW_H