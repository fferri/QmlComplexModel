import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal test

    Component {
        id: tagDelegate
        Rectangle {
            property int margin: 5
            color: tagColor
            radius: height / 2
            width: tagText.width + 3 * margin
            height: tagText.height + 2 * margin
            Text {
                id: tagText
                color: "#fff"
                text: tagName
                anchors.centerIn: parent
                font.bold: true
            }
        }
    }

    Component {
        id: itemDelegate
        Rectangle {
            color: ListView.isCurrentItem ? "#eee" : "transparent"
            width: parent.width
            implicitHeight: itemItem.implicitHeight + 20
            Rectangle {
                color: "#cfc"
                id: itemItem
                anchors.fill: parent
                anchors.margins: 10
                //anchors.centerIn: parent
                implicitWidth: column.implicitWidth
                implicitHeight: column.implicitHeight
                Column {
                    id: column
                    spacing: 10
                    Text {
                        text: model.name
                    }
                    Flow {
                        width: itemItem.width
                        spacing: 5
                        Repeater {
                            model: tags
                            delegate: tagDelegate
                        }
                    }
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: listView.currentIndex = index
            }
        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        anchors.bottomMargin: testButton.height
        model: myModel
        focus: true
        delegate: itemDelegate
    }

    Button {
        id: testButton
        anchors.top: listView.bottom
        text: "Test"
        onClicked: test()
    }
}
