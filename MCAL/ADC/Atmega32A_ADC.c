/*
 * Atmega32A_ADC.c
 *
 * Created: 8/23/2019 5:28:01 PM
 *  Author: Farouk
 */ 


#include "Atmega32A_ADC.h"

void ( *volatile ADC_INT_Fun) (void) = NULL;




/*#ifdef _AVR_ATMEGA32A_H_INCLUDED
	#error "ASYOD"
#endif*/

void	ADC_Init(ADC_TrigMode	ADC_Mode, ADC_Prescale	Prescaler, ADC_WorkMode	INT_OR_POLLING,
                 ADC_VoltRef ADC_VoltageReferPin, ADC_Ch_Select	ADC_Channel)
{
	ADMUX = 0x00;
	ADCSRA = 0x00;

	//DDRA &= ~(1<<DDRA2);  // SET ADC CHANNEL AS INPUT
	//PORTA |= 1<<PORTA2; 
	
	ADMUX |=  ( ADC_Channel | ADC_VoltageReferPin );  //0b11000010
	
	ADCSRA |=  (Prescaler | (ADC_Mode<<8) | INT_OR_POLLING); //0b00011011;
	ADC_ENABLE;
	SFIOR &= ~(0xE0);
	SFIOR |= (ADC_Mode>>8);

}


ISR(ADC_vect){
	if(ADC_INT_Fun != NULL)
	ADC_INT_Fun();
}
			