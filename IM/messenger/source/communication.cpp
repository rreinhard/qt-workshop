#include <QtCore/QDataStream>
#include <QtNetwork/QHostAddress>
#include <QtCore/QDebug>

#include "messenger/iudp_socket.h"
#include "messenger/communication.h"

namespace IM {

quint32 const Command::KeepAlive = 0;
quint32 const Command::Message = 1;
quint32 const Command::HostEvent = 2;

Communication::Communication(IUdpSocket & udp_socket, const QString & nickname, quint16 port) :
    _udp_socket(udp_socket),
    _port(port),
    _nickname(nickname),
    _keepalive_timer()
{
    connect (&_keepalive_timer, SIGNAL(timeout()), SLOT(handle_send_keep_alive_message()));
    connect (&_udp_socket, SIGNAL(receivedDatagramm(QByteArray&)), SLOT(handle_received_datagramm(QByteArray&)));
    const quint32 keep_alive_signal_periode = 5000;
    _keepalive_timer.start(keep_alive_signal_periode);
}

void Communication::handle_send_message(quint32 command, const QString & message)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);

    stream << command;
    stream << _nickname;
    stream << message;

    _udp_socket.writeDatagram(data, QHostAddress::Broadcast, _port);
    qDebug() << "nickname: " << _nickname << "message: " << message;
}

void Communication::handle_send_keep_alive_message ()
{
    if (_nickname.isEmpty())
        return;

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << Command::KeepAlive;
    stream << _nickname;

    _udp_socket.writeDatagram(data, QHostAddress::Broadcast, _port);

}

void Communication::handle_set_nickname (QString const & nickname)
{
  _nickname = nickname;
}

void Communication::handle_received_datagramm(QByteArray & datagram)
{
    QDataStream stream(&datagram, QIODevice::ReadOnly);
    quint32 cmd;
    QString name;

    stream.setVersion(QDataStream::Qt_5_0);
    stream >> cmd;
    stream >> name;

    switch (cmd)
    {
        case Command::KeepAlive:
            emit received_keep_alive(name);
            break;

        case Command::Message:
        {
            QString message_data;
            stream >> message_data;
            emit received_message(name, message_data);
        }
            break;

        case Command::HostEvent:
        {
            QString message_data;
            stream >> message_data;
            emit received_host_event(name, message_data);
        }
            break;
    }

    qDebug() << "Received: " << cmd << name;
}

} // IM

