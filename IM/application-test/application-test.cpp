#include <QString>
#include <QtTest>

class ApplicationTest : public QObject
{
    Q_OBJECT
    
public:
    ApplicationTest();
    
private Q_SLOTS:
    void execute();
};

ApplicationTest::ApplicationTest()
{
}

void ApplicationTest::execute()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ApplicationTest)

#include "application-test.moc"
