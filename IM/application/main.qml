import QtQuick 2.0

Rectangle {
    width: 320
    height: 480

    Text {
        anchors.centerIn: parent
        text: qsTr("Hello World")
    }

    id: qt_proj

    focus: true
    Keys.onEscapePressed: { console.log("ESC"); Qt.quit() }
}

