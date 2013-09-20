#include <QtWidgets/QApplication>
#include <QtTest/QTest>

#include "application_test.h"
#include "gui_test.h"
#include "sendwidget_test.h"
#include "setnickname_test.h"
#include "onlinelist_test.h"
#include "eventhandler_test.h"

template<typename Test>
void execute_test(int & exit_code, int argc, char * argv[])
{
    Test test;
    if(0 != QTest::qExec(&test, argc, argv)) {
        exit_code++;
    }
}

int main(int argc, char * argv[])
{
    QApplication application(argc, argv);

    int exit_code = 0;

    execute_test<SendWidgetTest>(exit_code, argc, argv);
    execute_test<SetNicknameTest>(exit_code, argc, argv);
    execute_test<OnlineList_Test>(exit_code, argc, argv);
    execute_test<EventHandler_Test>(exit_code, argc, argv);
    execute_test<Gui_Test>(exit_code, argc, argv);
    execute_test<Application_Test>(exit_code, argc, argv);
    return exit_code;
}


