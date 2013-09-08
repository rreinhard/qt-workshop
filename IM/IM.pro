TEMPLATE = subdirs

CPP_GUI = \
#    main-cpp \
#    application-cpp \

UIC_GUI = \
#    main-uic \
#    application-uic \

QML_GUI = \
    main-qml \
    application-qml \

SUBDIRS = \
    $${CPP_GUI} \
    $${UIC_GUI} \
    $${QML_GUI} \
    messenger \
    unit-tests \
    qml-tests

main.depends = messenger
main-qml.depends = messenger application-qml

unit-tests.depends = messenger

OTHER_FILES += \
    ../README.md

