/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 13 SEP 2021                    */
/*              NTI Diploma                    */
/*              7-SEGMENT Driver               */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

	
																	/* Initializing Seven Segment */
																	
void HSEVENSEG_voidInit(void)
{
	// Set all pins connected to segments to be output
	MDIO_voidSetPort(SEGMENT);
	
	
}

																	/* Add Seven Segment enable pin */

void HSEVENSEG_voidAddSeg(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	// Set enable pin to be output
	MDIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, OUTPUT);

	// Set pin to High to disable segment
	MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, HIGH);
}



																	/* Send Number to be displayed */
																	
void HSEVENSEG_voidDispaly(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Numbre)
{
	if(Copy_u8Numbre >= 10)
	{
		return;
	}
	else
	{
		// Declaring a variable
		u8 num;

		// Convert the number to binary matching the pins of the segments
		num = GetBinaryNumber(Copy_u8Numbre);

		// Send data to be displayed
		MDIO_voidWritePort(SEGMENT, num);

		MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, LOW);     // Enable Segment
	}

}

u8 GetBinaryNumber(u8 x){
	
	// segment a = LSB is connected to pin0
	u8 Binary_numbers[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
	
	//uint8_t BCD_numbers[] = {0b00000000, 0b00001000, 0b00000100, 0b00001100, 0b00000010, 0b00001010, 0b00000110, 0b00001110, 0b00000001, 0b00001001};
	
	// Get x in Binary
	switch (x) {
	
		case 0 :
			x = Binary_numbers[0];
			break;
	
		case 1 :
			x = Binary_numbers[1];
			break;
	
		case 2 :
			x = Binary_numbers[2];
			break;
	
		case 3 :
			x = Binary_numbers[3];
			break;
	
		case 4 :
			x = Binary_numbers[4];
			break;
	
		case 5 :
		    x = Binary_numbers[5];
			break;
	
		case 6 :
			x = Binary_numbers[6];
			break;
	
		case 7 :
			x = Binary_numbers[7];
			break;
	
		case 8 :
			x = Binary_numbers[8];
			break;
	
		case 9 :
			x = Binary_numbers[9];
			break;
	}
	return(x);
}

														/* Disable Segment */

void HSEVENSEG_voidDisable(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, HIGH);     // Disable Segment
}


													/* Count down function */

void HSEVENSEG_voidCOUNTDWN(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Number)
{
	// Declaring a temp variable
	u8 temp = Copy_u8Number;

	// Declaring Counter
	s16 counter = temp;

	#if COUNT_DWN_AUTO_RELOAD == OFF

		while(counter > -1)
		{

			// Convert decimal number to binary for seven segment
			GetBinaryNumber(counter);

			// Display
			HSEVENSEG_voidDispaly(Copy_u8Port, Copy_u8Pin, counter);

			// Delay for displaying
			_delay_ms(100);

		/*
		// Check to reload counter
		if(counter == 0)
		{
			// Reset Counter
			counter = 9;
		}

		else
		{
			// Counter Decrement
			counter--;
		}
		*/

			// Counter Decrement
			counter--;
		}

	#elif COUNT_DWN_AUTO_RELOAD == ON

		while(counter > -1)
		{
			// Convert decimal number to binary for seven segment
			GetBinaryNumber(counter);

			// Display
				HSEVENSEG_voidDispaly(Copy_u8Port, Copy_u8Pin, counter);

			// Delay for displaying
			_delay_ms(100);


			// Check to reload counter
			if(counter == 0)
			{
				// Reset Counter
				counter = 9;
			}

			else
			{
				// Counter Decrement
				counter--;
			}
		}

	#endif
}

												/* Count up function */

void HSEVENSEG_voidCOUNTUP(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Number)
{
	// Declaring a temp variable
	u8 temp = Copy_u8Number;

	// Declaring Counter
	s8 counter = temp;

	#if COUNT_UP_AUTO_RELOAD == OFF

		while(counter < 10)
		{
			// Convert decimal number to binary for seven segment
			GetBinaryNumber(counter);

			// Display
			HSEVENSEG_voidDispaly(Copy_u8Port, Copy_u8Pin, counter);

			// Delay for displaying
			_delay_ms(100);

			/*
			// Check to reload counter
			if(counter == 9)
			{
				// Reset Counter
				counter = 0;
			}

			else
			{
				// Counter Increment
				counter++;
			}
			 */

			// Counter Increment
			counter++;
	}

	#elif COUNT_UP_AUTO_RELOAD == ON

		while(counter < 10)
		{
			// Convert decimal number to binary for seven segment
			GetBinaryNumber(counter);

			// Display
			HSEVENSEG_voidDispaly(Copy_u8Port, Copy_u8Pin, counter);

			// Delay for displaying
			_delay_ms(100);


			// Check to reload counter
			if(counter == 9)
			{
				// Reset Counter
				counter = 0;
			}

			else
			{
				// Counter Increment
				counter++;
			}
		}

	#endif
}
