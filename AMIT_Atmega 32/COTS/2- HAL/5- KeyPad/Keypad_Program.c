/*
 * Keypad_Program.c
 *
 * Created: 13/09/2022 10:02:00
 *  Author: Mohammed
 */ 

//Priority --> Utiles
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_interface.h"

//HAL
#include "Keypad_Interface.h"
#include "Keypad_Configuration.h"

void KPD_ReadValue(u8* ReturnedValue)
{
    u8 Coloumb_Pins[4]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
	u8 Row_Pins[4]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	u8 KPD_Chars[4][4]=KPD_KEYS;
	
	if(ReturnedValue != NULL)
	{
		*ReturnedValue=KPD_NotPressed;
		u8 columbCount,rowCount;
		u8 pinValue;
		u8 pinFlag=0;
		for(columbCount=0;columbCount<4;columbCount++)
		{
			//Activate each columb
			DIO_SetPinValue(KPD_COLS_PORT,Coloumb_Pins[columbCount],DIO_Pin_Low);
			
			//Loop to check rows values
			for(rowCount=0;rowCount<4;rowCount++)
			{
				DIO_ReadPinValue(KPD_ROWS_PORT,Row_Pins[rowCount],&pinValue);
				if(0 == pinValue)
				{
					*ReturnedValue = KPD_Chars[rowCount][columbCount];
					while(0 == pinValue)
					{
						DIO_ReadPinValue(KPD_ROWS_PORT,Row_Pins[rowCount],&pinValue);
					}
					pinFlag=1;
					break;   //return 
				}
			}
			
			//Deactivate current columb
			DIO_SetPinValue(KPD_COLS_PORT,Coloumb_Pins[columbCount],DIO_Pin_High);
			
			if(1 == pinFlag)
			{
				break;
			}
		}
	}
}

