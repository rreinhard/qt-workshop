QT -= gui

TARGET = application

TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    application.cpp \
    uicontroller.cpp

HEADERS += \
    application.h \
    uicontroller.h

OTHER_FILES += \
    main.qml

RESOURCES += \
    application.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../messaging/release/ -lmessaging
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../messaging/debug/ -lmessaging
else:unix:!macx: LIBS += -L$$OUT_PWD/../messaging/ -lmessaging

INCLUDEPATH += $$PWD/../messaging
DEPENDPATH += $$PWD/../messaging

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../messaging/release/messaging.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../messaging/debug/messaging.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../messaging/libmessaging.a

