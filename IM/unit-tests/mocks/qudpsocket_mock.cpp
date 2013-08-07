#include <QtCore/QByteArray>

#include "qudpsocket_mock.h"

qint64 QUdpSocketMock::writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port)
{
    emit called_writeDatagram(datagram, host, port);
    return datagram.size();
}

