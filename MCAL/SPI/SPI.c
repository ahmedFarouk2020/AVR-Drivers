/*
 * SPI.c
 *
 * Created: 6/14/2019 3:24:16 PM
 *  Author: Farouk
 */ 
#include "uc_Config.h"
#include "StandardTypes.h"
#include "MACROSh.h"
#include "ATmega32A_GPIO.h"
#include "SPI.h"

uint8 toggle = 0;

	void SPI_Init(void)
	{
		
		GPIO_DirectionSet(GPIOB,PIN6,OUTPUT);
		SPCR = (1<<6)| (1<<5);
	}
	void SPI_Write(uint8 Data)
	{
		SPDR = Data;
	}
	uint8 SPI_ReadBuffer(void)
	{
		while ((SPSR & (1<<7)) == 0){}
		return SPDR;
	}
	
	uint8 SPI_ExData(uint8 Data)
	{
		SPI_Write(Data);
		return SPI_ReadBuffer();
	}
	
	void SPI_Config(void)
	{
		// MSB  clk polarity = 1   clk phase = 1   SPI_clk = clk/2   slave 
		SPCR = 0x0C;
		SPSR = 0x01;
		/* Enable SPI */
		SPCR = (1<<6);
	}
	
	void TakeAction(uint8 data)
	{
	       if(data == 0xFF)
		   {
	          GPIO_OutputHandle(GPIOA,PIN0,toggle);
			  TOGGLEBIT(toggle,0);
		   }
	}