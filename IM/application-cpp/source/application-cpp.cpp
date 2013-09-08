#include <QtWidgets/QApplication>

#include <messenger/controller.h>
#include <messenger/communication.h>
#include <messenger/udp_socket.h>

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

    QPushButton send_button("send");
    QLineEdit message_input;

    Gui gui(message_input, send_button);

    controller.connect(&gui, SIGNAL(send_message(QString const &)), SLOT(invoke_send_message(QString const &)));

    gui.show();
    return application.exec();
}

} // IM

