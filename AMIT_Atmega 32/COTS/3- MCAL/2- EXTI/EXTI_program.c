/*
 * EXTI_program.c
 *
 * Created: 9/15/2022 12:01:31 PM
 *  Author: AMIT
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "EXTI_interface.h"
#include "DIO_Interface.h"
static void(*pCallback)(void)=NULL;
/*
static void(*pCallback)(void)=NULL;
static void(*pCallback)(void)=NULL;*/

void EXTI_enable(EXTI_source interruptSource, EXTI_trigger interruptTriggerEdge)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		if(EXTI_RISING_EDGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
		{
			CLEAR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(EXTI_LOW_LEVEL == interruptTriggerEdge)
		{
			CLEAR_BIT(MCUCR,0);
			CLEAR_BIT(MCUCR,1);
		}
		else if(EXTI_ANY_LOGICAL_CHANGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,0);
			CLEAR_BIT(MCUCR,1);
		}
		
		SET_BIT(GICR,6); //enable INT0
		break;
		
		case EXTI_INT1:
		if(EXTI_RISING_EDGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
		{
			CLEAR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(EXTI_LOW_LEVEL == interruptTriggerEdge)
		{
			CLEAR_BIT(MCUCR,2);
			CLEAR_BIT(MCUCR,3);
		}
		else if(EXTI_ANY_LOGICAL_CHANGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,2);
			CLEAR_BIT(MCUCR,3);
		}
		
		SET_BIT(GICR,7); //enable INT1
		break;
		
		case EXTI_INT2:
		if(EXTI_RISING_EDGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCSR,6);
		}
		else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
		{
			CLEAR_BIT(MCUCSR,6);
		}
		
		SET_BIT(GICR,5); //enable INT2
		break;
	}
}


void EXTI_disable(EXTI_source interruptSource)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		CLEAR_BIT(GICR,6); //disable INT0
		break;
		
		case EXTI_INT1:
		CLEAR_BIT(GICR,7); //disable INT1
		break;
		
		case EXTI_INT2:
		CLEAR_BIT(GICR,5); //disable INT2
		break;
	}	
}

void EXTI_INT0SetCallback(void(*ptr)(void))
{
	if(ptr!=NULL)
	{
	    pCallback = ptr;
	}
}

// ISR Function protoType for EXTI0
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	if(pCallback!=NULL)
	{
	    pCallback();  //Call action
	}
}

