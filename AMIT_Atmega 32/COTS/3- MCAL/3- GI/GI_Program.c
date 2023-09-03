/*
 * CFile1.c
 *
 * Created: 18/09/2022 09:44:37
 *  Author: Mohammed
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "GI_Interface.h"

void GI_Enable(void)
{
	SET_BIT(SREG,7);
}

void GI_Disable(void)
{
	CLEAR_BIT(SREG,7);
}