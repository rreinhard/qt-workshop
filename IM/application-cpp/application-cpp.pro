TEMPLATE = lib

QT -= gui

CONFIG += staticlib

INCLUDEPATH += include

SOURCES += \
    source/application-cpp.cpp \
    source/gui.cpp \
    source/toolbar.cpp \
    source/sendwidget.cpp \
    source/onlinelist.cpp \
    source/set_nickname_dialog.cpp \
    source/eventhandler.cpp

HEADERS += \
    include/application-cpp/application-cpp.h \
    include/application-cpp/gui.h \
    include/application-cpp/toolbar.h \
    include/application-cpp/sendwidget.h \
    include/application-cpp/onlinelist.h \
    include/application-cpp/set_nickname_dialog.h \
    include/application-cpp/eventhandler.h \
    include/application-cpp/datastructures.h

unix: QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage

include(../common.pri)
include(../messenger/messenger.pri)

