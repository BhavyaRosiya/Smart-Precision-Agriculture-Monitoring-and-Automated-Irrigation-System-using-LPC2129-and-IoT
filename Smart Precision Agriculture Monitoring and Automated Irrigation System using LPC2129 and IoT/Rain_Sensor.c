#include<lpc21xx.h>
#include<string.h>
#include"header.h"

#define GREEN  0x02
#define YELLOW 0x04
#define RED    0x08
#define Pump  (1<<17)

#define Rain_sens ((IOPIN0 >> 14) & 1) // p0.14

void rain_sensor(void)
{
  if(Rain_sens == 1)          // No Rain
    {
        strcpy(Rain_Status, "NO");
        strcpy(Pump_Status, "READY");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;
    }
    else                        // Rain Detected
    {
        strcpy(Rain_Status, "DETECTED");
        strcpy(Pump_Status, "OFF");

        IOCLR0 = YELLOW;
        IOSET0 = GREEN | RED;

        IOCLR0 = Pump;
    }
}