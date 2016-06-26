#include "controllerwindow.h"
#include <QApplication>
#include <visa.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <commfuncs.h>
#include <string.h>








int main(int argc, char *argv[])
{
    double voltage; /* Value of voltage sent to power supply */
    char Buffer[256]; /* String returned from power supply */
    double current; /* Value of current output of power supply */




    QApplication a(argc, argv);
    ControllerWindow w;
    w.show();

    return a.exec();
}













