/*
 * Atmega32A_ADC.h
 *
 * Created: 6/23/2020 9:28:11 PM
 *  Author: farouk
 */ 


#ifndef ATMEGA32A_ADC_H_
#define ATMEGA32A_ADC_H_


#define NULL	((void *)0x00)



#include "uc_Config.h"
#include "Macros.h"
#include "StandardTypes.h"



typedef enum
{
	AREF_VoltRef=0x00,
	AVCC_VoltRef=0x40,
	_2_56V_VoltREF=0xC0,
}ADC_VoltRef;

typedef enum
{
	LEFT_Adjust=0x20,
	RIGHT_Adjust=0x00,
}ADC_DataAdjustment;

typedef enum
{
	ADC0_Channel,
	ADC1_Channel,
	ADC2_Channel,
	ADC3_Channel,
	ADC4_Channel,
	ADC5_Channel,
	ADC6_Channel,
	ADC7_Channel,
	DIFF_PADC0_NADC0_G10x,
	DIFF_PADC1_NADC0_G10x,
}ADC_Ch_Select;


typedef enum
{
	SingleConvertion=0x0000,
	AutoTrig_FreeRun=0x0020,      //the last two bits for SFIOR and the others for polling or trigger
	AutoTrig_AnalogComp=0x2020,
	AutoTrig_INT0_Req=4020,
	
}ADC_TrigMode;

typedef enum
{
	ADC_Polling=0x00,
	ADC_InterruptEnable=0x08,
}ADC_WorkMode;

typedef enum
{
	ADC_Div_2_,
	ADC_Div_2,
	ADC_Div_4,
	ADC_Div_8,
	ADC_Div_16,
	ADC_Div_32,
	ADC_Div_64,
	ADC_Div_128,
}ADC_Prescale;



void ADC_Init(ADC_TrigMode	ADC_Mode, ADC_Prescale	Prescaler, ADC_WorkMode	INT_OR_POLLING,
               ADC_VoltRef ADC_VoltageReferPin, ADC_Ch_Select	ADC_Channel);

extern void ( *volatile ADC_INT_Fun) (void);


#endif /* ATMEGA32A_ADC_H_ */