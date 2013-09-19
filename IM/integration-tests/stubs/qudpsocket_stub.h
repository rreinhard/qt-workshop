#ifndef QUDPSOCKET_STUB_H
#define QUDPSOCKET_STUB_H

#include <QtCore/QObject>
#include <QtNetwork/QHostAddress>

#include "messenger/iudp_socket.h"

class QUdpSocketStub : public QObject, public IM::IUdpSocket
{
    Q_OBJECT

public:
    qint64 writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port);

signals:
    void called_writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port);
};

Q_DECLARE_METATYPE(QHostAddress);

#endif // QUDPSOCKET_STUB_H
