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
    Communication(IUdpSocket & udp_socket, QString const & nickname, quint16 port);
    QString get_nickname() const;

public slots:
    void handle_send_message(quint32 command, QString const & message);
    void handle_send_keep_alive_message ();
    void handle_set_nickname(QString const & nickname);

public slots:
    void handle_received_datagramm(QByteArray &datagram);


signals:
    void received_keep_alive(QString nickname);
    void received_message(QString const & nickname, QString const & message);

private:
    IUdpSocket & _udp_socket;
    const quint16 _port;
    QString _nickname;
    QTimer _keepalive_timer;
};

inline QString Communication::get_nickname() const
{
    return _nickname;
}

} // IM

#endif // COMMUNICATION_H
