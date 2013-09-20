#ifndef EVENTLIST_INTEGRATION_H
#define EVENTLIST_INTEGRATION_H

#include <QObject>

class EventListIntegration : public QObject
{
    Q_OBJECT
    
private slots:
    void a_hoster_goes_offline();
    void a_hoster_stops_updating();

signals:
    void dummy();

};

#endif // ONLINELIST_INTEGRATION_H
