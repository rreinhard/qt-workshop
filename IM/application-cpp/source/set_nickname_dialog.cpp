#include "application-cpp/set_nickname_dialog.h"


namespace IM {

SetNicknameDialog::SetNicknameDialog(QLineEdit* nickname_input, QPushButton* set_button, QWidget* parent) :
    QDialog(parent),
    _nickname_input(nickname_input),
    _set_button(set_button)
{
  _layout.addWidget(_set_button);
  _layout.addWidget(_nickname_input);
  setLayout(&_layout);
  connect(_set_button, SIGNAL(clicked()), SLOT(handle_set_nickname_clicked()));
}

void SetNicknameDialog::handle_set_nickname_clicked()
{
  if (!_nickname_input->text().isEmpty()) {
    emit set_nickname(_nickname_input->text());
  }
  close();
}


} // namespace IM
