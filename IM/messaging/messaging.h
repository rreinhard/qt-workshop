#ifndef MESSAGING_H
#define MESSAGING_H

#include <QtNetwork/QUdpSocket>

class Messaging : public QObject
{
    Q_OBJECT

public:
    Messaging();

public slots:
    void start();
    void broadcast();
    void readDatagrams();

private:
    QUdpSocket _udpSocket;
};

#endif // MESSAGING_H
