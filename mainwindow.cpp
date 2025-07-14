#include "mainwindow.h"
#include "widgetsdemo.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QPixmap>
#include <QUrl>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_stackedWidget(nullptr)
    , m_welcomeWidget(nullptr)
    , m_comparisonWidget(nullptr)
    , m_widgetsDemo(nullptr)
    , m_qmlDemo(nullptr)
    , m_quickDemo(nullptr)
    , m_comparisonText(nullptr)
{
    setupMenuBar();
    setupUI();
    
    setWindowTitle("Qt UI技术演示程序 - Qt Widgets vs QML vs Qt Quick");
    setMinimumSize(800, 600);
    resize(1000, 700);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupMenuBar()
{
    QMenuBar *menuBar = this->menuBar();
    
    // 创建演示菜单
    QMenu *demoMenu = menuBar->addMenu("演示(&D)");
    
    m_widgetsAction = demoMenu->addAction("Qt Widgets演示");
    m_widgetsAction->setShortcut(QKeySequence("Ctrl+1"));
    connect(m_widgetsAction, &QAction::triggered, this, &MainWindow::showWidgetsDemo);
    
    m_qmlAction = demoMenu->addAction("QML演示");
    m_qmlAction->setShortcut(QKeySequence("Ctrl+2"));
    connect(m_qmlAction, &QAction::triggered, this, &MainWindow::showQmlDemo);
    
    m_quickAction = demoMenu->addAction("Qt Quick演示");
    m_quickAction->setShortcut(QKeySequence("Ctrl+3"));
    connect(m_quickAction, &QAction::triggered, this, &MainWindow::showQuickDemo);
    
    demoMenu->addSeparator();
    
    m_comparisonAction = demoMenu->addAction("技术对比");
    m_comparisonAction->setShortcut(QKeySequence("Ctrl+4"));
    connect(m_comparisonAction, &QAction::triggered, this, &MainWindow::showComparison);
    
    // 创建帮助菜单
    QMenu *helpMenu = menuBar->addMenu("帮助(&H)");
    QAction *aboutAction = helpMenu->addAction("关于");
    connect(aboutAction, &QAction::triggered, [this]() {
        QMessageBox::about(this, "关于", 
            "Qt UI技术演示程序 v1.0\n\n"
            "本程序演示了Qt中三种主要的UI技术：\n"
            "• Qt Widgets - 传统的桌面应用程序界面\n"
            "• QML - 声明式的用户界面语言\n"
            "• Qt Quick - 现代的动态用户界面框架\n\n"
            "使用Ctrl+1-4快捷键可以快速切换不同的演示。");
    });
}

void MainWindow::setupUI()
{
    m_stackedWidget = new QStackedWidget(this);
    setCentralWidget(m_stackedWidget);
    
    // 创建欢迎界面
    m_welcomeWidget = new QWidget;
    QVBoxLayout *welcomeLayout = new QVBoxLayout(m_welcomeWidget);
    
    QLabel *titleLabel = new QLabel("Qt UI技术演示程序");
    QFont titleFont;
    titleFont.setPointSize(24);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    
    QLabel *subtitleLabel = new QLabel("探索Qt Widgets、QML和Qt Quick的区别与联系");
    QFont subtitleFont;
    subtitleFont.setPointSize(14);
    subtitleLabel->setFont(subtitleFont);
    subtitleLabel->setAlignment(Qt::AlignCenter);
    subtitleLabel->setStyleSheet("color: #666; margin-bottom: 20px;");
    
    // 创建按钮布局
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    
    QPushButton *widgetsBtn = new QPushButton("Qt Widgets演示");
    widgetsBtn->setMinimumHeight(40);
    widgetsBtn->setStyleSheet("QPushButton { padding: 10px; font-size: 12px; }");
    connect(widgetsBtn, &QPushButton::clicked, this, &MainWindow::showWidgetsDemo);
    
    QPushButton *qmlBtn = new QPushButton("QML演示");
    qmlBtn->setMinimumHeight(40);
    qmlBtn->setStyleSheet("QPushButton { padding: 10px; font-size: 12px; }");
    connect(qmlBtn, &QPushButton::clicked, this, &MainWindow::showQmlDemo);
    
    QPushButton *quickBtn = new QPushButton("Qt Quick演示");
    quickBtn->setMinimumHeight(40);
    quickBtn->setStyleSheet("QPushButton { padding: 10px; font-size: 12px; }");
    connect(quickBtn, &QPushButton::clicked, this, &MainWindow::showQuickDemo);
    
    QPushButton *comparisonBtn = new QPushButton("技术对比");
    comparisonBtn->setMinimumHeight(40);
    comparisonBtn->setStyleSheet("QPushButton { padding: 10px; font-size: 12px; }");
    connect(comparisonBtn, &QPushButton::clicked, this, &MainWindow::showComparison);
    
    buttonLayout->addWidget(widgetsBtn);
    buttonLayout->addWidget(qmlBtn);
    buttonLayout->addWidget(quickBtn);
    buttonLayout->addWidget(comparisonBtn);
    
    welcomeLayout->addStretch();
    welcomeLayout->addWidget(titleLabel);
    welcomeLayout->addWidget(subtitleLabel);
    welcomeLayout->addLayout(buttonLayout);
    welcomeLayout->addStretch();
    
    m_stackedWidget->addWidget(m_welcomeWidget);
    
    // 创建对比界面
    createComparisonWidget();
}

void MainWindow::createComparisonWidget()
{
    m_comparisonWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(m_comparisonWidget);
    
    QLabel *titleLabel = new QLabel("Qt UI技术对比");
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    
    m_comparisonText = new QTextEdit;
    m_comparisonText->setReadOnly(true);
    m_comparisonText->setHtml(
        "<h2>Qt UI技术对比</h2>"
        
        "<h3>1. Qt Widgets</h3>"
        "<p><strong>特点：</strong></p>"
        "<ul>"
        "<li>传统的C++桌面应用程序界面框架</li>"
        "<li>基于命令式编程模型</li>"
        "<li>成熟稳定，功能丰富</li>"
        "<li>适合传统桌面应用</li>"
        "</ul>"
        "<p><strong>优点：</strong></p>"
        "<ul>"
        "<li>性能稳定，资源消耗相对较低</li>"
        "<li>文档完善，社区支持好</li>"
        "<li>与原生系统整合度高</li>"
        "<li>适合复杂的桌面应用</li>"
        "</ul>"
        "<p><strong>缺点：</strong></p>"
        "<ul>"
        "<li>界面相对传统，不够现代化</li>"
        "<li>自定义样式相对困难</li>"
        "<li>不适合触摸设备</li>"
        "</ul>"
        
        "<h3>2. QML (Qt Meta Language)</h3>"
        "<p><strong>特点：</strong></p>"
        "<ul>"
        "<li>声明式的用户界面描述语言</li>"
        "<li>基于JavaScript的脚本语言</li>"
        "<li>支持属性绑定和信号槽</li>"
        "<li>易于学习和使用</li>"
        "</ul>"
        "<p><strong>优点：</strong></p>"
        "<ul>"
        "<li>代码简洁，易于维护</li>"
        "<li>支持实时预览</li>"
        "<li>良好的设计师-开发者协作</li>"
        "<li>支持多平台</li>"
        "</ul>"
        "<p><strong>缺点：</strong></p>"
        "<ul>"
        "<li>相对较新，学习成本</li>"
        "<li>调试相对复杂</li>"
        "<li>性能可能不如Widgets</li>"
        "</ul>"
        
        "<h3>3. Qt Quick</h3>"
        "<p><strong>特点：</strong></p>"
        "<ul>"
        "<li>基于QML的现代UI框架</li>"
        "<li>支持硬件加速渲染</li>"
        "<li>内置动画和特效系统</li>"
        "<li>适合现代应用和移动设备</li>"
        "</ul>"
        "<p><strong>优点：</strong></p>"
        "<ul>"
        "<li>现代化的界面效果</li>"
        "<li>流畅的动画和过渡</li>"
        "<li>适合触摸设备</li>"
        "<li>跨平台支持好</li>"
        "</ul>"
        "<p><strong>缺点：</strong></p>"
        "<ul>"
        "<li>对GPU要求较高</li>"
        "<li>在某些情况下性能开销大</li>"
        "<li>调试工具相对有限</li>"
        "</ul>"
        
        "<h3>联系与选择建议</h3>"
        "<p><strong>联系：</strong></p>"
        "<ul>"
        "<li>QML和Qt Quick都是Qt框架的一部分</li>"
        "<li>Qt Quick是基于QML的UI框架</li>"
        "<li>可以在同一个应用中混合使用</li>"
        "<li>都支持信号槽机制</li>"
        "</ul>"
        "<p><strong>选择建议：</strong></p>"
        "<ul>"
        "<li><strong>Qt Widgets：</strong>传统桌面应用，对性能要求高</li>"
        "<li><strong>QML：</strong>简单的界面，需要快速开发</li>"
        "<li><strong>Qt Quick：</strong>现代化应用，移动设备，需要丰富的视觉效果</li>"
        "</ul>"
    );
    
    layout->addWidget(titleLabel);
    layout->addWidget(m_comparisonText);
    
    m_stackedWidget->addWidget(m_comparisonWidget);
}

void MainWindow::showWidgetsDemo()
{
    if (!m_widgetsDemo) {
        m_widgetsDemo = new WidgetsDemo;
        m_stackedWidget->addWidget(m_widgetsDemo);
    }
    m_stackedWidget->setCurrentWidget(m_widgetsDemo);
}

void MainWindow::showQmlDemo()
{
    if (!m_qmlDemo) {
        m_qmlDemo = new QQuickWidget;
        m_qmlDemo->setSource(QUrl("qrc:/qml/QmlDemo.qml"));
        m_qmlDemo->setResizeMode(QQuickWidget::SizeRootObjectToView);
        m_stackedWidget->addWidget(m_qmlDemo);
    }
    m_stackedWidget->setCurrentWidget(m_qmlDemo);
}

void MainWindow::showQuickDemo()
{
    if (!m_quickDemo) {
        m_quickDemo = new QQuickWidget;
        m_quickDemo->setSource(QUrl("qrc:/qml/QuickDemo.qml"));
        m_quickDemo->setResizeMode(QQuickWidget::SizeRootObjectToView);
        m_stackedWidget->addWidget(m_quickDemo);
    }
    m_stackedWidget->setCurrentWidget(m_quickDemo);
}

void MainWindow::showComparison()
{
    m_stackedWidget->setCurrentWidget(m_comparisonWidget);
}