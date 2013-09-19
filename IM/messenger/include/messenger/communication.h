#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QtCore/QObject>

namespace IM {

class IUdpSocket;

class Command {
public:
    static quint32 const KeepAlive;
    static quint32 const Message;
};

class Communication : public QObject
{
    Q_OBJECT
public:
    Communication(IUdpSocket & udp_socket, QString const & nickname);

public slots:
    void handle_send_message(QString const & message);
    void handle_send_keep_alive_message ();


private:
    IUdpSocket & _udp_socket;
    quint16 _port;
    QString _nickname;
};

} // IM

#endif // COMMUNICATION_H
