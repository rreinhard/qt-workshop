#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>

class UIController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY nicknameChanged)

public:
    explicit UIController(QObject *parent = 0);

    Q_INVOKABLE void send_message(QString message);

    QString nickname() const;
    void setNickname(QString nickname);

signals:
    void nicknameChanged();
    void dispatch_message(QString message);

private:
};

#endif // UICONTROLLER_H
