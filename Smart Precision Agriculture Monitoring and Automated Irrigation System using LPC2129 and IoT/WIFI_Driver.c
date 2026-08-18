#include <lpc21xx.h>
#include<string.h>
#include "header.h"

#define GREEN   0x02
#define YELLOW  0x04
#define RED     0x08

void wifi_Print(void)
{
     /*
       ESP8266 Wi-Fi Module
       Status Update
    */


    /* Wi-Fi Connection Status */

    strcpy(Wifi_Status, "CONNECTED");


    /* ThingSpeak Cloud Status */
													 
    strcpy(Cloud_Status, "UPDATED");


    
     

       uart0_tx_string("AT\r\n");
       delay_ms(500);

       uart0_tx_string("AT+CIPSTATUS\r\n");
       delay_ms(500);

    


    /*
       LED Indication

       GREEN  -> WiFi Connected
       YELLOW -> Connecting
       RED    -> Error
    */

    IOCLR0 = GREEN | YELLOW | RED;

    IOSET0 = GREEN;
}