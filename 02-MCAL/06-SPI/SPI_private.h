/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 27 SEP 2021                    */
/*              NTI Diploma                    */
/*              SPI Driver                     */
/***********************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


/* SPI Control Register */
#define			SPR0					0				// SPI Clock Rate Select bit 0
#define			SPR1					1               // SPI Clock Rate Select bit 1
#define			CPHA					2               // Clock Phase
#define			CPOL					3               // Clock Polarity
#define			MSTR					4               // Master/Slave Select
#define			DORD					5               // Data Order
#define			SPE						6               // SPI Enable
#define			SPIE					7               // SPI Interrupt Enable


// SPI Status Register
#define			SPI2X					0				// Double SPI Speed Bit
#define			WCOL					6               // Write COLlision Flag
#define			SPIF					7               // SPI Interrupt Flag
		



/* Private MACROS */
#define				SS					DIOB, 4				  // PORT B PIN 4 (Slave Select)
#define				MOSI				DIOB, 5               // PORT B PIN 5 (MASTER OUTPUT SLAVE INPUT)
#define				MISO				DIOB, 6               // PORT B PIN 6 (MASTER INPUT SLAVE OUTPUT)
#define				SCK					DIOB, 7               // PORT B PIN 7 (Serial Clock)

#define				MASTER				0
#define				SLAVE				1

#define				LSB					0
#define				MSB					1

#endif