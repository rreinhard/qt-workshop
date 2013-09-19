#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "application-cpp/onlinelist.h"

#include "onlinelist_integration.h"

void OnlineListIntegration::a_user_goes_offline()
{
    OnlineList testee;

    const QString expected_user = "Dave";
    testee.update_user(expected_user);

    QStringList result = testee.get_online_users();
    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first(), expected_user);

    QSignalSpy block_and(this, SIGNAL(dummy()));
    block_and.wait(7800);

    result = testee.get_online_users();

    QCOMPARE(result.size(), 0);
}

void OnlineListIntegration::a_user_stops_updating()
{
    OnlineList testee;

    const QString expected_user = "Dave";
    testee.update_user(expected_user);

    QStringList result = testee.get_online_users();
    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first(), expected_user);

    QSignalSpy block_and(this, SIGNAL(dummy()));

    block_and.wait(4000);
    testee.update_user(expected_user);
    result = testee.get_online_users();
    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first(), expected_user);

    block_and.wait(4000);
    testee.update_user(expected_user);
    result = testee.get_online_users();
    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first(), expected_user);

    block_and.wait(7800);

    result = testee.get_online_users();

    QCOMPARE(result.size(), 0);
}
