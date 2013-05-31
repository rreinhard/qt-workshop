
TEMPLATE = subdirs

SUBDIRS = \
    main \
    application \
    application-test

main.depends = \
    application

application-test.depends = application

