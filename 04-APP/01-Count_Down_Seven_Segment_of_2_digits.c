/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 13 SEP 2021                    */
/*              NTI Diploma                    */
/*              7-SEGMENT APP                  */
/*            Count Down for 2-Digits          */
/***********************************************/

												/* Count_Down_Seven_Segment_of_2_digits */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

									/* Some Configurations */

#define      INDICATION_LED        DIOD, PIN0
#define 	    SEG_1_EN		   DIOA, PIN0
#define 	    SEG_2_EN		   DIOA, PIN1



void CountDown2Digits(u8 Copy_u8Number);

int main()
{
	// Define an indication LED
	MDIO_voidSetPinDirection(INDICATION_LED, OUTPUT);

	// Initializing Seven Segment
	HSEVENSEG_voidInit();

	// Adding Seven_Segment to the system
	HSEVENSEG_voidAddSeg(SEG_1_EN);
	HSEVENSEG_voidAddSeg(SEG_2_EN);




	while(1)
	{
		// Turn off Process termination indication LED
		MDIO_voidSetPinValue(INDICATION_LED, LOW);

		// Calling Count Down Function
		CountDown2Digits(100);

		// Turn on Process termination indication LED
		MDIO_voidSetPinValue(INDICATION_LED, HIGH);

		// Set about 2 seconds delay
		_delay_ms(200);

	}
}

void CountDown2Digits(u8 Copy_u8Number)
{


	// Initializing a temporary variable holds the incoming data
	u8 temp = Copy_u8Number;

	// Declare two signed variables to hold each digit (number and remainder)
	s8 num, rem;

	// Declaring counter
	u8 i = 0;

	if(Copy_u8Number >= 100)
	{
		// Set Both Segments to state Error
		MDIO_voidWritePort(SEGMENT, 0b01000000);
		MDIO_voidSetPinValue(SEG_1_EN, LOW);
		MDIO_voidSetPinValue(SEG_2_EN, LOW);
		_delay_ms(300);
	}

	else if(Copy_u8Number < 100)
	{
		// Separate the number into two digits
		num = temp / 10;
		rem = temp % 10;

		while(num >= 0)
		{
			for(i = 0; i <= 10; i++)
			{
				HSEVENSEG_voidDispaly(SEG_1_EN, num);
				_delay_ms(5);
				HSEVENSEG_voidDisable(SEG_1_EN);

				HSEVENSEG_voidDispaly(SEG_2_EN, rem);
				_delay_ms(5);
				HSEVENSEG_voidDisable(SEG_2_EN);

			}

			//Check for remainder value
			if(rem > 0)
			{
				// Remainder Decrement
				rem--;
			}
			else if(rem == 0)
			{
				// Check for number value
				if(num > 0)
				{
					// Reloading the low digit to 9
					rem = 9;

					// number Decrement
					num--;
				}
				else if(num == 0)
				{
					// when number reaches zero and remainder reaches zero, break
					break;
				}
			}
		}

	}


		// Turn off the segments
		HSEVENSEG_voidDisable(SEG_1_EN);
		HSEVENSEG_voidDisable(SEG_2_EN);

}
