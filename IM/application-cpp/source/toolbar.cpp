#include "application-cpp/toolbar.h"

#include <QtWidgets/QPushButton>

namespace IM {

Toolbar::Toolbar(QPushButton * event_button, QPushButton * settings_button) :
    QWidget(nullptr),
    _layout(),
    _event_button(event_button),
    _settings_button(settings_button)
{
    _layout.addWidget(_event_button);
    _layout.addWidget(_settings_button);
    setLayout(&_layout);

    //connect(_send_button, SIGNAL(clicked()), SLOT(handle_send_button_clicked()));
}

void Toolbar::handle_send_button_clicked()
{
    //if(!_message_input->text().isEmpty()) {
    //    emit send_message(_message_input->text());
    //    _message_input->clear();
    //}
}

} // IM

