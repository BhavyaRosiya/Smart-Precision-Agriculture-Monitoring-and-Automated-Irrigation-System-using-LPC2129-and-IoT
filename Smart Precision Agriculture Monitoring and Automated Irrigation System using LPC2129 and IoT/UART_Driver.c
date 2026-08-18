#include<LPC21xx.h>
#include"header.h"
void uart0_init(unsigned int baud)
{
  int PCLK , result = 0;
	int a[] = {15000000,60000000,30000000};
	
	PCLK = a[VPBDIV];
	
	result = PCLK / ( 16 * baud);
	
	
	PINSEL0 |= 0x05;
	U0LCR = 0x83;
	U0DLL = (result & 0xFF);
	U0DLM = (result >> 8) & 0xFF;
	U0LCR = 0x03;
}

#define THRE ((U0LSR >> 5) & 1)
void uart0_tx(unsigned char data)
{
  U0THR = data;
	while(THRE == 0);
}

#define RDR (U0LSR & 1)
unsigned char uart0_rx(void)
{
   while(RDR == 0);
	 return U0RBR;
}

void uart0_tx_string(char *ptr)
{
  while(*ptr)
	{
	  uart0_tx(*ptr);
		ptr++;
	}
}

void uart0_binary(int num)
{
  int pos, temp;
	for(pos = 7; pos >= 0; pos--)
	{
	  temp = num >> pos & 1;
		uart0_tx(temp + 48);
	}
}

void uart0_tx_integer(int num)
{
  int a[10] , i = 0;
	if(num == 0)
	{
	  uart0_tx('0');
		return;
	}
	
	if(num < 0)
	{
	  uart0_tx('-');
		num =-num;
	}
	
	while(num > 0)
	{
	  a[i] = num % 10 + 48;
		num = num / 10;
		i++;
	}
	
	for(i = i - 1; i >= 0; i--)
	uart0_tx(a[i]);
}

void uart0_tx_float(float f)
{
  int num;
	
	if(f == 0)
	{
	  uart0_tx_string("0.0");
		return;
	}
	
	if(f < 0)
	{
	  uart0_tx('-');
		f =-f;
	}
	
	num = f;
	uart0_tx_integer(num);
	uart0_tx('.');
	num = ((f - num) * 100 + 0.05);
	uart0_tx_integer(num);
}

int uart0_rx_integer(void)
{
  int temp , num = 0 ,sign = 1;
	
	while(1)
	{
	  temp = uart0_rx();
		uart0_tx(temp);
		
		if(temp == '\r')
		break;
		
		if(temp == '-')
		{
		  sign = -1;
			continue;
		}
		
		num  = num * 10 + ( temp - '0');
	}
	return num * sign;
}

float uart0_rx_float(void)
{
    char ch;
    float num = 0, frac = 0.1;
    int sign = 1, flag = 0;

    while(1)
    {
        ch = uart0_rx();
        uart0_tx(ch);

        if(ch == '\r')
            break;

        if(ch == '-')
        {
            sign = -1;
            continue;
        }

        if(ch == '.')
        {
            flag = 1;
            continue;
        }

        if(flag == 0)
            num = num * 10 + (ch - '0');
        else
        {
            num = num + (ch - '0') * frac;
            frac = frac / 10;
        }
    }

    return num * sign;
}

void uart0_rx_string(char *p, int size)
{
  int i;
	char ch;
	
	for(i = 0; i < size - 1; i++)
	{
	  while(RDR == 0);
		
		ch = U0RBR;
		
		if(ch == '\r')
		break;
		
		uart0_tx(ch);
		
		p[i] = ch;
	}
	
	p[i] = '\0';
}
void uart0_tx_hex(int num)
{
 int rem, i = 0;
    char a[20];
   uart0_tx_string("0x");
    if(num == 0)
    {
        uart0_tx('0');
        return;
    }

    while(num > 0)
    {
        rem = num % 16;

        if(rem < 10)
            a[i] = rem + 48;
        else
            a[i] = rem + 55;

        num = num / 16;

        i++;
    }

    for(i = i - 1; i >= 0; i--)
    {
        uart0_tx(a[i]);
    }
}

void uart0_tx_octal(int num)
{
	 int rem , i = 0;
   char a[20];
	 uart0_tx_string("0");
	 
	if(num == 0)
	{
		 uart0_tx('0');
		 return;
	}
	
	while(num > 0)
	{
		rem = num % 8;
		a[i] = rem + '0';
		
		num = num / 8;
		i++;
	}
   	for(i = i - 1; i >= 0; i--)
	  uart0_tx(a[i]);
 }
