TEMPLATE = app

QT += testlib
QT -= gui

CONFIG += testcase console
CONFIG -= app_bundle


SOURCES += main.cpp \
    communication_integration.cpp \
    stubs/qudpsocket_stub.cpp
HEADERS += \
    communication_integration.h \
    stubs/qudpsocket_stub.h


include(../common.pri)
include(../messenger/messenger.pri)
