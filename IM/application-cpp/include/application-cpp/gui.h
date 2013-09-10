#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>

class QLineEdit;
class QPushButton;

namespace IM {

class Gui: public QObject {
    Q_OBJECT

public:
    Gui(QLineEdit * message_input, QPushButton * send_button);

    void show();

public slots:
    void handle_send_button_clicked();

signals:
    void send_message(QString const & message);

private:
    QWidget _window;
    QHBoxLayout _layout;

    QLineEdit * _message_input;
    QPushButton * _send_button;
};

} // IM

#endif // GUI_H
