TEMPLATE = app

QT += testlib gui widgets

CONFIG += testcase
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    sendwidget_test.cpp \
    setnickname_test.cpp

HEADERS += \
    sendwidget_test.h \
    setnickname_test.h

include(../common.pri)
include(../application-cpp/application-cpp.pri)
include(../messenger/messenger.pri)

