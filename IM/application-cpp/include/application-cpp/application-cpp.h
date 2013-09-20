#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtCore/QObject>
#include <QtCore/QStringList>
#include <QtCore/QStringListModel>

class QTextEdit;

class OnlineList;
class EventList;

namespace IM {

class Communication;
class EventHandler;

class Application : public QObject
{
    Q_OBJECT
public:
    Application();

    int execute(int argc, char * argv[]);

private slots:
    void update_Model();
    void received_message(QString const & nickname, QString const & message);
    void send_event_message(QString const & event_name);

private:
    QStringListModel* _online_list_model;
    QTextEdit* _chat_widget;
    Communication* _communication;
    EventHandler* _eventhandler;
    OnlineList* _onlinelist;
    EventList* _eventList;
};

} // IM

#endif // APPLICATION_H
