#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>

#include "messenger/iudp_socket.h"

namespace IM {
// ,
class UdpSocket : public IUdpSocket
{
 Q_OBJECT

public:
    UdpSocket(quint16 port);
    ~UdpSocket();
    virtual qint64 writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port) override final;



private slots:
    void receivedUdpFrame();

private:
    QUdpSocket _udp_socket;
    const quint16 _port;
};

} // IM

#endif // UDP_SOCKET_H
