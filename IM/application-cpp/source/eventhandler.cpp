#include "application-cpp/eventhandler.h"

namespace IM
{

EventHandler::EventHandler(QObject *parent) :
    QObject(parent),
    _eventData(),
    _sendCycle(5000)
{
    connect(&_sendTimer, SIGNAL(timeout()), SLOT(resend_message()));
}

void EventHandler::create_event(QString eventname)
{
    _eventData.active = true;
    _eventData.event_name = eventname;

    _sendTimer.start(_sendCycle);
    emit send_event_message(_eventData.event_name);
}

void EventHandler::remove_event()
{
    _eventData.active = false;
    _sendTimer.stop();
}

void EventHandler::resend_message()
{
    emit send_event_message(_eventData.event_name);
}

} //namespace IM
