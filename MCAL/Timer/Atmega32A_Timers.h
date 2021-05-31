/*
 * Atmega32A_Timers.h
 *
 * Created: 9/6/2019 5:09:39 PM
 *  Author: Farouk
 */ 


#ifndef ATMEGA32A_TIMERS_H_
#define ATMEGA32A_TIMERS_H_

#include <uc_Config.h>
#include <StandardTypes.h>
#include <Macros.h>
#include <ATmega32A_GPIO.h>
#include <avr/io.h>

/*#define TCCR0	((IO_register *)(0x53))
#define TCNT0	((IO_register *)(0x52))
#define OCR0	((IO_register *)(0x5C))
#define TIMSK	((IO_register *)(0x59))
#define TIFR	((IO_register *)(0x58))*/
	
typedef enum
{
	Timer0_NormalMode=0x00,
	Timer0_CTCMode=0x08,
	Timer0_FastPWMMode=0x48,
	Timer0_PhaseCorrectPWMMode=0x40,
}Timer_Modes;

typedef enum
{
	Timer0_DisableCompOut=0x00,
	Timer0_NonPWM_SETCompOut=0x30,
	Timer0_NonPwm_ClearCompOut=0x20,
	Timer0_NonPwm_ToggleCompOut=0x10,
	Timer0_FastPWM_NonInvertMode=0x20,
	Timer0_FastPWM_InvertMode=0x30,
	Timer0_PhaseCorrect_NonInvertMode=0x20,
	Timer0_PhaseCorrect_InvertMode=0x30,
}CompareOutputMode;

typedef enum
{
	Timer0_Disabled=0x00,
	Timer0_FCPU=0x01,
	Timer0_FCPU_DIV8=0x02,
	Timer0_FCPU_DIV64=0x03,
	Timer0_FCPU_DIV256=0x04,
	Timer0_FCPU_DIV1024=0x05,
	Timer0_ExteranlClock_FallingEdge=0x06,
	Timer0_ExternalClock_RisingEdge=0x07,
}Timer0_ClockSource;

typedef enum
{
	Timer0_InterruptsDisabled0=0x00,
	Timer0_OVF_Enable0=0x01,
	Timer0_Comp_Enable0=0x02,
	Timer0_OVF_Comp_Enable0=0x03,
}Timer0_Interrupt;

void Timer0_Init(
					Timer_Modes TMode,
					CompareOutputMode CMode,
					Timer0_ClockSource Clk,
					Timer0_Interrupt Interrupt);

void Timer0_ForceCompare(void);


extern void (* volatile OverFlow_Isr)(void);
extern void (* volatile CTC_Isr)(void);
#endif /* ATMEGA32A_TIMERS_H_ */