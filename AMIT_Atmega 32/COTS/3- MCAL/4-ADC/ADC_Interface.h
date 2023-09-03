/*
 * ADC_Interface.h
 *
 * Created: 20/09/2022 12:41:39
 *  Author: Mohammed
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

//MACROS for 
#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1
#define ADC_CHANNEL_2   2
#define ADC_CHANNEL_3   3
#define ADC_CHANNEL_4   4
#define ADC_CHANNEL_5   5
#define ADC_CHANNEL_6   6
#define ADC_CHANNEL_7   7

void ADC_INIT(void);
void ADC_GetDigitalValue(u8 ChannelNum,u16* DigitalValue);

#endif /* ADC_INTERFACE_H_ */