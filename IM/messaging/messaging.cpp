#include "messaging.h"

#include <QtCore/QTimer>

Messaging::Messaging()
    : _udpSocket(this)
{
}

void Messaging::start()
{
    qDebug() << "start";

    _udpSocket.bind(QHostAddress::Broadcast, 41000);
    connect(&_udpSocket, SIGNAL(readyRead()), this, SLOT(readDatagrams()));

    QTimer::singleShot(1000, this, SLOT(broadcast()));

}

void Messaging::broadcast()
{
    qDebug() << "broadcast";

    QByteArray datagram;
    datagram.append("Hello world");
    _udpSocket.writeDatagram(datagram, QHostAddress::Broadcast, 41000);

    QTimer::singleShot(2000, this, SLOT(broadcast()));
}

void Messaging::readDatagrams()
{
    while(_udpSocket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(_udpSocket.pendingDatagramSize());
        QHostAddress sender;
        quint16 port;

        _udpSocket.readDatagram(datagram.data(), datagram.size(), &sender, &port);

        qDebug() << "Read " << sender << " " << port;
    }
}
