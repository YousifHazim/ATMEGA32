#include "STD_TYPES.h"
#include "BIT_UTILIES.h"


#include "SPI/SPI.h"
#include "SPI_prv.h"

void SPI_voidInit(void){

	/* Enable SPI */

#if SPI == Enable

	SET_BIT(SPCR, SPE); // Enable

	/* Data Order */

#if Order == LSB
	SET_BIT(SPCR, DORD); //the LSB of the data word is transmitted first.
#elif Order == MSB
	CLR_BIT(SPCR, DORD); //the MSB of the data word is transmitted first
#else
	#error "Data Order Must be LSB or MSB"
#endif

	/* Clock Polarity */

#if Polarity == Rising_Falling
	CLR_BIT(SPCR, CPOL); // Leading -> Rising , Trailing -> Falling
#elif Polarity == Falling_Rising
	SET_BIT(SPCR, CPOL); // Leading -> Falling , Trailing -> Rising
#else
	#error "Clock Polarity Must be Rising or Falling"
#endif

	/* Clock Phase */

#if Phase == Sample_Setup
	CLR_BIT(SPCR, CPHA); // Leading -> Sample , Trailing -> Setup
#elif Phase == Setup_Sample
	SET_BIT(SPCR, CPHA); // Leading -> Setup , Trailing -> Sample
#else
	#error "Clock Phase Must be Sample or Setup"
#endif

	/* Enabe Master Or Slave Mode */

#if	MODE == Master

		SET_BIT(SPCR, MSTR); // Master SPI mode

	/* Prescaller */

#if Prescaller == Prescaller0_4
		CLR_BIT(SPCR, SPR0);
		CLR_BIT(SPCR, SPR1);
		CLR_BIT(SPSR, SPI2X0);
#elif Prescaller == Prescaller0_16
		SET_BIT(SPCR, SPR0);
		CLR_BIT(SPCR, SPR1);
		CLR_BIT(SPSR, SPI2X0);
#elif Prescaller == Prescaller0_64
		CLR_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		CLR_BIT(SPSR, SPI2X0);
#elif Prescaller == Prescaller0_128
		SET_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		CLR_BIT(SPSR, SPI2X0);
#elif Prescaller == Prescaller1_2
		CLR_BIT(SPCR, SPR0);
		CLR_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X0);
#elif Prescaller == Prescaller1_8
		SET_BIT(SPCR, SPR0);
		CLR_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X0);
#elif Prescaller == Prescaller1_32
		CLR_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X0);
#elif Prescaller == Prescaller1_64
		SET_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X0);
#else
	#error "Must be chose Prescaller"
#endif

		/* Enabe Master Or Slave Mode */

#elif MODE == Slave

		CLR_BIT(SPCR, MSTR); // Slave SPI mode

#else
	#error "Must be chose Master or Slave"
#endif

		/* Disable SPI */

#elif SPI == Disable
		CLR_BIT(SPCR, SPE); // Disable
#else
	#error "SPI Must be Enable or Disable"
#endif

}

u8 SPI_SendAndReceive(u8 u8Data){

	SPDR = u8Data;

	while (GET_BIT(SPSR, SPIF) == 0); // SPI Interrupt Flag

	return SPDR;

}

void SPI_SendData(u8 u8Data){

	SPDR = u8Data;

	while (GET_BIT(SPSR, SPIF) == 0); // SPI Interrupt Flag

}

u8 SPI_ReceiveData(void){

	while (GET_BIT(SPSR, SPIF) == 0); // SPI Interrupt Flag

	return SPDR;

}
