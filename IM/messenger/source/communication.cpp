#include <QtCore/QDataStream>
#include <QtNetwork/QHostAddress>

#include "messenger/iudp_socket.h"
#include "messenger/communication.h"

namespace IM {

quint32 const Command::KeepAlive = 0;
quint32 const Command::Message = 1;
quint32 const Command::HostEvent = 2;

Communication::Communication(IUdpSocket & udp_socket) :
    _udp_socket(udp_socket),
    _port(41000)
{
}

void Communication::handle_send_message(quint32 command, const QString & nickname, const QString & message)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);

    stream << command;
    stream << nickname;
    stream << message;

    _udp_socket.writeDatagram(data, QHostAddress::Broadcast, _port);
}

} // IM

