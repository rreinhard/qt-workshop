#include <QtTest/QTest>
#include <QtTest/QSignalSpy>
#include <QtCore/QTimer>

#include "eventlist_test.h"
#include "application-cpp/eventlist.h"

EventList_Test::EventList_Test(QObject *parent) :
    QObject(parent)
{
}

void EventList_Test::adding_a_new_event()
{
    EventList testee;

    const QString expected_user = "Dave";
    const QString expected_event = "Beer";
    testee.update_event(expected_user, expected_event);

    IM::Events result = testee.get_active_events();

    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first().nick_name, expected_user);
    QCOMPARE(result.first().event_name, expected_event);
}

void EventList_Test::updating_an_event()
{
    EventList testee;

    const QString expected_user = "Dave";
    const QString expected_event = "Beer";

    testee.update_event(expected_user, expected_event);
    testee.update_event(expected_user, expected_event);

    IM::Events result = testee.get_active_events();

    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first().nick_name, expected_user);
    QCOMPARE(result.first().event_name, expected_event);
}

void EventList_Test::adding_lots_of_events()
{
    EventList testee;

    const QString expected_user = "Dave";
    const QString expected_user1 = "Dave1";
    const QString expected_user2 = "Dave2";
    const QString expected_user3 = "Dave3";
    const QString expected_user4 = "Dave4";
    const QString expected_user5 = "Dave5";
    const QString expected_user6 = "Dave6";
    const QString expected_user7 = "Dave7";
    const QString expected_user8 = "Dave8";
    const QString expected_user9 = "Dave9";
    const QString expected_user10 = "Dave10";

    testee.update_event(expected_user, expected_user1);
    testee.update_event(expected_user, expected_user2);
    testee.update_event(expected_user, expected_user3);
    testee.update_event(expected_user, expected_user4);
    testee.update_event(expected_user, expected_user5);
    testee.update_event(expected_user, expected_user6);
    testee.update_event(expected_user, expected_user7);
    testee.update_event(expected_user, expected_user8);
    testee.update_event(expected_user, expected_user9);
    testee.update_event(expected_user, expected_user10);

    IM::Events result = testee.get_active_events();

    QCOMPARE(result.size(), 10);
    QCOMPARE(result.first().event_name, expected_user1);
    QCOMPARE(result.last().event_name, expected_user10);

}
