import QtQuick 2.3
import QtQuick.Controls 1.2
import cresus 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    /*OperationsData {
        id: data
    }*/

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: data.searchNewOperations()
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
    }

    Row {
        anchors.fill : parent


        MenuTab {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 200
        }

        Column {
            anchors.top : parent.top
            anchors.bottom: parent.bottom
            OperationListHeader {
                id: currentOperationsList
                anchors.left: parent.left
                anchors.right: parent.right
                height: 200
            }
            Rectangle{
                color:"red"
                anchors.left: parent.left
                anchors.right: parent.right
                height: 200
            }

            //OperationListView {
            //    anchors.fill: parent
            //}
        }
    }
}
