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

    QSignalSpy abc(this, SIGNAL(dummy()));
    abc.wait(7800);

    result = testee.get_online_users();

    QCOMPARE(result.size(), 0);
}
