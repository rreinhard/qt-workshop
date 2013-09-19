TEMPLATE = app

QT += testlib
QT -= gui

CONFIG += testcase console
CONFIG -= app_bundle


SOURCES += main.cpp \
    communication_integration.cpp \
    stubs/qudpsocket_stub.cpp \
    onlinelist_integration.cpp
HEADERS += \
    communication_integration.h \
    stubs/qudpsocket_stub.h \
    onlinelist_integration.h


include(../common.pri)
include(../application-cpp/application-cpp.pri)
include(../messenger/messenger.pri)
