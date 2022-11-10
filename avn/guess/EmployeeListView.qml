import QtQuick 2.0

Item {
    id: root

    property alias model: listView.model

    signal selectedItemChanged(int index, int id)

    Rectangle {
        id: header
        anchors {
            left: root.left
            right: root.right
        }
        height: 40
        color: "lightgrey"
        radius: 5

        Text {
            id: name
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                leftMargin: 20
            }
            width: parent.width * 2 / 3
            text: "Name"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignLeft
        }

        Text {
            id: point
            anchors {
                right: parent.right
                verticalCenter: parent.verticalCenter
                rightMargin: 20
            }
            width: root.width / 3
            text: "Point"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignRight
        }
    }

    ListView {
        id: listView
        anchors {
            top: header.bottom
            bottom: root.bottom
            topMargin: 10
        }
        width: root.width
        clip: true
        delegate: Item {
            width: listView.width
            height: 40

            Text {
                anchors {
                    left: parent.left
                    verticalCenter: parent.verticalCenter
                    leftMargin: 20
                }
                width: parent.width * 2 / 3
                text: "Name"
                font.pixelSize: 20
                horizontalAlignment: Text.AlignLeft
            }

            Text {
                anchors {
                    right: parent.right
                    verticalCenter: parent.verticalCenter
                    rightMargin: 20
                }
                width: parent.width / 3
                text: "0.0"
                font.pixelSize: 20
                horizontalAlignment: Text.AlignRight
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    listView.currentIndex = model.index
                    selectedItemChanged(model.index, model.id)
                }
            }
        }
        highlight: Rectangle {
            y: listView.currentItem.y
            width: listView.width
            height: 40
            color: "lightblue"
            radius: 5
        }
        highlightFollowsCurrentItem: false
        populate: Transition {
            id: trans
            SequentialAnimation {
                PropertyAction { property: "opacity"; value: 0.0 }
                PauseAnimation { duration: trans.ViewTransition.index * 500 }
                NumberAnimation { property: "opacity"; from: 0.0; to: 1.0; duration: 2000; easing.type: Easing.InOutQuad }
            }
        }
    }
}
