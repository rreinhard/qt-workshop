import QtQuick 2.0

Rectangle {
    anchors.fill: parent

    anchors.margins: 2

    signal submit(string message)

    Rectangle {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: id_send_button.left
        height: parent.height

        anchors.rightMargin: 2

        border { color: "black"; width: 1 }

        TextInput {
            id: id_message_input
            objectName: "id_message_input"

            anchors.fill: parent

            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            clip: true

            selectByMouse: true
        }
    }

    Button {
        id: id_send_button
        objectName: "id_send_button"

        anchors.top: parent.top
        anchors.right:  parent.right

        width: 64
        height: parent.height

        button_text: "send"

        onButtonClicked: {
            if(id_message_input.text.length > 0) {
                submit(id_message_input.text);
                id_message_input.text = "";
            }
        }
    }
}

