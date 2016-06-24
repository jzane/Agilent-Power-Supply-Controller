#include "controllerwindow.h"
#include <QApplication>
#include <visa.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <julianzane.h>


//VISession objs created successfully
ViSession defaultRM; /* Resource manager id */
ViSession power_supply; /* Identifies power supply */
int bGPIB = 1; /* Set the number to 0 for use with the RS-232
 interface */
long ErrorStatus; /* VISA Error code */
char commandString[256];
char ReadBuffer[256];
//func prototypes in julian.h
//void delay(clock_t wait);
//void SendSCPI(char* pString);
//void CheckError(char* pMessage);




int main(int argc, char *argv[])
{


    /*********************************************************************/
   // using sample code fom keysight
    //note: might need to move some objs and vars to ControllerWindow to manage memory better
            //->might need to be part of that scope

    double voltage; /* Value of voltage sent to power supply */
    char Buffer[256]; /* String returned from power supply */
    double current; /* Value of current output of power supply */
    OpenPort();
    /* Query the power supply id, read response and print it */
    sprintf(Buffer,"*IDN?");
    SendSCPI(Buffer);
    printf("Instrument identification string:\n %s\n\n",Buffer);
    SendSCPI((ViString)"*RST"); /* Set power-on condition */
    SendSCPI((ViString)"Current 2"); /* Set current limit to 2A */
    SendSCPI((ViString)"Output on"); /* Turn output on */
    printf("Voltage Current\n\n"); /* Print heading */
    /*Step from 0.6 to 0.8 volt in 0.02 steps */
    for(voltage = 0.6; voltage <=0.8001; voltage +=0.02)
    {
    printf("%.3f",voltage); /* Display diode voltage*/
    /* Set output voltage */
    ErrorStatus = viPrintf(power_supply,(ViString)"Volt %f\n",voltage); //explicitly casting c_string as VIString
    if(!bGPIB)
    delay(500);/* 500 msec wating for RS-232 interface*/
    CheckError((ViString)"Unable to set voltage");
    /* Measure output current */
    ErrorStatus = viPrintf(power_supply,(ViString)"Measure:Current?\n");
    CheckError((ViString)"Unable to write device");
    delay(500); /* Allow output to wait for 500 msec */
    /* Retrieve reading */
    ErrorStatus = viScanf(power_supply,(ViString)"%lf",&current);
    CheckError((ViString)"Unable to read voltage");
    printf("%6.4f\n",current); /* Display diode current */
    }
    SendSCPI((ViString)"Output off"); /* Turn output off */
    ClosePort();

    /* Build the address required to open communication with GPIB card or RS-232.*/
    /* The address format looks like this: "GPIB0::5::INSTR". */
    /* To use the RS-232 interface using COM1 port, change it to "ASRL1::INSTR" */
    /* address format */




    QApplication a(argc, argv);
    ControllerWindow w;
    w.show();

    return a.exec();
}
