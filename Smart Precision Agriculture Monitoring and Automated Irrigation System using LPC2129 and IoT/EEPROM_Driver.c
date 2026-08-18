#include <lpc21xx.h>
#include<string.h>
#include "header.h"

#define GREEN   0x02
#define YELLOW  0x04
#define RED     0x08

void EEPROM_Data(void)
{
 unsigned char temp;

    
    i2c_write(0xA0, 0x07, Water_Level); // write data
    delay_ms(10);

    temp = i2c_read(0xA1, 0x07); //read data

  
    if(temp == Water_Level)
    {
        strcpy(EEPROM_Status, "DATA SAVED");

        IOCLR0 = GREEN;
        IOSET0 = YELLOW | RED;
    }
    else
    {
        strcpy(EEPROM_Status, "WRITE FAIL");

        IOCLR0 = RED;
        IOSET0 = GREEN | YELLOW;
    }

    
    //uart0_tx_string("\r\nWater Level Stored in EEPROM = ");
    //uart0_tx_integer(temp);
    //uart0_tx_string("%\r\n");
}