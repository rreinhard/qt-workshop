#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <messenger/communication.h>

#include "application-cpp/sendwidget.h"



namespace IM {

SendWidget::SendWidget(QLineEdit * message_input, QPushButton * send_button, QWidget *parent) :
    QWidget(parent),
    _message_input(message_input),
    _send_button(send_button)
{
  _layout.addWidget(_message_input);
  _layout.addWidget(_send_button);
  setLayout(&_layout);
  connect(_send_button, SIGNAL(clicked()), SLOT(handle_send_button_clicked()));
  connect(_message_input, SIGNAL(returnPressed()), SLOT(handle_send_button_clicked()));
}


void SendWidget::handle_send_button_clicked()
{
    if(!_message_input->text().isEmpty()) {
        emit send_message(Command::Message, _message_input->text());
        _message_input->clear();
    }
}


} //namespace IM
