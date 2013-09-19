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

void OnlineList_Test::adding_a_user_again()
{
    OnlineList testee;

    const QString expected_user = "Dave";

    testee.update_user(expected_user);
    testee.update_user(expected_user);

    QStringList result = testee.get_online_users();

    QCOMPARE(result.size(), 1);
    QCOMPARE(result.first(), expected_user);
}

void OnlineList_Test::adding_lots_of_users()
{
    OnlineList testee;

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

    testee.update_user(expected_user1);
    testee.update_user(expected_user2);
    testee.update_user(expected_user3);
    testee.update_user(expected_user4);
    testee.update_user(expected_user5);
    testee.update_user(expected_user6);
    testee.update_user(expected_user7);
    testee.update_user(expected_user8);
    testee.update_user(expected_user9);
    testee.update_user(expected_user10);

    QStringList result = testee.get_online_users();

    QCOMPARE(result.size(), 10);
    QCOMPARE(result.first(), expected_user1);
    QCOMPARE(result.last(), expected_user10);

}
