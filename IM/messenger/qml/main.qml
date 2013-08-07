import QtQuick 2.0

Rectangle {
    width: 300
    height: 500

    Column {
        anchors.fill: parent

        Row {
            id: id_menu_bar

            width: parent.width
            height: 25

            Rectangle {
                width: 250
                height: parent.height

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
                        width: 150
                        height: parent.height

                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter

                        clip: true

                        selectByMouse: true

                        text: "my name"
                    }
                }
            }

            Button {
                width: 50
                height: parent.height

                border { color: "black"; width: 1 }

                button_text: "Exit"
                onButtonClicked: Qt.quit()
            }
        }

        Rectangle {
            id: id_online_list_frame

            width: parent.width
            height: 250

            border { color: "black"; width: 1 }
        }

        Rectangle {
            id: id_chat_log_frame

            width: parent.width
            height: 200

            border { color: "black"; width: 1 }
        }

        Row {
            id: id_send_message_frame

            width: parent.width
            height: 25

            Rectangle {
                id: id_message_input

                width: 250
                height: parent.height

                border { color: "black"; width: 1 }

                TextInput {
                    anchors.fill: parent
                    anchors.margins: 4

                    clip: true

                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter

                    selectByMouse: true
                }
            }

            Button {
                id: id_submit_message_button

                width: 50
                height: parent.height

                border { color: "black"; width: 1 }

                button_text: "Send"
            }
        }
    }
}

