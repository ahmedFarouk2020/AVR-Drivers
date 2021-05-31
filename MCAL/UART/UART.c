/*
 * UART.c
 *
 * Created: 6/27/2020 1:17:26 PM
 *  Author: Farouk
 */ 

#include "UART.h"
#include <util/delay.h>

void uart_transmit_init (baud_rate BR, Stop_bit_setting SB, Parity_mode pm, Synchronization_mode s_mode, Char_Size size, Polling_or_INT trig_modeT)
{
	ENABLE_TRANSMITTER; // UCSRB= (1<<3)
	UCSRB |= trig_modeT ;
	UCSRC|= (1<<URSEL) | SB | pm | s_mode | size ;
	
	//UBRR_value = (1000000/(16*BR) )-1;
	UBRRL= 0x06;//UBRRL = ( UBRR_value<<8 ) ;
	//CLEARBIT(UBRRH, URSEL) ; // UBRRH &= ~(1<<URSEL)
	//UBRRH = (UBRR_value>>8) ;
}

void uart_receive_init(baud_rate BR, Stop_bit_setting SB, Parity_mode pm, Synchronization_mode s_mode, Char_Size size, Polling_or_INT trig_modeR)
{
	ENABLE_RECEIVER;
	UCSRB |= trig_modeR;
	
	UCSRC|= (1<<URSEL) | SB | pm | s_mode | size ;
	
	//UBRR_value = (1000000/(16*BR) )-1;
	UBRRL= 0x06;//UBRRL = (uint8) UBRR_value ;
	//CLEARBIT(UBRRH, URSEL) ; // UBRRH &= ~(1<<URSEL)
	//UBRRH = (uint8) (UBRR_value>>8) ;
}



