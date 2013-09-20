#ifndef IUDP_SOCKET_H
#define IUDP_SOCKET_H

#include <QtCore/QtGlobal>
#include <QtCore/QObject>

class QHostAddress;
class QByteArray;

namespace IM {

class IUdpSocket : public QObject
{
    Q_OBJECT

public:
    virtual ~IUdpSocket() {}

    virtual qint64 writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port) = 0;

signals:
    void receivedDatagramm(QByteArray & datagram);
};

} // IM

#endif // IUDP_SOCKET_H
