/*
 * SSD_Program.c
 *
 * Created: 18/09/2022 12:36:49
 *  Author: Mohammed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_Interface.h"

/* HAL */
#include "SSD_Interface.h"

void SSD_ON(void)
{
	DIO_SetPinValue(DIO_PORTB,DIO_Pin1,DIO_Pin_High);  //Left
	DIO_SetPinValue(DIO_PORTB,DIO_Pin2,DIO_Pin_High); //Right
	DIO_SetPinValue(DIO_PORTB,DIO_Pin3,DIO_Pin_Low);
}

void SSD_DisplayNum(u8 DisplayedNumber)
{
	 WriteHalfPort(DisplayedNumber);
}

void SSD_DisplayTwoNumbers(u8 FirstNum,u8 SecondNum)
{
	//Activate Left Part of the SSD
	DIO_SetPinValue(DIO_PORTB,DIO_Pin1,DIO_Pin_Low);  //Left
	DIO_SetPinValue(DIO_PORTB,DIO_Pin2,DIO_Pin_High); //Right
	DIO_SetPinValue(DIO_PORTB,DIO_Pin3,DIO_Pin_Low);
	SSD_DisplayNum(FirstNum);
	_delay_ms(2);
	
	//Activate Right Part of the SSD
	DIO_SetPinValue(DIO_PORTB,DIO_Pin1,DIO_Pin_High);  //Left
	DIO_SetPinValue(DIO_PORTB,DIO_Pin2,DIO_Pin_Low); //Right
	DIO_SetPinValue(DIO_PORTB,DIO_Pin3,DIO_Pin_Low);
	SSD_DisplayNum(SecondNum);
	_delay_ms(2);
}

static void WriteHalfPort(u8 Value)
{
	if(1==READ_BIT(Value,0))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_Pin4,DIO_Pin_High);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_Pin4,DIO_Pin_Low);
	}
	
	if(1==READ_BIT(Value,1))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_Pin5,DIO_Pin_High);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_Pin5,DIO_Pin_Low);
	}
	
	if(1==READ_BIT(Value,2))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_Pin6,DIO_Pin_High);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_Pin6,DIO_Pin_Low);
	}
	
	if(1==READ_BIT(Value,3))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_Pin7,DIO_Pin_High);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_Pin7,DIO_Pin_Low);
	}
}