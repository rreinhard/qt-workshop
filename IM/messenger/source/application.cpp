#include "messenger/application.h"

#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>
#include <QtCore/QThread>

namespace IM {

Application::Application()
{
}

int Application::execute(int argc, char * argv[])
{
    QGuiApplication application(argc, argv);
    QQuickView view;

    view.connect(view.engine(), SIGNAL(quit()), SLOT(close()));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/IM/main.qml"));

    view.show();

    return application.exec();
}

} // IM

