/*
 * LCD_Configuration.h
 *
 * Created: 11/09/2022 11:29:32
 *  Author: Mohammed
 */ 


#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_

/* Macros For Rs configuration */
#define LCD_RS_PORT     DIO_PORTB
#define LCD_RS_PIN      DIO_Pin1

/* Macros For Rw configuration */
#define LCD_RW_PORT     DIO_PORTB
#define LCD_RW_PIN      DIO_Pin2

/* Macros For En configuration */
#define LCD_EN_PORT     DIO_PORTB
#define LCD_EN_PIN      DIO_Pin3

#define LCD_MODE        LCD_4BIT_MODE

#define LCD_DATA_PORT   DIO_PORTA

#define LCD_D4_PIN   DIO_Pin4
#define LCD_D4_PORT  DIO_PORTA

#define LCD_D5_PIN   DIO_Pin5
#define LCD_D5_PORT  DIO_PORTA

#define LCD_D6_PIN   DIO_Pin6
#define LCD_D6_PORT  DIO_PORTA

#define LCD_D7_PIN   DIO_Pin7
#define LCD_D7_PORT  DIO_PORTA

#endif /* LCD_CONFIGURATION_H_ */