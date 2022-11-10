import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.0

Window {
    width: 480
    height: 920
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    title: qsTr("Guess")
    visible: true

    Text {
        id: name
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            topMargin: 20
        }
        width: 400
        text: "Mr Someome"
        font {
            pixelSize: 26
            bold: true
        }
        horizontalAlignment: Text.AlignHCenter
    }

    Column {
        id: skills
        anchors {
            top: name.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: 20
        }
        width: 300
        spacing: 5

        Skill {
            width: skills.width
            skillName: "Assembly"
            skillPoint: "4/5"
        }

        Skill {
            width: skills.width
            skillName: "C++"
            skillPoint: "5/5"
        }

        Skill {
            width: skills.width
            skillName: "Javascript"
            skillPoint: "3/5"
        }

        Skill {
            width: skills.width
            skillName: "QML"
            skillPoint: "3/5"
        }

        Skill {
            width: skills.width
            skillName: "OpenGL"
            skillPoint: "4/5"
        }
    }

    Button {
        id: refresh
        anchors {
            top: skills.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: 20
        }
        width: 200
        height: 40

        Text {
            anchors.fill: parent
            text: "Refresh"
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
    }
}
