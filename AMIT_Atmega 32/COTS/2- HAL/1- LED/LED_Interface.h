/*
 * LED_Interface.h
 *
 * Created: 10/09/2022 14:52:10
 * Author: Mohammed
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

//LED_PORTS
#define LED0_PORT  DIO_PORTC
#define LED1_PORT  DIO_PORTC
#define LED2_PORT  DIO_PORTD

//LED_PINS
#define LED0_PIN   DIO_Pin2
#define LED1_PIN   DIO_Pin7
#define LED2_PIN   DIO_Pin3

//Forward Connection
#define LED_on_FWD    1
#define LED_off_FWD   0

//Reverse Connection
#define LED_on_REV    0
#define LED_off_REV   1

void LED_STATE   (u8 Port_Id,u8 Pin_Id,u8 CONNECTION);
void LED_TOGGLE  (u8 Port_Id,u8 Pin_Id);

#endif /* LED_INTERFACE_H_ */