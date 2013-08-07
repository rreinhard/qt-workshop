#include "messenger/udp_socket.h"

namespace IM {

UdpSocket::UdpSocket() :
    _udp_socket()
{
}

qint64 UdpSocket::writeDatagram(const QByteArray & datagram, const QHostAddress & host, quint16 port)
{
    return _udp_socket.writeDatagram(datagram, host, port);
}

} // IM

