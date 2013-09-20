#include <QDebug>
#include <QDataStream>

#include "messenger/udp_socket.h"

namespace IM {

UdpSocket::UdpSocket(quint16 port) :
    _udp_socket(),
    _port(port)
{
    _udp_socket.bind(_port, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    connect(&_udp_socket, SIGNAL(readyRead()), SLOT(receivedUdpFrame()));
}

UdpSocket::~UdpSocket()
{}

qint64 UdpSocket::writeDatagram(const QByteArray & datagram, const QHostAddress & host, quint16 port)
{
    return _udp_socket.writeDatagram(datagram, host, port);
}

void UdpSocket::receivedUdpFrame()
{
    qint64 size_max = 1024 * 32;
    char tmp[size_max];
    QHostAddress hostaddr = QHostAddress(QHostAddress::Broadcast);
    quint16 port = _port;

    int recvd_bytes = _udp_socket.readDatagram(tmp, size_max, &hostaddr, &port);
    while (recvd_bytes != -1)
    {
        QByteArray datagram = QByteArray(tmp, recvd_bytes);
        emit receivedDatagramm(datagram);
        recvd_bytes = _udp_socket.readDatagram(tmp, size_max, &hostaddr, &port);
    }
}

} // IM

