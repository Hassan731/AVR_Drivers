/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 8 SEP 2021                     */
/*              NTI Diploma                    */
/*              LED Driver                     */
/***********************************************/


#ifndef  LED_H
#define  LED_H


// Initialize Port 
void HLED_voidLedPortInit(u8 Copy_u8Port);

// Initializing the pin to be output
void HLED_voidLedInit(u8 Copy_u8Port, u8 Copy_u8Pin);

// Turn ON LED
void HLED_voidLedOn(u8 Copy_u8Port, u8 Copy_u8Pin);

// Turn OFF LED
void HLED_voidLedOff(u8 Copy_u8Port, u8 Copy_u8Pin);

// Toggle LED
void HLED_voidLedTog(u8 Copy_u8Port, u8 Copy_u8Pin);

// Turn All LEDs on the hole Port On
void HLED_voidLedPortOn(u8 Copy_u8Port);

// Turn All LEDs on the hole Port Off
void HLED_voidLedPortOff(u8 Copy_u8Port);



																		/*   Available Pins   */
																		
/*

	   DIOA:           DIOB:			DIOC:				DIOD:
			PIN0  			PIN0     	 	 PIN0             	 PIN0
			PIN1			PIN1             PIN1                PIN1
			PIN2			PIN2             PIN2                PIN2
			PIN3			PIN3             PIN3                PIN3
			PIN4			PIN4             PIN4                PIN4
			PIN5			PIN5             PIN5                PIN5
			PIN6			PIN6             PIN6                PIN6
			PIN7			PIN7             PIN7                PIN7
			
*/

#endif