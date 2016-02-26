import QtQuick 2.0
import QtQuick.Controls 1.4
import cresus 1.0

View {
    id: view1

    TabView {
        id: tabView1
        anchors.fill: parent
        frameVisible: false

        Tab {
            title: "New operations"
            ListView {

                NewOperationsModel
                {
                    id : filterModel
                    sourceModel : view1.operations
                }

                model: filterModel

                delegate: Operation {
                    date: operation_date
                    label: operation_label
                    account: operation_account
                    amount: operation_value

                    anchors.left: parent.left
                    anchors.right: parent.right
                }
            }
        }
        Tab {
            title: "All operations"
            ListView {
                id: list
                model: view1.operations

                delegate: Operation {
                    date: operation_date
                    label: operation_label
                    account: operation_account
                    amount: operation_value

                    anchors.left: parent.left
                    anchors.right: parent.right
                }
            }
        }
    }
}
