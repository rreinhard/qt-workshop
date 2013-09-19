#ifndef ONLINELIST_INTEGRATION_H
#define ONLINELIST_INTEGRATION_H

#include <QObject>

class OnlineListIntegration : public QObject
{
    Q_OBJECT
    
private slots:
    void a_user_goes_offline();

signals:
    void dummy();

};

#endif // ONLINELIST_INTEGRATION_H
