QT += testlib
QT -= gui

QMAKE_CXXFLAGS += -std=c++11

QMAKE_LFLAGS_DEBUG += -fprofile-arcs

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

