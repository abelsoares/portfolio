import Qt 4.7
import QtWebKit 1.0

Rectangle {
    width: 1000
    height: 800

    Image {
        id: image1
        x: 116
        y: 231
        width: 772
        height: 532
        smooth: true
        fillMode: "PreserveAspectFit"
        source: "../qml_contents/images/bookNewton.jpg"
    }

    Rectangle {
        id: rectangle1
        x: 96
        y: 31
        width: 811
        height: 216
        color: "#3b5998"
        radius: 18
        border.color: "#fbf8f8"
        Text {
            id: text1
            x: 62
            y: 35
            width: 699
            height: 132
            color: "#ffffff"
            text: "Mostra a imagem de Isaac Newton para ver uma animação 3D sobre as Leis de Newton."
            wrapMode: "WordWrap"
            font.bold: true
            font.family: "Segoe Print"
            font.pointSize: 23
            horizontalAlignment: "AlignHCenter"
            verticalAlignment: "AlignVCenter"
        }
        border.width: 5
        opacity: 0.84
    }
    Rectangle {
        id: rectangle2
        objectName:"overlay"
        x: 0
        y: 0
        width: 1000
        height: 800
        color: "#000000"
        border.color: "#000000"
        opacity: 0
        Behavior on opacity { SmoothedAnimation { velocity: 20 } }

        Rectangle {
            id: rectangle3
            objectName:"overlay_bt"
            x: 626
            y: 703
            width: 175
            height: 53
            color: "#252525"
            radius: 12
            opacity: 0
            border.color: "#ffffff"

            Text {
                id: text2
                objectName:"overlay_text"
                x: 51
                y: 4
                width: 170
                height: 40
                color: "#fdfdfd"
                text: "close"
                opacity: 0
                font.pointSize: 25
            }
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.LeftButton | Qt.RightButton

                onEntered: {

                }

                onPressed: {
                    bookViewerWidget.QmlCloseBtClicked();
                }
            }
        }
    }
}
