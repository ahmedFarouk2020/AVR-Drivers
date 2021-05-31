/*
 * LCD.h
 *
 * Created: 6/30/2020 10:49:36 AM
 *  Author: Farouk
 */ 

// for 8-bit mode only i will modify it later
#ifndef LCD_H_
#define LCD_H_

#include "Macros.h"
#include "StandardTypes.h"
#include "uc_Config.h"

#define RS 							0
#define RW  						1
#define E   						2
#define LCD_DATA_OUT 				PORTD
#define LCD_DATA_IN  				PIND
#define LCD_DATA_DIR 				DDRD
#define LCD_CTRL_OUT 				PORTC
#define LCD_CTRL_IN  				PINC
#define LCD_CTRL_DIR 				DDRC
// commands
#define DISPLAY_OFF_CURSOR_OFF 		0x08
#define DISPLAY_ON_CURSOR_ON   		0x0E
#define DISPLAY_ON_CURSOR_OFF   	0x0C
#define DISPLAY_ON_CURSOR_BLINKING  0x0F
#define SHIFT_LEFT					0x18
#define SHIFT_RIGHT					0x1C
#define TWO_LINE_8_BITS 			0x38
#define CURSOR_OFF      			0x0c
#define CLEAR_SCREEN    			0x01
#define LINE_1                      0x80
#define LINE_2                      0xC0
// function prototype
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 character);
void LCD_init(void);
void LCD_displayString(uint8 * str);
void LCD_displayInt(int a_number);
void LCD_displayOnColRow(uint8 row , uint8 col , const uint8 * str);
void LCD_goToColRow(uint8 row , uint8 col);
void LCD_clearScreen(void);




#endif /* LCD_H_ */