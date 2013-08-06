TEMPLATE = app

QT += testlib
QT -= gui

CONFIG += testcase console
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    dummy_test.cpp

HEADERS += \
    dummy_test.h

include(../common.pri)
include(../messenger/messenger.pri)

