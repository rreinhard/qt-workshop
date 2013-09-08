QT += gui widgets

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

LIBS += -lapplication-uic

win32 {
    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../application-uic/release/
    CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../application-uic/debug/

    CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application-uic/release/application-uic.lib
    CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application-uic/debug/application-uic.lib
}

unix {
    LIBS += -L$$OUT_PWD/../application-uic/
    PRE_TARGETDEPS += $$OUT_PWD/../application-uic/libapplication-uic.a

    QMAKE_LFLAGS_DEBUG += -fprofile-arcs
}

