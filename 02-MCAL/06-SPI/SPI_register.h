/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 27 SEP 2021                    */
/*              NTI Diploma                    */
/*              SPI Driver                     */
/***********************************************/

#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H


/* SPI Registers */
#define		SPCR				*((volatile u8*)0x2D)				// SPI Control Register
#define 	SPSR				*((volatile u8*)0x2E)               // SPI Status Register
#define 	SPDR				*((volatile u8*)0x2F)               // SPI Data Register



/* Status Register */
#define		SREG			*((volatile u8*)0x5F)					// Status Register

/* DDRx and PORTx Registers to use in timers */
#define 	DDRA      	    *((volatile u8*)0x3A)
#define		DDRB			*((volatile u8*)0x37)
#define		DDRC			*((volatile u8*)0x34)
#define		DDRD			*((volatile u8*)0x31)

#define 	PORTA          *((volatile u8*)0x3B)
#define 	PORTB          *((volatile u8*)0x38)
#define 	PORTC          *((volatile u8*)0x35)
#define 	PORTD          *((volatile u8*)0x32)

#endif