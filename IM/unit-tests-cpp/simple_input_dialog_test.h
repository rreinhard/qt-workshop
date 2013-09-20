#ifndef SETNICKNAMETEST_H
#define SETNICKNAMETEST_H

#include <QObject>

class QPushButton;
class QLineEdit;

class SimpleInputDialogTest : public QObject
{
    Q_OBJECT
    
private slots:
    void clicking_the_button_signals_set_input_with_the_text_from_the_input_field();
    void clicking_the_button_does_not_signal_set_input_when_the_input_field_is_empty();
    
};

#endif // SETNICKNAMETEST_H
