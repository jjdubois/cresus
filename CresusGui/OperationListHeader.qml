import QtQuick 2.0

Item {

    id: operationHeader
    height: 50
    Image {
        id: icon
        width: 50
        height: 50
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Text {
        id: label
        text: qsTr("Label")
        anchors.left: icon.right
        anchors.right: amount.left
        anchors.rightMargin: 6
        anchors.top: parent.top
        font.pointSize: 12
    }

    ValueItem {
        id: amount
        anchors.right: parent.right
        anchors.top: parent.top
    }

    Item {
        anchors.top: label.bottom
        anchors.bottom: parent.bottom
        anchors.left: icon.right
        anchors.right: parent.right

        Row {
            id: row1
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.centerIn: parent
            spacing: 6

            Row {
                anchors.bottom: parent.bottom
                Image {
                    id: image1
                    width: 20
                    height: 20
                    source: "qrc:/qtquickplugin/images/template_image.png"
                }
                ValueItem {
                    id: expense
                }
            }

            Row {
                anchors.bottom: parent.bottom
                Image {
                    id: image2
                    width: 20
                    height: 20
                    source: "qrc:/qtquickplugin/images/template_image.png"
                }
                ValueItem {
                    id: income
                }
            }
        }
    }
}
