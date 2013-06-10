#include "testsendmessages.h"

#include <QtCore/QCoreApplication>
#include <QtTest/QTest>

int main(int argc, char * argv[]) {

    QCoreApplication application(argc, argv);

    int exit_code;

    TestSendMessages send_messages;
    exit_code = QTest::qExec(&send_messages, argc, argv);
    if(0 != exit_code) {
        return exit_code;
    }

    return 0;
}


