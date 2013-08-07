#include "messenger/controller.h"

namespace IM {

Controller::Controller() :
    _nickname("")
{
}

void Controller::invoke_send_message(const QString & message)
{
    emit send_message(_nickname, message);
}

void Controller::set_nickname(const QString & nickname)
{
    _nickname = nickname;
}

} // IM

