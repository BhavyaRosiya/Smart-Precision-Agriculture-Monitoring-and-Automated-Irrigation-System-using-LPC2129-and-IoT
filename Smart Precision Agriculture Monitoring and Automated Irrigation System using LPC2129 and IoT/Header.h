#include<stdio.h>

typedef unsigned int u32;
typedef int s32;
typedef char s8;
typedef unsigned char u8;

//ADC 
extern u32 adc_read(u8 ch_num);
extern void adc_init(void);

//INTERRUPT DELCLARATIONS
void EINT0_Handler(void) __irq;
void config_vic_for_eint0(void);
void uart0_Handler(void) __irq;
void config_vic_for_uart0(void);

//UART DECLARATION//
void uart0_init(unsigned int baud);
void uart0_tx(unsigned char data);
unsigned char uart0_rx(void);
void uart0_tx_string(char *ptr);
void uart0_tx_integer(int num);
void uart0_tx_float(float f);
void uart0_binary(int num);
int uart0_rx_integer(void);
float uart0_rx_float(void);
void uart0_rx_string(char *p ,int size);
void uart0_tx_hex(int num);
void uart0_tx_octal(int num);
int uart0_atoi(char *);

//DELAY DECLARATION//
void delay_ms(unsigned int ms);
void delay_sec(unsigned int);

//LCD DECLARATION//
void lcd_init(void);
void lcd_data(unsigned char data);
void lcd_cmd(unsigned char cmd);
extern void lcd_string(char *ptr);
extern void lcd_integer(int num);
extern void lcd_float(float f);
extern void lcd_cgram(void);

//CAN DECLARATION
typedef struct CAN1_MSG{
	u32 id;
	u32 byteA;
	u32 byteB;
	u8 rtr;
	u8 dlc;
	u8 ff;
}CAN1;

extern void can1_tx(CAN1 v);
extern void can1_init(void);

//I2C DECLARATION
extern void i2c_init(void);
extern void i2c_write(u8 sa,u8 mr,u8 data);
extern u8 i2c_read(u8 sa,u8 mr);

//SENSOR DECLARATION
void soil_sensor(void);
void water_sensor(void);
void Lm35_Temp(void);
void rain_sensor(void);
void ldr_sensor(void);
void Flame_Sensor(void);
void PIR_Sensor(void);
void RTC_Print(void);
void EEPROM_Data(void);
void CAN_Print(void);
void wifi_Print(void);

//GLOBAL VARIABLES 

// Sensor Values 
extern unsigned int Soil_Moisture;
extern unsigned int Water_Level;
extern unsigned int Temperature;
extern unsigned int Humidity;
extern char Temperature_Status[10];
extern unsigned int Light_Intensity;

// Status Strings 
extern char Soil_Status[10];
extern char Water_Status[10];
extern char Rain_Status[15];
extern char Light_Status[10];
extern char Flame_Status[15];
extern char Motion_Status[15];
extern char Alarm_Status[5];
extern char Security_Status[10];

extern char Pump_Status[5];
//extern char Relay_Status[5];

extern char Wifi_Status[15];
extern char Cloud_Status[15];

extern char RTC_Date[15];
extern char RTC_Time[20];

extern char EEPROM_Status[20];
extern char CAN_Status[15];
extern char CAN_Frame[20];
extern char System_Status[15];

// Display Function 
void Display_System(void);