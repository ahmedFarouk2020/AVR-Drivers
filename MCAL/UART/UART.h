/*
 * UART.h
 *
 * Created: 6/27/2020 11:10:50 AM
 *  Author: Farouk
 */ 


#ifndef UART_H_
#define UART_H_

#include "Macros.h"
#include "StandardTypes.h"
#include "uc_Config.h"

#define ENABLE_TRANSMITTER  UCSRB= (1<<3)
#define ENABLE_RECEIVER     UCSRB= (1<<4)

typedef enum{
// first 2 bit for UCSRC the last 2 bits for UCSRB
_5_bits=0x00,
_6_bits=0x02, 
_7_bits=0x04,
_8_bits=0x06,
//_9_bits=0x0406
	
}Char_Size;

typedef enum{
// in UCSRB reg
polling=0x00,
Receive_Complete_INT=0x80,
Transmit_Complete_INT=0x40,
Data_REG_Empty_INT=0x20
	
}Polling_or_INT;

typedef enum{
// in UCSRC reg 
Asynchronous=0x00,
Synchronous=0x40
}Synchronization_mode;

typedef enum{
// in UCSRC reg
disabled=0x00,
even_parity=0x20,
odd_parity=0x30
}Parity_mode;

typedef enum{
// in UCSRC
_1_stopbit=0x00,
_2_stopbits=0x08,
}Stop_bit_setting;

/*typedef enum{
	
receiev_complete_flag,
Transmit_Complete_flag,
transmit_buffer_empty_flag,
Frame_Error_flag,
Data_OverRun_flag,
parity_error_flag
}UART_flags;
*/

typedef enum{
// in UBRR
_24=2400, 
_48=4800,
_96=9600	
}baud_rate;

 uint16 UBRR_value; 

void uart_transmit_init(baud_rate BR, Stop_bit_setting SB, Parity_mode pm, Synchronization_mode s_mode, Char_Size size, Polling_or_INT trig_modeT);
void uart_receive_init(baud_rate BR, Stop_bit_setting SB, Parity_mode pm, Synchronization_mode s_mode, Char_Size size, Polling_or_INT trig_modeR);
//void uart_send (Polling_or_INT trig_mode1, Polling_or_INT trig_mode2);

//void uart_receive (Polling_or_INT mode);
#endif /* UART_H_ */