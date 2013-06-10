#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QObject>

class Transport : public QObject
{
    Q_OBJECT
public:
    explicit Transport(QObject *parent = nullptr);
    
signals:
    void receive(QByteArray data);
    
public slots:
    void send(QByteArray data);
    
};

#endif // TRANSPORT_H
