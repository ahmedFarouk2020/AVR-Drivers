/*
 * Atmega32A_Timers.c
 *
 * Created: 9/6/2019 5:09:20 PM
 *  Author: Farouk
 */ 

//#define _AVR_ATMEGA32A_H_INCLUDED
#include "Atmega32A_Timers.h"
#include <avr/interrupt.h>
#include "ATmega32A_EXT_ISR.h"





void (* volatile OverFlow_Isr)(void) = NULL;
void (* volatile CTC_Isr)(void) = NULL;


ISR(_VECTOR(11))
{
	if (OverFlow_Isr != NULL)
	{
		OverFlow_Isr();
	}
}

ISR( _VECTOR(10))
{
	if ( CTC_Isr != NULL)
	{
		CTC_Isr();
	}
}


void Timer0_Init(
					Timer_Modes TMode,
					CompareOutputMode CMode,
					Timer0_ClockSource Clk,
					Timer0_Interrupt Interrupt)
{
		TIMSK &= 0xFC;
		TIMSK |= Interrupt;
		TCCR0 = TMode | CMode | Clk;
		
}