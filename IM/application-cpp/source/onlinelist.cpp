#include "application-cpp/onlinelist.h"

OnlineList::OnlineList(QObject *parent) :
    QObject(parent),
    _update_timer()
{
    connect(&_update_timer, SIGNAL(timeout()), this, SLOT(update_timestamps()));
    _update_timer.start(500);
}

void OnlineList::update_user(QString const & nickname)
{
    bool found_user = false;
    QTime now = QTime::currentTime();

    for(User_list::iterator iterator = _online_users.begin(); iterator != _online_users.end(); iterator++)
    {
        if(iterator->first == nickname)
        {
            iterator->second = now;
            found_user = true;
            break;
        }
    }

    if(!found_user)
    {
        _online_users.append(User_entry(nickname, now));
    }
}

void OnlineList::update_timestamps()
{
    if (_online_users.empty())
        return;

    QTime now = QTime::currentTime();

    for(User_list::iterator iterator = _online_users.begin(); iterator != _online_users.end(); iterator++)
    {
        if(iterator->second.addSecs(7) > now)
        {
            _online_users.erase(iterator);
        }
    }

}

QStringList OnlineList::get_online_users()
{
    QStringList result;
    for(User_list::iterator iterator = _online_users.begin(); iterator != _online_users.end(); iterator++)
    {
        result.append(iterator->first);
    }
    return result;
}
