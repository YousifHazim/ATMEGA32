#ifndef INCLUDE_MCAL_DIO_DIO_H_
#define INCLUDE_MCAL_DIO_DIO_H_

#include "STD_TYPES.h"

typedef enum{
	Dio_enuOK,
	Dio_InvalideInput
}Dio_tenuErrorStatus;

// define PORTS

#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

// define PINS

#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7

// Direction PIN

#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1

// Value options PIN

#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0

// Direction PORT

#define DIO_u8_PORT_OUTPUT 255
#define DIO_u8_PORT_INPUT 0

// IO PINS

Dio_tenuErrorStatus DIO_enuSetPinValue ( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal);
Dio_tenuErrorStatus DIO_enuSetPinDirection ( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir );
Dio_tenuErrorStatus Dio_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId);
Dio_tenuErrorStatus DIO_enuSetPortDirection (u8 Copy_u8PortId , u8 Copy_u8PortDir);
Dio_tenuErrorStatus DIO_enuSetPortValue (u8 Copy_u8PortId , u8 Copy_u8PortVal);

#endif /* INCLUDE_MCAL_DIO_DIO_H_ */
