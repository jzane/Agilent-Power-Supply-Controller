#include "controllerwindow.h"
#include "ui_controllerwindow.h"
#include <commfuncs.h>
#include <visa.h>
#include <sstream> //for long to string conversion



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
    ui->ControllerWindow::lineEdit->setText("1"); //default to com port 1
    ui->ControllerWindow::radioButton_2->setChecked(true); //default to output off radio checked
    SendSCPI((char*)"Output off"); //actually send output off command

}

ControllerWindow::~ControllerWindow()
{
    SendSCPI((char*) "*RST"); //resets device
    SendSCPI((char*)"Output off");

    delete ui;
}

void ControllerWindow::on_pushButton_clicked()
{
    OpenPort(); //opens port with comm number specifier
    sprintf_s(Buffer, "*IDN?");
    SendSCPI(Buffer);
    //getting instrument ID string
    ui->ControllerWindow::label->setText(Buffer);
}


/**************************/
//OPENS PORT FOR COMM
void ControllerWindow::OpenPort()
{
    QString comm;
    comm = ui->ControllerWindow::lineEdit->text();
    std::string str = comm.toStdString();
    const char * p = str.c_str(); //converting QString to char *

    char GPIB_Address[3];
    char COM_Address[2];
    char VISA_address[40]; /* Complete VISA address sent to card */
    if(bGPIB)
        strcpy(GPIB_Address,"5"); /* Select GPIB address between 0 to 30*/
    else
        strcpy(COM_Address,p); /* Set the number to 2 for COM2 port */
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
        int error = (int)ErrorStatus; //casting long to int

        ui->ControllerWindow::label_5->setText(pMessage);

        ClosePort();
        //exit(0); STOP CLOSING THE PROGRAM, JESUS FUCK
    }
    else
    {

        ui->ControllerWindow::label_5->setText("");
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
        delay(200); /* Unit is milliseconds */
    pdest = strchr(commandString, '?'); /* Search for query command */
    if( pdest != NULL ){
        ErrorStatus = viScanf(power_supply,(char *)"%s",&ReadBuffer);
        CheckError((ViString)"Can’t Read From Driver");

        strcpy(pString,ReadBuffer);
    }
}

//the voltage "Set!" button
void ControllerWindow::on_pushButton_2_clicked()
{
    QString mess;
    mess = (QString)"Current " + ui->ControllerWindow::lineEdit_2->text();
    std::string str1 = mess.toStdString();
    const char* messSend = str1.c_str();
    //above: converting message to char* to be able to send through scpi func "SendSCPI"
    SendSCPI((char*)"*RST"); /* Set power-on condition */
    SendSCPI((char*)messSend); /* Set current limit to 'x' A */
    SendSCPI((char*)"Output on"); /* Turn output on */

    //set voltage
    std::string voltage1 = "VOLT " + (ui->ControllerWindow::lineEdit_3->text()).toStdString() + "\n";
    const char * volt = voltage1.c_str();
    SendSCPI((char*)volt);
    ui->ControllerWindow::radioButton->setChecked(true);

    //ErrorStatus = viPrintf(power_supply, "Volt %f\n", (ViString)voltage1);
    //delay(300);/* 300 msec wating for RS-232 interface*/
    //CheckError((char*)"Unable to set voltage");


}

void ControllerWindow::on_radioButton_clicked()
{
    SendSCPI((char*)"Output on");
}

void ControllerWindow::on_radioButton_2_clicked()
{
    SendSCPI((char*)"Output off");
}



/*
//FOR OUTPUT 2
//the voltage "Set!" button
void ControllerWindow::on_pushButton_3_clicked()
{
    QString mess2;
    mess2 = (QString)"Current " + ui->ControllerWindow::lineEdit_4->text();
    std::string str2 = mess.toStdString();
    const char* messSend1 = str2.c_str();
    //above: converting message to char* to be able to send through scpi func "SendSCPI"
    SendSCPI((char*)"*RST"); // Set power-on condition
    SendSCPI((char*)messSend1); // Set current limit to 'x' A
    SendSCPI((char*)"Output on"); // Turn output on

    //set voltage
    std::string voltage1 = "VOLT " + (ui->ControllerWindow::lineEdit_3->text()).toStdString() + "\n";
    const char * volt = voltage1.c_str();
    SendSCPI((char*)volt);
    ui->ControllerWindow::radioButton->setChecked(true);

    //ErrorStatus = viPrintf(power_supply, "Volt %f\n", (ViString)voltage1);
    //delay(300);// 300 msec wating for RS-232 interface
    //CheckError((char*)"Unable to set voltage");


}

*/
