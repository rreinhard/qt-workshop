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

