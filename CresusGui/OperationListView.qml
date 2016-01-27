import QtQuick 2.0
import QtQuick.Controls 1.4

View {
    id: view1
    TabView {
        id: tabView1
        anchors.fill: parent
    }
    Tab {
            title: "New operations"
                ListView {
                    anchors.fill: parent
                    model : 5

                    delegate: Operation {

                    }
                }
        }
        Tab {
            title: "All operations"
            ListView {
                anchors.fill: parent
                model : 5

                delegate: Operation {

                }
            }
        }

}
