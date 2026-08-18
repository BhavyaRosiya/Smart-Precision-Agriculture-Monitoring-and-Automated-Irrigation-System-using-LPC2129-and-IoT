#include <lpc21xx.h>
#include "header.h"

void RTC_Print(void)
{
    unsigned char sec, min, hour;
    unsigned char date, month, year;
    unsigned char am_pm;

    sec   = i2c_read(0xD1, 0x00);
    min   = i2c_read(0xD1, 0x01);
    hour  = i2c_read(0xD1, 0x02);
    date  = i2c_read(0xD1, 0x04);
    month = i2c_read(0xD1, 0x05);
    year  = i2c_read(0xD1, 0x06);

    am_pm = (hour >> 5) & 1;

    sprintf(RTC_Date, "%c%c/%c%c/20%c%c",
            (date/16)+'0', (date%16)+'0',
            (month/16)+'0', (month%16)+'0',
            (year/16)+'0', (year%16)+'0');

    sprintf(RTC_Time, "%c%c:%c%c:%c%c %s",
            (hour/16)+'0', (hour%16)+'0',
            (min/16)+'0', (min%16)+'0',
            (sec/16)+'0', (sec%16)+'0',
            am_pm ? "PM" : "AM");
}