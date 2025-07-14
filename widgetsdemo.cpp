#include "widgetsdemo.h"
#include <QApplication>
#include <QMessageBox>
#include <QHeaderView>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QPixmap>
#include <QFont>
#include <QDateTime>

WidgetsDemo::WidgetsDemo(QWidget *parent)
    : QWidget(parent)
    , m_progressValue(0)
{
    setupBasicControls();
    setupInputControls();
    setupDisplayControls();
    setupContainerControls();
    setupLayout();
    
    // 设置定时器
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &WidgetsDemo::updateProgressBar);
    m_timer->start(100);
}

void WidgetsDemo::setupBasicControls()
{
    m_pushButton = new QPushButton("点击我");
    m_pushButton->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; padding: 8px; border-radius: 4px; }");
    connect(m_pushButton, &QPushButton::clicked, this, &WidgetsDemo::onButtonClicked);
    
    m_statusLabel = new QLabel("状态: 就绪");
    m_statusLabel->setStyleSheet("QLabel { color: #333; font-weight: bold; }");
}

void WidgetsDemo::setupInputControls()
{
    m_lineEdit = new QLineEdit;
    m_lineEdit->setPlaceholderText("请输入文本...");
    connect(m_lineEdit, &QLineEdit::textChanged, this, &WidgetsDemo::onLineEditChanged);
    
    m_textEdit = new QTextEdit;
    m_textEdit->setPlaceholderText("这是一个多行文本编辑器...");
    m_textEdit->setMaximumHeight(100);
    
    m_comboBox = new QComboBox;
    m_comboBox->addItems({"选项1", "选项2", "选项3", "选项4"});
    connect(m_comboBox, QOverload<const QString &>::of(&QComboBox::currentTextChanged),
            this, &WidgetsDemo::onComboBoxChanged);
    
    m_spinBox = new QSpinBox;
    m_spinBox->setRange(0, 100);
    m_spinBox->setValue(50);
    
    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setRange(0, 100);
    m_slider->setValue(50);
    connect(m_slider, &QSlider::valueChanged, this, &WidgetsDemo::onSliderValueChanged);
    
    m_checkBox = new QCheckBox("复选框");
    connect(m_checkBox, &QCheckBox::toggled, this, &WidgetsDemo::onCheckBoxToggled);
    
    m_radioButton1 = new QRadioButton("选项A");
    m_radioButton2 = new QRadioButton("选项B");
    m_radioButton1->setChecked(true);
    
    m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->addButton(m_radioButton1);
    m_buttonGroup->addButton(m_radioButton2);
    
    connect(m_radioButton1, &QRadioButton::toggled, this, &WidgetsDemo::onRadioButtonToggled);
    connect(m_radioButton2, &QRadioButton::toggled, this, &WidgetsDemo::onRadioButtonToggled);
    
    m_dateEdit = new QDateEdit(QDate::currentDate());
    m_timeEdit = new QTimeEdit(QTime::currentTime());
    m_dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime());
    
    m_dial = new QDial;
    m_dial->setRange(0, 100);
    m_dial->setValue(25);
    m_dial->setMaximumSize(80, 80);
}

void WidgetsDemo::setupDisplayControls()
{
    m_progressBar = new QProgressBar;
    m_progressBar->setRange(0, 100);
    m_progressBar->setValue(0);
    
    m_lcdNumber = new QLCDNumber;
    m_lcdNumber->setDigitCount(3);
    m_lcdNumber->display(50);
    m_lcdNumber->setMaximumHeight(60);
    
    m_imageLabel = new QLabel;
    m_imageLabel->setText("图片显示区域");
    m_imageLabel->setAlignment(Qt::AlignCenter);
    m_imageLabel->setStyleSheet("QLabel { border: 2px dashed #ccc; background-color: #f9f9f9; }");
    m_imageLabel->setMinimumSize(150, 100);
}

void WidgetsDemo::setupContainerControls()
{
    // 列表控件
    m_listWidget = new QListWidget;
    m_listWidget->addItems({"列表项1", "列表项2", "列表项3", "列表项4"});
    m_listWidget->setMaximumHeight(120);
    connect(m_listWidget, &QListWidget::itemClicked, this, &WidgetsDemo::onListItemClicked);
    
    // 表格控件
    m_tableWidget = new QTableWidget(3, 3);
    m_tableWidget->setHorizontalHeaderLabels({"列A", "列B", "列C"});
    m_tableWidget->setMaximumHeight(120);
    
    // 填充表格数据
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString("单元格(%1,%2)").arg(i+1).arg(j+1));
            m_tableWidget->setItem(i, j, item);
        }
    }
    
    connect(m_tableWidget, &QTableWidget::cellClicked, this, &WidgetsDemo::onTableCellClicked);
    
    // 树形控件
    m_treeWidget = new QTreeWidget;
    m_treeWidget->setHeaderLabels({"项目", "值"});
    m_treeWidget->setMaximumHeight(120);
    
    QTreeWidgetItem *root1 = new QTreeWidgetItem(m_treeWidget, {"根项目1", "值1"});
    QTreeWidgetItem *child1 = new QTreeWidgetItem(root1, {"子项目1", "子值1"});
    QTreeWidgetItem *child2 = new QTreeWidgetItem(root1, {"子项目2", "子值2"});
    
    QTreeWidgetItem *root2 = new QTreeWidgetItem(m_treeWidget, {"根项目2", "值2"});
    QTreeWidgetItem *child3 = new QTreeWidgetItem(root2, {"子项目3", "子值3"});
    
    m_treeWidget->expandAll();
    connect(m_treeWidget, &QTreeWidget::itemClicked, this, &WidgetsDemo::onTreeItemClicked);
}

void WidgetsDemo::setupLayout()
{
    // 创建主布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    
    // 左侧布局
    QVBoxLayout *leftLayout = new QVBoxLayout;
    
    // 基本控件分组
    m_groupBox1 = new QGroupBox("基本控件");
    QVBoxLayout *basicLayout = new QVBoxLayout(m_groupBox1);
    basicLayout->addWidget(m_pushButton);
    basicLayout->addWidget(m_statusLabel);
    
    // 输入控件分组
    m_groupBox2 = new QGroupBox("输入控件");
    QFormLayout *inputLayout = new QFormLayout(m_groupBox2);
    inputLayout->addRow("文本输入:", m_lineEdit);
    inputLayout->addRow("下拉框:", m_comboBox);
    inputLayout->addRow("数字输入:", m_spinBox);
    inputLayout->addRow("滑块:", m_slider);
    inputLayout->addRow("", m_checkBox);
    
    QHBoxLayout *radioLayout = new QHBoxLayout;
    radioLayout->addWidget(m_radioButton1);
    radioLayout->addWidget(m_radioButton2);
    inputLayout->addRow("单选按钮:", radioLayout);
    
    inputLayout->addRow("日期:", m_dateEdit);
    inputLayout->addRow("时间:", m_timeEdit);
    inputLayout->addRow("日期时间:", m_dateTimeEdit);
    inputLayout->addRow("拨盘:", m_dial);
    
    leftLayout->addWidget(m_groupBox1);
    leftLayout->addWidget(m_groupBox2);
    
    // 右侧布局
    QVBoxLayout *rightLayout = new QVBoxLayout;
    
    // 显示控件分组
    m_groupBox3 = new QGroupBox("显示控件");
    QVBoxLayout *displayLayout = new QVBoxLayout(m_groupBox3);
    displayLayout->addWidget(new QLabel("进度条:"));
    displayLayout->addWidget(m_progressBar);
    displayLayout->addWidget(new QLabel("LCD数字:"));
    displayLayout->addWidget(m_lcdNumber);
    displayLayout->addWidget(new QLabel("图片显示:"));
    displayLayout->addWidget(m_imageLabel);
    
    // 容器控件分组
    m_groupBox4 = new QGroupBox("容器控件");
    QVBoxLayout *containerLayout = new QVBoxLayout(m_groupBox4);
    
    // 创建选项卡
    m_tabWidget = new QTabWidget;
    
    // 列表选项卡
    QWidget *listTab = new QWidget;
    QVBoxLayout *listLayout = new QVBoxLayout(listTab);
    listLayout->addWidget(new QLabel("列表控件:"));
    listLayout->addWidget(m_listWidget);
    m_tabWidget->addTab(listTab, "列表");
    
    // 表格选项卡
    QWidget *tableTab = new QWidget;
    QVBoxLayout *tableLayout = new QVBoxLayout(tableTab);
    tableLayout->addWidget(new QLabel("表格控件:"));
    tableLayout->addWidget(m_tableWidget);
    m_tabWidget->addTab(tableTab, "表格");
    
    // 树形选项卡
    QWidget *treeTab = new QWidget;
    QVBoxLayout *treeLayout = new QVBoxLayout(treeTab);
    treeLayout->addWidget(new QLabel("树形控件:"));
    treeLayout->addWidget(m_treeWidget);
    m_tabWidget->addTab(treeTab, "树形");
    
    containerLayout->addWidget(m_tabWidget);
    
    // 多行文本编辑器
    containerLayout->addWidget(new QLabel("多行文本:"));
    containerLayout->addWidget(m_textEdit);
    
    connect(m_tabWidget, &QTabWidget::currentChanged, this, &WidgetsDemo::onTabChanged);
    
    rightLayout->addWidget(m_groupBox3);
    rightLayout->addWidget(m_groupBox4);
    
    // 添加到主布局
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    
    // 设置标题
    setWindowTitle("Qt Widgets 演示");
}

void WidgetsDemo::onButtonClicked()
{
    static int clickCount = 0;
    clickCount++;
    m_statusLabel->setText(QString("按钮被点击了 %1 次").arg(clickCount));
    
    // 显示消息框
    QMessageBox::information(this, "信息", QString("这是第 %1 次点击!").arg(clickCount));
}

void WidgetsDemo::onSliderValueChanged(int value)
{
    m_spinBox->setValue(value);
    m_lcdNumber->display(value);
    m_dial->setValue(value);
}

void WidgetsDemo::onComboBoxChanged(const QString &text)
{
    m_statusLabel->setText(QString("选择了: %1").arg(text));
}

void WidgetsDemo::onCheckBoxToggled(bool checked)
{
    m_statusLabel->setText(QString("复选框状态: %1").arg(checked ? "选中" : "未选中"));
}

void WidgetsDemo::onRadioButtonToggled(bool checked)
{
    if (checked) {
        QRadioButton *radio = qobject_cast<QRadioButton*>(sender());
        if (radio) {
            m_statusLabel->setText(QString("选择了: %1").arg(radio->text()));
        }
    }
}

void WidgetsDemo::onLineEditChanged(const QString &text)
{
    m_statusLabel->setText(QString("输入文本: %1").arg(text));
}

void WidgetsDemo::onListItemClicked()
{
    QListWidgetItem *item = m_listWidget->currentItem();
    if (item) {
        m_statusLabel->setText(QString("选择了列表项: %1").arg(item->text()));
    }
}

void WidgetsDemo::onTableCellClicked(int row, int column)
{
    QTableWidgetItem *item = m_tableWidget->item(row, column);
    if (item) {
        m_statusLabel->setText(QString("点击了表格单元格 (%1,%2): %3").arg(row+1).arg(column+1).arg(item->text()));
    }
}

void WidgetsDemo::onTreeItemClicked()
{
    QTreeWidgetItem *item = m_treeWidget->currentItem();
    if (item) {
        m_statusLabel->setText(QString("选择了树形项: %1").arg(item->text(0)));
    }
}

void WidgetsDemo::onTabChanged(int index)
{
    QString tabNames[] = {"列表", "表格", "树形"};
    if (index >= 0 && index < 3) {
        m_statusLabel->setText(QString("切换到选项卡: %1").arg(tabNames[index]));
    }
}

void WidgetsDemo::updateProgressBar()
{
    m_progressValue = (m_progressValue + 1) % 101;
    m_progressBar->setValue(m_progressValue);
}