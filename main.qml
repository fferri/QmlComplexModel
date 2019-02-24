import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

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
                        text: name
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

    Component.onCompleted: {
        console.log("myModel: " + myModel)
        console.log("myModel.count: " + myModel.count)
    }

    ListModel {
       id: listModel
       ListElement {
           name: "apple"
           tags: [ListElement {tagName: "juicy"; tagColor: "blue"}, ListElement {tagName: "red"; tagColor: "red"}, ListElement {tagName: "round"; tagColor: "blue"}]
       }
       ListElement {
           name: "banana"
           tags: [ListElement {tagName: "yellow"; tagColor: "#a90"}, ListElement {tagName: "straight"; tagColor: "blue"}]
       }
    }

    ListView {
        id: listView
        anchors.fill: parent
        model: 1 ? myModel : listModel
        focus: true
        delegate: itemDelegate
    }
}
