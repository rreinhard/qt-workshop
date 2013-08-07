TEMPLATE = app

QT += qmltest
QT -= gui

CONFIG += qmltestcase console
CONFIG -= app_bundle

DEFINES += QUICK_TEST_SOURCE_DIR=\\\"$$PWD\\\"

SOURCES += \
    qml-tests.cpp

OTHER_FILES += \
    utils.js \
    tst_nickname.qml \
    tst_button.qml

