/*
 * Macros.h
 *
 * Created: 6/28/2019 6:05:31 PM
 *  Author: Farouk
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SETBIT(Register,Bit_num)		( (Register)|= (1<<(Bit_num)))
#define CLEARBIT(Register,Bit_num)		( (Register)&=~(1<<(Bit_num)))
#define TOGGLEBIT(Register,Bit_num)		( (Register)^= (1<<(Bit_num)))
#define IS_BIT_SET(Register,Bit_num)	(((Register) & (1<<(Bit_num)))>>(Bit_num))
#define IS_BIT_CLEAR(Register,Bit_num)	(!IS_BIT_SET(Register,Bit_num))

#define ADC_ENABLE             (ADCSRA |= (1<<7))
#define ADC_START_CONVERSION       (ADCSRA |= (1<<6))

#define NULL	((void *)0x00)

#endif /* MACROS_H_ */