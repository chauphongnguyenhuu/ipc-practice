import QtQuick 2.0

Item {
    id: root

    property alias skillName: name.text
    property alias skillPoint: point.text
    property bool pass: true

    implicitWidth: icon.width + point.width + status.width
    implicitHeight: 50

    Image {
        id: icon
        anchors {
            left: root.left
            verticalCenter: root.verticalCenter
        }
        width: 32
        height: 32
        source: "qrc:/paw.png"
    }

    Text {
        id: name
        anchors {
            left: icon.right
            right: point.left
            verticalCenter: root.verticalCenter
            leftMargin: 10
            rightMargin: 5
        }
        elide: Text.ElideRight
        font.pixelSize: 20
    }

    Text {
        id: point
        anchors {
            right: status.left
            verticalCenter: root.verticalCenter
            rightMargin: 5
        }
        width: 50
        elide: Text.ElideRight
        font.pixelSize: 20
    }

    Image {
        id: status
        anchors {
            right: root.right
            verticalCenter: root.verticalCenter
        }
        width: 32
        height: 32
        source: pass ? "qrc:/check.png" : "qrc:/close.png"
    }
}
