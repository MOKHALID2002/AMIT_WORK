/*
 * Switch_Interface.h
 *
 * Created: 12/09/2022 01:46:24
 *  Author: Mohammed
 */ 


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

//SWITCH_PORTS
#define PUSH0_PORT  DIO_PORTB
#define PUSH1_PORT  DIO_PORTD
#define PUSH2_PORT  DIO_PORTD

//SWITCH_PINS
#define PUSH0_PIN   DIO_Pin0
#define PUSH1_PIN   DIO_Pin6
#define PUSH2_PIN   DIO_Pin2

u8 Switch_GetState(u8 Port_Id,u8 Pin_Id);

#endif /* SWITCH_INTERFACE_H_ */