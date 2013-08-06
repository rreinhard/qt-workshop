TEMPLATE = lib

QT -= gui

CONFIG += staticlib

INCLUDEPATH += include

SOURCES += \
    source/application.cpp \

HEADERS += \
    include/messenger/application.h \

OTHER_FILES += \
    qml/main.qml

RESOURCES += \
    messenger.qrc

QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage

include(../common.pri)

