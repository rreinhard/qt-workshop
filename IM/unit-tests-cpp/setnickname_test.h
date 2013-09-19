#ifndef SETNICKNAMETEST_H
#define SETNICKNAMETEST_H

#include <QObject>

class QPushButton;
class QLineEdit;

class SetNicknameTest : public QObject
{
    Q_OBJECT
    
private slots:
    void clicking_the_set_button_signals_set_nickname_with_the_name_from_the_input_field();
    void clicking_the_set_button_does_not_signal_set_nickname_when_the_input_field_is_empty();
    
};

#endif // SETNICKNAMETEST_H
