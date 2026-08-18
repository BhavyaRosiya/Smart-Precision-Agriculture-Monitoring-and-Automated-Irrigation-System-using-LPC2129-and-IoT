#include<lpc21xx.h>
#include"header.h"

void adc_init(void)
{
  const int a[] = {4,19,9,4,4};
	unsigned int CLKDIV = 0;
	CLKDIV = a[VPBDIV];
	PINSEL1 |= 0x15400000;
	ADCR = 0x00200000 | (CLKDIV << 8);
}

#define DONE ((ADDR >> 31) & 1)
unsigned int adc_read(unsigned char ch)
{
  unsigned int res = 0;
	ADCR |= 1 << 24;
	ADCR |= 1 << ch;
	while(DONE == 0);
	ADCR ^= 1 << ch;
	ADCR ^= 1 << 24;
	res = (ADDR >> 6) & 0x3FF;
	return res;
}
