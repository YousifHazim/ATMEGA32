#ifndef INCLUDE_MCAL_EXTINT_EXTINT_INTERFACE_H_
#define INCLUDE_MCAL_EXTINT_EXTINT_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_UTILIES.h"

#define EXTINT_INT0 0
#define EXTINT_INT1 1
#define EXTINT_INT2 2

// Modes of INT0 & INT1

#define EXTINT_INT01_lowlevel 0
#define EXTINT_INT01_logicalChange 1
#define EXTINT_INT01_fallingEdge 2
#define EXTINT_INT01_risingEdge 3

// Modes of INT2

#define EXTINT_INT2_fallingEdge 2
#define EXTINT_INT2_risingEdge 3


#define GICR_INT0    6
#define GICR_INT1    7
#define GICR_INT2    5

void EXTINT_voidEnable(u8 Copy_u8ExtIntNum , u8 Copy_u8EdgeIntSource);

void EXTINT_voidDisable(u8 Copy_u8ExtIntNum);


#endif /* INCLUDE_MCAL_EXTINT_EXTINT_INTERFACE_H_ */
