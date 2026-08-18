#include<LPC21xx.h>
#include<string.h>
#include "header.h"

#define GREEN   0x02
#define YELLOW  0x04
#define RED     0x08

CAN1 tx_msg;

void CAN_Print(void)
{
   
    tx_msg.id  = 0x101;
    tx_msg.rtr = 0;
    tx_msg.dlc = 8;

    tx_msg.byteA = 0x11223344;
    tx_msg.byteB = 0x55667788;


    can1_tx(tx_msg); //send can frame


    strcpy(CAN_Status, "ACTIVE");
    strcpy(CAN_Frame, "SENT");

    IOCLR0 = GREEN;
    IOSET0 = YELLOW | RED;
}