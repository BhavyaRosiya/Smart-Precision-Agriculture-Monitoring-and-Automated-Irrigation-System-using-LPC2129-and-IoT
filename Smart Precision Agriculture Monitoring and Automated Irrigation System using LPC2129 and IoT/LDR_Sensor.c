#include<lpc21xx.h>
#include<string.h>
#include"header.h"

#define GREEN  0x02
#define YELLOW 0x04
#define RED    0x08

void ldr_sensor(void)
{
 unsigned int value, temp;

    value = adc_read(3);

    temp = (value * 100) / 1023;

    Light_Intensity = temp;

    if(temp >= 70)
    {
        strcpy(Light_Status, "HIGH");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;
    }
    else if(temp >= 30)
    {
        strcpy(Light_Status, "MEDIUM");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;
    }
    else
    {
        strcpy(Light_Status, "LOW");

        IOCLR0 = YELLOW;
        IOSET0 = GREEN | RED;
    }
}
