#ifndef CONTROLLER_TEST_H
#define CONTROLLER_TEST_H

#include <QtCore/QObject>

class ControllerTest : public QObject
{
    Q_OBJECT

private slots:
    void invoke_send_message_sends_signal_send_message();
};

#endif // CONTROLLER_TEST_H
