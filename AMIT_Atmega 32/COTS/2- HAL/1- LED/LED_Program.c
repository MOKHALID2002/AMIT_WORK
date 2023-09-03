/*
 * LED_Program.c
 *
 * Created: 10/09/2022 14:51:47
 * Author: Mohammed
 */ 

//Priority --> Utiles
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
//MCAL
#include "DIO_interface.h"
//HAL
#include "LED_Interface.h"

void LED_STATE(u8 Port_Id,u8 Pin_Id,u8 CONNECTION)
{
	switch(CONNECTION)
	{
		case 0: 
		DIO_SetPinDirection(Port_Id,Pin_Id,DIO_PinOutput);
		DIO_SetPinValue(Port_Id,Pin_Id,DIO_Pin_Low);
		break;
		
		case 1: 
		DIO_SetPinDirection(Port_Id,Pin_Id,DIO_PinOutput);
		DIO_SetPinValue(Port_Id,Pin_Id,DIO_Pin_High);
		break;
		
	}
}

void LED_TOGGLE(u8 Port_Id,u8 Pin_Id)
{
	DIO_SetPinDirection(Port_Id,Pin_Id,DIO_PinOutput);
	DIO_TogglePinValue(Port_Id,Pin_Id);
}

