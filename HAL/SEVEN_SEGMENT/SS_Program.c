/*********************************************************/
/* author  : Farouk                                      */
/* Version : v01                                         */
/* Date    : August 19 2020                              */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SS_interface.h"

#include "DIO_interface.h"
#include "RCC_interface.h"

void SS_Init(uint8_t PortId)
{
	MGPIO_voidSetPinDirection(PortId , PIN0 , OUTPUT );
	MGPIO_voidSetPinDirection(PortId , PIN1 , OUTPUT );
	MGPIO_voidSetPinDirection(PortId , PIN2 , OUTPUT );
	MGPIO_voidSetPinDirection(PortId , PIN3 , OUTPUT );
	MGPIO_voidSetPinDirection(PortId , PIN4 , OUTPUT );
	MGPIO_voidSetPinDirection(PortId , PIN5 , OUTPUT );
	MGPIO_voidSetPinDirection(PortId , PIN6 , OUTPUT );
}



void SS_voidDisplayNum(uint8_t portId, uint8_t Num, uint8_t mode)
{
	
	
	switch(mode)
	{
		case COMMON_CATHODE : 
		          DIO_setPortValue(portId,Num);
				  break;
		case COMMON_ANODE : 
		          DIO_setPortValue(portId,Num);
				  break;
	}
}