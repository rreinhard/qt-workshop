#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QtCore/QObject>
#include <QtCore/QTimer>

namespace IM {

class IUdpSocket;

class Command {
public:
    static quint32 const KeepAlive;
    static quint32 const Message;
    static quint32 const HostEvent;
};

class Communication : public QObject
{
    Q_OBJECT
public:
    Communication(IUdpSocket & udp_socket, QString const & nickname);

public slots:
    void handle_send_message(quint32 command, QString const & message);
    void handle_send_keep_alive_message ();

private:
    IUdpSocket & _udp_socket;
    quint16 _port;
    QString _nickname;
    QTimer _keepalive_timer;
};

} // IM

#endif // COMMUNICATION_H
