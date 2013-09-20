#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtCore/QObject>
#include <QtCore/QStringList>
#include <QtCore/QStringListModel>

class QTextEdit;

namespace IM {

class Application : public QObject
{
    Q_OBJECT
public:
    Application();

    int execute(int argc, char * argv[]);

public slots:
    void update_Model(QStringList list);
    void received_message(QString const & nickname, QString const & message);

private:
    QStringListModel* _online_list_model;
    QTextEdit* _chat_widget;
};

} // IM

#endif // APPLICATION_H
