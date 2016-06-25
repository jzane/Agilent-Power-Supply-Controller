//header file to put all my functions in so I
//don't get them confused with functions from the GUI
#include <visa.h>

#ifndef JULIANZANE_H
#define JULIANZANE_H


//opens com port for serial rs232 communication with device
//can only connect one device at a time unless using GPIB
void OpenPort();

//closes port, will eventually take care of memory management as well
//just not in first public release (beta?)
void ClosePort();

//checks error fetch from device
void CheckError(char* pMessage);

//delays a specified time, used in serial comm
void delay(clock_t wait);

//actually sends scpi commands to device via serial comm or GPIB
void SendSCPI(char* pString);


#endif // JULIANZANE_H


#include <julianzane.cpp>
