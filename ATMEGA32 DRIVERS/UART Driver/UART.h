#ifndef INCLUDE_MCAL_UART_UART_H_
#define INCLUDE_MCAL_UART_UART_H_


#include "STD_TYPES.h"

/* USART Mode Select */

#define USART_MODE_SELECT_ASYNCHRONOUS 		0
#define USART_MODE_SELECT_SYNCHRONOUS 		1

/* USART Parity Mode */

#define USART_PARITY_MODE_DISABLED 			0
#define USART_PARITY_MODE_RESERVED 			0
#define USART_PARITY_MODE_ENABLED_EVEN  	1
#define USART_PARITY_MODE_ENABLED_ODD   	2

/* USART Stop Bit Select */

#define USART_STOP_BIT_SELECT_1_Bit 		0
#define USART_STOP_BIT_SELECT_2_Bit 		1

/* USART Character Size */

#define USART_CHARACTER_SIZE_5_Bit 			0
#define USART_CHARACTER_SIZE_6_Bit 			1
#define USART_CHARACTER_SIZE_7_Bit 			2
#define USART_CHARACTER_SIZE_8_Bit 			3
#define USART_CHARACTER_SIZE_RESERVED_Bit 	0
#define USART_CHARACTER_SIZE_RESERVED_Bit 	0
#define USART_CHARACTER_SIZE_RESERVED_Bit 	0
#define USART_CHARACTER_SIZE_9_Bit 			4

/* USART Clock Polarity "Synchronous Mode Only" */

#define USART_CLOCK_POLARITY_RISING_FALLING	0 // Transmitted Data at rising Edge & Received Data at falling Edge
#define USART_CLOCK_POLARITY_FALLING_RISING	1 // Transmitted Data at falling Edge & Received Data at rising Edge
#define USART_CLOCK_POLARITY_DISABLE		2

/* Double the USART Transmission Speed */

#define USART_DOUBLE_SPPED_DISABLE 			0
#define USART_DOUBLE_SPPED_ENABLE 			1

/* Baud Rate ( bps )  "For 8MHZ Only" */

#define USART_BAUD_RATE_2400 				0
#define USART_BAUD_RATE_4800				1
#define USART_BAUD_RATE_9600 				2
#define USART_BAUD_RATE_14400 				3
#define USART_BAUD_RATE_19200 				4
#define USART_BAUD_RATE_28800 				5
#define USART_BAUD_RATE_38400 				6
#define USART_BAUD_RATE_57600 				7
#define USART_BAUD_RATE_76800 				8

/* USART Struct */

typedef struct {

	u8 USART_Mode;
	u8 Parity_Mode;
	u8 Num_of_Stop_Bits;
	u8 Character_Size;
	u8 Clock_Polarity;
	u8 Double_Speed;
	u8 baud_rate;

}USART_STRUCT;

/* USART Initialize */

void USART_voidInit(USART_STRUCT * Add_ptrPointerUSART);

/* USART Send Data */

void USART_voidSendChar(u8 data);

/* USART Receive Data */

u8 USART_u8GetChar(void);


#endif /* INCLUDE_MCAL_UART_UART_H_ */
