#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <messenger/communication.h>

#include "mocks/qudpsocket_mock.h"
#include "communication_test.h"

void CommunicationTest::handle_send_message_broadcasts_the_message_over_udp()
{
    // arrange
    qRegisterMetaType<QHostAddress>("QHostAddress");
    QUdpSocketMock udp_socket;
    QSignalSpy writeDatagram(&udp_socket, SIGNAL(called_writeDatagram(QByteArray const &, QHostAddress const &, quint16)));

    // act
    const QString expected_nickname = "Name";
    IM::Communication testee(udp_socket, expected_nickname);
    const QString expected_message = "Hello world.";
    testee.handle_send_message(expected_message);

    // assert
    QCOMPARE(writeDatagram.count(), 1);

    const auto arguments = writeDatagram.takeFirst();
    QDataStream data(arguments.at(0).toByteArray());

    quint32 command;
    QString nickname;
    QString message;
    data >> command >> nickname >> message;

    const quint32 expected_command = IM::Command::Message;
    QCOMPARE(command, expected_command);
    QCOMPARE(nickname, expected_nickname);
    QCOMPARE(message, expected_message);

    const QHostAddress expected_address = QHostAddress::Broadcast;
    QCOMPARE(qvariant_cast<QHostAddress>(arguments.at(1)), expected_address);

    const quint32 expected_port = 41000;
    QCOMPARE(arguments.at(2).toUInt(), expected_port);
}

void CommunicationTest::send_keep_alive_message_over_udp ()
{
    const QString expected_nickname = "Name";

    // arrange
    qRegisterMetaType<QHostAddress>("QHostAddress");
    QUdpSocketMock udp_socket;
    QSignalSpy writeDatagram(&udp_socket, SIGNAL(called_writeDatagram(QByteArray const &, QHostAddress const &, quint16)));

    // act
    IM::Communication testee(udp_socket, expected_nickname);

    testee.handle_send_keep_alive_message();

    // assert
    QCOMPARE(writeDatagram.count(), 1);

    const auto arguments = writeDatagram.takeFirst();
    QDataStream data(arguments.at(0).toByteArray());



    const QHostAddress expected_address = QHostAddress::Broadcast;
    QCOMPARE(qvariant_cast<QHostAddress>(arguments.at(1)), expected_address);

    const quint32 expected_port = 41000;
    QCOMPARE(arguments.at(2).toUInt(), expected_port);

    quint32 command;
    QString nickname;
    data >> command >> nickname;

    const quint32 expected_command = IM::Command::KeepAlive;
    QCOMPARE(command, expected_command);
    QCOMPARE(nickname, expected_nickname);
}

