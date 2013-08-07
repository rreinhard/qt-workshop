import QtQuick 2.0

Rectangle {
    width: 200
    height: 20

    property alias nickname: id_nick_input.text

    border { color: "black"; width: 1 }

    Row {
        anchors.fill: parent
        spacing: 2

        Text {
            width: 80
            height: parent.height

            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter

            text: "nickname:"
        }

        TextInput {
            id: id_nick_input
            objectName: "id_nick_input"

            width: parent.width - 82
            height: parent.height

            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter

            clip: true

            selectByMouse: true

            text: nickname

        }
    }
}

