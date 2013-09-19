#include <QtTest/QTest>
#include <QtTest/QSignalSpy>
#include <QtCore/QTimer>

#include "onlinelist_test.h"
#include "application-cpp/onlinelist.h"

OnlineList_Test::OnlineList_Test(QObject *parent) :
    QObject(parent)
{
}

void OnlineList_Test::adding_a_single_user()
{
    OnlineList testee;

    const QString expected_user = "Dave";
    testee.update_user(expected_user);

    QStringList result = testee.get_online_users();

    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first(), expected_user);
}

void OnlineList_Test::adding_lots_of_users()
{
    OnlineList testee;

    const QString expected_user = "Dave";
    testee.update_user(expected_user);

    QStringList result = testee.get_online_users();

    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first(), expected_user);

}
