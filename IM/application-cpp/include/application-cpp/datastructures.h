#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <QString>

namespace  IM
{

struct EventData
{
    EventData() :
        active(false)
    {}

    EventData(QString event_name_) :
        active(true),
        event_name(event_name_)
    {}

    bool active;
    QString event_name;
};

} //namespace  IM


#endif // DATASTRUCTURES_H
