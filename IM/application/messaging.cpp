#include "messaging.h"

#include <QtCore/QTimer>
#include <QtCore/QDataStream>

Messaging::Messaging() :
        _udpSocket(this) {
}

void Messaging::start() {
    qDebug() << "start";

    _udpSocket.bind(41000);
    connect(&_udpSocket, SIGNAL(readyRead()), this, SLOT(readDatagrams()));

    QTimer::singleShot(1000, this, SLOT(broadcast()));

}

void Messaging::broadcast() {
    qDebug() << "broadcast";

    QString nick("My Name");

    QByteArray datagram;
    QDataStream stream(&datagram, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << nick;
    stream << Command::KeepAlive;

    _udpSocket.writeDatagram(datagram, QHostAddress::Broadcast, 41000);

    QTimer::singleShot(1000, this, SLOT(broadcast()));
}

void Messaging::readDatagrams() {
    while (_udpSocket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(_udpSocket.pendingDatagramSize());
        QHostAddress sender;
        quint16 port;

        _udpSocket.readDatagram(datagram.data(), datagram.size(), &sender,
                &port);

        QDataStream stream(datagram);
        QString nick;
        quint32 cmd;
        stream >> nick >> cmd;

        qDebug() << "Read " << sender << port << nick << cmd;
    }
}

void Messaging::send_message(QString message) {
    qDebug() << message;


    QString nick("My Name");

    QByteArray datagram;
    QDataStream stream(&datagram, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << nick;
    stream << Command::Message;
    stream << message;

    _udpSocket.writeDatagram(datagram, QHostAddress::Broadcast, 41000);

}

