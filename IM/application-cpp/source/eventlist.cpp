#include "application-cpp/eventlist.h"

EventList::EventList(QObject *parent) :
    QObject(parent),
    _update_timer()
{
    connect(&_update_timer, SIGNAL(timeout()), this, SLOT(update_timestamps()));
    _update_timer.start(500);
}

void EventList::update_event(QString const & nickname, QString const & eventname)
{
    bool found_event = false;
    QTime now = QTime::currentTime();

    for(auto iterator = _active_events.begin(); iterator != _active_events.end(); iterator++)
    {
        if((iterator->first.nick_name == nickname)&&(iterator->first.event_name == eventname))
        {
            iterator->second = now;
            found_event = true;
            break;
        }
    }

    if(!found_event)
    {
        _active_events.append(Event_entry(IM::EventData(nickname, eventname), now));
        emit list_changed(get_active_events());
    }
}

void EventList::update_timestamps()
{
    bool listchanged = false;
    if (_active_events.empty())
        return;

    QTime now = QTime::currentTime();
    QMutableListIterator<Event_entry> i(_active_events);

    while (i.hasNext())
    {
        if(i.next().second.addSecs(7) < now)
        {
            i.remove();
            listchanged = true;
        }
    }

    if (listchanged)
    {
        IM::Events event_list = get_active_events();
        emit list_changed(event_list);
    }
}

IM::Events EventList::get_active_events()
{
    IM::Events result;
    for(auto iterator = _active_events.begin(); iterator != _active_events.end(); iterator++)
    {
        result.append(iterator->first);
    }
    return result;
}
