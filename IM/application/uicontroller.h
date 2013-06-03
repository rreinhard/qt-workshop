#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>

class UIController : public QObject
{
    Q_OBJECT

public:
    explicit UIController(QObject *parent = 0);

};

#endif // UICONTROLLER_H
