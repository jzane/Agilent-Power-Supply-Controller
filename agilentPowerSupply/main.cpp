#include "controllerwindow.h"
#include <QApplication>
#include <visa.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <julianzane.h>



ViSession defaultRM; /* Resource manager id */
ViSession power_supply; /* Identifies power supply */
int bGPIB = 1; /* Set the number to 0 for use with the RS-232
 interface */
long ErrorStatus; /* VISA Error code */
char commandString[256];
char ReadBuffer[256];
void delay(clock_t wait);
void SendSCPI(char* pString);
void CheckError(char* pMessage);




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControllerWindow w;
    w.show();

    return a.exec();
}
