#ifndef GUI_TEST_H
#define GUI_TEST_H

#include <QObject>

namespace IM
{
class Toolbar;
class SendWidget;
}

class QListView;
class QTextEdit;

class Gui_Test : public QObject
{
    Q_OBJECT
public:
    explicit Gui_Test(QObject *parent = 0);

private slots:
    void init();
    void show_gui_test();

private:
    IM::Toolbar* _toolbar;
    QTextEdit* _chat_widget;
    IM::SendWidget* _send_widget;
    QListView* _online_list_view;
};

#endif // GUI_TEST_H
