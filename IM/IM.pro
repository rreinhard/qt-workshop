
TEMPLATE = subdirs

SUBDIRS = \
    main \
    application \
    application-test \
    messaging

main.depends = \
    application

application-test.depends = application

