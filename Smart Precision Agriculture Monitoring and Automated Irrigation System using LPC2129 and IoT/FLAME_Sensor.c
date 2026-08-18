#include<lpc21xx.h>
#include<string.h>
#include"header.h"

#define GREEN   0x02
#define YELLOW  0x04
#define RED     0x08

#define BUZZER  (1<<21)
#define flame_sens ((IOPIN0 >> 15 ) & 1)

void Flame_Sensor(void)
{
    if(flame_sens == 1)        // No Fire
    {
        strcpy(Flame_Status, "SAFE");
        strcpy(Alarm_Status, "OFF");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;

        IOCLR0 = BUZZER;
    }
    else                       // Fire Detected
    {
        strcpy(Flame_Status, "DETECTED");
        strcpy(Alarm_Status, "ON");

        IOCLR0 = RED;
        IOSET0 = GREEN | YELLOW;

        IOSET0 = BUZZER;
    }
}