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
#include "application-cpp/onlinelist.h"
#include "application-cpp/set_nickname_dialog.h"

namespace IM {

Application::Application() :
    QObject() ,
    _online_list_model(new QStringListModel())
{}

int Application::execute(int argc, char * argv[])
{
    QApplication application(argc, argv);

    const quint16 port = 41000;

    UdpSocket udpSocket(port);
    Communication communication(udpSocket, "Dummy", port);


    OnlineList onlinelist;

    connect(&communication, SIGNAL(received_keep_alive(QString)), &onlinelist, SLOT(update_user(QString)));
    connect(&onlinelist, SIGNAL(list_changed(QStringList)), SLOT(update_Model(QStringList)));

    _chat_widget = new QTextEdit();
    _chat_widget->setReadOnly(true);


    QPushButton * settings_button = new QPushButton("settings");

    QPushButton * set_button = new QPushButton("set nickname");
    QLineEdit * nickname_input = new QLineEdit(communication.get_nickname());

    const QString set_nickname_dialog_title("Set nickname");

    SimpleInputDialog set_nickname_dialog(set_nickname_dialog_title, nickname_input, set_button);

    set_nickname_dialog.setModal(true);
    QObject::connect(settings_button, SIGNAL(clicked()), &set_nickname_dialog, SLOT(show()));
    communication.connect(&set_nickname_dialog, SIGNAL(set_input(const QString &)), SLOT(handle_set_nickname(const QString &)));


    QPushButton * event_button = new QPushButton("event");
    QPushButton * create_event_button = new QPushButton("create event");
    QLineEdit * eventname_input = new QLineEdit("");

    const QString create_event_dialog_title("Create event");

    SimpleInputDialog create_event_dialog(create_event_dialog_title, eventname_input, create_event_button);

    create_event_dialog.setModal(true);
    QObject::connect(event_button, SIGNAL(clicked()), &create_event_dialog, SLOT(show()));
  //  eventhandler.connect(&create_event_dialog, SIGNAL(set_input(const QString &)), SLOT(handle_set_event(const QString &)));


    Toolbar* toolbar = new Toolbar(event_button, settings_button);

    QPushButton * send_button = new QPushButton("send");
    QLineEdit * message_input = new QLineEdit();
    SendWidget* send_widget = new SendWidget(message_input, send_button);


    QListView* online_list_view = new QListView();
    online_list_view->setModel(_online_list_model);
    _online_list_model->setStringList(onlinelist.get_online_users());

    Gui gui(toolbar, _chat_widget, send_widget, online_list_view);

    communication.connect(send_widget, SIGNAL(send_message(quint32, QString const &)), SLOT(handle_send_message(quint32, QString const &)));
    connect(&communication, SIGNAL(received_message(QString const &, QString const &)), SLOT(received_message(QString const &, QString const &)));

    gui.show();
    return application.exec();
}

void Application::update_Model(QStringList list)
{
    _online_list_model->setStringList(list);
}

void Application::received_message(QString const & nickname, QString const & message)
{
    _chat_widget->append(nickname + ": " + message);
}

} // IM

