/*
 * DIO_Program.c
 *
 * Created: 07/09/2022 19:02:04
 * Author: Mohammed
 */ 

//Priority --> Utiles
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_interface.h"

void DIO_SetPinDirection(u8 Port_Id,u8 Pin_Id,u8 Pin_Direction)
{
	if((Port_Id<=3) && (Pin_Id<=7) && ((Pin_Direction==DIO_PinOutput)||(Pin_Direction==DIO_PinInput)))
	{
		switch(Port_Id)
		{
			case 0: //DIO_PORTA
			if(DIO_PinOutput == Pin_Direction)
			{
				SET_BIT(DDRA,Pin_Id);
			}
			else
			{
				CLEAR_BIT(DDRA,Pin_Id);
			}
			break;
			
			case 1: //DIO_PORTB
			if(DIO_PinOutput == Pin_Direction)
			{
				SET_BIT(DDRB,Pin_Id);
			}
			else
			{
				CLEAR_BIT(DDRB,Pin_Id);
			}
			break;
			
			case 2: //DIO_PORTC
			if(DIO_PinOutput == Pin_Direction)
			{
				SET_BIT(DDRC,Pin_Id);
			}
			else
			{
				CLEAR_BIT(DDRC,Pin_Id);
			}
			break;
			
			case 3: //DIO_PORTD
			if(DIO_PinOutput == Pin_Direction)
			{
				SET_BIT(DDRD,Pin_Id);
			}
			else
			{
				CLEAR_BIT(DDRD,Pin_Id);
			}
			break;
		}
	}
}

void DIO_SetPinValue(u8 Port_Id,u8 Pin_Id,u8 Pin_Value)
{
	if((Port_Id<=3) && (Pin_Id<=7) && ((Pin_Value==DIO_Pin_High)||(Pin_Value==DIO_Pin_Low)))
	{
		switch(Port_Id)
		{
			case 0: //DIO_PORTA
			if(DIO_Pin_High == Pin_Value)
			{
				SET_BIT(PORTA,Pin_Id);
			}
			else
			{
				CLEAR_BIT(PORTA,Pin_Id);
			}
			break;
			
			case 1: //DIO_PORTB
			if(DIO_Pin_High == Pin_Value)
			{
				SET_BIT(PORTB,Pin_Id);
			}
			else
			{
				CLEAR_BIT(PORTB,Pin_Id);
			}
			break;
			
			case 2: //DIO_PORTC
			if(DIO_Pin_High == Pin_Value)
			{
				SET_BIT(PORTC,Pin_Id);
			}
			else
			{
				CLEAR_BIT(PORTC,Pin_Id);
			}
			break;
			
			case 3: //DIO_PORTD
			if(DIO_Pin_High == Pin_Value)
			{
				SET_BIT(PORTD,Pin_Id);
			}
			else
			{
				CLEAR_BIT(PORTD,Pin_Id);
			}
			break;
		}
	}
}

void DIO_ReadPinValue(u8 Port_Id,u8 Pin_Id,u8* Pin_Value)
{
	if((Port_Id<=3) && (Pin_Id<=7) && (Pin_Value!=NULL))
	{
		switch(Port_Id)
		{
			case 0: //DIO_PORTA
			if(DIO_Pin_High == READ_BIT(PINA,Pin_Id))
			{
				*Pin_Value = DIO_Pin_High;
			}
			else
			{
				*Pin_Value = DIO_Pin_Low;
			}
			break;
			
			case 1: //DIO_PORTB
			if(DIO_Pin_High == READ_BIT(PINB,Pin_Id))
			{
				*Pin_Value = DIO_Pin_High;
			}
			else
			{
				*Pin_Value = DIO_Pin_Low;
			}
			break;
			
			case 2: //DIO_PORTC
			if(DIO_Pin_High == READ_BIT(PINC,Pin_Id))
			{
				*Pin_Value = DIO_Pin_High;
			}
			else
			{
				*Pin_Value = DIO_Pin_Low;
			}
			break;
			
			case 3: //DIO_PORTD
			if(DIO_Pin_High == READ_BIT(PIND,Pin_Id))
			{
				*Pin_Value = DIO_Pin_High;
			}
			else
			{
				*Pin_Value = DIO_Pin_Low;
			}
			break;
		}
	}
}

void DIO_TogglePinValue(u8 Port_Id,u8 Pin_Id)
{
	if((Port_Id<=3) && (Pin_Id<=7))
	{
		switch(Port_Id)
		{
			case 0: //DIO_PORTA
			TOGGLE_BIT(PORTA,Pin_Id);
			break;
			
			case 1: //DIO_PORTB
			TOGGLE_BIT(PORTB,Pin_Id);
			break;
			
			case 2: //DIO_PORTC
			TOGGLE_BIT(PORTC,Pin_Id);
			break;
			
			case 3: //DIO_PORTD
			TOGGLE_BIT(PORTD,Pin_Id);
			break;
		}
	}
}

void DIO_ActivatePinPullUpRes(u8 Port_Id,u8 Pin_Id)
{
	if((Port_Id<=3) && (Pin_Id<=7))
	{
		switch(Port_Id)
		{
			case 0:
			SET_BIT(PORTA,Pin_Id);
			break;
			
			case 1:
			SET_BIT(PORTB,Pin_Id);
			break;
			
			case 2:
			SET_BIT(PORTC,Pin_Id);
			break;
			
			case 3:
			SET_BIT(PORTD,Pin_Id);
			break;
		}
	}
}

void DIO_SetPortDirection(u8 Port_Id,u8 Port_Direction)
{
	if((Port_Id<=3) && ((DIO_PortOutput==Port_Direction)||(DIO_PortInput==Port_Direction)))
	{
		switch(Port_Id)
		{
			case 0:
			if(DIO_PortOutput==Port_Direction)
			{
				DDRA = 0xff;
			}
			else
			{
				DDRA = 0x00;
			}
			break;
			
			case 1:
			if(DIO_PortOutput==Port_Direction)
			{
				DDRB = 0xff;
			}
			else
			{
				DDRB = 0x00;
			}
			break;
			
			case 2:
			if(DIO_PortOutput==Port_Direction)
			{
				DDRC = 0xff;
			}
			else
			{
				DDRC = 0x00;
			}
			break;
			
			case 3:
			if(DIO_PortOutput==Port_Direction)
			{
				DDRD = 0xff;
			}
			else
			{
				DDRD = 0x00;
			}
			break;
		}
	}
}

void DIO_SetPortValue(u8 Port_Id,u8 Port_Value)
{
	if(Port_Id<=3)
	{
		switch(Port_Id)
		{
			case 0:
			PORTA = Port_Value;
			break;
			
			case 1:
			PORTB = Port_Value;
			break;
			
			case 2:
			PORTC = Port_Value;
			break;
			
			case 3:
			PORTD = Port_Value;
			break;
		}
	}
}

void DIO_ReadPortValue(u8 Port_Id,u8* Port_Value)
{
	if((Port_Id<=3) && (Port_Value!=NULL))
	{
		switch(Port_Id)
		{
			case 0:
			*Port_Value = PINA;
			break;
			
			case 1:
			*Port_Value = PINB;
			break;
			
			case 2:
			*Port_Value = PINC;
			break;
			
			case 3:
			*Port_Value = PIND;
			break;
		}
	}		
}

void DIO_TogglePortValue(u8 Port_Id)
{
	if(Port_Id<=3)
	{
		switch(Port_Id)
		{
			case 0:
			PORTA = ~PORTA;    //PORTA ^= 0xff;
			break;
			
			case 1:
			PORTB = ~PORTB;    //PORTB ^= 0xff;
			break;
			
			case 2:
			PORTC = ~PORTC;    //PORTC ^= 0xff;
			break;
			
			case 3:
			PORTD = ~PORTD;    //PORTD ^= 0xff;
			break;
		}
	}
}

void DIO_ActivatePortPullUpRes(u8 Port_Id,u8 Pin_Id)
{
	if(Port_Id<=3)
	{
		switch(Port_Id)
		{
			case 0:
			PORTA = 0xff;
			break;
			
			case 1:
			PORTB = 0xff;
			break;
			
			case 2:
			PORTC = 0xff;
			break;
			
			case 3:
			PORTD = 0xff;
			break;
		}
	}
}