#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtCore/QStringList>

#include "application-cpp/gui.h"
#include "application-cpp/sendwidget.h"
#include "application-cpp/toolbar.h"
#include "gui_test.h"

Gui_Test::Gui_Test(QObject *parent) :
    QObject(parent)
{
}

void Gui_Test::init()
{
    _toolbar = new IM::Toolbar(new QPushButton(), new QPushButton());
    _chat_widget = new QTextEdit();
    _send_widget = new IM::SendWidget(new QLineEdit(), new QPushButton());
    _online_list_view = new QListView();
}

void Gui_Test::show_gui_test()
{
    IM::Gui testee(_toolbar, _chat_widget, _send_widget, _online_list_view);
    QCOMPARE(testee.isShown(), false);
    testee.show();
    QCOMPARE(testee.isShown(), true);
}
