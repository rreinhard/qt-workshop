#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QString>
#include <QTimer>

#include "application-cpp/datastructures.h"

namespace IM
{

class EventHandler : public QObject
{
    Q_OBJECT
public:
    explicit EventHandler(QObject *parent = 0);
    EventData get_event() {return _eventData;}

signals:
    void send_event_message(QString const & eventname);

public slots:
    void create_event(QString eventname);
    void remove_event();

private slots:
    void resend_message();

private:
    QTimer _sendTimer;
    EventData _eventData;
    const int _sendCycle;
};

} // namespace IM

#endif // EVENTHANDLER_H
