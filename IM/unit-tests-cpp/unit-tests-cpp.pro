TEMPLATE = app

QT += testlib gui widgets

CONFIG += testcase
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    sendwidget_test.cpp \
    onlinelist_test.cpp

HEADERS += \
    sendwidget_test.h \
    onlinelist_test.h

include(../common.pri)
include(../application-cpp/application-cpp.pri)

