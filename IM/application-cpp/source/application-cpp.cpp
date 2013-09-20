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
    _online_list_model(new QStringListModel()),
    _communication(nullptr)
{}

int Application::execute(int argc, char * argv[])
{
    QApplication application(argc, argv);

    const quint16 port = 41000;

    UdpSocket udpSocket(port);
    _communication = new Communication(udpSocket, "Dummy", port);


    OnlineList onlinelist;

    connect(_communication, SIGNAL(received_keep_alive(QString)), &onlinelist, SLOT(update_user(QString)));
    connect(&onlinelist, SIGNAL(list_changed(QStringList)), SLOT(update_Model(QStringList)));

    _chat_widget = new QTextEdit();
    _chat_widget->setReadOnly(true);

    QPushButton * event_button = new QPushButton("event");
    QPushButton * settings_button = new QPushButton("settings");

    QPushButton * set_button = new QPushButton("set nickname");
    QLineEdit * nickname_input = new QLineEdit(_communication->get_nickname());

    SetNicknameDialog set_nickname_dialog(nickname_input, set_button);
    set_nickname_dialog.setModal(true);
    QObject::connect(settings_button, SIGNAL(clicked()), &set_nickname_dialog, SLOT(show()));

    _communication->connect(&set_nickname_dialog, SIGNAL(set_nickname(const QString &)), SLOT(handle_set_nickname(const QString &)));

    Toolbar* toolbar = new Toolbar(event_button, settings_button);

    QPushButton * send_button = new QPushButton("send");
    QLineEdit * message_input = new QLineEdit();
    SendWidget* send_widget = new SendWidget(message_input, send_button);


    QListView* online_list_view = new QListView();
    online_list_view->setModel(_online_list_model);
    _online_list_model->setStringList(onlinelist.get_online_users());




    Gui gui(toolbar, _chat_widget, send_widget, online_list_view);

    _communication->connect(send_widget, SIGNAL(send_message(quint32, QString const &)), SLOT(handle_send_message(quint32, QString const &)));
    connect(_communication, SIGNAL(received_message(QString const &, QString const &)), SLOT(received_message(QString const &, QString const &)));

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

void Application::send_event_message(QString const & event_name)
{
    _communication->handle_send_message(Command::HostEvent, event_name);
}

} // IM

