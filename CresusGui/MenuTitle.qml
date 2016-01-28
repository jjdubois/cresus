import QtQuick 2.0

Column {
    property alias text: label.text
    Text {
        id: label
    }
    Rectangle {
        height: 1
        anchors.left: parent.left
        anchors.right: parent.right
    }
}
