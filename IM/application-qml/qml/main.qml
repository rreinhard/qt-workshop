import QtQuick 2.0

Rectangle {
    width: 320
    height: 32

    SendMessage {
        onSubmit: controller.invoke_send_message(message);
    }
}

