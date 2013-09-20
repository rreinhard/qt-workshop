#include "application-cpp/simple_input_dialog.h"


namespace IM {

SimpleInputDialog::SimpleInputDialog(const QString & title, QLineEdit* input_field, QPushButton* set_button, QWidget* parent) :
    QDialog(parent),
    _input_field(input_field),
    _set_button(set_button)
{
  _layout.addWidget(_set_button);
  _layout.addWidget(_input_field);
  setLayout(&_layout);
  setWindowTitle(title);
  connect(_set_button, SIGNAL(clicked()), SLOT(handle_set_button_clicked()));
}

void SimpleInputDialog::handle_set_button_clicked()
{
  if (!_input_field->text().isEmpty()) {
    emit set_input(_input_field->text());
  }
  close();
}


} // namespace IM
