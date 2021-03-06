TEMPLATE = lib

QT -= gui

CONFIG += staticlib

INCLUDEPATH += include

SOURCES += \
    source/controller.cpp \
    source/communication.cpp \
    source/udp_socket.cpp

HEADERS += \
    include/messenger/controller.h \
    include/messenger/communication.h \
    include/messenger/iudp_socket.h \
    include/messenger/udp_socket.h

unix: QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage

include(../common.pri)

