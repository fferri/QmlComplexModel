import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Complex Model Demo")

    signal test

    Component {
        id: tagDelegate
        Rectangle {
            property int margin: 5
            color: tagColor
            border.color: Qt.rgba(0, 0, 0, 0.33)
            radius: height / 2
            width: tagText.width + 3 * margin
            height: tagText.height + 2 * margin
            Text {
                id: tagText
                color: "#fff"
                text: tagName
                anchors.centerIn: parent
                font.bold: true
                font.pixelSize: 11
            }
        }
    }

    Component {
        id: itemDelegate
        Rectangle {
            id: itemRect
            property string normalColor: "#80ffffff"
            property string selectionColor: "#603366cc"
            gradient: Gradient {
                GradientStop { position: 0; color: Qt.tint("#fff", itemRect.ListView.isCurrentItem ? itemRect.selectionColor : itemRect.normalColor) }
                GradientStop { position: 1; color: Qt.tint("#aaa", itemRect.ListView.isCurrentItem ? itemRect.selectionColor : itemRect.normalColor) }
            }
            border.color: ListView.isCurrentItem ? Qt.tint("#aaa", selectionColor) : "transparent"
            width: parent.width
            implicitHeight: itemItem.implicitHeight + 20
            Item {
                id: itemItem
                anchors.fill: parent
                anchors.margins: 10
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
        onFocusChanged: listView.focus = true
        clip: true
    }

    Button {
        id: testButton
        anchors.top: listView.bottom
        text: "Test"
        onClicked: test()
    }
}
