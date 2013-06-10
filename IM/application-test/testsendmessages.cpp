#include "testsendmessages.h"

#include "messaging.h"

#include <QtTest/QSignalSpy>
#include <QtTest/QTest>

TestSendMessages::TestSendMessages() :
    QObject(nullptr)
{
}

void TestSendMessages::empty_message_shall_not_be_sent()
{
    Messaging messaging;
    connect(this, SIGNAL(send_message(QString())), &messaging, SLOT(send_message(QString)));

    emit send_message("");

    QSignalSpy transport(&messaging, SIGNAL(send(QByteArray)));

    QCOMPARE(transport.wait(1000), false);
    QCOMPARE(transport.count(), 0);
}
