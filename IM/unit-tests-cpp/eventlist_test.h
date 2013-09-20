#ifndef EVENTLIST_TEST_H
#define EVENTLIST_TEST_H

#include <QObject>

class EventList_Test : public QObject
{
    Q_OBJECT
public:
    explicit EventList_Test(QObject *parent = 0);

private slots:

    void adding_a_new_event();
    void updating_an_event();
    void adding_lots_of_events();

};

#endif // EVENTLIST_TEST_H
