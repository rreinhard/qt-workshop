#include <QtCore/QCoreApplication>
#include <QtTest/QTest>

#include "dummy_test.h"

int main(int argc, char * argv[])
{
    QCoreApplication application(argc, argv);

    int exit_code = 0;

    DummyTest dummy_test;
    exit_code = QTest::qExec(&dummy_test, argc, argv);
    if(0 != exit_code) {
        exit_code++;
    }

    return exit_code;
}


