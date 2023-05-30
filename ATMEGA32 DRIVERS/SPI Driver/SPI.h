
#ifndef INCLUDE_MCAL_SPI_SPI_H_
#define INCLUDE_MCAL_SPI_SPI_H_

/* SPCR Register */

#define SPR0 	0 // SPI Clock Rate
#define SPR1 	1 // SPI Clock Rate
#define CPHA 	2 // Clock Phase
#define CPOL 	3 // Clock Polarity
#define MSTR 	4 // Master/Slave Select
#define DORD 	5 // Data Order
#define SPE  	6 // SPI Enable

/* SPSR Register */

#define SPIF	7 // SPI Interrupt Flag
#define SPI2X0	0 // Double SPI Speed Bit

/* SPI Function */

void SPI_voidInit(void);
u8 SPI_SendAndReceive(u8 u8Data);
void SPI_SendData(u8 u8Data);
u8 SPI_ReceiveData(void);

#endif /* INCLUDE_MCAL_SPI_SPI_H_ */
