TEMPLATE = subdirs

SUBDIRS = \
    main \
    messenger \
    unit-tests \
    qml-tests

main.depends = messenger

unit-tests.depends = messenger

