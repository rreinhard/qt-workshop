QT -= gui

TARGET = main
TEMPLATE = app

SOURCES +=  \
    main.cpp

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage
QMAKE_LFLAGS_DEBUG += -fprofile-arcs
CONFIG(debug, debug|release): LIBS += -lgcov

include (../application/application.pri)

