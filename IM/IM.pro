TEMPLATE = subdirs


SUBDIRS = \
    $${CPP_GUI} \
    messenger \
    unit-tests

# dependencies for the C++ gui skeleton
main-cpp.depends = messenger application-cpp
unit-tests-cpp.depends = application-cpp

unit-tests.depends = messenger


OTHER_FILES += \
    ../README.md

