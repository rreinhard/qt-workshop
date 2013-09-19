TEMPLATE = subdirs

# sub projects for the C++ gui skeleton
CPP_GUI = \
    main-cpp \
    application-cpp \
    unit-tests-cpp \

SUBDIRS = \
    $${CPP_GUI} \
    messenger \
    unit-tests \
    integration-tests

# dependencies for the C++ gui skeleton
main-cpp.depends = messenger application-cpp
unit-tests-cpp.depends = application-cpp
integration-tests.depends = application-cpp

unit-tests.depends = messenger


OTHER_FILES += \
    ../README.md

