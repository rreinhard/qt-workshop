#include <QtWidgets/QTextEdit>
#include "application-cpp/gui.h"
#include "application-cpp/sendwidget.h"
#include "application-cpp/toolbar.h"

namespace IM {

Gui::Gui(Toolbar* toolbar, QTextEdit* chat_widget, SendWidget* send_widget) :
    QObject(nullptr),
    _window(),
    _toolbar(toolbar),
    _send_widget(send_widget),
    _chat_widget(chat_widget),
    _main_layout(),
    _event_layout(),
    _chat_layout()
{
}

void Gui::show()
{
    _chat_layout.addWidget(_chat_widget);
    _chat_layout.addWidget(_send_widget);


    _event_layout.addLayout(&_chat_layout);

    _main_layout.addWidget(_toolbar);
    _main_layout.addLayout(&_event_layout);


    _window.setLayout(&_main_layout);
    _window.show();
}

} // IM

