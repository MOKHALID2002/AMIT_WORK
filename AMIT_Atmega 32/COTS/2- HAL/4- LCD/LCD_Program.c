/*
 * LCD_Program.c
 *
 * Created: 11/09/2022 11:28:17
 * Author: Mohammed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

//Priority --> Utiles
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_Interface.h"

//HAL
#include "LCD_Interface.h"
#include "LCD_Configuration.h"

void LCD_Initialize(void)
{
	_delay_ms(35);

	#if LCD_MODE == LCD_8BIT_MODE
	LCD_SendCommand(0b00111000);
	
	#elif LCD_MODE == LCD_4BIT_MODE
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_Pin_Low); //RS=0..Command
	
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_Pin_Low); //RW=0..Write
	
	WriteHalfPort(0b0010);
	
	//ENABLE
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_High);
	_delay_ms(1);   
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_Low);
	
	LCD_SendCommand(0b00101000);  //N = 1 , F = 0
	
	#endif
	_delay_us(45);
	
	LCD_SendCommand(0b00001100);  //D = 1 , C = 1 , B = 1
	_delay_us(45);
	
	LCD_SendCommand(0b00000001);  //Clear display
	_delay_ms(2);
	
	LCD_SendCommand(0b00000110);  //Set entry mode
}

void LCD_SendCommand(u8 Command)
{
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_Pin_Low); //RS=0..Command
	
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_Pin_Low); //RW=0..Write
	
	#if LCD_MODE == LCD_8BIT_MODE
	DIO_SetPortValue(LCD_DATA_PORT,Command);
	//ENABLE
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_High);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_Low);
	
	#elif LCD_MODE == LCD_4BIT_MODE 
	WriteHalfPort(Command>>4); //Most 4 bits
	
    //ENABLE
    DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_High);
    _delay_ms(1);
    DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_Low);
	
	WriteHalfPort(Command); //Least 4 bits
	
	//ENABLE
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_High);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_Low);
	#endif
}

void LCD_SendCharacter(u8 Data)
{
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_Pin_High); //RS=1..Data
	
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_Pin_Low);  //RW=0..Write
    
	#if LCD_MODE == LCD_8BIT_MODE
	DIO_SetPortValue(LCD_DATA_PORT,Data);
	//ENABLE
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_High);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_Low);
	
	#elif LCD_MODE == LCD_4BIT_MODE
	WriteHalfPort(Data>>4); //Most 4 bits
	
	//ENABLE
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_High);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_Low);
	
	WriteHalfPort(Data); //Least 4 bits
	
	//ENABLE
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_High);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_Pin_Low);
	#endif
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

void LCD_WriteString(u8* String)
{
	u8 StringLen=0;
	if(String != NULL)
	{
		while(String[StringLen] != '\0')
		{
			LCD_SendCharacter(String[StringLen]);
			StringLen++;
		}
	}
}

void LCD_WriteNumber(u32 NUMBER)
{
	u32 Local_reserved=1;
	if(NUMBER==0)
	{
		LCD_SendCharacter('0');
	}
	else
	{
		while(NUMBER!=0)
		{
			Local_reserved = Local_reserved*10+(NUMBER%10);
			NUMBER/=10;
		}
		do 
		{
			LCD_SendCharacter((Local_reserved%10)+'0');
			Local_reserved/=10;
		} while (Local_reserved!=1);
	}
}

void LCD_GoToSpecificPos(u8 LineNum,u8 Position)
{
	if(LineNum == LCD_Line_One)
	{
		if(Position<=15)
		{
			LCD_SendCommand(0x80+Position);
		}
	}
	else if(LineNum == LCD_Line_Two)
	{
		if(Position<=15)
		{
			LCD_SendCommand(0xc0+Position);
		}
	}
}

void LCD_Clear(void)
{
	LCD_SendCommand(0b00000001);  //Clear display
	_delay_ms(2);
}

void LCD_Shift(u8 Shift_Direction)
{
	if(Shift_Direction == LCD_Shift_Left)
	{
		LCD_SendCommand(0b00011000);
		_delay_ms(10);
	}
	else if(Shift_Direction == LCD_Shift_Right)
	{
		LCD_SendCommand(0b00011100);
		_delay_ms(10);
	}
}

//void LCD_WriteSpecialChar  (u8* pattern,u8 charPosition,u8 LineNum,u8 Position)

/*
void WriteString(u8 String[80])
{
	u8 i;
	for(i=0;String[i]!='\0';i++)
	{
		LCD_SendCharacter(String[i]);
		if(i==15)
		{
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
			LCD_SendCharacter(' ');
		}
	}
}
*/