#include "controllerwindow.h"
#include "ui_controllerwindow.h"
#include <visa.h>
#include <sstream> //for long to string conversion
#include <string>
#include <cstring>
#include <iostream>



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
    delay(500);
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
        delay(70); /* Unit is milliseconds */ //NEEDS TO BE HERE!!!!!!!!!!!!!!!!!!!!!
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



//not going to be in version 1.0.0

/*

//FOR OUTPUT 2
//the voltage "Set!" button
void ControllerWindow::on_pushButton_3_clicked()
{
    SendSCPI((char*)"INST OUT 2"); //channel 2
    QString mess2;
    mess2 = (QString)"Current " + ui->ControllerWindow::lineEdit_4->text(); //second source only
    std::string str2 = mess2.toStdString();
    const char* messSend1 = str2.c_str();
    //above: converting message to char* to be able to send through scpi func "SendSCPI"

    SendSCPI((char*)messSend1); // Set current limit to 'x' A
    SendSCPI((char*)"Output on"); // Turn output on for output 2

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


//manually specifying the voltage ramp
void ControllerWindow::on_pushButton_3_clicked()
{

    //limit current first, same as in manual mode
    QString mess;
    mess = (QString)"Current " + ui->ControllerWindow::lineEdit_7->text();
    std::string str1 = mess.toStdString();
    const char* messSend = str1.c_str();
    //above: converting message to char* to be able to send through scpi func "SendSCPI"

    SendSCPI((char*)messSend); /* Set current limit to 'x' A */


    double stepSize; //this will change

    double delayTime = 70; //const value of 'x' milliseconds
    double Vstart;
    Vstart= ui->ControllerWindow::lineEdit_4->text().toDouble(); //starting voltage
    double Vend;
    Vend= ui->ControllerWindow::lineEdit_5->text().toDouble();//ending voltage
    double riseTime;
    riseTime = (ui->ControllerWindow::lineEdit_6->text().toDouble()) * 1000; //rise time converted to milliseconds
    stepSize;
    stepSize= (delayTime) * (1/riseTime) * (Vend-Vstart); //units will be V/step
    int numSteps = (1/delayTime) * riseTime; //number of steps, and integer


    //not entering either conditional statements
    if ((Vstart - Vend) <= 0) //positive slope
    {
        for (double voltage = Vstart; voltage <= Vend; voltage = voltage += stepSize)
        {
            std::string str = to_string(voltage); //now a string
            std::string message = "VOLT " + str; //create message
            const char * p = message.c_str(); //convert to c_string->char array
            SendSCPI((char *)p);
            delay(delayTime);
        }
        std::string str = to_string(Vend); //now a string
        std::string message = "VOLT " + str; //create message
        const char * p = message.c_str(); //convert to c_string->char array
        SendSCPI((char *)p);
    }

    else if ((Vstart - Vend) > 0)//negative slope
    {
        for (double voltage = Vstart; voltage >= Vend; voltage = voltage += stepSize)
        {
            std::string str = to_string(voltage); //now a string
            std::string message = "VOLT " + str; //create message
            const char * p = message.c_str(); //convert to c_string->char array
            SendSCPI((char *)p);
            delay(delayTime);
        }
        std::string str = to_string(Vend); //now a string
        std::string message = "VOLT " + str; //create message
        const char * p = message.c_str(); //convert to c_string->char array
        SendSCPI((char *)p);
    }



    //V0.01.2 WAY OF DOING IT
    //LIMITATIONS: CAN'T CHANGE STEP SIZE, CAN'T DO NEGATIVE SLOPE
    //WANT TO MAXIMIZE RESOLUTION, THEREFORE MINIMIZE STEP SIZE
    /*
    double steps = (((ui->ControllerWindow::lineEdit_5->text()).toDouble() + stepSize) - ((ui->ControllerWindow::lineEdit_4->text()).toDouble())) * 10;//gives # of steps
    delayTime = (((ui->ControllerWindow::lineEdit_6->text().toDouble())/steps))-0.07; //dont forget to convert to millis
    delayTime = delayTime *1000; //millis
    //to kep it going negative
    if (delayTime < 0)
    {
        delayTime = 0;
    }
    //this gives a max slope of: 1.429 V/S

    for ( voltage = (ui->ControllerWindow::lineEdit_4->text()).toDouble(); voltage <= (ui->ControllerWindow::lineEdit_5->text()).toDouble(); voltage += stepSize)
    {
        std::string str = to_string(voltage); //now a string
        std::string message = "VOLT " + str; //create message
        const char * p = message.c_str(); //convert to c_string->char array
        SendSCPI((char *)p);
        delay(delayTime);

        //TODO: be able to stop the ramp when a 'stop/reset'button is pressed
    }

    //in case the for lop stops one stepsize short of final voltage
    voltage = (ui->ControllerWindow::lineEdit_5->text()).toDouble();
    std::string str = to_string(voltage); //now a string
    std::string message = "VOLT " + str; //create message
    const char * p = message.c_str(); //convert to c_string->char array
    SendSCPI((char *)p);
    */
}


//function used to convert from double to string

std::string ControllerWindow::to_string(double x)
{
    std::ostringstream ss;
    ss << x;
    return ss.str();
}
