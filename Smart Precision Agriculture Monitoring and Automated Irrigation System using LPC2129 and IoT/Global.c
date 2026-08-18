#include "header.h"

// Sensor Values 
unsigned int Soil_Moisture = 0;
unsigned int Water_Level   = 0;
unsigned int Temperature   = 0;
unsigned int Humidity      = 0;
unsigned int Light_Intensity = 0;

// Status Strings 
char Soil_Status[10]   = "NORMAL";
char Water_Status[10]  = "NORMAL";
char Rain_Status[15]   = "NO";
char Light_Status[10]  = "HIGH";
char Flame_Status[15]  = "SAFE";
char Motion_Status[15] = "CLEAR";
char Temperature_Status[10] = "NORMAL";
char Alarm_Status[5] = "OFF";
char Security_Status[10] = "NORMAL";


char Pump_Status[5]  = "OFF";
//char Relay_Status[5] = "OFF";

char Wifi_Status[15]  = "CONNECTED";
char Cloud_Status[15] = "UPDATED";

char RTC_Date[15] = "01/08/2026";
char RTC_Time[20] = "10:45:30 AM";

char EEPROM_Status[20] = "DATA SAVED";
char CAN_Status[15]    = "ACTIVE";
char CAN_Frame[20] = "SENT";
char System_Status[15] = "NORMAL";