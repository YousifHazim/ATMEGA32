/*

 * EXTINT_program.c
 *
 *  Created on: Sep 22, 2022
 *      Author: AL-NABAA
 */

#include "BIT_UTILIES.h"
#include "EXTINT_prv.h"
#include "Dio_prv.h"
#include "EXTINT_Interface.h"
#include "STD_TYPES.h"
#include "util/delay.h"


void EXTINT_voidEnable(u8 Copy_u8ExtIntNum , u8 Copy_u8EdgeIntSource){

	switch( Copy_u8ExtIntNum ){

	case EXTINT_INT0 :
	{
		SET_BIT(GICR,GICR_INT0);
		switch(Copy_u8EdgeIntSource){

		case EXTINT_INT01_lowlevel : CLR_BIT(MCUCR,1);CLR_BIT(MCUCR,0);break;
		case EXTINT_INT01_logicalChange : SET_BIT(MCUCR,0);CLR_BIT(MCUCR,1);break;
		case EXTINT_INT01_fallingEdge : SET_BIT(MCUCR,1);CLR_BIT(MCUCR,0);break;
		case EXTINT_INT01_risingEdge : SET_BIT(MCUCR,1);SET_BIT(MCUCR,0);break;

		}
		break;
	}
	case EXTINT_INT1 :
	{
		SET_BIT(GICR,GICR_INT1);
		switch(Copy_u8EdgeIntSource){

		case EXTINT_INT01_lowlevel : CLR_BIT(MCUCR,3);CLR_BIT(MCUCR,2);break;
		case EXTINT_INT01_logicalChange : SET_BIT(MCUCR,2);CLR_BIT(MCUCR,3);break;
		case EXTINT_INT01_fallingEdge : SET_BIT(MCUCR,3);CLR_BIT(MCUCR,2);break;
		case EXTINT_INT01_risingEdge : SET_BIT(MCUCR,3);SET_BIT(MCUCR,2);break;

		}
		break;
	}
	case EXTINT_INT2 :
	{
		SET_BIT(GICR,GICR_INT2);
		switch(Copy_u8EdgeIntSource){
		case EXTINT_INT2_fallingEdge : CLR_BIT(MCUCR,6);break;
		case EXTINT_INT2_risingEdge : SET_BIT(MCUCR,6);break;

		}
		break;
	}
	}



void EXTINT_voidDisable(u8 Copy_u8ExtIntNum){

	switch( Copy_u8ExtIntNum ){
	case EXTINT_INT0 : 	CLR_BIT(GICR,GICR_INT0);break;
	case EXTINT_INT1 : CLR_BIT(GICR,GICR_INT1);break;
	case EXTINT_INT2 : CLR_BIT(GICR,GICR_INT2);break;

	}
}
}
