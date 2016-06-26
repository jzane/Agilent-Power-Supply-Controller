#include "controllerwindow.h"
#include "ui_controllerwindow.h"
#include <commfuncs.h>
#include <visa.h>


ViSession defaultRM; /* Resource manager id */
ViSession power_supply; /* Identifies power supply */
int bGPIB = 0; /* Set the number to 0 for use with the RS-232
               interface */
long ErrorStatus; /* VISA Error code */
char commandString[256];
char ReadBuffer[256];
void delay(clock_t wait);
void SendSCPI(char* pString);
void CheckError(char* pMessage);

/* shouldnt need these b/c prototypes are in .h file
void OpenPort();
void ClosePort();
void SendSCPI(char *);
*/

double voltage; /* Value of voltage sent to power supply */
char Buffer[256]; /* String returned from power supply */
double current; /* Value of current output of power supply */




ControllerWindow::ControllerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControllerWindow)
{
    ui->setupUi(this);
}

ControllerWindow::~ControllerWindow()
{
    delete ui;
}

void ControllerWindow::on_pushButton_clicked()
{
    OpenPort(); //opens port with comm number specifier
    sprintf_s(Buffer, "*IDN?");
    SendSCPI(Buffer);
    //getting inst. ID string
    ui->ControllerWindow::label->setText(Buffer);
}


/**************************/
//OPENS PORT FOR COMM
void ControllerWindow::OpenPort()
{

    char GPIB_Address[3];
    char COM_Address[2];
    char VISA_address[40]; /* Complete VISA address sent to card */
    if(bGPIB)
        strcpy(GPIB_Address,"5"); /* Select GPIB address between 0 to 30*/
    else
        strcpy(COM_Address,"4"); /* Set the number to 2 for COM2 port */
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




void ControllerWindow::ClosePort()
{
    /* Close the communication port */
    viClose(power_supply);
    viClose(defaultRM);
}


void ControllerWindow::CheckError(char* pMessage)
{
    if (ErrorStatus < VI_SUCCESS){
        printf("\n %s",pMessage);
        ClosePort();
        exit(0);
    }
}
void ControllerWindow::delay(clock_t wait)
{
    clock_t goal;
    goal = wait + clock();
    while( goal > clock() ) ;
}


void ControllerWindow::SendSCPI(char* pString)
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

