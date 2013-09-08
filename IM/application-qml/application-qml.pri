QT += qml quick

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

LIBS += -lapplication-qml

win32 {
    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../application-qml/release/
    CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../application-qml/debug/

    CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application-qml/release/application-qml.lib
    CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application-qml/debug/application-qml.lib
}

unix {
    LIBS += -L$$OUT_PWD/../application-qml/
    PRE_TARGETDEPS += $$OUT_PWD/../application-qml/libapplication-qml.a

    QMAKE_LFLAGS_DEBUG += -fprofile-arcs
}

