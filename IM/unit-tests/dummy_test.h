#ifndef DUMMY_TEST_H
#define DUMMY_TEST_H

#include <QObject>

class DummyTest : public QObject
{
    Q_OBJECT

public:
    explicit DummyTest();

private slots:
    void dummy_test();

};

#endif // DUMMY_TEST_H
