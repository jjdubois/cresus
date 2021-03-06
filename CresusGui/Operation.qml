import QtQuick 2.0

Item {
    id: operation

    property alias date : date.text
    property alias label : label.text
    property alias account : account.text
    property alias amount : amount.text

    height : 50

    Image {
        id: icon
        width: 50
        height: 50
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        //source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Text {
        id: date
        text: qsTr("Date")
        anchors.top: parent.top
        anchors.right: parent.right
        font.pointSize: 12
    }

    Text {
        id: label
        anchors.top: parent.top
        text: qsTr("Label")
        anchors.left: icon.right
        anchors.right: date.left
        font.pointSize: 16
        elide: Text.ElideRight
    }

    Text {
        id: account
        text: qsTr("account")
        anchors.bottom: parent.bottom
        anchors.right: amount.left
        anchors.left: icon.right
        font.pointSize: 12
    }

    Text {
        id: amount
        text: qsTr("0.0")
        anchors.bottom: parent.bottom
        anchors.right: unit.left
        anchors.rightMargin: 5
        font.pointSize: 16
    }

    Text {
        id: unit
        text: qsTr("€")
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        font: amount.font
    }
}
