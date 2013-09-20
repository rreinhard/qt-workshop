#ifndef COMMUNICATION_TEST_H
#define COMMUNICATION_TEST_H

#include <QObject>

class CommunicationTest : public QObject
{
    Q_OBJECT

private slots:
    void handle_send_message_broadcasts_the_message_over_udp();
    void send_keep_alive_message_broadcasts_the_keep_alive_message_over_udp();
    void set_nickname_and_send_message_broadcasts_the_message_over_udp_with_correct_nickname_set();
    void received_keep_alive_test();
    void received_message_test();
    void received_host_event_test();
};

#endif // COMMUNICATION_TEST_H
