import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root
    width: 800
    height: 600
    
    property string currentInfo: "欢迎使用QML演示"
    
    // 背景渐变
    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#f0f8ff" }
            GradientStop { position: 1.0; color: "#e6f3ff" }
        }
    }
    
    ScrollView {
        anchors.fill: parent
        anchors.margins: 20
        
        ColumnLayout {
            spacing: 20
            width: parent.width
            
            // 标题
            Rectangle {
                Layout.fillWidth: true
                height: 60
                color: "#2196F3"
                radius: 10
                
                Text {
                    anchors.centerIn: parent
                    text: "QML演示 - 声明式UI"
                    color: "white"
                    font.pixelSize: 24
                    font.bold: true
                }
            }
            
            // 信息显示区域
            Rectangle {
                Layout.fillWidth: true
                height: 40
                color: "#ffffff"
                border.color: "#ccc"
                border.width: 1
                radius: 5
                
                Text {
                    id: infoText
                    anchors.centerIn: parent
                    text: root.currentInfo
                    color: "#333"
                    font.pixelSize: 14
                }
            }
            
            // 基本控件区域
            GroupBox {
                title: "基本控件"
                Layout.fillWidth: true
                
                ColumnLayout {
                    anchors.fill: parent
                    spacing: 10
                    
                    RowLayout {
                        Layout.fillWidth: true
                        
                        Button {
                            text: "点击我"
                            onClicked: {
                                root.currentInfo = "QML按钮被点击了！"
                                clickAnimation.start()
                            }
                            
                            // 点击动画
                            SequentialAnimation {
                                id: clickAnimation
                                ScaleAnimator {
                                    target: parent
                                    from: 1.0
                                    to: 1.2
                                    duration: 100
                                }
                                ScaleAnimator {
                                    target: parent
                                    from: 1.2
                                    to: 1.0
                                    duration: 100
                                }
                            }
                        }
                        
                        Button {
                            text: "样式按钮"
                            background: Rectangle {
                                color: parent.pressed ? "#45a049" : "#4CAF50"
                                radius: 8
                            }
                            onClicked: root.currentInfo = "样式化的QML按钮"
                        }
                        
                        Item { Layout.fillWidth: true }
                    }
                    
                    RowLayout {
                        Layout.fillWidth: true
                        
                        Text {
                            text: "文本输入:"
                            font.pixelSize: 12
                        }
                        
                        TextField {
                            id: textInput
                            Layout.fillWidth: true
                            placeholderText: "请在这里输入文本..."
                            onTextChanged: root.currentInfo = "输入内容: " + text
                        }
                    }
                    
                    RowLayout {
                        Layout.fillWidth: true
                        
                        Text {
                            text: "下拉选择:"
                            font.pixelSize: 12
                        }
                        
                        ComboBox {
                            model: ["选项1", "选项2", "选项3", "选项4"]
                            onCurrentTextChanged: root.currentInfo = "选择了: " + currentText
                        }
                    }
                }
            }
            
            // 交互控件区域
            GroupBox {
                title: "交互控件"
                Layout.fillWidth: true
                
                ColumnLayout {
                    anchors.fill: parent
                    spacing: 10
                    
                    RowLayout {
                        Layout.fillWidth: true
                        
                        Text {
                            text: "滑块:"
                            font.pixelSize: 12
                        }
                        
                        Slider {
                            id: slider
                            Layout.fillWidth: true
                            from: 0
                            to: 100
                            value: 50
                            onValueChanged: {
                                root.currentInfo = "滑块值: " + Math.round(value)
                                progressBar.value = value / 100
                            }
                        }
                        
                        Text {
                            text: Math.round(slider.value)
                            font.pixelSize: 12
                            color: "#666"
                        }
                    }
                    
                    RowLayout {
                        Layout.fillWidth: true
                        
                        Text {
                            text: "进度条:"
                            font.pixelSize: 12
                        }
                        
                        ProgressBar {
                            id: progressBar
                            Layout.fillWidth: true
                            value: 0.5
                        }
                    }
                    
                    RowLayout {
                        Layout.fillWidth: true
                        
                        CheckBox {
                            text: "复选框"
                            onCheckedChanged: root.currentInfo = "复选框状态: " + (checked ? "选中" : "未选中")
                        }
                        
                        RadioButton {
                            text: "单选按钮1"
                            ButtonGroup.group: radioGroup
                            onCheckedChanged: if (checked) root.currentInfo = "选择了: " + text
                        }
                        
                        RadioButton {
                            text: "单选按钮2"
                            ButtonGroup.group: radioGroup
                            onCheckedChanged: if (checked) root.currentInfo = "选择了: " + text
                        }
                        
                        ButtonGroup {
                            id: radioGroup
                        }
                    }
                }
            }
            
            // 列表和文本区域
            GroupBox {
                title: "列表和文本"
                Layout.fillWidth: true
                Layout.fillHeight: true
                
                RowLayout {
                    anchors.fill: parent
                    spacing: 10
                    
                    // 列表视图
                    ListView {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumHeight: 200
                        
                        model: ListModel {
                            ListElement { name: "QML列表项1"; description: "这是第一个项目" }
                            ListElement { name: "QML列表项2"; description: "这是第二个项目" }
                            ListElement { name: "QML列表项3"; description: "这是第三个项目" }
                            ListElement { name: "QML列表项4"; description: "这是第四个项目" }
                        }
                        
                        delegate: ItemDelegate {
                            width: ListView.view.width
                            height: 50
                            
                            Rectangle {
                                anchors.fill: parent
                                color: parent.hovered ? "#f0f0f0" : "white"
                                border.color: "#ddd"
                                border.width: 1
                                radius: 5
                                
                                Column {
                                    anchors.left: parent.left
                                    anchors.leftMargin: 10
                                    anchors.verticalCenter: parent.verticalCenter
                                    
                                    Text {
                                        text: name
                                        font.pixelSize: 14
                                        font.bold: true
                                    }
                                    
                                    Text {
                                        text: description
                                        font.pixelSize: 12
                                        color: "#666"
                                    }
                                }
                            }
                            
                            onClicked: root.currentInfo = "点击了: " + name
                        }
                    }
                    
                    // 文本区域
                    ScrollView {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumHeight: 200
                        
                        TextArea {
                            placeholderText: "这是QML的多行文本编辑器...\n\n特点：\n• 声明式语法\n• 属性绑定\n• 信号槽机制\n• 简洁易读"
                            wrapMode: TextArea.Wrap
                            onTextChanged: root.currentInfo = "文本长度: " + text.length
                        }
                    }
                }
            }
            
            // QML特性说明
            GroupBox {
                title: "QML特性"
                Layout.fillWidth: true
                
                Text {
                    anchors.fill: parent
                    text: "QML特性展示：\n" +
                          "• 声明式语法 - 简洁易读的UI描述\n" +
                          "• 属性绑定 - 自动更新UI状态\n" +
                          "• 信号槽机制 - 事件处理\n" +
                          "• 动画支持 - 流畅的过渡效果\n" +
                          "• 组件化 - 可重用的UI元素\n" +
                          "• JavaScript集成 - 动态行为控制"
                    font.pixelSize: 12
                    color: "#555"
                    wrapMode: Text.WordWrap
                }
            }
        }
    }
}