import QtQuick 2.3
import QtQuick.Controls 1.2
import cresus 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function initData() {
        if( operationsData && model )
        {
            model.setOperationsList( operationsData );
        }
    }
    property OperationsData operationsData : OperationsData{}
    onOperationsDataChanged: initData()
    property OperationsModel model : OperationsModel{}
    onModelChanged: initData()

    property bool menu_shown: false

    /* this functions toggles the menu and starts the animation */
    function onMenu() {
        game_translate_.x = root.menu_shown ? 12 : menuTab.width
        root.menu_shown = !root.menu_shown
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: operationsData.searchNewOperations()
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
    }

    Item
    {
        anchors.fill: parent

        Rectangle {
            id: menuView
            anchors.fill: parent
            color: "black"
            MenuTab {
                id: menuTab
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: 200
            }
        }

        Rectangle {
            id: contentView
            anchors.fill: parent
            color: "white"
            /* this is what moves the normal view aside */
            transform: Translate {
                id: game_translate_
                x: 12
                Behavior on x {
                    NumberAnimation {
                        duration: 400
                        easing.type: Easing.OutQuad
                    }
                }
            }

            Column {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                OperationListHeader {
                    id: currentOperationsList
                    anchors.left: parent.left
                    anchors.right: parent.right
                }

                Item {
                    id: viewContainer

                    width: root.width - 12
                    height: root.height - currentOperationsList.height

                    property int currentIndex: 0

                    Row {
                        id: r
                        transform: Translate {
                            x: -viewContainer.currentIndex * viewContainer.width
                            Behavior on x {
                                NumberAnimation {
                                    duration: 200
                                }
                            }
                        }

                        Repeater {
                            model: VisualItemModel {
                                id: itemModel
                                OperationListView {
                                    height: viewContainer.height
                                    width: viewContainer.width
                                    operations : operationsData.currentModel()
                                }
                                Rectangle {
                                    height: viewContainer.height
                                    width: viewContainer.width
                                    color: "green"
                                }
                                Rectangle {
                                    height: viewContainer.height
                                    width: viewContainer.width
                                    color: "blue"
                                }
                            }
                        }
                    }

                    Row
                    {
                        anchors.top: viewContainer.top
                        anchors.horizontalCenter: viewContainer.horizontalCenter
                        spacing: 10
                        Repeater
                        {
                            model : itemModel.count
                            Text {
                                text: index
                                MouseArea
                                {
                                    anchors.fill: parent
                                    onClicked: viewContainer.currentIndex = index
                                }
                            }
                        }
                    }
                }
            }
            /* put this last to "steal" touch on the normal window when menu is shown */
            MouseArea {
                anchors.fill: parent
                enabled: root.menu_shown
                onClicked: root.onMenu()
            }
        }
        /* this is the menu shadow */
        BorderImage {
            id: menu_shadow_
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.leftMargin: -10
            anchors.rightMargin: -10
            z: 2 /* this will place it below normal_view_ */
            //visible: root.menu_shown
            source: "images/shadow.png"
            border {
                left: 12
                top: 12
                right: 12
                bottom: 12
            }
            MouseArea {
                anchors.fill: parent
                onClicked: root.onMenu()
            }
        }
    }
}
