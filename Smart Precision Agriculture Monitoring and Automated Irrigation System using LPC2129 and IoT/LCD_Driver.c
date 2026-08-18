#include<LPC21xx.h>
#include"header.h"

void lcd_data(unsigned char data)
{
  unsigned int temp;
	IOCLR1 = 0xFE << 16;
	temp = (data & 0xF0) << 16;
	IOSET1 = temp;
	IOSET1 = 1 << 17;
	IOCLR1 = 1 << 18;
	IOSET1 = 1 << 19;
	delay_ms(2);
	IOCLR1 = 1 << 19;
	
	IOCLR1 = 0xFE << 16;
	temp = (data & 0x0F) << 20;
	IOSET1 = temp;
	IOSET1 = 1 << 17;
	IOCLR1 = 1 << 18;
	IOSET1 = 1 << 19;
	delay_ms(2);
	IOCLR1 = 1 << 19;
}

void lcd_cmd(unsigned char cmd)
{
  unsigned int temp;
	IOCLR1 = 0xFE << 16;
	temp = (cmd & 0xF0) << 16;
	IOSET1 = temp;
	IOCLR1 = 1 << 17;
	IOCLR1 = 1 << 18;
	IOSET1 = 1 << 19;
	delay_ms(2);
	IOCLR1 = 1 << 19;
	
	IOCLR1 = 0xFE << 16;
	temp = (cmd & 0x0F) << 20;
	IOSET1 = temp;
	IOCLR1 = 1 << 17;
	IOCLR1 = 1 << 18;
	IOSET1 = 1 << 19;
	delay_ms(2);
	IOCLR1 = 1 << 19;
}

void lcd_init(void)
{
  IODIR1 = 0xFE << 16;
	IOCLR1 = 1 << 19;
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
}

void lcd_string(char *ptr)
{
  while(*ptr != '\0')
	{
	  lcd_data(*ptr);
		ptr++;
	}
}

void lcd_integer(int num)
{
  int a[10] , i=0;
	
	if(num == 0)
	lcd_data('0');
	
	if(num < 0)
	{
	  num = -num;
		lcd_data('-');
	}
	
	while(num > 0)
	{
	  a[i] = num % 10 + 48;
		num = num / 10;
		i++;
	}
	
	for(i = i - 1; i >= 0; i--)
	lcd_data(a[i]);
}

void lcd_float(float f)
{
  int num;
	
	if(f < 0)
	{
	  lcd_data('-');
	  f = -f;
	}
	
	if(f == 0)
	{
	lcd_string("0.0");
	return;
	}
	
	num = f;
	
	lcd_integer(num);
	lcd_data('.');
	num = ((f - num) * 100 + 0.05);
	lcd_integer(num);
}

void lcd_cgram(void)
{
  int i;
  unsigned char a[] = {0x05,0x01,0x05,0x12,0x04,0x34,0x45,0x00};
  lcd_cmd(0x40);
	for(i = 0; i < 8; i++)
	lcd_data(a[i]);
}


