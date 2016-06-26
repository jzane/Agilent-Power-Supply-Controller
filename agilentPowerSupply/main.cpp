#include "controllerwindow.h"
#include <QApplication>
#include <visa.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>








int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    ControllerWindow w;
    w.show();

    return a.exec();
}













