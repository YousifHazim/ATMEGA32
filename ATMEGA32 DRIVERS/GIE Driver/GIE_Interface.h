#ifndef INCLUDE_MCAL_GIE_GIE_INTERFACE_H_
#define INCLUDE_MCAL_GIE_GIE_INTERFACE_H_

#include "BIT_UTILIES.h"
#include "STD_TYPES.h"


#define SREG_BIT  7

void GIE_voidGlobalInterruptEnable(void); // enable

void GIE_voidGlobalInterruptDisable(void); // disable

#endif /* INCLUDE_MCAL_GIE_GIE_INTERFACE_H_ */
