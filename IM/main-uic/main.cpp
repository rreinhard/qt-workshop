#include <QtCore/QObject>

#include <application-uic/application-uic.h>

int main(int argc, char * argv[])
{
    IM::Application application;
    return application.execute(argc, argv);
}

