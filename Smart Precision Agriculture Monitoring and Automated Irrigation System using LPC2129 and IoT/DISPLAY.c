#include <lpc21xx.h>
#include "header.h"

void Display_System(void)
{
    uart0_tx_string("=================================================\r\n");
    uart0_tx_string("SMART PRECISION AGRICULTURE MONITORING SYSTEM\r\n");
    uart0_tx_string("=================================================\r\n");

    uart0_tx_string("Controller     : LPC2129 ARM7\r\n");
    uart0_tx_string("Project Status : RUNNING\r\n");
    uart0_tx_string("---------------------------------------------\r\n");

    // Soil 
    uart0_tx_string("Soil Moisture  : ");
    uart0_tx_integer(Soil_Moisture);
    uart0_tx_string("%\r\n");

    // Water
    uart0_tx_string("Water Level    : ");
    uart0_tx_integer(Water_Level);
    uart0_tx_string("%\r\n");

    // Temperature 
    uart0_tx_string("Temperature    : ");
    uart0_tx_integer(Temperature);
    uart0_tx_string(" C\r\n");

    // Humidity
    //uart0_tx_string("Humidity       : ");
    //uart0_tx_integer(Humidity);
    //uart0_tx_string("%\r\n");

    // Rain 
    uart0_tx_string("Rain Status    : ");
    uart0_tx_string(Rain_Status);
    uart0_tx_string("\r\n");

    // Light 
    uart0_tx_string("Light Intensity: ");
    uart0_tx_string(Light_Status);
    uart0_tx_string("\r\n");

    // Flame 
    uart0_tx_string("Flame Status   : ");
    uart0_tx_string(Flame_Status);
    uart0_tx_string("\r\n");

    // Motion 
    uart0_tx_string("Motion Status  : ");
    uart0_tx_string(Motion_Status);
    uart0_tx_string("\r\n");

    // Pump 
    uart0_tx_string("Pump Status    : ");
    uart0_tx_string(Pump_Status);
    uart0_tx_string("\r\n");

    // Relay 
    //uart0_tx_string("Relay Status   : ");
    //uart0_tx_string(Relay_Status);
    //uart0_tx_string("\r\n");

    // Wi-Fi 
    uart0_tx_string("Wi-Fi Status   : ");
    uart0_tx_string(Wifi_Status);
    uart0_tx_string("\r\n");

    // Cloud 
    uart0_tx_string("Cloud Status   : ");
    uart0_tx_string(Cloud_Status);
    uart0_tx_string("\r\n");

    // RTC Date 
    //uart0_tx_string("RTC Date       : ");
    //uart0_tx_string(RTC_Date);
    //uart0_tx_string("\r\n");

    // RTC Time 
    //uart0_tx_string("RTC Time       : ");
    //uart0_tx_string(RTC_Time);
    //uart0_tx_string("\r\n");

    // EEPROM 
    uart0_tx_string("EEPROM Status  : ");
    uart0_tx_string(EEPROM_Status);
    uart0_tx_string("\r\n");

    // CAN 
    uart0_tx_string("CAN Status     : ");
    uart0_tx_string(CAN_Status);
    uart0_tx_string("\r\n");

    // System 
    uart0_tx_string("System Status  : ");
    uart0_tx_string(System_Status);
    uart0_tx_string("\r\n");

   

    if(Soil_Moisture < 30)
    {
        uart0_tx_string("Warning        : SOIL DRY\r\n");
        uart0_tx_string("Action         : IRRIGATION STARTED\r\n");
    }

    if(Rain_Status[0]=='D')     
    {
        uart0_tx_string("Message        : RAIN DETECTED\r\n");
        uart0_tx_string("Action         : IRRIGATION STOPPED\r\n");
    }

    if(Flame_Status[0]=='D')     
    {
        uart0_tx_string("Emergency      : FIRE ALERT\r\n");
    }

    if(Motion_Status[0]=='D')   
    {
        uart0_tx_string("Message        : UNAUTHORIZED MOVEMENT\r\n");
    }

    if(Water_Level < 20)
    {
        uart0_tx_string("Warning        : LOW WATER LEVEL\r\n");
        uart0_tx_string("Action         : PUMP PROTECTED\r\n");
    }

    uart0_tx_string("---------------------------------------------\r\n");
    uart0_tx_string("Monitoring...\r\n\r\n");
}