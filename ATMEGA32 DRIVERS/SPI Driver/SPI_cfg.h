#ifndef INCLUDE_MCAL_SPI_SPI_CFG_H_
#define INCLUDE_MCAL_SPI_SPI_CFG_H_

/* SPI Enable Or Disable */

// Enable  1
// Disable 0

#define SPI Enable

/* Data Order */

// LSB 1 -> the LSB of the data word is transmitted first
// MSB 0 -> the MSB of the data word is transmitted first

#define Order LSB

/* Clock Polarity */

// Rising_Falling 0 -> Leading -> Rising , Trailing -> Falling
// Falling_Rising 1 -> Leading -> Falling , Trailing -> Rising

#define Polarity Rising_Falling

/* Clock Phase */

// Sample_Setup 0 	-> Leading -> Sample , Trailing -> Setup
// Setup_Sample 1	-> Leading -> Setup , Trailing -> Sample

#define Phase Sample_Setup

/* Enabe Master Or Slave Mode */

// Master
// Slave

#define MODE Master

/* Prescaller */

// Prescaller0_4  		-> f/4 		without SPI2X
// Prescaller0_16 		-> f/16		without SPI2X
// Prescaller0_64 		-> f/64		without SPI2X
// Prescaller0_128 		-> f/128 	without SPI2X

// Prescaller1_2 		-> f/2		with SPI2X
// Prescaller1_8 		-> f/8 		with SPI2X
// Prescaller1_32 		-> f/32 	with SPI2X
// Prescaller1_64 		-> f/64 	with SPI2X

#define Prescaller Prescaller0_4

#endif /* INCLUDE_MCAL_SPI_SPI_CFG_H_ */
