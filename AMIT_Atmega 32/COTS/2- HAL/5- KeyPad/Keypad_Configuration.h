/*
 * Keypad_Configuration.h
 *
 * Created: 13/09/2022 10:02:41
 *  Author: Mohammed
 */ 


#ifndef KEYPAD_CONFIGURATION_H_
#define KEYPAD_CONFIGURATION_H_

//
#define KPD_COLS_PORT  DIO_PORTA
#define KPD_COL0_PIN   DIO_Pin4
#define KPD_COL1_PIN   DIO_Pin5
#define KPD_COL2_PIN   DIO_Pin6
#define KPD_COL3_PIN   DIO_Pin7

//
#define KPD_ROWS_PORT  DIO_PORTC
#define KPD_ROW0_PIN   DIO_Pin3
#define KPD_ROW1_PIN   DIO_Pin4
#define KPD_ROW2_PIN   DIO_Pin5
#define KPD_ROW3_PIN   DIO_Pin6

#define KPD_KEYS  {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'}

#endif /* KEYPAD_CONFIGURATION_H_ */