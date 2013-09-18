TEMPLATE = lib

QT -= gui

CONFIG += staticlib

INCLUDEPATH += include

SOURCES += \
    source/application-cpp.cpp \
    source/gui.cpp \
    source/toolbar.cpp

HEADERS += \
    include/application-cpp/application-cpp.h \
    include/application-cpp/gui.h \
    include/application-cpp/toolbar.h

unix: QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage

include(../common.pri)
include(../messenger/messenger.pri)

