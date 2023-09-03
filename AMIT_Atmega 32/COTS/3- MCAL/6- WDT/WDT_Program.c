/*
 * WDT_Program.c
 *
 * Created: 30/09/2022 23:01:27
 *  Author: Mohammed
 */ 

//Priority --> Utiles
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "WDT_Interface.h"

void WDT_Start(void)
{
	//Select Prescaler value --> 2.1 sec
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	
	//Enable Watchdog timer 
	SET_BIT(WDTCR,3);
}

void WDT_Stop(void)
{
	//Write logical one to WDTOE and WDE 
	WDTCR = (1<<4) | (1<<3);
	
	//Turn off WDT 
	WDTCR = 0x00;
}