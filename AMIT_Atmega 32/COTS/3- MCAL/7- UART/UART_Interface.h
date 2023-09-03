/*
 * UART_Interface.h
 *
 * Created: 04/10/2022 09:30:47
 *  Author: Mohammed
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init     (void);
void UART_TxChar   (u8 Data);
void UART_TxString (u8* String);
void UART_RxChar   (u8* ReturnedData);

#endif /* UART_INTERFACE_H_ */