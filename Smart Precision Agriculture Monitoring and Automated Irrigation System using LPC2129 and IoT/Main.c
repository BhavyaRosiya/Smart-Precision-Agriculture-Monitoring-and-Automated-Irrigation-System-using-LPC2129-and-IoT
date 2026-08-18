#include<lpc21xx.h>
#include"header.h"

#define Pump (1 << 17)
#define GREEN 0x02
#define YELLOW 0x04
#define RED 0x08
#define BUZZER  (1<<21)  //BUZZER IN RADOLABZ BOARD

#define Rain_sens ((IOPIN0 >> 14) & 1) //Lpc2129 p0.14
#define flame_sens ((IOPIN0 >> 15 ) & 1) //LP2129 P0.15
#define Pir_sens ((IOPIN0 >> 16 ) & 1)


int value,temp,flag;
int main()
{
  uart0_init(9600);
  adc_init();
	i2c_init();
	//can1_init();
  lcd_init();
	

	IODIR0 |= Pump;
	IODIR0 |= GREEN | YELLOW | RED; // LEDs
	IOSET0 |= GREEN | YELLOW | RED;

	  uart0_tx_string("=================================================\r\n");
    uart0_tx_string("SMART PRECISION AGRICULTURE MONITORING SYSTEM\r\n");
    uart0_tx_string("=================================================\r\n");

    uart0_tx_string("Controller     : LPC2129 ARM7\r\n");
    uart0_tx_string("Project Status : RUNNING\r\n");
    uart0_tx_string("---------------------------------------------\r\n");

    lcd_cmd(0x01);
    lcd_cmd(0x80);
    lcd_string("SMART AGRI");
    lcd_cmd(0xC0);
    lcd_string("SYSTEM READY");

    delay_ms(1000);

	
 while(1)
  {
		
		
        soil_sensor();
        water_sensor();
        Lm35_Temp();
        rain_sensor();
        ldr_sensor();
        Flame_Sensor();
        PIR_Sensor();

       
       // RTC_Print();
        EEPROM_Data();
       // CAN_Print();
       // wifi_Print();

       
        Display_System();

        delay_ms(2000);
  }
}