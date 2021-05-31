/*
 * uc_Config.h
 *
 * Created: 6/28/2019 5:38:22 PM
 *  Author: Farouk
 */ 


#ifndef UC_CONFIG_H_
#define UC_CONFIG_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "StandardTypes.h"
#include "Macros.h"
	
#define F_CPU (1000000U) 
#include <util/delay.h>


typedef enum
{
 FALSE,
 TRUE,
}bool;


#define GLOBAL_INT_ENABLE()		(SETBIT(SREG,7))
#define GLOBAL_INT_DISABLE()	(CLEARBIT(SREG,7))

#endif /* UC_CONFIG_H_ */