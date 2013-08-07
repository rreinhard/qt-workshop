import QtQuick 2.0

Rectangle {
    width: 50
    height: 25

    property string button_text: ""

    signal buttonClicked()

    border { color: "black"; width: 1 }

    Text {
        anchors.fill: parent

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        text: button_text
    }

    MouseArea {
        anchors.fill: parent
        onClicked: buttonClicked()
    }
}

