
TEMPLATE = subdirs

SUBDIRS = \
    main \
    application \
    application-test \
    messaging

application.depends = \
    messaging

main.depends = \
    application

application-test.depends = application

