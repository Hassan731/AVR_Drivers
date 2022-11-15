/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 27 SEP 2021                    */
/*              NTI Diploma                    */
/*              SPI Driver                     */
/***********************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


																	/* SLAVES SET */
#define 	SLAVES_NO								3								

/* Initialize an array to store slaves Port, bit */	
						
u8 slave[SLAVES_NO][2] = {{SS}, {DIOB,0}, {DIOB, 1} };                                  // NOTES:
																					   /*		
																									1- you should Set the number of slaves and type its port and pin in the array
																									2- SS is always connected to Port B Pin 4
																									3- you can add any number of slaves according to available pins
																									4- you can call only one slave a time
																						*/
																									


																/* SPI CONFIGURATIONS */
																
#define		MASTER_OR_SLAVE							MASTER				// choose from: MASTER , SLAVE
#define 	DATA_ORDER								MSB					// choose from: MSB , LSB    -> the choosed one will be transmitted first
#define 	SPI_CLOCK_PRESCALER						4					// choose from: 2, 4, 8, 16, 32, 64, 128
#define 	MODE									0					// choose from: 0, 1, 2, 3						
																					/*
																							"MODE"							"Leading Edge"			"Trailing Edge"
																					
																					MODE 0:		CPOL = 0, CPHA = 0			Sample (Rising)			Setup (Falling)
																					MODE 1:		CPOL = 0, CPHA = 1			Setup (Rising)			Sample (Falling)
																					MODE 2:		CPOL = 1, CPHA = 0			Sample (Falling)		Setup (Rising)
																					MODE 3:		CPOL = 1, CPHA = 1			Setup (Falling)			Sample (Rising)
																					
																									*/



/*  */





#endif