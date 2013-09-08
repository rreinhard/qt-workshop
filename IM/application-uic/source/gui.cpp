#include "ui_im_form.h"

#include "application-uic/gui.h"

namespace IM {

Gui::Gui(Ui::ImForm & im_form) :
    QWidget(nullptr),
    _im_form(im_form)
{
    _im_form.setupUi(this);
}

void Gui::on_send_button_clicked()
{
    if(!_im_form.message_input->text().isEmpty()) {
        emit send_message(_im_form.message_input->text());
        _im_form.message_input->clear();
    }
}

} // IM

