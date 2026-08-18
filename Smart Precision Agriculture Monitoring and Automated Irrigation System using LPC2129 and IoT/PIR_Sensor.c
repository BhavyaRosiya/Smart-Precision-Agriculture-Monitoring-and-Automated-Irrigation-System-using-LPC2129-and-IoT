#include<lpc21xx.h>
#include<string.h>
#include"header.h"

#define GREEN  0x02
#define YELLOW 0x04
#define RED    0x08

#define BUZZER  (1<<21)
#define Pir_sens ((IOPIN0 >> 16 ) & 1)

void PIR_Sensor(void)
{
 if(Pir_sens == 0)          // No Motion
    {
        strcpy(Motion_Status, "CLEAR");
        strcpy(Security_Status, "NORMAL");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;

        IOCLR0 = BUZZER;
    }
    else                       // Motion Detected
    {
        strcpy(Motion_Status, "DETECTED");
        strcpy(Security_Status, "ALERT");

        IOCLR0 = YELLOW;
        IOSET0 = GREEN | RED;

        IOSET0 = BUZZER;
    }
}