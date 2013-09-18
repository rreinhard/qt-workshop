#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

#include <messenger/controller.h>
#include <messenger/communication.h>
#include <messenger/udp_socket.h>

#include "application-cpp/toolbar.h"
#include "application-cpp/gui.h"
#include "application-cpp/application-cpp.h"

namespace IM {

Application::Application()
{
}

int Application::execute(int argc, char * argv[])
{
    QApplication application(argc, argv);

    Controller controller;

    UdpSocket udpSocket;
    Communication communication(udpSocket);
    communication.connect(&controller, SIGNAL(send_message(const QString &, const QString &)), SLOT(handle_send_message(const QString &, const QString &)));

    QPushButton * event_button = new QPushButton("event");
    QPushButton * settings_button = new QPushButton("settings");

    Toolbar toolbar(event_button, settings_button);

    QPushButton * send_button = new QPushButton("send");
    QLineEdit * message_input = new QLineEdit();

    Gui gui(message_input, send_button);

    controller.connect(&gui, SIGNAL(send_message(QString const &)), SLOT(invoke_send_message(QString const &)));

    gui.show();
    return application.exec();
}

} // IM

