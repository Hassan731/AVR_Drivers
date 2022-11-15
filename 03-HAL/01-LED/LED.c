/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 8 SEP 2021                     */
/*              NTI Diploma                    */
/*              LED Driver                     */
/***********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED.h"


																		/* Initialize Port */
																		
void HLED_voidLedPortInit(u8 Copy_u8Port)
{
	MDIO_voidSetPort(Copy_u8Port);
}

                                                                 /* Initializing the port to be output */

void HLED_voidLedInit(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	MDIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, OUTPUT);
	
}

                                                                             /* Turn ON LED */

void HLED_voidLedOn(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, HIGH);
	
}

                                                                            
                                                                             /* Turn OFF LED */
																			 
void HLED_voidLedOff(u8 Copy_u8Port, u8 Copy_u8Pin)
{
		MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, LOW);

}

                                                                             /* Toggle LED */

void HLED_voidLedTog(u8 Copy_u8Port, u8 Copy_u8Pin)
{
		MDIO_voidTogglePin(Copy_u8Port, Copy_u8Pin);
}

                                                                      /* Turn All LEDs on the hole Port On */

void HLED_voidLedPortOn(u8 Copy_u8Port)
{
	
	MDIO_voidPortOn(Copy_u8Port);
}

                                                                      /* Turn All LEDs on the hole Port Off */

void HLED_voidLedPortOff(u8 Copy_u8Port)
{
	
	MDIO_voidPortOff(Copy_u8Port);
}



