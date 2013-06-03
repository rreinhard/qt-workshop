
QT += qml quick
QT -= gui

TARGET = main

TEMPLATE = app

SOURCES +=  \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../application/release/ -lapplication
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../application/debug/ -lapplication
else:unix:!macx: LIBS += -L$$OUT_PWD/../application/ -lapplication

INCLUDEPATH += $$PWD/../application
DEPENDPATH += $$PWD/../application

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application/release/application.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application/debug/application.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../application/libapplication.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../messaging/release/ -lmessaging
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../messaging/debug/ -lmessaging
else:unix:!macx: LIBS += -L$$OUT_PWD/../messaging/ -lmessaging

INCLUDEPATH += $$PWD/../messaging
DEPENDPATH += $$PWD/../messaging

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../messaging/release/messaging.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../messaging/debug/messaging.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../messaging/libmessaging.a

