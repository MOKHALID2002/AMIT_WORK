/*
 * LCD_Interface.h
 *
 * Created: 11/09/2022 11:28:39
 * Author: Mohammed
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_8BIT_MODE  1
#define LCD_4BIT_MODE  2

#define LCD_Shift_Left   0
#define LCD_Shift_Right  1

#define LCD_Line_One   1
#define LCD_Line_Two   2

void LCD_Initialize        (void); 
void LCD_SendCommand       (u8 Command);
void LCD_SendCharacter     (u8 Data); //Character
static void WriteHalfPort  (u8 Value);
void LCD_WriteString       (u8* String);
void LCD_Clear             (void);
void LCD_Shift             (u8 Shift_Direction);
void LCD_GoToSpecificPos   (u8 LineNum,u8 Position);
void LCD_WriteNumber       (u32 NUMBER); //
//void LCD_WriteSpecialChar  (u8* pattern,u8 charPosition,u8 LineNum,u8 Position);

#endif /* LCD_INTERFACE_H_ */