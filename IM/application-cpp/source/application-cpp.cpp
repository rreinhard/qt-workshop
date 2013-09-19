#include <QtCore/QStringListModel>
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

namespace IM {

Application::Application()
{
}

int Application::execute(int argc, char * argv[])
{
    QApplication application(argc, argv);

    Controller controller;

    UdpSocket udpSocket;
    Communication communication(udpSocket, "Dummy");
    communication.connect(&controller, SIGNAL(send_message(const QString &, const QString &)), SLOT(handle_send_message(const QString &, const QString &)));

    QPushButton * event_button = new QPushButton("event");
    QPushButton * settings_button = new QPushButton("settings");

    Toolbar* toolbar = new Toolbar(event_button, settings_button);
    QTextEdit* chat_widget = new QTextEdit();

    QPushButton * send_button = new QPushButton("send");
    QLineEdit * message_input = new QLineEdit();
    SendWidget* send_widget = new SendWidget(message_input, send_button);

    QStringListModel* online_list_model = new QStringListModel();
    QListView* online_list_view = new QListView();
    online_list_view->setModel(online_list_model);

    Gui gui(toolbar, chat_widget, send_widget, online_list_view);

    controller.connect(&gui, SIGNAL(send_message(QString const &)), SLOT(invoke_send_message(QString const &)));

    gui.show();
    return application.exec();
}

} // IM

