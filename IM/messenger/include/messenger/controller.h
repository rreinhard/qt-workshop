#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtCore/QObject>

namespace IM {

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();

    Q_INVOKABLE void invoke_send_message(const QString & message);

    void set_nickname(const QString & nickname);

signals:
    void send_message(const QString & nickname, QString const & message);

private:
    QString _nickname;
};

} // IM

#endif // CONTROLLER_H
