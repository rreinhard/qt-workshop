QT += testlib
QT -= gui

TARGET = application-test
TEMPLATE = app
CONFIG += testcase
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    testsendmessages.cpp

HEADERS += \
    testsendmessages.h

include (../application/application.pri)

