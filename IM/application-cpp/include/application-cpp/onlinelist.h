#ifndef ONLINELIST_H
#define ONLINELIST_H

#include <QList>
#include <QPair>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <QTime>
#include <QObject>

class OnlineList : public QObject
{
    Q_OBJECT
public:
    explicit OnlineList(QObject *parent = 0);

    QStringList get_online_users();

signals:

public slots:
    void update_user(QString const & nickname);

private slots:
    void update_timestamps();

private:
    typedef QPair<QString, QTime> User_entry;
    typedef QList<User_entry> User_list;

    User_list _online_users;
    QTimer _update_timer;
};

#endif // ONLINELIST_H
