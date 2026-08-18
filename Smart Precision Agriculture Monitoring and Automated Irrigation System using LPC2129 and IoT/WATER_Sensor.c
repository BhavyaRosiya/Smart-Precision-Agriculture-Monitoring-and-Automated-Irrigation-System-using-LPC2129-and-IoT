#include<lpc21xx.h>
#include<string.h>
#include"header.h"

#define GREEN 0x02
#define YELLOW 0x04
#define RED 0x08
#define Pump (1 << 17) 

void water_sensor(void)
{
 unsigned int value;

    value = adc_read(1);

    Water_Level = (value * 100) / 1023;

    if(Water_Level < 30)
    {
        strcpy(Water_Status, "LOW");
        strcpy(Pump_Status, "OFF");

        IOCLR0 = RED;
        IOSET0 = GREEN | YELLOW;

        IOCLR0 = Pump;
    }
    else if(Water_Level < 80)
    {
        strcpy(Water_Status, "NORMAL");
        strcpy(Pump_Status, "READY");

        IOCLR0 = YELLOW;
        IOSET0 = GREEN | RED;

        IOCLR0 = Pump;
    }
    else
    {
        strcpy(Water_Status, "FULL");
        strcpy(Pump_Status, "READY");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;

        IOCLR0 = Pump;
    }
}
