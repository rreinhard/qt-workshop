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
    IM::Communication testee(udp_socket, expected_nickname, 41000);
    const QString expected_message = "Hello world.";
    testee.handle_send_message(IM::Command::Message, expected_message);

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

void CommunicationTest::send_keep_alive_message_broadcasts_the_keep_alive_message_over_udp ()
{
    const QString expected_nickname = "Name";

    // arrange
    qRegisterMetaType<QHostAddress>("QHostAddress");
    QUdpSocketMock udp_socket;
    QSignalSpy writeDatagram(&udp_socket, SIGNAL(called_writeDatagram(QByteArray const &, QHostAddress const &, quint16)));

    // act
    IM::Communication testee(udp_socket, expected_nickname, 41000);

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

void CommunicationTest::set_nickname_and_send_message_broadcasts_the_message_over_udp_with_correct_nickname_set ()
{
    // arrange
    qRegisterMetaType<QHostAddress>("QHostAddress");
    QUdpSocketMock udp_socket;
    QSignalSpy writeDatagram(&udp_socket, SIGNAL(called_writeDatagram(QByteArray const &, QHostAddress const &, quint16)));

    // act
    const QString expected_nickname = "BugsBunny";
    IM::Communication testee(udp_socket, "Dummy", 41000);

    testee.handle_set_nickname(expected_nickname);
    const QString expected_message = "Hello world.";
    testee.handle_send_message(IM::Command::Message, expected_message);

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


void CommunicationTest::received_keep_alive_test()
{
    const QString expected_nickname = "Name";

    // arrange
    QUdpSocketMock udp_socket;
    const quint32 expected_command = IM::Command::KeepAlive;

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << expected_command;
    stream << expected_nickname;

    // act
    IM::Communication testee(udp_socket, expected_nickname, 41000);

    QSignalSpy rcvd_kee_alive(&testee, SIGNAL(received_keep_alive(QString )));

    testee.handle_received_datagramm(data);

    // assert
    QCOMPARE(rcvd_kee_alive.count(), 1);

    const auto arguments = rcvd_kee_alive.takeFirst();
    QString str(arguments.at(0).toString());

    QCOMPARE(str, expected_nickname);
}

void CommunicationTest::received_message_test()
{
    const QString expected_nickname = "Name";
    const QString expected_data = "Message Data";

    // arrange
    QUdpSocketMock udp_socket;
    const quint32 expected_command = IM::Command::Message;

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << expected_command;
    stream << expected_nickname;
    stream << expected_data;

    // act
    IM::Communication testee(udp_socket, expected_nickname, 41000);

    QSignalSpy rcvd_keep_alive(&testee, SIGNAL(received_message(QString const &, QString const & )));

    testee.handle_received_datagramm(data);

    // assert
    QCOMPARE(rcvd_keep_alive.count(), 1);

    const auto arguments = rcvd_keep_alive.takeFirst();
    QCOMPARE(arguments.size(), 2);

    QString str(arguments.at(0).toString());
    QString msg_data(arguments.at(1).toString());

    QCOMPARE(str, expected_nickname);
    QCOMPARE(msg_data, expected_data);
}

void CommunicationTest::received_host_event_test()
{
    const QString expected_nickname = "Name";
    const QString expected_data = "Message Data";

    // arrange
    QUdpSocketMock udp_socket;
    const quint32 expected_command = IM::Command::HostEvent;

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << expected_command;
    stream << expected_nickname;
    stream << expected_data;

    // act
    IM::Communication testee(udp_socket, expected_nickname, 41000);

    QSignalSpy rcvd_keep_alive(&testee, SIGNAL(received_host_event(QString const &, QString const & )));

    testee.handle_received_datagramm(data);

    // assert
    QCOMPARE(rcvd_keep_alive.count(), 1);

    const auto arguments = rcvd_keep_alive.takeFirst();
    QCOMPARE(arguments.size(), 2);

    QString str(arguments.at(0).toString());
    QString msg_data(arguments.at(1).toString());

    QCOMPARE(str, expected_nickname);
    QCOMPARE(msg_data, expected_data);
}
