/********************************/
//Julian Zane function implementation file//
//assumed all functions are global as no need to have
//anything else right now

#include <visa.h>


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
CheckError("Unable to open port");
if(!bGPIB)
SendSCPI("System:Remote");
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
