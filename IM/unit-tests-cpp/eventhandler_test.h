#ifndef EVENTHANDLER_TEST_H
#define EVENTHANDLER_TEST_H

#include <QObject>

class EventHandler_Test : public QObject
{
    Q_OBJECT
public:
    explicit EventHandler_Test(QObject *parent = 0);

private slots:
    void create_event_test();
    void remove_event_test();
};

#endif // EVENTHANDLER_TEST_H
