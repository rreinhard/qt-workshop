#include <QtCore/QByteArray>

#include "qudpsocket_stub.h"

qint64 QUdpSocketStub::writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port)
{
    emit called_writeDatagram(datagram, host, port);
    return datagram.size();
}

