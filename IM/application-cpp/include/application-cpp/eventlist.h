#ifndef EVENTLIST_H
#define EVENTLIST_H

#include <QList>
#include <QPair>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <QTime>
#include <QObject>

#include "application-cpp/datastructures.h"

class EventList : public QObject
{
    Q_OBJECT
public:
    explicit EventList(QObject *parent = 0);

    IM::Events get_active_events();

signals:
    void list_changed(IM::Events list);

public slots:
    void update_event(QString const & nickname, QString const & eventname);

private slots:
    void update_timestamps();

private:
    typedef QPair<IM::EventData, QTime> Event_entry;
    typedef QList<Event_entry> Event_list;

    Event_list _active_events;
    QTimer _update_timer;
};

#endif // EVENTLIST_H
