TEMPLATE = lib

QT -= gui
QT += widgets

CONFIG += staticlib

INCLUDEPATH += include

SOURCES += \
    source/application-uic.cpp \
    source/gui.cpp

HEADERS += \
    include/application-uic/application-uic.h \
    include/application-uic/gui.h

FORMS += \
    im_form.ui

unix: QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage

include(../common.pri)
include(../messenger/messenger.pri)


