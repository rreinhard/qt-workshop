#include "application.h"

#include "uicontroller.h"

#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>

Application::Application()
{
}

int Application::execute(int argc, char * argv[])
{
    QGuiApplication application(argc, argv);
    QQuickView view;

    Q_INIT_RESOURCE(application);

    UIController ui_controller;
    view.engine()->rootContext()->setContextProperty("ui_controller", &ui_controller);

    view.connect(view.engine(), SIGNAL(quit()), SLOT(close()));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/IM/main.qml"));

    view.show();

    return application.exec();


    return 0;
}
