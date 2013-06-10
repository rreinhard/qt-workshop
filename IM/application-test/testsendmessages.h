#ifndef TESTSENDMESSAGES_H
#define TESTSENDMESSAGES_H

#include <QObject>

class TestSendMessages : public QObject
{
    Q_OBJECT

public:
    explicit TestSendMessages();
    
signals:
    void send_message(QString message);

private slots:
    void empty_message_shall_not_be_sent();

};

#endif // TESTSENDMESSAGES_H
