TEMPLATE = app

QT += testlib gui widgets

CONFIG += testcase
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    sendwidget_test.cpp \
    onlinelist_test.cpp \
    application_test.cpp \
    gui_test.cpp \
    simple_input_dialog_test.cpp \
    eventhandler_test.cpp \
    eventlist_test.cpp

HEADERS += \
    sendwidget_test.h \
    onlinelist_test.h \
    application_test.h \
    gui_test.h \
    simple_input_dialog_test.h \
    eventhandler_test.h \
    eventlist_test.h

include(../common.pri)
include(../application-cpp/application-cpp.pri)
include(../messenger/messenger.pri)

