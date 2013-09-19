#ifndef SEND_WIDGET_TEST_H
#define SEND_WIDGET_TEST_H

#include <QtCore/QObject>

class QPushButton;
class QLineEdit;

class SendWidgetTest : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void clicking_the_send_button_signals_send_message_with_the_message_from_the_input_field();
    void clicking_the_send_button_does_not_signal_send_message_when_the_input_field_is_empty();
    void clicking_the_send_button_clears_the_input_field_is_empty();

private:
    QPushButton * _send_button;
    QLineEdit * _message_input;
};

#endif // SEND_WIDGET_TEST_H
