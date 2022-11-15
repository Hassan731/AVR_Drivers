/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 12 SEP 2021                    */
/*              NTI Diploma                    */
/*              KEYPAD Driver                  */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_private.h"
#include "DIO_interface.h"

#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"

// To use delay
#define F_CPU 8000000UL
#include <util/delay.h>


																	/* Initializing KEYPAD */
																	
void HKEYPAD_voidInit(void)
{
	// Set all ROWS to be OUTPUT
	MDIO_voidSetPinDirection(ROW1, OUTPUT);
	MDIO_voidSetPinDirection(ROW2, OUTPUT);
	MDIO_voidSetPinDirection(ROW3, OUTPUT);
	MDIO_voidSetPinDirection(ROW4, OUTPUT);
	
	// Set all ROWS to HIGH
	MDIO_voidSetPinValue(ROW1, HIGH);
	MDIO_voidSetPinValue(ROW2, HIGH);
	MDIO_voidSetPinValue(ROW3, HIGH);
	MDIO_voidSetPinValue(ROW4, HIGH);
	
	
	
	// Set all COULMNS to be INPUT
	MDIO_voidSetPinDirection(COULMN1, INPUT);
	MDIO_voidSetPinDirection(COULMN1, INPUT);
	MDIO_voidSetPinDirection(COULMN1, INPUT);
	MDIO_voidSetPinDirection(COULMN1, INPUT);
	
	// Enable PULL_UP resistors for all coulmns
	MDIO_voidSetPinValue(COULMN1, HIGH);
	MDIO_voidSetPinValue(COULMN2, HIGH);
	MDIO_voidSetPinValue(COULMN3, HIGH);
	MDIO_voidSetPinValue(COULMN4, HIGH);
	
	
}


																  /* Read Button from KEYPAD */
																  
u8 HKEYPAD_u8Read(void)
{
	// Declaring counters
	u8 counter1, counter2;
	
	// Declaring temp variable
	u8 temp;
	
	// Declaring variables
	u8 value;
	
	// Check every button if pressed
	
	for(counter1 = 0; counter1 < ROWS; counter1++)
	{
		// Set each row to 0 and check every coulmn in the row for any pressed button
		MDIO_voidSetPinValue(rows[counter1][0], rows[counter1][1], LOW);
		
		for(counter2 = 0; counter2 < COULMNS; counter2++)
		{
			temp = MDIO_u8GetPinValue(coulmns[counter2][0], coulmns[counter2][1]);
			
			if(temp == 0)
	        {
	        	_delay_ms(10);
	        	temp = MDIO_u8GetPinValue(coulmns[counter2][0], coulmns[counter2][1]);
	        	 if(temp == 0)
	        	 {
	        	value = buttons[counter1][counter2];
	        	 }
			}
			/*
			if(if temp == 0)
			{
				value = buttons[counter1][counter2];
			}
			*/
		}
		
		MDIO_voidSetPinValue(rows[counter1][0], rows[counter1][1], HIGH);
		
	}
	
	return value;
}
