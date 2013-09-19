#ifndef ONLINELIST_TEST_H
#define ONLINELIST_TEST_H

#include <QObject>

class OnlineList_Test : public QObject
{
    Q_OBJECT
public:
    explicit OnlineList_Test(QObject *parent = 0);

private slots:

    void adding_a_single_user();
    void adding_a_user_again();
    void adding_lots_of_users();

};

#endif // ONLINELIST_TEST_H
