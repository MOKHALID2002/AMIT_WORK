/*
 * ATMEGA32_REG.h
 *
 * Created: 07/09/2022 20:54:54
 * Author: Mohammed
 */ 

#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_
						//DIO_REGISTERS

//Data Direction Registers
#define DDRA    (*(volatile u8*)0x3A)
#define DDRB    (*(volatile u8*)0x37)
#define DDRC    (*(volatile u8*)0x34)
#define DDRD    (*(volatile u8*)0x31)

//Output Registers
#define PORTA   (*(volatile u8*)0x3B)
#define PORTB   (*(volatile u8*)0x38)
#define PORTC   (*(volatile u8*)0x35)
#define PORTD   (*(volatile u8*)0x32)

//Input Registers
#define PINA    (*(volatile u8*)0x39)
#define PINB    (*(volatile u8*)0x36)
#define PINC    (*(volatile u8*)0x33)
#define PIND    (*(volatile u8*)0x30) 

						//EXTERNAL INTERRUPT REGISTERS

//MCU Control Register
#define MCUCR   (*(volatile u8*)0x55)

//MCU Control and Status Register
#define MCUCSR  (*(volatile u8*)0x54)

//General Interrupt Control Register
#define GICR    (*(volatile u8*)0x5B)

//General Interrupt Flag Register
#define GIFR    (*(volatile u8*)0x5A)

//Status Register
#define SREG    (*(volatile u8*)0x5F)

                        //ADC Registers

//ADC Multiplexer Selection Register						
#define ADMUX  (*(volatile u8*)0x27)

//ADC Control and Status Register A
#define ADCSRA  (*(volatile u8*)0x26)

//ADC Data Registers
#define ADCL    (*(volatile u8*)0x24)
#define ADCH    (*(volatile u8*)0x25)
#define ADC_u16 (*(volatile u16*)0x24)     

//Special FunctionIO Register
#define SFIOR   (*(volatile u8*)0x50)

                        //Timers Registers
//TIMER0

//Timer/Counter control register
#define TCCR0  (*(volatile u8*)0x53)

//Timer/Counter register
#define TCNT0  (*(volatile u8*)0x52)

//Output compare register
#define OCR0   (*(volatile u8*)0x5C)

//Timer/Counter interrupt mask register
#define TIMSK  (*(volatile u8*)0x59)

//Timer/Counter interrupt flag register
#define TIFR   (*(volatile u8*)0x58)

//Timer1

//Timer/counter 1 control register A
#define TCCR1A    (*(volatile u8*)0x4F)

//Timer/counter 1 control register B
#define TCCR1B    (*(volatile u8*)0x4E)

//Timer/counter1
#define TCNT1L    (*(volatile u8*)0x4C)
#define TCNT1H    (*(volatile u8*)0x4D)
#define TCNT1_u16 (*(volatile u16*)0x4C)

//Output compare register 1 A
#define OCR1AL    (*(volatile u8*)0x4A)
#define OCR1AH    (*(volatile u8*)0x4B)
#define OCR1A_u16 (*(volatile u16*)0x4A)

//Output compare register 1 B
#define OCR1BL    (*(volatile u8*)0x48)
#define OCR1BH    (*(volatile u8*)0x49)
#define OCR1B_u16 (*(volatile u16*)0x48)

//Input Capture register 1
#define ICR1L     (*(volatile u8*)0x46)
#define ICR1H     (*(volatile u8*)0x47)
#define ICR1_u16  (*(volatile u16*)0x46)

                        //Timers Registers
//Watchdog timer

//Watchdog Timer Control Register
#define WDTCR     (*(volatile u8*)0x41)

                        //UART Registers

//USART I/O Data Register
#define UDR       (*(volatile u8*)0x2C)

//USART Control and Status Register A
#define UCSRA     (*(volatile u8*)0x2B)

//USART Control and Status Register B
#define UCSRB     (*(volatile u8*)0x2A)

//USART Control and Status Register C
#define UCSRC     (*(volatile u8*)0x40)

//USART Baud Rate Registers
#define UBRRL     (*(volatile u8*)0x29)
#define UBRRH     (*(volatile u8*)0x40)

#endif /* ATMEGA32_REG_H_ */