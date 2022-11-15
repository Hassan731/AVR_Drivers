/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 7 SEP 2021                     */
/*              NTI Diploma                    */
/*              DIO Driver                     */
/***********************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

													        	 /*  Available PORTS  */
														 
/*   
	 DIOA
	 DIOB
	 DIOC
	 DIOD
	 
*/

													        	 /*  Available PINS  */
														 
/*  
	 PIN0
	 PIN1
	 PIN2
	 PIN3
	 PIN4
	 PIN5
	 PIN6
	 PIN7
	 
*/

														        /*  Available MODES  */
														 
/*   
	 OUTPUT
	 INPUT
	 
*/
 
													    	 /*  Available OUTPUT Values  */
														 
/*   
	 HIGH
	 LOW
	 
*/

																/* Private MACROS */
		
#define INPUT     0
#define OUTPUT    1

#define HIGH      1
#define LOW       0

#define DIOA      0
#define DIOB      1
#define DIOC      2
#define DIOD      3

#define PIN0      0
#define PIN1      1
#define PIN2      2
#define PIN3      3
#define PIN4      4
#define PIN5      5
#define PIN6      6
#define PIN7      7

													        	 /* Available Functions */

		
// Set Port to be output
void MDIO_voidSetPort(u8 Copy_u8Port);

// Set Port to be Input
void MDIO_voidResetPort(u8 Copy_u8Port);

// Set Port to High (only when OUTPUT)
void MDIO_voidPortOn(u8 Copy_u8Port);

// Set Port to LOW (only when OUTPUT)
void MDIO_voidPortOff(u8 Copy_u8Port);

// Set particular pin to be input or output
void MDIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

// Set Particular pin to be High or Low (Only if the pin is output)
void MDIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

// Toggle Pin
void MDIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);

// Read pin value (Only if the pin is input)
u8 MDIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

// Read All port
u32 MDIO_u32GetPortValue(u8 Copy_u8Port);

// Write on the whole PORT
void MDIO_voidWritePort(u8 Copy_u8Port, u8 Copy_u8Data);




#endif
