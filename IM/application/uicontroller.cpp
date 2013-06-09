#include "uicontroller.h"

#include <QtCore/QSettings>

UIController::UIController(QObject *parent) :
        QObject(parent) {
}

QString UIController::nickname() const {
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "bbv", "IM");
    QString nickname = settings.value("Nickname", "").toString();
    return nickname;
}

void UIController::setNickname(QString nickname) {
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "bbv", "IM");
    settings.setValue("Nickname", nickname);
    emit nicknameChanged();
}

void UIController::send_message(QString message) {
    emit dispatch_message(message);
}

