TEMPLATE = app

QT += testlib gui widgets

CONFIG += testcase
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    gui_test.cpp

HEADERS += \
    gui_test.h

include(../common.pri)
include(../application-cpp/application-cpp.pri)

