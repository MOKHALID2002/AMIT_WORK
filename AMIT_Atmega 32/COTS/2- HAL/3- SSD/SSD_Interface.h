/*
 * SSD_Interface.h
 *
 * Created: 18/09/2022 12:37:32
 *  Author: Mohammed
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

void SSD_ON(void);
void SSD_DisplayNum(u8 DisplayedNumber);
static void WriteHalfPort(u8 Value);
void SSD_DisplayTwoNumbers(u8 FirstNum,u8 SecondNum);

#endif /* SSD_INTERFACE_H_ */