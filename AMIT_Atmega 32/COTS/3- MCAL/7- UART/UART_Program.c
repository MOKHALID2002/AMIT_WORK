/*
 * UART_Program.c
 *
 * Created: 04/10/2022 09:30:24
 *  Author: Mohammed
 */ 

//Priority --> Utiles
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "UART_Interface.h"

void UART_Init(void)
{
	//Disable --> Double the USART Transmission Speed
	CLEAR_BIT(UCSRA,1);
	
	//For character size --> 8 bits
	CLEAR_BIT(UCSRB,2);
	
	//
	UCSRC = 0x86; // 0b10000110 (Initial value)
	
	//Set Buad rate = 9600
	UBRRL = 103;
	
	//Receiver Enable
	SET_BIT(UCSRB,3);
	
	//Transmitter Enable
	SET_BIT(UCSRB,4);
}

void UART_TxChar(u8 Data)
{
	UDR = Data;
	while(0 == READ_BIT(UCSRA,5));
}

void UART_RxChar(u8* ReturnedData)
{
	if(ReturnedData != NULL)
	{
		while(0 == READ_BIT(UCSRA,7));
		*ReturnedData = UDR;
	}
}

void UART_TxString(u8* String)
{
	u8 counter=0;
	if(String != NULL)
	{
		while(String[counter] != '\0')
		{
			UART_TxChar(String[counter]);
			counter++;
		}
	}
}