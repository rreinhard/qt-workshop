QT -= gui

TARGET = application
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    application.cpp \
    uicontroller.cpp \
    messaging.cpp \
    transport.cpp

HEADERS += \
    application.h \
    uicontroller.h \
    messaging.h \
    transport.h

OTHER_FILES += \
    main.qml

RESOURCES += \
    application.qrc

