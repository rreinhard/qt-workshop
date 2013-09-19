#ifndef COMMUNICATION_INTEGRATION_H
#define COMMUNICATION_INTEGRATION_H

#include <QObject>

class CommunicationIntegration : public QObject
{
    Q_OBJECT
    
private slots:
    void keep_alive_message_should_be_sent_every_5_seconds();
    
};

#endif // COMMUNICATION_INTEGRATION_H
