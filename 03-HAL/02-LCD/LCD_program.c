/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 9 SEP 2021                     */
/*              NTI Diploma                    */
/*              LCD Driver                     */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_private.h"
#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"

// To use delay we must add these lines
#define F_CPU 8000000UL
#include <util/delay.h>



																			/* Initializing the LCD */
																			
void HLCD_voidLcdInit()
{
	// Set Pins attached to LCD to be Output
	MDIO_voidSetPinDirection(RS, OUTPUT);             
	MDIO_voidSetPinDirection(R_W, OUTPUT);
 	MDIO_voidSetPinDirection(E, OUTPUT);   
	
	switch(WRITING_MODE)                                 // Check for mode
	{
		case Eight_BIT_MODE:
			MDIO_voidSetPort(LCD_PORT);                 // if mode was 8_Bit, enable all port
			
			// Activate 8_bit Mode
			HLCD_voidWriteCMD(EIGHT_BIT);
	
			break;
		case FOUR_BIT_MODE:
			MDIO_voidSetPinDirection(D4, OUTPUT);       // if mode was 4_Bit, enable only four pins
			MDIO_voidSetPinDirection(D5, OUTPUT);
			MDIO_voidSetPinDirection(D6, OUTPUT);
			MDIO_voidSetPinDirection(D7, OUTPUT);  

			// Activate 4_bit mode
			HLCD_voidWriteCMD(FOUR_BIT_CMD1);
			HLCD_voidWriteCMD(FOUR_BIT_CMD2);
			HLCD_voidWriteCMD(FOUR_BIT_CMD3);
			
			break;
		default:
			MDIO_voidSetPort(LCD_PORT);
			break;
	}
	           
	// make a small delay
	_delay_ms(100);
	
	
	// some commands to make things ready
	HLCD_voidWriteCMD(DSP_ON_CRS_OFF);  							 /* THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR */
    HLCD_voidWriteCMD(CLEAR);  					     				 /*            THIS_COMMAND_TO_CLEAR_LCD_               */
    HLCD_voidWriteCMD(CRS_INC);  				 					 /*   THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT    */
    HLCD_voidWriteCMD(HOME);  						    			 /*          THIS_COMMAND_TO_RETURN_HOME                */
	
}


																				/* Send Command */
																				
void HLCD_voidWriteCMD(u8 Copy_u8CMD)
{
	// Set RS, E and R/w to zero
	MDIO_voidSetPinValue(RS, LOW);
	MDIO_voidSetPinValue(E, LOW);
	MDIO_voidSetPinValue(R_W, LOW);
	
	// Check for the writing mode
	switch(WRITING_MODE)
	{
		case Eight_BIT_MODE:
		// Sending Command
			MDIO_voidWritePort(LCD_PORT, Copy_u8CMD);
			MDIO_voidSetPinValue(E, HIGH);
			_delay_ms(5);
			MDIO_voidSetPinValue(E, LOW);
			_delay_ms(10);
			break;
		
		case FOUR_BIT_MODE:
		// Sending High Part
			MDIO_voidWritePort(LCD_PORT, (Copy_u8CMD & 0xf0) | (LCD_PORT & 0x0f));
			MDIO_voidSetPinValue(E, HIGH);
			_delay_ms(1);
			MDIO_voidSetPinValue(E, LOW);
		
		// Sending LOW Part
			MDIO_voidWritePort(LCD_PORT, (Copy_u8CMD << 4) | (LCD_PORT & 0x0f));
			MDIO_voidSetPinValue(E, HIGH);
			_delay_ms(1);
		MDIO_voidSetPinValue(E, LOW);
			_delay_ms(5);

			break;
		
		default:
		break;
	}
}


																				/* Send one Char */
																				
void HLCD_voidWriteChar(u8 Copy_u8char)
{

	// Set RS, E and R/w to zero
	MDIO_voidSetPinValue(RS, HIGH);
	MDIO_voidSetPinValue(E, LOW);
	MDIO_voidSetPinValue(R_W, LOW);
	
	// Check for the writing mode
	switch(WRITING_MODE)
	{
		case Eight_BIT_MODE:
		// Sending Data
			MDIO_voidWritePort(LCD_PORT, Copy_u8char);
			MDIO_voidSetPinValue(E, HIGH);
			_delay_ms(5);
			MDIO_voidSetPinValue(E, LOW);
			_delay_ms(10);
			break;
		
		case FOUR_BIT_MODE:
		// Sending High Part
			MDIO_voidWritePort(LCD_PORT, (Copy_u8char & 0xf0) | (LCD_PORT & 0x0f));
			MDIO_voidSetPinValue(E, HIGH);
			_delay_ms(1);
			MDIO_voidSetPinValue(E, LOW);
		
		// Sending LOW Part
			MDIO_voidWritePort(LCD_PORT, (Copy_u8char << 4) | (LCD_PORT & 0x0f));
			MDIO_voidSetPinValue(E, HIGH);
			_delay_ms(1);
			MDIO_voidSetPinValue(E, LOW);
			_delay_ms(5);
		
		break;
		
		default:
		break;
	}
	// Increment cursor
	HLCD_voidWriteCMD(CRS_INC);

	// Blink Cursor
	HLCD_voidWriteCMD(DISP_CRS_BLINK);
}


																				  /* Send String */
																				  
void HLCD_voidWriteString(u8* STR_PTR)
{
	u8 i =0;
	
	while(STR_PTR[i] != '\0')
	{
		HLCD_voidWriteChar(STR_PTR[i]);
		++i;
	}
}

																			       /* Clear LCD   */
																				   
void HLCD_voidClear(void)
{
	HLCD_voidWriteCMD(CLEAR);
}

																				  /* Send integer */

void HLCD_voidWriteNumber(u8 Copy_u8num)
{
	// Initializing Variables
	u32 rem = 0;
	u8 arr [17];
	s8 i = 0;
	
	// Storing each digit in an array
	while(Copy_u8num != 0)
	{
		rem = Copy_u8num % 10;
		arr[i] = rem + 48;
		i++;
		Copy_u8num = Copy_u8num / 10;
	}
	i--;
	
	// Sending char by char to the LCD
	while(i > -1)
	{
	    HLCD_voidWriteChar(arr[i]);
	    i--;
	}
	
}

																		/* Read from LCD */

u32 HLCD_u32LCDRead(void)
{
		// Declaring variable for data read
		u32 value;

		// Set the data port to be input
		MDIO_voidResetPort(LCD_PORT);

		// Set RS, E to zero and R/w to one
		MDIO_voidSetPinValue(RS, HIGH);
		MDIO_voidSetPinValue(E, LOW);
		MDIO_voidSetPinValue(R_W, HIGH);

		// Check for the writing mode
		switch(WRITING_MODE)
		{
			case Eight_BIT_MODE:
			// Reading Data
				value = MDIO_u32GetPortValue(LCD_PORT);
				MDIO_voidSetPinValue(E, HIGH);
				_delay_ms(5);
				MDIO_voidSetPinValue(E, LOW);
				_delay_ms(10);
				break;
				/*
			case FOUR_BIT_MODE:
			// Sending High Part
				MDIO_voidWritePort(LCD_PORT, (Copy_u8char & 0xf0) | (LCD_PORT & 0x0f));
				MDIO_voidSetPinValue(E, HIGH);
				_delay_ms(1);
				MDIO_voidSetPinValue(E, LOW);

			// Sending LOW Part
				MDIO_voidWritePort(LCD_PORT, (Copy_u8char << 4) | (LCD_PORT & 0x0f));
				MDIO_voidSetPinValue(E, HIGH);
				_delay_ms(1);
				MDIO_voidSetPinValue(E, LOW);
				_delay_ms(5);

			break;
				*/
			default:
			break;
		}
		return value;
}
