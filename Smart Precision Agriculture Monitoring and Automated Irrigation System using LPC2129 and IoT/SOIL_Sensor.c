#include <lpc21xx.h>
#include <string.h>
#include "header.h"

#define GREEN 0x02
#define YELLOW 0x04
#define RED 0x08
#define Pump (1 << 17) // RElay Connect to P0.17

void soil_sensor(void)
{
    unsigned int value;

    value = adc_read(0);

    Soil_Moisture = (value * 100) / 1023;

    if(Soil_Moisture < 30)
    {
        strcpy(Soil_Status, "DRY");
        strcpy(Pump_Status, "ON");

        IOCLR0 = YELLOW;
        IOSET0 = GREEN | RED;

        IOSET0 = Pump;
    }
    else if(Soil_Moisture < 70)
    {
        strcpy(Soil_Status, "NORMAL");
        strcpy(Pump_Status, "OFF");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;

        IOCLR0 = Pump;
    }
    else
    {
        strcpy(Soil_Status, "WET");
        strcpy(Pump_Status, "OFF");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;

        IOCLR0 = Pump;
    }
}