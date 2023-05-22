#include "Dio.h"
#include "BIT_UTILIES.h"
#include "Dio_prv.h"


Dio_tenuErrorStatus DIO_enuSetPinValue( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal){

	Dio_tenuErrorStatus LOC_enuErrorStatus = Dio_enuOK;

	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7)){ // check the port & pin is available

		if(Copy_u8PinVal == DIO_u8_HIGH){ // if the pin is on

			switch(Copy_u8PortId){

				case DIO_u8_PORTA : SET_BIT(PORTA_Register,Copy_u8PinId);break;
				case DIO_u8_PORTB : SET_BIT(PORTB_Register,Copy_u8PinId);break;
				case DIO_u8_PORTC : SET_BIT(PORTC_Register,Copy_u8PinId);break;
				case DIO_u8_PORTD : SET_BIT(PORTD_Register,Copy_u8PinId);break;
				default : /* wrong ID */ ;break;

			}
		}

		else if(Copy_u8PinVal == DIO_u8_LOW){ // if the pin is off

			switch(Copy_u8PortId){

			case DIO_u8_PORTA : CLR_BIT(PORTA_Register,Copy_u8PinId);break;
			case DIO_u8_PORTB : CLR_BIT(PORTB_Register,Copy_u8PinId);break;
			case DIO_u8_PORTC : CLR_BIT(PORTC_Register,Copy_u8PinId);break;
			case DIO_u8_PORTD : CLR_BIT(PORTD_Register,Copy_u8PinId);break;
			default : /* wrong ID */ ;break;

			}
		}
		else
			{
				LOC_enuErrorStatus = Dio_InvalideInput;
			}
		}
	else
	{
		LOC_enuErrorStatus = Dio_InvalideInput;
	}

	return LOC_enuErrorStatus;
}

Dio_tenuErrorStatus DIO_enuSetPinDirection( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir){

	Dio_tenuErrorStatus LOC_enuErrorStatus = Dio_enuOK;

	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7)){ // check the port & pin is available

		if(Copy_u8PinDir == DIO_u8_OUTPUT){ // if the pin is output = 1

			switch(Copy_u8PortId){

				case DIO_u8_PORTA : SET_BIT(DDRA_Register,Copy_u8PinId);break;
				case DIO_u8_PORTB : SET_BIT(DDRB_Register,Copy_u8PinId);break;
				case DIO_u8_PORTC : SET_BIT(DDRC_Register,Copy_u8PinId);break;
				case DIO_u8_PORTD : SET_BIT(DDRD_Register,Copy_u8PinId);break;
				default : /* wrong ID */ ;break;

			}
		}

		else if(Copy_u8PinDir == DIO_u8_INPUT){ // if the pin is input = 0

			switch(Copy_u8PortId){

			case DIO_u8_PORTA : CLR_BIT(DDRA_Register,Copy_u8PinId);break;
			case DIO_u8_PORTB : CLR_BIT(DDRB_Register,Copy_u8PinId);break;
			case DIO_u8_PORTC : CLR_BIT(DDRC_Register,Copy_u8PinId);break;
			case DIO_u8_PORTD : CLR_BIT(DDRD_Register,Copy_u8PinId);break;
			default : /* wrong ID */ ;break;

			}
		}
		else
			{
				LOC_enuErrorStatus = Dio_InvalideInput;
			}
		}
	else
	{
		LOC_enuErrorStatus = Dio_InvalideInput;
	}

	return LOC_enuErrorStatus;
}


Dio_tenuErrorStatus DIO_enuSetPortDirection (u8 Copy_u8PortId , u8 Copy_u8PortDir){

	 Dio_tenuErrorStatus LOC_enErrorStatus = Dio_enuOK;
	 	 	if( Copy_u8PortId <= DIO_u8_PORTD ){


	 	 			 			switch (Copy_u8PortId){

	 	 			 			case DIO_u8_PORTA : DDRA_Register=Copy_u8PortDir; break;

	 	 			 			case DIO_u8_PORTB : DDRB_Register=Copy_u8PortDir; break;

	 	 			 			case DIO_u8_PORTC : DDRC_Register=Copy_u8PortDir; break;

	 	 			 			case DIO_u8_PORTD : DDRD_Register=Copy_u8PortDir; break;
	 	 			 			default:/*wrong id */ break;
	 	 			 			}


	 	 			     }
	 	 	else
	 	 		LOC_enErrorStatus = Dio_InvalideInput;

	 	 	return  LOC_enErrorStatus;
	 	 	}

Dio_tenuErrorStatus DIO_enuSetPortValue (u8 Copy_u8PortId , u8 Copy_u8PortVal){  //for output

	 Dio_tenuErrorStatus LOC_enErrorStatus =Dio_enuOK;
	 	 	if( Copy_u8PortId <= DIO_u8_PORTD ){


	 	 			 			switch (Copy_u8PortId){

	 	 			 			case DIO_u8_PORTA : PORTA_Register=Copy_u8PortVal; break;

	 	 			 			case DIO_u8_PORTB : PORTB_Register=Copy_u8PortVal; break;

	 	 			 			case DIO_u8_PORTC : PORTC_Register=Copy_u8PortVal; break;

	 	 			 			case DIO_u8_PORTD : PORTD_Register=Copy_u8PortVal; break;

	 	 			 			default:/*wrong id */ break;
	 	 			 			}


	 	 			     }
	 	 	else
	 	 	 LOC_enErrorStatus =Dio_InvalideInput;

	 	 	return  LOC_enErrorStatus;
	 	 	}

u8 Dio_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId){

	 u8 LOC_u8ResultLocal;
	 if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7)){

		 switch (Copy_u8PortId)
		 {
		 case DIO_u8_PORTA: LOC_u8ResultLocal=GET_BIT(PINA_Register,Copy_u8PinId) ; break;
		 case DIO_u8_PORTB: LOC_u8ResultLocal=GET_BIT(PINB_Register,Copy_u8PinId) ; break;
		 case DIO_u8_PORTC: LOC_u8ResultLocal=GET_BIT(PINC_Register,Copy_u8PinId) ; break;
		 case DIO_u8_PORTD: LOC_u8ResultLocal=GET_BIT(PIND_Register,Copy_u8PinId) ; break;
		 default:/*wrong id */ break;

		 }

	 }
	 else
		 LOC_u8ResultLocal=0xff;
return
		 LOC_u8ResultLocal;

 }

