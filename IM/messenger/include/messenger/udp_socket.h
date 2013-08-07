#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include <QtNetwork/QUdpSocket>

#include "messenger/iudp_socket.h"

namespace IM {

class UdpSocket : public IUdpSocket
{
public:
    UdpSocket();

    virtual qint64 writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port) override final;

private:
    QUdpSocket _udp_socket;
};

} // IM

#endif // UDP_SOCKET_H
