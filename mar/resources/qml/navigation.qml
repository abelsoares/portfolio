import Qt 4.7
import "../scripts/script.js" as Script

Rectangle {
    width: 500
    height: 480
    color: "#eae7ef"

    Rectangle {
        id: bt1
        property int aux_bt: 0

        x: 23
        y: 67
        width: 193
        height: 49
        color: "#3b5998"
        radius: 12
        scale: 1
        Behavior on width { SmoothedAnimation { velocity: 200 } }

        Text {
            id: text1
            x: 24
            y: 12
            width: 210
            height: 28
            color: "#ffffff"
            //text: sharedObject.text
            text: "Vídeo Newton"
            font.pointSize: 14
            font.bold: true
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onEntered: {
                info.text = 'Entered'
                parent.width = 246
                bt1_icon.opacity = 1;
                //parent.height = parent.height + 20
            }
            onExited: {
                if(parent.aux_bt == 0)
                {
                    parent.width = 193
                    bt1_icon.opacity = 0;
                    parent.color = "#3b5998";
                }
                info.text = 'Exited (pressed=' + pressed + ')'
                //parent.height = parent.height - 20
            }

            onPressed: {
                parent.aux_bt = 1;

                bt2.width = 193;
                bt2_icon.opacity = 0;
                bt2.color = "#3b5998";

                parent.width = 246;
                bt1_icon.opacity = 1;

                bt2.aux_bt = 0;

                sharedObject.QmlBtClicked(1);
                bt1.color = "#293F69"
                info.text = 'Pressed (button=' + (mouse.button == Qt.RightButton ? 'right' : 'left')
                    + ' shift=' + (mouse.modifiers & Qt.ShiftModifier ? 'true' : 'false') + ')'
                var posInBox = bt1.mapToItem(box, mouse.x, mouse.y)
                posInfo.text = + mouse.x + ',' + mouse.y + ' in square'
                        + ' (' + posInBox.x + ',' + posInBox.y + ' in window)'
            }

            onReleased: {
                info.text = 'Released (isClick=' + mouse.isClick + ' wasHeld=' + mouse.wasHeld + ')'
                posInfo.text = ''
            }

            onPressAndHold: info.text = 'Press and hold'
            onClicked: info.text = 'Clicked (wasHeld=' + mouse.wasHeld + ')'
            onDoubleClicked: info.text = 'Double clicked'
        }

        Image {
            id: bt1_icon
            x: 186
            y: 5
            width: 48
            height: 38
            opacity: 0
            rotation: 9
            smooth: true
            fillMode: "PreserveAspectFit"
            source: "../qml_contents/images/VLC_48x48.png"
            Behavior on opacity { SmoothedAnimation { velocity: 10 } }
        }
    }

    Rectangle {
        id: bt2
        property int aux_bt: 0
        x: 23
        y: 124
        width: 193
        height: 49
        color: "#3b5998"
        radius: 12
        Behavior on width { SmoothedAnimation { velocity: 200 } }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onEntered: {
                info.text = 'Entered'
                parent.width = 246
                bt2_icon.opacity = 1;
            }
            onExited: {
                if(parent.aux_bt == 0)
                {
                    parent.width = 193
                    bt2_icon.opacity = 0;
                    parent.color = "#3b5998";
                }
                info.text = 'Exited (pressed=' + pressed + ')'
            }

            onPressed: {
                parent.aux_bt = 1;
                bt1.aux_bt = 0;

                bt1.width = 193
                bt1_icon.opacity = 0;
                bt1.color = "#3b5998";

                parent.width = 246;
                bt2_icon.opacity = 1;
                bt2.color = "#293F69"

                sharedObject.QmlBtClicked(2);
                info.text = 'Pressed (button=' + (mouse.button == Qt.RightButton ? 'right' : 'left')
                    + ' shift=' + (mouse.modifiers & Qt.ShiftModifier ? 'true' : 'false') + ')'
                var posInBox = bt1.mapToItem(box, mouse.x, mouse.y)
                posInfo.text = + mouse.x + ',' + mouse.y + ' in square'
                        + ' (' + posInBox.x + ',' + posInBox.y + ' in window)'
            }

            onReleased: {
                info.text = 'Released (isClick=' + mouse.isClick + ' wasHeld=' + mouse.wasHeld + ')'
                posInfo.text = ''
            }

            onPressAndHold: info.text = 'Press and hold'
            onClicked: info.text = 'Clicked (wasHeld=' + mouse.wasHeld + ')'
            onDoubleClicked: info.text = 'Double clicked'
        }
        Text {
            id: text2
            x: 24
            y: 12
            width: 210
            height: 28
            color: "#ffffff"
            text: "Animação 3D"
            font.bold: true
            font.pointSize: 14
        }

        Image {
            id: bt2_icon
            Behavior on opacity { SmoothedAnimation { velocity: 10 } }
            x: 189
            y: 4
            width: 48
            height: 38
            smooth: true
            source: "../qml_contents/images/VLC_48x48.png"
            fillMode: "PreserveAspectFit"
            rotation: 9
            opacity: 0
        }
    }

    Rectangle {
        id: bt3
        x: 23
        y: 181
        width: 193
        height: 49
        color: "#3b5998"
        radius: 12
        Behavior on width { SmoothedAnimation { velocity: 200 } }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onEntered: {
                info.text = 'Entered'
                parent.width = 246
                bt3_icon.opacity = 1;
            }
            onExited: {
                info.text = 'Exited (pressed=' + pressed + ')'
                parent.width = 193
                bt3_icon.opacity = 0;
            }

            onPressed: {
                info.text = 'Pressed (button=' + (mouse.button == Qt.RightButton ? 'right' : 'left')
                    + ' shift=' + (mouse.modifiers & Qt.ShiftModifier ? 'true' : 'false') + ')'
                var posInBox = bt1.mapToItem(box, mouse.x, mouse.y)
                posInfo.text = + mouse.x + ',' + mouse.y + ' in square'
                        + ' (' + posInBox.x + ',' + posInBox.y + ' in window)'
            }

            onReleased: {
                info.text = 'Released (isClick=' + mouse.isClick + ' wasHeld=' + mouse.wasHeld + ')'
                posInfo.text = ''
            }

            onPressAndHold: info.text = 'Press and hold'
            onClicked: info.text = 'Clicked (wasHeld=' + mouse.wasHeld + ')'
            onDoubleClicked: info.text = 'Double clicked'
        }

        Text {
            id: text3
            x: 24
            y: 12
            width: 210
            height: 28
            color: "#ffffff"
            text: "Leis de Newton"
            font.bold: true
            font.pointSize: 14
        }
        Image {
            id: bt3_icon
            Behavior on opacity { SmoothedAnimation { velocity: 10 } }
            x: 189
            y: 4
            width: 48
            height: 38
            smooth: true
            source: "../qml_contents/images/VLC_48x48.png"
            fillMode: "PreserveAspectFit"
            rotation: 9
            opacity: 0
        }
    }

    Rectangle {
        id: bt4
        x: 23
        y: 238
        width: 193
        height: 49
        color: "#3b5998"
        radius: 12
        Behavior on width { SmoothedAnimation { velocity: 200 } }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onEntered: {
                info.text = 'Entered'
                parent.width = 246
                bt4_icon.opacity = 1;
            }
            onExited: {
                info.text = 'Exited (pressed=' + pressed + ')'
                parent.width = 193
                bt4_icon.opacity = 0;
            }

            onPressed: {
                info.text = 'Pressed (button=' + (mouse.button == Qt.RightButton ? 'right' : 'left')
                    + ' shift=' + (mouse.modifiers & Qt.ShiftModifier ? 'true' : 'false') + ')'
                var posInBox = bt1.mapToItem(box, mouse.x, mouse.y)
                posInfo.text = + mouse.x + ',' + mouse.y + ' in square'
                        + ' (' + posInBox.x + ',' + posInBox.y + ' in window)'
            }

            onReleased: {
                info.text = 'Released (isClick=' + mouse.isClick + ' wasHeld=' + mouse.wasHeld + ')'
                posInfo.text = ''
            }

            onPressAndHold: info.text = 'Press and hold'
            onClicked: info.text = 'Clicked (wasHeld=' + mouse.wasHeld + ')'
            onDoubleClicked: info.text = 'Double clicked'
        }

        Text {
            id: text4
            x: 24
            y: 12
            width: 210
            height: 28
            color: "#ffffff"
            text: "Leis de Newton"
            font.bold: true
            font.pointSize: 14
        }

        Image {
            id: bt4_icon
            Behavior on opacity { SmoothedAnimation { velocity: 10 } }
            x: 189
            y: 4
            width: 48
            height: 38
            smooth: true
            source: "../qml_contents/images/VLC_48x48.png"
            fillMode: "PreserveAspectFit"
            rotation: 9
            opacity: 0
        }
    }

    Text {
        id: text5
        x: 22
        y: 9
        width: 215
        height: 34
        color: "#3b5998"
        text: "Conteúdos"
        styleColor: "#3b5998"
        font.bold: true
        font.pointSize: 21
    }
    Text {
        id: info
        anchors.bottom: posInfo.top; anchors.horizontalCenter: parent.horizontalCenter; anchors.margins: 30

        onTextChanged: console.log(text)
    }

    Text {
        id: posInfo
        anchors.bottom: parent.bottom; anchors.horizontalCenter: parent.horizontalCenter; anchors.margins: 30
    }
}
