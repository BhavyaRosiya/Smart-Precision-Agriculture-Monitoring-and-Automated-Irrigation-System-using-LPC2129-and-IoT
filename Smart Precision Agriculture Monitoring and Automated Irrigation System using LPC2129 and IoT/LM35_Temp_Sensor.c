#include<lpc21xx.h>
#include<string.h>
#include"header.h"

#define RED 0x08
#define GREEN 0x02
#define YELLOW 0x04

void Lm35_Temp(void)
{
  unsigned int value;

    value = adc_read(2);

    Temperature = (value * 330) / 1023;

    if(Temperature < 20)
    {
        strcpy(Temperature_Status, "LOW");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;
    }
    else if(Temperature <= 35)
    {
        strcpy(Temperature_Status, "NORMAL");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;
    }
    else
    {
        strcpy(Temperature_Status, "HIGH");

        IOCLR0 = YELLOW;
        IOSET0 = GREEN | RED;
    }
}