/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 13 SEP 2021                    */
/*              NTI Diploma                    */
/*             PUSH_BUTTON Driver              */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "PUSH_BUTTON_config.h"
#include "PUSH_BUTTON_interface.h"


																	/* Initializing Push Button */
																	
void HButton_voidInit()
{
	MDIO_voidSetPinDirection(Button_Port, Button_Pin, INPUT);
	
	MDIO_voidSetPinValue(Button_Port, Button_Pin, HIGH);
	
}

																		/* Read the Button */
																		
u8 HButton_u8Read()
{
	// Initializing variable for the value
	u8 value = 0;
	
	// Reading Value
	value = MDIO_u8GetPinValue(Button_Port, Button_Pin);
	
	return value;
	
}
