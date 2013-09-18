#include "application-cpp/sendwidget.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

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
}


void SendWidget::handle_send_button_clicked()
{
    if(!_message_input->text().isEmpty()) {
        emit send_message(_message_input->text());
        _message_input->clear();
    }
}


} //namespace IM
