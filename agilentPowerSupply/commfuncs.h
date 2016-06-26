#include <visa.h>
#include <time.h>

#ifndef COMMFUNCS_H
#define COMMFUNCS_H

//func prototypes
void OpenPort();
void ClosePort();
void CheckError(char*);
void delay(clock_t);
void SendSCPI(char*);


#endif // COMMFUNCS_H
