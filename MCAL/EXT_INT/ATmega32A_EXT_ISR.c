/*
 * ATmega32A_EXT_ISR.c
 *
 * Created: 7/19/2019 3:46:43 PM
 *  Author: Farouk
 */ 
#include "ATmega32A_EXT_ISR.h"




 void ( *volatile ISR0_PTR) (void)=NULL;
 void ( *volatile ISR1_PTR) (void)=NULL;
 void ( *volatile ISR2_PTR) (void)=NULL;


ISR(INT0_vect)
{
	if (ISR0_PTR  != NULL)
	{
		ISR0_PTR();
	}	
}

ISR(INT1_vect)
{
		if (ISR1_PTR  != NULL)
		{
			ISR1_PTR();
		}
} 
ISR(INT2_vect)
{
		if (ISR2_PTR  != NULL)
		{
			ISR2_PTR();
		}
}
static void ISR_SettingError(void)
{
	while(1)
	{
		DDRA = 0x01;
		PORTA = 0X01;
		//printf("HardWare Fault \n");
		// Stuck Error
	}
}

void EXT_INT_EnableFunc(
						ATmega32A_EXTINT_Enable INT_number,
						ATmega32A_EXTINT_Sense_control  INT_Sense)
						{
							switch (INT_number)
							{
								case EXT_INT0_Enable:
									 MCUCR &= (0xFC); /* Clear Prev Selection */
									 MCUCR |= (INT_Sense & 0x03);
									 if((INT_Sense & 0xFC) != 0)
									 {
										 ISR_SettingError(); /* Int sence and Int Number are not Compatible */
									 }
									 GICR |= INT_number;
								break;
								case EXT_INT1_Enable:
								MCUCR &= (0xF3);
								MCUCR |= (INT_Sense & 0x0C);
								 if((INT_Sense & 0xF3) != 0)
								 {
									 ISR_SettingError(); /* Int Mode and Int Number are not Compatible */
								 }
								 GICR |= INT_number;
								break;
								case EXT_INT2_Enable:
									 MCUCSR &= 0xBF;
									 MCUCSR |= (INT_Sense & 0x40);
									 if ((INT_Sense & 0xBF) != 0)
									 {
								   		ISR_SettingError(); /* Int Mode and Int Number are not Compatible */
								 	 }
									GICR |= INT_number;
								break;
								default:
									ISR_SettingError(); // Wrong Int Number
								break;
								
							}
						}

void EXT_INT_DisableFunc(ATmega32A_EXTINT_Enable INT_number)
{
	GICR &= (~INT_number);
}