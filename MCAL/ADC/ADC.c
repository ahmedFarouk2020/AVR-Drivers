/*
 * ADC.c
 *
 * Created: 9/18/2021 9:28:11 PM
 *  Author: Overflow
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


/*****
 * Description: set global initialization to all channels [prescalar,voltage ref,int or poll,operation mode]
 * Paramerters: uint8 mode (single conversion, free running, ..)
 * 				uint8 prescalar (ADC_Div_2)
 *				uint8 trig_mode (INt, polling)
 *				uint8 reference volt ()
 * Return: none
 * Ex: ADC_Init(AutoTrig_FreeRun,ADC_Div_128,ADC_Polling,_2_56V_VoltREF);
 */
void ADC_Init(ADC_Mode Mode, ADC_Prescale Prescaler, ADC_ConvCompleteCheck int_or_pol,
               ADC_VoltRef ref_volt)
{
	// reset registers
	ADMUX  = 0x00;
	ADCSRA = 0x00;
	// enable channel & define the refrence voltage
	ADMUX |= ref_volt;  //0b11000010
	
    // set ADEN in ADCSRA (ADC Enable)
    SET_BIT(ADCSRA,ADC_ENABLE_BIT);
	
	// set preescaler & trigger mode & int_or_polling
	ADCSRA |=  (Prescaler | Mode | int_or_pol); //0b00011011;
	// clear SFIOR (last 4 bits)
	SFIOR &= ~(0xE0);
	// set auto-trigger mode
	SFIOR |= (Mode>>8);

}


/*****
 * Description: Read the value of ADC data register 
 * Paramerters: uint8 channel_ID
 * Return: uint16_t sensor reading
 * Ex: uint16_t result = Adc_getReading(ADC3_Channel);
 */
uint16_t ADC_GetReading(ADC_Ch_Select channel)
{
	// select ADC channel
	ADMUX |=  channel;
	// set ADSC in ADCSRA ADC (start conversion)
	SET_BIT(ADCSRA,ADC_START_CONVERSION);
	// wait until flag is set (conversion completed)
	while(!GET_BIT(ADCSRA,ADC_CONVERSION_COMPLETED_FLAG));
	
	uint16_t reading = ADC_DATA; 
	
	// clear the flag (must be the last step)
	SET_BIT(ADCSRA,ADC_CONVERSION_COMPLETED_FLAG);
	
	return reading;
}

#if KEY == LOCKED
void ADC_Set_Callback(void(*pf)(void))
{
	ADC_Callback = pf;
}
#endif