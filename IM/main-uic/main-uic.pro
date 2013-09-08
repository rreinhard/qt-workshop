TARGET = messenger
TEMPLATE = app

QT -= gui

SOURCES +=  \
    main.cpp

include(../common.pri)
include(../application-uic/application-uic.pri)
include(../messenger/messenger.pri)

