#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <messenger/communication.h>

#include "stubs/qudpsocket_stub.h"

#include "communication_integration.h"

void CommunicationIntegration::keep_alive_message_should_be_sent_every_5_seconds()
{
    const QString expected_nickname = "Name";

    // arrange
    qRegisterMetaType<QHostAddress>("QHostAddress");
    QUdpSocketStub udp_socket;
    QSignalSpy writeDatagram(&udp_socket, SIGNAL(called_writeDatagram(QByteArray const &, QHostAddress const &, quint16)));

    // act
    IM::Communication testee(udp_socket, expected_nickname, 41000);

    const quint32 keep_alive_signal_periode = 10000;
    writeDatagram.wait(keep_alive_signal_periode);

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


void CommunicationIntegration::no_keep_alive_if_empty_name()
{
    const QString expected_nickname;

    // arrange
    qRegisterMetaType<QHostAddress>("QHostAddress");
    QUdpSocketStub udp_socket;
    QSignalSpy writeDatagram(&udp_socket, SIGNAL(called_writeDatagram(QByteArray const &, QHostAddress const &, quint16)));

    // act
    IM::Communication testee(udp_socket, expected_nickname, 41000);

    const quint32 keep_alive_signal_periode = 10000;
    writeDatagram.wait(keep_alive_signal_periode);

    // assert
    QCOMPARE(writeDatagram.count(), 0);
}
