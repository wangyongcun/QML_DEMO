#ifndef WIDGETSDEMO_H
#define WIDGETSDEMO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QSlider>
#include <QProgressBar>
#include <QCheckBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QListWidget>
#include <QTableWidget>
#include <QTreeWidget>
#include <QTabWidget>
#include <QGroupBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QDial>
#include <QLCDNumber>
#include <QScrollArea>
#include <QSplitter>
#include <QTimer>

class WidgetsDemo : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetsDemo(QWidget *parent = nullptr);

private slots:
    void onButtonClicked();
    void onSliderValueChanged(int value);
    void onComboBoxChanged(const QString &text);
    void onCheckBoxToggled(bool checked);
    void onRadioButtonToggled(bool checked);
    void onLineEditChanged(const QString &text);
    void onListItemClicked();
    void onTableCellClicked(int row, int column);
    void onTreeItemClicked();
    void onTabChanged(int index);
    void updateProgressBar();

private:
    void setupBasicControls();
    void setupInputControls();
    void setupDisplayControls();
    void setupContainerControls();
    void setupLayout();
    
    // 基本控件
    QPushButton *m_pushButton;
    QLabel *m_statusLabel;
    
    // 输入控件
    QLineEdit *m_lineEdit;
    QTextEdit *m_textEdit;
    QComboBox *m_comboBox;
    QSpinBox *m_spinBox;
    QSlider *m_slider;
    QCheckBox *m_checkBox;
    QRadioButton *m_radioButton1;
    QRadioButton *m_radioButton2;
    QButtonGroup *m_buttonGroup;
    QDateEdit *m_dateEdit;
    QTimeEdit *m_timeEdit;
    QDateTimeEdit *m_dateTimeEdit;
    QDial *m_dial;
    
    // 显示控件
    QProgressBar *m_progressBar;
    QLCDNumber *m_lcdNumber;
    QLabel *m_imageLabel;
    
    // 容器控件
    QListWidget *m_listWidget;
    QTableWidget *m_tableWidget;
    QTreeWidget *m_treeWidget;
    QTabWidget *m_tabWidget;
    
    // 布局和分组
    QGroupBox *m_groupBox1;
    QGroupBox *m_groupBox2;
    QGroupBox *m_groupBox3;
    QGroupBox *m_groupBox4;
    QScrollArea *m_scrollArea;
    QSplitter *m_splitter;
    
    // 定时器
    QTimer *m_timer;
    int m_progressValue;
};

#endif // WIDGETSDEMO_H