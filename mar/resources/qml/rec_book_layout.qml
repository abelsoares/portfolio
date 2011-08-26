import Qt 4.7

Rectangle {
    width: 640
    height: 480

    Image {
        id: image1
        x: 0
        y: 0
        width: 640
        height: 480
        source: "../demo_01-build-desktop/book.jpg"

        Rectangle {
            id: rectangle1
            x: 79
            y: 137
            width: 483
            height: 206
            color: "#3b5998"
            radius: 25
            border.width: 5
            border.color: "#fbf8f8"
            opacity: 0.87

            Text {
                id: text1
                x: 56
                y: -1
                width: 372
                height: 128
                color: "#ffffff"
                text: "Livro reconhecido!"
                font.bold: true
                font.family: "Segoe Print"
                wrapMode: "WordWrap"
                verticalAlignment: "AlignVCenter"
                horizontalAlignment: "AlignHCenter"
                font.pointSize: 19
            }

            Text {
                id: text2
                x: 68
                y: 95
                width: 349
                height: 44
                color: "#ffffff"
                text: "A carregar conteúdo..."
                wrapMode: "WordWrap"
                font.bold: true
                font.family: "Segoe Print"
                font.pointSize: 19
                horizontalAlignment: "AlignHCenter"
                verticalAlignment: "AlignVCenter"
            }

            Image {
                id: image2
                x: 390
                y: 104
                width: 32
                height: 27
                fillMode: "PreserveAspectFit"
                smooth: false
                source: "../demo_01-build-desktop/busy.png"
            }
        }
    }
}
