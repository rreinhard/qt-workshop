#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <QString>
#include <QList>

namespace  IM
{

struct EventData
{
    EventData() :
        active(false)
    {}

    EventData(QString nick_name_, QString event_name_) :
        active(true),
        nick_name(nick_name_),
        event_name(event_name_)
    {}

    bool active;
    QString nick_name;
    QString event_name;
};

typedef QList<EventData> Events;

} //namespace  IM


#endif // DATASTRUCTURES_H
