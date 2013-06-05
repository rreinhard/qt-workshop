#include "uicontroller.h"

UIController::UIController(QObject *parent) :
    QObject(parent),
    _nickname("Fish")
{
}

QString UIController::nickname() const
{
    return _nickname;
}

void UIController::setNickname(QString nickname)
{
    _nickname = nickname;
    emit nicknameChanged();
}
