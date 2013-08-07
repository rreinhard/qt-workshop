TEMPLATE = lib

QT -= gui

CONFIG += staticlib

INCLUDEPATH += include

SOURCES += \
    source/application.cpp \
    source/controller.cpp \
    source/communication.cpp \
    source/udp_socket.cpp

HEADERS += \
    include/messenger/application.h \
    include/messenger/controller.h \
    include/messenger/communication.h \
    include/messenger/iudp_socket.h \
    include/messenger/udp_socket.h

OTHER_FILES += \
    qml/main.qml \
    qml/Button.qml \
    qml/SendMessage.qml

RESOURCES += \
    messenger.qrc

QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage

include(../common.pri)

