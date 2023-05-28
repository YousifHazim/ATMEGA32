#include "GIE_Interface.h"
#include "GIE_prv.h"
#include "BIT_UTILIES.h"
#include "STD_TYPES.h"


void GIE_voidGlobalInterruptEnable(void)
{

	SET_BIT(SREG,SREG_BIT);

}

void GIE_voidGlobalInterruptDisable(void)
{

	CLR_BIT(SREG,SREG_BIT);

}
