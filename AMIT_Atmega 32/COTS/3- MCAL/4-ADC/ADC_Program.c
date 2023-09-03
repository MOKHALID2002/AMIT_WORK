/*
 * ADC_Program.c
 *
 * Created: 20/09/2022 12:41:24
 *  Author: Mohammed
 */ 

//Priority --> Utiles
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "ADC_Interface.h"

void ADC_INIT(void)
{
	//Select VREF=AVCC
	SET_BIT(ADMUX,6);
	CLEAR_BIT(ADMUX,7);
	
	//Select Right Adjustment
	CLEAR_BIT(ADMUX,5);
	
	//Auto trigger off -- Single conversion mode
	CLEAR_BIT(ADCSRA,5);
	
	//Disable interrupt
	CLEAR_BIT(ADCSRA,3);
	
	//Prescaler 128 for 16MHz
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	//ADC Enable
	SET_BIT(ADCSRA,7);
}

void ADC_GetDigitalValue(u8 ChannelNum,u16* DigitalValue)
{
	if(ChannelNum<32 && DigitalValue!=NULL)
	{
		//Clear ADMUX Channel bits
		ADMUX&=0b11100000;
		
		//Select Channel number
		ADMUX|=ChannelNum;
		
		//Start Conversion
		SET_BIT(ADCSRA,6);
		
		//Wait for the flag of the ADC to be 1
		while(0 == READ_BIT(ADCSRA,4));
		
		//Clear Flag
	    SET_BIT(ADCSRA,4);
		
		//Read Digital Value
		*DigitalValue = ADC_u16;
	}
}