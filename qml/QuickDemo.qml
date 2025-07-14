import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root
    width: 800
    height: 600
    
    property real animationValue: 0
    property bool isAnimating: false
    property string statusText: "Qt Quick动画演示"
    
    // 动态背景
    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { 
                position: 0.0
                color: Qt.hsla(animationValue * 0.1, 0.3, 0.9, 1.0)
            }
            GradientStop { 
                position: 1.0
                color: Qt.hsla(animationValue * 0.1 + 0.1, 0.4, 0.8, 1.0)
            }
        }
        
        // 背景动画
        SequentialAnimation {
            id: backgroundAnimation
            loops: Animation.Infinite
            running: true
            
            NumberAnimation {
                target: root
                property: "animationValue"
                from: 0
                to: 360
                duration: 10000
            }
        }
    }
    
    // 粒子效果背景
    Repeater {
        model: 20
        
        Rectangle {
            width: 4
            height: 4
            color: Qt.hsla(Math.random(), 0.8, 0.6, 0.3)
            radius: 2
            x: Math.random() * root.width
            y: Math.random() * root.height
            
            SequentialAnimation {
                loops: Animation.Infinite
                running: true
                
                ParallelAnimation {
                    NumberAnimation {
                        target: parent
                        property: "x"
                        to: Math.random() * root.width
                        duration: 3000 + Math.random() * 2000
                        easing.type: Easing.InOutQuad
                    }
                    NumberAnimation {
                        target: parent
                        property: "y"
                        to: Math.random() * root.height
                        duration: 3000 + Math.random() * 2000
                        easing.type: Easing.InOutQuad
                    }
                    NumberAnimation {
                        target: parent
                        property: "opacity"
                        to: Math.random() * 0.8 + 0.2
                        duration: 2000
                        easing.type: Easing.InOutSine
                    }
                }
            }
        }
    }
    
    ScrollView {
        anchors.fill: parent
        anchors.margins: 20
        anchors.leftMargin: 68
        anchors.rightMargin: -28
        anchors.topMargin: 8
        anchors.bottomMargin: 32
        
        ColumnLayout {
            spacing: 20
            width: parent.width
            
            // 标题区域
            Rectangle {
                Layout.fillWidth: true
                height: 80
                color: "#00000040"
                radius: 15
                
                // 发光效果
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 2
                    radius: 13
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: "#ffffff20" }
                        GradientStop { position: 1.0; color: "#ffffff05" }
                    }
                }
                
                Column {
                    anchors.centerIn: parent
                    spacing: 5
                    
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Qt Quick演示"
                        color: "white"
                        font.pixelSize: 28
                        font.bold: true
                        
                        // 文字阴影效果
                        style: Text.Outline
                        styleColor: "#80ffffff"
                    }
                    
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "现代动画与特效"
                        color: "#ccffffff"
                        font.pixelSize: 16
                    }
                }
            }
            
            // 状态显示
            Rectangle {
                Layout.fillWidth: true
                height: 50
                color: "#ffffff30"
                radius: 10
                border.color: "#ffffff50"
                border.width: 1
                
                Text {
                    anchors.centerIn: parent
                    text: root.statusText
                    color: "white"
                    font.pixelSize: 16
                    font.bold: true
                }
            }
            
            // 动画控件区域
            GroupBox {
                title: "动画控件"
                Layout.fillWidth: true
                
                background: Rectangle {
                    color: "#ffffff20"
                    radius: 10
                    border.color: "#ffffff40"
                    border.width: 1
                }
                
                label: Text {
                    text: parent.title
                    color: "white"
                    font.pixelSize: 16
                    font.bold: true
                }
                
                ColumnLayout {
                    anchors.fill: parent
                    spacing: 15
                    
                    // 动画按钮
                    RowLayout {
                        Layout.fillWidth: true
                        spacing: 10
                        
                        Button {
                            id: animatedButton
                            text: "弹跳动画"
                            
                            background: Rectangle {
                                color: parent.pressed ? "#3f51b5" : "#4caf50"
                                radius: 20
                                
                                Behavior on color {
                                    ColorAnimation { duration: 200 }
                                }
                            }
                            
                            onClicked: {
                                root.statusText = "弹跳动画已启动"
                                bounceAnimation.start()
                            }
                            
                            SequentialAnimation {
                                id: bounceAnimation
                                
                                NumberAnimation {
                                    target: animatedButton
                                    property: "scale"
                                    to: 1.2
                                    duration: 150
                                    easing.type: Easing.OutQuad
                                }
                                NumberAnimation {
                                    target: animatedButton
                                    property: "scale"
                                    to: 0.9
                                    duration: 100
                                    easing.type: Easing.InQuad
                                }
                                NumberAnimation {
                                    target: animatedButton
                                    property: "scale"
                                    to: 1.0
                                    duration: 150
                                    easing.type: Easing.OutBounce
                                }
                            }
                        }
                        
                        Button {
                            id: rotateButton
                            text: "旋转动画"
                            
                            background: Rectangle {
                                color: parent.pressed ? "#ff5722" : "#ff9800"
                                radius: 20
                            }
                            
                            onClicked: {
                                root.statusText = "旋转动画已启动"
                                rotateAnimation.start()
                            }
                            
                            RotationAnimation {
                                id: rotateAnimation
                                target: rotateButton
                                from: 0
                                to: 360
                                duration: 1000
                                easing.type: Easing.InOutCubic
                            }
                        }
                        
                        Button {
                            id: fadeButton
                            text: "淡入淡出"
                            
                            background: Rectangle {
                                color: parent.pressed ? "#673ab7" : "#9c27b0"
                                radius: 20
                            }
                            
                            onClicked: {
                                root.statusText = "淡入淡出动画已启动"
                                fadeAnimation.start()
                            }
                            
                            SequentialAnimation {
                                id: fadeAnimation
                                
                                NumberAnimation {
                                    target: fadeButton
                                    property: "opacity"
                                    to: 0.2
                                    duration: 500
                                }
                                NumberAnimation {
                                    target: fadeButton
                                    property: "opacity"
                                    to: 1.0
                                    duration: 500
                                }
                            }
                        }
                    }
                    
                    // 动画形状
                    Rectangle {
                        Layout.fillWidth: true
                        height: 100
                        color: "#ffffff15"
                        radius: 10
                        border.color: "#ffffff30"
                        border.width: 1
                        
                        // 移动的圆形
                        Rectangle {
                            id: movingCircle
                            width: 40
                            height: 40
                            radius: 20
                            color: "#e91e63"
                            y: 30
                            
                            // 简单的边框发光效果
                            border.color: "#80e91e63"
                            border.width: 2
                            
                            SequentialAnimation {
                                loops: Animation.Infinite
                                running: true
                                
                                NumberAnimation {
                                    target: movingCircle
                                    property: "x"
                                    to: parent.width - movingCircle.width
                                    duration: 2000
                                    easing.type: Easing.InOutQuad
                                }
                                NumberAnimation {
                                    target: movingCircle
                                    property: "x"
                                    to: 0
                                    duration: 2000
                                    easing.type: Easing.InOutQuad
                                }
                            }
                        }
                    }
                }
            }
            
            // 交互式卡片
            GroupBox {
                title: "交互式卡片"
                Layout.fillWidth: true
                
                background: Rectangle {
                    color: "#ffffff20"
                    radius: 10
                    border.color: "#ffffff40"
                    border.width: 1
                }
                
                label: Text {
                    text: parent.title
                    color: "white"
                    font.pixelSize: 16
                    font.bold: true
                }
                
                GridLayout {
                    anchors.fill: parent
                    columns: 3
                    columnSpacing: 10
                    rowSpacing: 10
                    
                    Repeater {
                        model: 6
                        
                        Rectangle {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.minimumHeight: 100
                            color: Qt.hsla(index * 0.1, 0.6, 0.7, 0.8)
                            radius: 15
                            
                            // 卡片内容
                            Column {
                                anchors.centerIn: parent
                                spacing: 5
                                
                                Text {
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    text: "卡片 " + (index + 1)
                                    color: "white"
                                    font.pixelSize: 16
                                    font.bold: true
                                }
                                
                                Text {
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    text: "点击我"
                                    color: "#ccffffff"
                                    font.pixelSize: 12
                                }
                            }
                            
                            MouseArea {
                                anchors.fill: parent
                                hoverEnabled: true
                                
                                onEntered: {
                                    parent.scale = 1.05
                                    hoverAnimation.start()
                                }
                                
                                onExited: {
                                    parent.scale = 1.0
                                    hoverAnimation.stop()
                                }
                                
                                onClicked: {
                                    root.statusText = "点击了卡片 " + (index + 1)
                                    clickAnimation.start()
                                }
                            }
                            
                            // 悬停动画
                            SequentialAnimation {
                                id: hoverAnimation
                                loops: Animation.Infinite
                                
                                NumberAnimation {
                                    target: parent
                                    property: "color"
                                    to: Qt.hsla(index * 0.1, 0.8, 0.8, 0.9)
                                    duration: 1000
                                }
                                NumberAnimation {
                                    target: parent
                                    property: "color"
                                    to: Qt.hsla(index * 0.1, 0.6, 0.7, 0.8)
                                    duration: 1000
                                }
                            }
                            
                            // 点击动画
                            SequentialAnimation {
                                id: clickAnimation
                                
                                ParallelAnimation {
                                    NumberAnimation {
                                        target: parent
                                        property: "scale"
                                        to: 0.9
                                        duration: 100
                                    }
                                    NumberAnimation {
                                        target: parent
                                        property: "opacity"
                                        to: 0.7
                                        duration: 100
                                    }
                                }
                                ParallelAnimation {
                                    NumberAnimation {
                                        target: parent
                                        property: "scale"
                                        to: 1.0
                                        duration: 200
                                        easing.type: Easing.OutBack
                                    }
                                    NumberAnimation {
                                        target: parent
                                        property: "opacity"
                                        to: 1.0
                                        duration: 200
                                    }
                                }
                            }
                            
                            // 缩放动画
                            Behavior on scale {
                                NumberAnimation {
                                    duration: 200
                                    easing.type: Easing.OutQuad
                                }
                            }
                        }
                    }
                }
            }
            
            // Qt Quick特性说明
            GroupBox {
                title: "Qt Quick特性"
                Layout.fillWidth: true
                
                background: Rectangle {
                    color: "#ffffff20"
                    radius: 10
                    border.color: "#ffffff40"
                    border.width: 1
                }
                
                label: Text {
                    text: parent.title
                    color: "white"
                    font.pixelSize: 16
                    font.bold: true
                }
                
                Text {
                    anchors.fill: parent
                    text: "Qt Quick特性展示：\n" +
                          "• 硬件加速渲染 - 流畅的图形性能\n" +
                          "• 丰富的动画系统 - 各种过渡效果\n" +
                          "• 现代UI设计 - 渐变、阴影、特效\n" +
                          "• 触摸友好 - 适合移动设备\n" +
                          "• 粒子系统 - 复杂的视觉效果\n" +
                          "• 状态管理 - 流畅的状态切换\n" +
                          "• 组件重用 - 高效的开发模式"
                    color: "white"
                    font.pixelSize: 14
                    wrapMode: Text.WordWrap
                }
            }
        }
    }
}