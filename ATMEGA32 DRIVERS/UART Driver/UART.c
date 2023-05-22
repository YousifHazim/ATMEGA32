
#include "BIT_UTILIES.h"
#include "UART.h"
#include "UART_prv.h"

	u8 USART_REG = 0;

void USART_voidInit(USART_STRUCT * Add_ptrPointerUSART){


	SET_BIT(USART_REG,7); // To Select UCSRC

	/* USART Mode Select */

	switch(Add_ptrPointerUSART->USART_Mode)
	{
	case USART_MODE_SELECT_ASYNCHRONOUS: CLR_BIT(USART_REG,6);break;
	case USART_MODE_SELECT_SYNCHRONOUS : SET_BIT(USART_REG,6);break;
	}

	/* USART Parity Mode */

	switch(Add_ptrPointerUSART->Parity_Mode)
	{
	case USART_PARITY_MODE_DISABLED     : CLR_BIT(USART_REG,5);CLR_BIT(USART_REG,4);break;
	case USART_PARITY_MODE_ENABLED_EVEN : CLR_BIT(USART_REG,5);SET_BIT(USART_REG,4);break;
	case USART_PARITY_MODE_ENABLED_ODD  : SET_BIT(USART_REG,5);SET_BIT(USART_REG,4);break;
	}

	/* USART Stop Bit Select */

	switch(Add_ptrPointerUSART->Num_of_Stop_Bits)
	{
	case USART_STOP_BIT_SELECT_1_Bit : CLR_BIT(USART_REG,3);break;
	case USART_STOP_BIT_SELECT_2_Bit : SET_BIT(USART_REG,3);break;
	}

	/* USART Character Size */

	switch(Add_ptrPointerUSART->Character_Size)
	{
	case USART_CHARACTER_SIZE_5_Bit : CLR_BIT(UCSRB,2);CLR_BIT(USART_REG,1);CLR_BIT(USART_REG,2);break;
	case USART_CHARACTER_SIZE_6_Bit : CLR_BIT(UCSRB,2);SET_BIT(USART_REG,1);CLR_BIT(USART_REG,2);break;
	case USART_CHARACTER_SIZE_7_Bit : CLR_BIT(UCSRB,2);CLR_BIT(USART_REG,1);SET_BIT(USART_REG,2);break;
	case USART_CHARACTER_SIZE_8_Bit : CLR_BIT(UCSRB,2);SET_BIT(USART_REG,1);SET_BIT(USART_REG,2);break;
	case USART_CHARACTER_SIZE_9_Bit : SET_BIT(UCSRB,2);SET_BIT(USART_REG,1);SET_BIT(USART_REG,2);break;
	}

	/* USART Clock Polarity "Synchronous Mode Only" */

	switch(Add_ptrPointerUSART->Clock_Polarity)
	{
	case USART_CLOCK_POLARITY_RISING_FALLING : CLR_BIT(USART_REG,0);break;
	case USART_CLOCK_POLARITY_FALLING_RISING : SET_BIT(USART_REG,0);break;
	case USART_CLOCK_POLARITY_DISABLE 		 : CLR_BIT(USART_REG,0);break;
	}

	/* Double the USART Transmission Speed */

	switch(Add_ptrPointerUSART->Double_Speed){

	case USART_DOUBLE_SPPED_DISABLE : CLR_BIT(UCSRA,1);

	/* Baud Rate ( bps )  "For 8MHZ Only" */

		switch(Add_ptrPointerUSART->baud_rate){

		case USART_BAUD_RATE_2400  : UBRRL= 207; UBRRH=0; break;
		case USART_BAUD_RATE_4800  : UBRRL= 103; UBRRH=0; break;
	    case USART_BAUD_RATE_9600  : UBRRL= 51;  UBRRH=0; break;
	    case USART_BAUD_RATE_14400 : UBRRL= 34;  UBRRH=0; break;
	    case USART_BAUD_RATE_19200 : UBRRL= 25;  UBRRH=0; break;
	    case USART_BAUD_RATE_28800 : UBRRL= 16;  UBRRH=0; break;
	    case USART_BAUD_RATE_38400 : UBRRL= 12;  UBRRH=0; break;
	    case USART_BAUD_RATE_57600 : UBRRL= 8;   UBRRH=0; break;
	    case USART_BAUD_RATE_76800 : UBRRL= 6;   UBRRH=0; break;

		}break;


	case USART_DOUBLE_SPPED_ENABLE : SET_BIT(UCSRA,1);

	/* Baud Rate ( bps )  "For 8MHZ Only" */

		switch(Add_ptrPointerUSART->baud_rate){

        case USART_BAUD_RATE_2400 : UBRRL= 160; UBRRH=1; break;
        case USART_BAUD_RATE_4800 : UBRRL= 207; UBRRH=0; break;
        case USART_BAUD_RATE_9600 : UBRRL= 103; UBRRH=0; break;
        case USART_BAUD_RATE_14400 : UBRRL= 68; UBRRH=0; break;
        case USART_BAUD_RATE_19200 : UBRRL= 51; UBRRH=0; break;
        case USART_BAUD_RATE_28800 : UBRRL= 34; UBRRH=0; break;
        case USART_BAUD_RATE_38400 : UBRRL= 25; UBRRH=0; break;
        case USART_BAUD_RATE_57600 : UBRRL= 16; UBRRH=0; break;
        case USART_BAUD_RATE_76800 : UBRRL= 12; UBRRH=0; break;

		}break;
	}


	UCSRA = USART_REG;	 // Put The Value Of USART_REG In UCSRA

	SET_BIT(UCSRB,4);	// Enable RX ( Receiver Enable )

	SET_BIT(UCSRB,3); 	// Enable TX ( Transmitter Enable )
}



void USART_voidSendChar(u8 data){

	while(GET_BIT(UCSRA,5) == 0 ); // FLAG USART Data Register Empty
	UDR__T = data;

}

u8 USART_u8GetChar(void){

	u8 result;

	while(GET_BIT(UCSRA,7) == 0 ); // FLAG USART Receive Complete
	result = UDR__R;

	return result;
}
