/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 7 SEP 2021                     */
/*              NTI Diploma                    */
/*              DIO Driver                     */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"


                                                                       /* Set Port to be output */
																	   
void MDIO_voidSetPort(u8 Copy_u8Port)
{
	
	switch(Copy_u8Port)
	{
		case DIOA:
			DDRA = 0xff;
			break;
		case DIOB:
			DDRB = 0xff;
			break;
		case DIOC:
			DDRC = 0xff;
			break;
		case DIOD:
			DDRD = 0xff;
			break;
		default:
			break;
	}
	
	
}

                                                                       /* Set Port to be Input */
																	   
void MDIO_voidResetPort(u8 Copy_u8Port)
{
	
	switch(Copy_u8Port)
	{
		case DIOA:
			DDRA = 0x00;
			break;
		case DIOB:
			DDRB = 0x00;
			break;
		case DIOC:
			DDRC = 0x00;
			break;
		case DIOD:
			DDRD = 0x00;
			break;
		default:
			break;
	}
	
}

																  /* Set Port to High (only when OUTPUT) */
																  
void MDIO_voidPortOn(u8 Copy_u8Port)
{
	switch(Copy_u8Port)
	{
		case DIOA:
			PORTA = 0xff;
			break;
		case DIOB:
			PORTB = 0xff;
			break;
		case DIOC:
			PORTC = 0xff;
			break;
		case DIOD:
			PORTD = 0xff;
			break;
		default:
			break;
	}
}

																  /* Set Port to LOW (only when OUTPUT) */
																  
void MDIO_voidPortOff(u8 Copy_u8Port)
{
	switch(Copy_u8Port)
	{
		case DIOA:
			PORTA = 0x00;
			break;
		case DIOB:
			PORTB = 0x00;
			break;
		case DIOC:
			PORTC = 0x00;
			break;
		case DIOD:
			PORTD = 0x00;
			break;
		default:
			break;
	}
}

                                                              /*  Set particular pin to be input or output */
															  
void MDIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	
	switch(Copy_u8Port)
	{
		case DIOA:
			if(Copy_u8Mode == OUTPUT)
			{
				SET_BIT(DDRA,Copy_u8Pin);
				break;
			}
			else if(Copy_u8Mode == INPUT)
			{
				CLR_BIT(DDRA,Copy_u8Pin);
				break;
			}
			else
			{
				break;
			}
			
		case DIOB:
			if(Copy_u8Mode == OUTPUT)
			{
				SET_BIT(DDRB,Copy_u8Pin);
				break;
			}
			else if(Copy_u8Mode == INPUT)
			{
				CLR_BIT(DDRB,Copy_u8Pin);
				break;
			}
			else
			{
				break;
			}
		
		case DIOC:
			if(Copy_u8Mode == OUTPUT)
			{
				SET_BIT(DDRC,Copy_u8Pin);
				break;
			}
			else if(Copy_u8Mode == INPUT)
			{
				CLR_BIT(DDRC,Copy_u8Pin);
				break;
			}
			else
			{
				break;
			}
		case DIOD:
			if(Copy_u8Mode == OUTPUT)
			{
				SET_BIT(DDRD,Copy_u8Pin);
				break;
			}
			else if(Copy_u8Mode == INPUT)
			{
				CLR_BIT(DDRD,Copy_u8Pin);
				break;
			}
			else
			{
				break;
			}
			
		default:
			break;
	}
	
	
}

                                                 /*   Set Particular pin to be High or Low (Only if the pin is output)   */
												 
void MDIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case DIOA:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(PORTA,Copy_u8Pin);
				break;
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTA,Copy_u8Pin);
				break;
			}
			else
			{
				break;
			}
			
		case DIOB:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(PORTB,Copy_u8Pin);
				break;
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTB,Copy_u8Pin);
				break;
			}
			else
			{
				break;
			}
		
		case DIOC:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(PORTC,Copy_u8Pin);
				break;
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTC,Copy_u8Pin);
				break;
			}
			else
			{
				break;
			}
			
			case DIOD:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(PORTD,Copy_u8Pin);
				break;
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTD,Copy_u8Pin);
				break;
			}
			else
			{
				break;
			}
			
		default:
			break;
	}
}

																/* Toggle Pin (Only if the pin is output)*/
																
void MDIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	
	switch(Copy_u8Port)
	{
		case DIOA:
			TOG_BIT(PORTA, Copy_u8Pin);
			break;
		case DIOB:
			TOG_BIT(PORTB, Copy_u8Pin);
			break;
		case DIOC:
			TOG_BIT(PORTC, Copy_u8Pin);
			break;
		case DIOD:
			TOG_BIT(PORTD, Copy_u8Pin);
			break;
		default:
			break;
	}
	
}



                                                                /* Read pin value (Only if the pin is input) */
																
u8 MDIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	// Declaring Variable
	u8 u8_LocalVariable;
	
	// Switch for the desired port
	switch(Copy_u8Port)
	{
		case DIOA:
			u8_LocalVariable = GET_BIT(PINA, Copy_u8Pin);
			break;
		case DIOB:
			u8_LocalVariable = GET_BIT(PINB, Copy_u8Pin);
			break;
		case DIOC:
			u8_LocalVariable = GET_BIT(PINC, Copy_u8Pin);
			break;
		case DIOD:
			u8_LocalVariable = GET_BIT(PIND, Copy_u8Pin);
			break;
		default:
			break;
		
	}
	
	return u8_LocalVariable;
}


																		/* Write on the whole PORT */
																		
void MDIO_voidWritePort(u8 Copy_u8Port, u8 Copy_u8Data)
{
	switch(Copy_u8Port)
	{
		case DIOA:
			PORTA = Copy_u8Data;
			break;
		case DIOB:
			PORTB = Copy_u8Data;
			break;
		case DIOC:
			PORTC = Copy_u8Data;
			break;
		case DIOD:
			PORTD = Copy_u8Data;
			break;
		default:
			break;
	}
}

													/* Read All port */
u32 MDIO_u32GetPortValue(u8 Copy_u8Port)
{
		// Declaring Variable
		u32 u32_LocalVariable;

		// Switch for the desired port
		switch(Copy_u8Port)
		{
			case DIOA:
				u32_LocalVariable = PINA;
				break;
			case DIOB:
				u32_LocalVariable = PINB;
				break;
			case DIOC:
				u32_LocalVariable = PINC;
				break;
			case DIOD:
				u32_LocalVariable = PIND;
				break;
			default:
				break;

		}

		return u32_LocalVariable;

}
