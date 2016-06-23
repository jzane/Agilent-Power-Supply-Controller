#include "controllerwindow.h"
#include <QApplication>
#include <visa.h>
#include <julianzane.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControllerWindow w;
    w.show();

    return a.exec();
}
