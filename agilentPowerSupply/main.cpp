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


    // open resource manager
        ViSession rscmng;
        ViStatus stat = viOpenDefaultRM(&rscmng);

        // search for the oscilloscope
        ViChar viFound[VI_FIND_BUFLEN];
        ViUInt32 nFound;
        ViFindList listOfFound;
        stat = viFindRsrc(rscmng, (ViString)"USB?*", &listOfFound, &nFound, viFound);

        // connect to the oscilloscope
        ViSession osc;
        stat = viOpen(rscmng, viFound, VI_NULL, VI_NULL, &osc);

        // communicate
        viPrintf(osc, (ViString)"*IDN?\n");
        char buf[256] = {0};
        viScanf(osc,(ViString)"%t",&buf);


        // close VI sessions
        viClose(osc);
        viClose(rscmng);



    QApplication a(argc, argv);
    ControllerWindow w;
    w.show();

    return a.exec();
}











/**************************/
//OPENS PORT FOR COMM
void OpenPort()
{
    char GPIB_Address[3];
    char COM_Address[2];
    char VISA_address[40]; /* Complete VISA address sent to card */
    if(bGPIB)
        strcpy(GPIB_Address,"5"); /* Select GPIB address between 0 to 30*/
    else
        strcpy(COM_Address,"1"); /* Set the number to 2 for COM2 port */
    if(bGPIB){ /* For use with GPIB 7 address, use "GPIB::7::INSTR" address format */
        strcpy(VISA_address,"GPIB::");
        strcat(VISA_address,GPIB_Address);
        strcat(VISA_address,"::INSTR");
    }
    else{ /* For use with COM2 port, use "ASRL2::INSTR" address format */
        strcpy(VISA_address,"ASRL");
        strcat(VISA_address,COM_Address);
        strcat(VISA_address,"::INSTR");
    }
    /* Open communication session with the power supply */
    ErrorStatus = viOpenDefaultRM(&defaultRM);
    ErrorStatus = viOpen(defaultRM,VISA_address,0,0,&power_supply);
    CheckError((char *)"Unable to open port");
    if(!bGPIB)
        SendSCPI((char *)"System:Remote"); //added to cast as char *
}//end openport()




void ClosePort()
{
    /* Close the communication port */
    viClose(power_supply);
    viClose(defaultRM);
}


void CheckError(char* pMessage)
{
    if (ErrorStatus < VI_SUCCESS){
        printf("\n %s",pMessage);
        ClosePort();
        exit(0);
    }
}
void delay(clock_t wait)
{
    clock_t goal;
    goal = wait + clock();
    while( goal > clock() ) ;
}


void SendSCPI(char* pString)
{
    char* pdest;
    strcpy(commandString,pString);
    strcat(commandString,(ViString)"\n");
    ErrorStatus = viPrintf(power_supply,commandString);
    CheckError((ViString)"Can’t Write to Driver");
    if (bGPIB == 0)
        delay(1000); /* Unit is milliseconds */
    pdest = strchr(commandString, '?'); /* Search for query command */
    if( pdest != NULL ){
        ErrorStatus = viScanf(power_supply,(char *)"%s",&ReadBuffer);
        CheckError((ViString)"Can’t Read From Driver");

        strcpy(pString,ReadBuffer);
    }
}


