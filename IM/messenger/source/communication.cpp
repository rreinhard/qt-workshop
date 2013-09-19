#include <QtCore/QDataStream>
#include <QtNetwork/QHostAddress>

#include "messenger/iudp_socket.h"
#include "messenger/communication.h"

namespace IM {

quint32 const Command::KeepAlive = 0;
quint32 const Command::Message = 1;
quint32 const Command::HostEvent = 2;

Communication::Communication(IUdpSocket & udp_socket, const QString & nickname) :
    _udp_socket(udp_socket),
    _port(41000),
    _nickname(nickname),
    _keepalive_timer()
{
    connect (&_keepalive_timer, SIGNAL(timeout()), this, SLOT(handle_send_keep_alive_message()));
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
}

void Communication::handle_send_keep_alive_message ()
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << Command::KeepAlive;
    stream << _nickname;

    _udp_socket.writeDatagram(data, QHostAddress::Broadcast, _port);

}

} // IM

