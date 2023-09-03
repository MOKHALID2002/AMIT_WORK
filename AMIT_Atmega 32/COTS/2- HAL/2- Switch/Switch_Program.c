/*
 * Switch_Program.c
 *
 * Created: 12/09/2022 01:46:07
 *  Author: Mohammed
 */ 
//Priority --> Utiles
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_interface.h"

//HAL
#include "Switch_interface.h"

u8 Switch_GetState(u8 Port_Id,u8 Pin_Id)
{
	u8 Switch_State;
	
	DIO_SetPinDirection(Port_Id,Pin_Id,DIO_PortInput);
	DIO_ReadPinValue(Port_Id,Pin_Id,& Switch_State);
	
	return Switch_State;
}