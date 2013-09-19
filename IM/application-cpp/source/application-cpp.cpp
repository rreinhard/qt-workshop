#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QTextEdit>

#include <messenger/controller.h>
#include <messenger/communication.h>
#include <messenger/udp_socket.h>

#include "application-cpp/toolbar.h"
#include "application-cpp/gui.h"
#include "application-cpp/application-cpp.h"
#include "application-cpp/sendwidget.h"
#include "application-cpp/set_nickname_dialog.h"

namespace IM {

Application::Application()
{
}

int Application::execute(int argc, char * argv[])
{
    QApplication application(argc, argv);

    UdpSocket udpSocket;
    Communication communication(udpSocket, "Dummy");


    QPushButton * event_button = new QPushButton("event");
    QPushButton * settings_button = new QPushButton("settings");

    QPushButton * set_button = new QPushButton("set nickname");
    QLineEdit * nickname_input = new QLineEdit(communication.get_nickname());

    SetNicknameDialog set_nickname_dialog(nickname_input, set_button);
    set_nickname_dialog.setModal(true);
    QObject::connect(settings_button, SIGNAL(clicked()), &set_nickname_dialog, SLOT(show()));

    communication.connect(&set_nickname_dialog, SIGNAL(set_nickname(const QString &)), SLOT(handle_set_nickname(const QString &)));

    Toolbar* toolbar = new Toolbar(event_button, settings_button);
    QTextEdit* chat_widget = new QTextEdit();

    QPushButton * send_button = new QPushButton("send");
    QLineEdit * message_input = new QLineEdit();
    SendWidget* send_widget = new SendWidget(message_input, send_button);

    QListView* online_list_view = new QListView();

    Gui gui(toolbar, chat_widget, send_widget, online_list_view);

    communication.connect(send_widget, SIGNAL(send_message(quint32, QString const &)), SLOT(handle_send_message(quint32, QString const &)));

    gui.show();
    return application.exec();
}

} // IM

