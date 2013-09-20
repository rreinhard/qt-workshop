#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "application-cpp/eventlist.h"

#include "eventlist_integration.h"

void EventListIntegration::a_hoster_goes_offline()
{
    EventList testee;

    const QString expected_user = "Dave";
    const QString expected_event = "Beer";
    testee.update_event(expected_user, expected_event);

    IM::Events result = testee.get_active_events();
    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first().nick_name, expected_user);
    QCOMPARE(result.first().event_name, expected_event);

    QSignalSpy block_and(this, SIGNAL(dummy()));
    block_and.wait(7800);

    result = testee.get_active_events();

    QCOMPARE(result.size(), 0);
}

void EventListIntegration::a_hoster_stops_updating()
{
    EventList testee;

    const QString expected_user = "Dave";
    const QString expected_event = "Beer";
    testee.update_event(expected_user, expected_event);

    IM::Events result = testee.get_active_events();
    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first().nick_name, expected_user);
    QCOMPARE(result.first().event_name, expected_event);

    QSignalSpy block_and(this, SIGNAL(dummy()));

    block_and.wait(4000);
    testee.update_event(expected_user, expected_event);
    result = testee.get_active_events();
    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first().nick_name, expected_user);
    QCOMPARE(result.first().event_name, expected_event);

    block_and.wait(4000);
    testee.update_event(expected_user, expected_event);
    result = testee.get_active_events();
    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first().nick_name, expected_user);
    QCOMPARE(result.first().event_name, expected_event);

    block_and.wait(7800);

    result = testee.get_active_events();

    QCOMPARE(result.size(), 0);
}
