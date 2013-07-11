
QT += qml quick network

INCLUDEPATH += $$PWD/../application
DEPENDPATH += $$PWD/../application

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../application/release/ -lapplication
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../application/debug/ -lapplication
else:unix:!macx: LIBS += -L$$OUT_PWD/../application/ -lapplication

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application/release/application.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../application/debug/application.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../application/libapplication.a


