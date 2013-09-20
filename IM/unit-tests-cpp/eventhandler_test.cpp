
#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "application-cpp/eventhandler.h"

#include "eventhandler_test.h"

EventHandler_Test::EventHandler_Test(QObject *parent) :
    QObject(parent)
{
}

void EventHandler_Test::create_event_test()
{
    IM::EventHandler testee;

    IM::EventData data = testee.get_event();

    QCOMPARE(data.active, false);

    const QString expected_eventname = "Event Name";

    QSignalSpy signal_spy(&testee, SIGNAL(send_event_message(QString const &)));

    testee.create_event(expected_eventname);
    data = testee.get_event();

    QCOMPARE(data.active, true);
    QCOMPARE(data.event_name, expected_eventname);

    signal_spy.wait(50);

    const auto arguments = signal_spy.takeFirst();
    QCOMPARE(arguments.size(), 1);
    QCOMPARE(arguments.at(0).toString(), expected_eventname);
}

void EventHandler_Test::remove_event_test()
{
    IM::EventHandler testee;

    const QString expected_eventname = "Event Name";

    testee.create_event(expected_eventname);

    IM::EventData data = testee.get_event();

    QCOMPARE(data.active, true);

    testee.remove_event();

    data = testee.get_event();

    QCOMPARE(data.active, false);
}
