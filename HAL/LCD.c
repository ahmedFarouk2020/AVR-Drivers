/*
 * LCD.c
 *
 * Created: 6/30/2020 11:04:39 AM
 *  Author: Farouk
 */ 

#include "LCD.h"
#include "Atmega32A_ADC.h"
#include "ATmega32A_EXT_ISR.h"
#include <util/delay.h>

void LCD_init(void)
{
	LCD_DATA_DIR = 0XFF;
	LCD_CTRL_DIR = 0X07;
	_delay_ms(15);
	LCD_sendCommand(TWO_LINE_8_BITS);
	LCD_sendCommand(DISPLAY_ON_CURSOR_ON);
	LCD_sendCommand(CLEAR_SCREEN);
	_delay_ms(2);
}

void LCD_sendCommand(uint8 command)
{
	LCD_DATA_OUT = command;
	CLEARBIT(LCD_CTRL_OUT, RS); CLEARBIT(LCD_CTRL_OUT, RW); SETBIT(LCD_CTRL_OUT, E);
	_delay_ms(1);
	CLEARBIT(LCD_CTRL_OUT, E);
	_delay_ms(1);
}

void LCD_displayCharacter(uint8 character)
{
	LCD_DATA_OUT = character;
	SETBIT(LCD_CTRL_OUT, RS); CLEARBIT(LCD_CTRL_OUT, RW); SETBIT(LCD_CTRL_OUT, E);
	_delay_ms(1);
	CLEARBIT(LCD_CTRL_OUT, E);
	_delay_ms(1);
}

void LCD_displayString(uint8 * str)
{
	uint8 i=0;
	while(str[i] != 0)
	{
		LCD_displayCharacter(str[i]);
		_delay_ms(100);
		i++;
	}
}