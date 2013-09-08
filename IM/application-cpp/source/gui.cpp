#include "application-cpp/gui.h"

namespace IM {

Gui::Gui(QLineEdit & message_input, QPushButton & send_button) :
    QObject(nullptr),
    _window(),
    _layout(),
    _message_input(message_input),
    _send_button(send_button)
{
    connect(&_send_button, SIGNAL(clicked()), SLOT(handle_send_button_clicked()));
}

void Gui::show()
{
    _layout.addWidget(&_message_input);
    _layout.addWidget(&_send_button);

    _window.setLayout(&_layout);
    _window.show();
}

void Gui::handle_send_button_clicked()
{
    if(!_message_input.text().isEmpty()) {
        emit send_message(_message_input.text());
    }
    _message_input.clear();
}

} // IM

