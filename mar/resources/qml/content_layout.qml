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
                y: 39
                width: 372
                height: 128
                color: "#ffffff"
                text: "Mostra a capa do teu livro para a webcam e começa a interagir!"
                font.bold: true
                font.family: "Segoe Print"
                wrapMode: "WordWrap"
                verticalAlignment: "AlignVCenter"
                horizontalAlignment: "AlignHCenter"
                font.pointSize: 19
            }
        }
    }
}
