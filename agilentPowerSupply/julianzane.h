//header file to put all my functions in so I
//don't get them confused with functions from the GUI

#ifndef JULIANZANE_H
#define JULIANZANE_H


//opens com port for serial rs232 communication with device
//can only connect one device at a time unless using GPIB
void OpenPort();

//closes port, will eventually take care of memory management as well
//just not in first public release (beta?)
void closeport();

//checks error fetch from device
void CheckError(char* pMessage);

//delays a specified time, used in serial comm
void delay(clock_t wait);




#endif // JULIANZANE_H
