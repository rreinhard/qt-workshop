#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>

class UIController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY nicknameChanged)

public:
    explicit UIController(QObject *parent = 0);


    QString nickname() const;
    void setNickname(QString nickname);

signals:
    void nicknameChanged();

private:
    QString _nickname;
};

#endif // UICONTROLLER_H
