/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 27 SEP 2021                    */
/*              NTI Diploma                    */
/*              SPI Driver                     */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_register.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"


/* Initializing SPI */
void MSPI_voidInit(void)
{
								/* Select SPI Clock	*/
								
	#if		SPI_CLOCK_PRESCALER == 2               
		CLR_BIT(SPCR,  SPR0);				// Set SPR0  bit in SPCR to 0
		CLR_BIT(SPCR,  SPR1);               // Set SPR1  bit in SPCR to 0
		SET_BIT(SPSR,  SPI2X);              // Set SPI2X bit in SPSR to 1
		
	#elif	SPI_CLOCK_PRESCALER == 4
		CLR_BIT(SPCR,  SPR0);				// Set SPR0  bit in SPCR to 0
		CLR_BIT(SPCR,  SPR1);               // Set SPR1  bit in SPCR to 0
		CLR_BIT(SPSR,  SPI2X);              // Set SPI2X bit in SPSR to 0
	
	#elif	SPI_CLOCK_PRESCALER == 8
		SET_BIT(SPCR,  SPR0);				// Set SPR0  bit in SPCR to 1
		CLR_BIT(SPCR,  SPR1);               // Set SPR1  bit in SPCR to 0
		SET_BIT(SPSR,  SPI2X);              // Set SPI2X bit in SPSR to 1
	
	#elif	SPI_CLOCK_PRESCALER == 16
		SET_BIT(SPCR,  SPR0);				// Set SPR0  bit in SPCR to 1
		CLR_BIT(SPCR,  SPR1);               // Set SPR1  bit in SPCR to 0
		CLR_BIT(SPSR,  SPI2X);              // Set SPI2X bit in SPSR to 0
	
	#elif	SPI_CLOCK_PRESCALER == 32
		CLR_BIT(SPCR,  SPR0);				// Set SPR0  bit in SPCR to 0
		SET_BIT(SPCR,  SPR1);               // Set SPR1  bit in SPCR to 1
		SET_BIT(SPSR,  SPI2X);              // Set SPI2X bit in SPSR to 1
	
	#elif	SPI_CLOCK_PRESCALER == 64
		CLR_BIT(SPCR,  SPR0);				// Set SPR0  bit in SPCR to 0
		SET_BIT(SPCR,  SPR1);               // Set SPR1  bit in SPCR to 1
		CLR_BIT(SPSR,  SPI2X);              // Set SPI2X bit in SPSR to 0
	
	#elif	SPI_CLOCK_PRESCALER == 128
		SET_BIT(SPCR,  SPR0);				// Set SPR0  bit in SPCR to 1
		SET_BIT(SPCR,  SPR1);               // Set SPR1  bit in SPCR to 1
		CLR_BIT(SPSR,  SPI2X);              // Set SPI2X bit in SPSR to 0
		
	#endif
	
	
							/* 	Select Data Order	*/
							
	#if 	DATA_ORDER == LSB
		SET_BIT(SPCR,  DORD);				// Set DORD bit in SPCR to 1
		
	#elif	DATA_ORDER == MSB
		CLR_BIT(SPCR,  DORD);				// Set DORD bit in SPCR to 0
		
	#endif
	
	
						/* 	Select type: Master/Slave	*/
						
	#if 	MASTER_OR_SLAVE == MASTER
		SET_BIT(SPCR,  MSTR);				// Set MSTR bit in SPCR to 1
		
	#elif	MASTER_OR_SLAVE == SLAVE
		CLR_BIT(SPCR,  MSTR);				// Set MSTR bit in SPCR to 0
		
	#endif
	
	
				/*	 Select MODE (Clock Phase and Clock Polarity)	*/
				
	#if 	MODE == 0
		CLR_BIT(SPCR,  CPHA);				// Set CPHA bit in SPCR to 0
		CLR_BIT(SPCR,  CPOL);				// Set CPOL bit in SPCR to 0
		
	#elif	MODE == 1
		SET_BIT(SPCR,  CPHA);				// Set CPHA bit in SPCR to 1
		CLR_BIT(SPCR,  CPOL);				// Set CPOL bit in SPCR to 0
		
	#elif	MODE == 2
		CLR_BIT(SPCR,  CPHA);				// Set CPHA bit in SPCR to 0
		SET_BIT(SPCR,  CPOL);				// Set CPOL bit in SPCR to 1
		
	#elif	MODE == 3
		SET_BIT(SPCR,  CPHA);				// Set CPHA bit in SPCR to 1
		SET_BIT(SPCR,  CPOL);				// Set CPOL bit in SPCR to 1
		
	#endif
	
	
				/* 	Enable Global Interrupt in SREG Register		*/
				
	SET_BIT(SREG,  7);						// Set interrupt bit in SREG to 1
	
	
							/* Enable SPI Interrupt	*/
							
	SET_BIT(SPCR,  SPIE);					// Set SPIE bit in SPCR to 1
	
							/* Set SPI Pins to be output */
	SET_BIT(MOSI);
	SET_BIT(MISO);
	SET_BIT(SCK);
	
								/* 	SPI Enable	*/
								
	SET_BIT(SPCR,  SPE);					// Set SPE bit in SPCR to 1
	
	
}


/* Transmit and Recieve Data */
void MSPI_voidTransiever(u8 Copy_u8TransmittedData, u8 *Copy_RecievedData)
{
	// Send Data
	SPDR = Copy_u8TransmittedData;
	
	// Wait Data to be fully transmitted
	while(GET_BIT(SPSR, SPIF) == 0);
	
	// Store recieved data
	Copy_RecievedData = SPDR;
}


/*
// Slave Select 
void MSPI_voidSlaveSelect(u8 Copy_u8SlavePin)
{
	// Set All Slaves Pins to be output 
	u8 i = 0;
	while(i < SLAVES_NO)
	{
			SET_BIT(slave[i][0], slave[i][1]);				// Set pin to be output
			i++;
	}
	
	
								// Set All Slaves Pins to be HIGH 
	u8 i = 0;
	while(i < SLAVES_NO)
	{
		if()
		{
			
		}
		
		else if()
		{
			
		}
		
		else if()
		{
			
		}
		
		else if()
		{
			
		}
			SET_BIT(slave[i][0], slave[i][1]);				// Set pin to be output
			i++;
	}
	
	
	
	
}
*/

