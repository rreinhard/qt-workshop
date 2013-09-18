#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

class QLineEdit;
class QPushButton;
class QTextEdit;


namespace IM {

class SendWidget;
class Toolbar;

class Gui: public QObject {
    Q_OBJECT

public:
    Gui(Toolbar *toolbar, QTextEdit * chat_widget, SendWidget *send_widget);

    void show();

private:
    QWidget _window;
    Toolbar* _toolbar;
    SendWidget* _send_widget;
    QTextEdit * _chat_widget;
    QVBoxLayout _main_layout;
    QHBoxLayout _event_layout;
    QVBoxLayout _chat_layout;
};

} // IM

#endif // GUI_H
