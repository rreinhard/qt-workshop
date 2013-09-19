#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>

class QPushButton;

namespace IM {

class Toolbar: public QWidget {
    Q_OBJECT

public:
    Toolbar(QPushButton * event_button, QPushButton * settings_button);

public slots:
    void handle_send_button_clicked();

signals:
    void send_message(QString const & message);

private:
    QWidget _window;
    QHBoxLayout _layout;

    QPushButton * _event_button;
    QPushButton * _settings_button;
};

} // IM

#endif // TOOLBAR_H
