#include <QtTest/QTest>

#include "dummy_test.h"

DummyTest::DummyTest() :
    QObject(nullptr)
{
}

void DummyTest::dummy_test()
{
    QVERIFY(true);
}



