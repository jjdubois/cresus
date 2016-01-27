import QtQuick 2.0

Row {
    spacing: 6
    Text {
        id: amount
        text: qsTr("Value")
        font.pointSize: label.font.pointSize
    }

    Text {
        id: amountUnit
        text: qsTr("€")
        font.pointSize: label.font.pointSize
    }
}
