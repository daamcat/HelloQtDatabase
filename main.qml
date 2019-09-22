import QtQuick 2.13
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import com.mycompany.mycomponent 1.0

Window
{
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BackEnd
    {
        id: backEnd
        userName: "Salam"
    }

    BorderImage {
        id: borderImage
        x: 88
        y: 55
        width: 40
        height: 45
        source: "icons/Files-View-File-icon.png"
    }

    TextField
    {
        id: textEdit
        x: 280
        y: 256
        width: 166
        height: 44
        text: backEnd.tableName
        anchors.verticalCenterOffset: -156
        anchors.horizontalCenterOffset: -62
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 12
        onEditingFinished: backEnd.userName = text

    }

    TableView
    {
        id: tableView
        y: 207
        sortIndicatorVisible: true
        highlightOnFocus: true
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        anchors.left: parent.left
        anchors.right: parent.right






        TableViewColumn
        {
            role: "Description"
            title: "Description"
        }
        TableViewColumn
        {
            role: "Price"
            title: "Price"
        }
        TableViewColumn
        {
            role: "Date"
            title: "Date"
        }
        TableViewColumn
        {
            role: "Withdrawal"
            title: "Withdrawal"
        }
        TableViewColumn
        {
            role: "Tag"
            title: "Tag"
        }
        model: MySqlTableModel
    }
}







/*##^## Designer {
    D{i:4;anchors_x:184}
}
 ##^##*/
