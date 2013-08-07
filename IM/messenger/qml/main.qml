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

            Nickname {
                width: 250
                height: parent.height
            }

            Button {
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

                button_text: "Send"
            }
        }
    }
}

