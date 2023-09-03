/*
 * DIO_Interface.h
 *
 * Created: 07/09/2022 19:02:28
 * Author: Mohammed
 */ 

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

//Macros for Pin_Id
#define DIO_Pin0  0
#define DIO_Pin1  1
#define DIO_Pin2  2
#define DIO_Pin3  3
#define DIO_Pin4  4
#define DIO_Pin5  5
#define DIO_Pin6  6
#define DIO_Pin7  7

//Macros for Pin_Direction
#define DIO_PinOutput  1
#define DIO_PinInput   0

//Macros for Pin_State
#define DIO_Pin_High   1
#define DIO_Pin_Low    0

//Macros for Port_Id 
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

//Macros for Port_Direction
#define DIO_PortOutput  0xff
#define DIO_PortInput   0x00

//Macros for Port_State
#define DIO_Port_High   0xff
#define DIO_Port_Low    0x00

//Apis --> Application Program Interface

//Pin Apis
void DIO_SetPinDirection      (u8 Port_Id,u8 Pin_Id,u8 Pin_Direction);
void DIO_SetPinValue          (u8 Port_Id,u8 Pin_Id,u8 Pin_Value);
void DIO_ReadPinValue         (u8 Port_Id,u8 Pin_Id,u8* Pin_Value);
void DIO_TogglePinValue       (u8 Port_Id,u8 Pin_Id);
void DIO_ActivatePinPullUpRes (u8 Port_Id,u8 Pin_Id); //Input resistance

//Port Apis
void DIO_SetPortDirection      (u8 Port_Id,u8 Port_Direction);
void DIO_SetPortValue          (u8 Port_Id,u8 Port_Value);
void DIO_ReadPortValue         (u8 Port_Id,u8* Port_Value);
void DIO_TogglePortValue       (u8 Port_Id);
void DIO_ActivatePortPullUpRes (u8 Port_Id,u8 Pin_Id); //Input resistance

#endif /* DIO_INTERFACE_H_ */