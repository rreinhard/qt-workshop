QT += gui widgets

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

LIBS += -lapplication-cpp

win32 {
    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../application-cpp/release/
    CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../application-cpp/debug/

    CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application-cpp/release/application-cpp.lib
    CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application-cpp/debug/application-cpp.lib
}

unix {
    LIBS += -L$$OUT_PWD/../application-cpp/
    PRE_TARGETDEPS += $$OUT_PWD/../application-cpp/libapplication-cpp.a

    QMAKE_LFLAGS_DEBUG += -fprofile-arcs
}

