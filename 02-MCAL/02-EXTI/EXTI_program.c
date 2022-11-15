/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 15 SEP 2021                    */
/*              NTI Diploma                    */
/*              Interrupt Driver               */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"


																	/* Interrupt 0 Initialization */
																	
void MEXTI_INT0_Init()
{
	// Global Interrupt Enable
	SET_BIT(SREG, 7);
	
	// External Interrupt Request 0 Enable
	SET_BIT(GICR, INT0);
	
	// Select INT0 Triggering
	
	#if 	INT0_TRIG == FALLING_EDGE
	// Configure the interrupt to work when the falling edge occurs
	CLR_BIT(MCUCR, ISC00);				// Set the ISC00 bit in the MCUCR register to 0
	SET_BIT(MCUCR, ISC01);              // Set the ISC01 bit in the MCUCR register to 1
	
	#elif	INT0_TRIG == RISING_EDGE
	// Configure the interrupt to work when the rising edge occurs
	SET_BIT(MCUCR, ISC00);				// Set the ISC00 bit in the MCUCR register to 1
	SET_BIT(MCUCR, ISC01);				// Set the ISC01 bit in the MCUCR register to 1
	
	#elif	INT0_TRIG == LOW_LEV
	// Configure the interrupt to work when the rising edge occurs
	CLR_BIT(MCUCR, ISC00);				// Set the ISC00 bit in the MCUCR register to 0
	CLR_BIT(MCUCR, ISC01);				// Set the ISC01 bit in the MCUCR register to 0
	
	#elif	INT0_TRIG == LOGIC_CHANGE
	// Configure the interrupt to work when the rising edge occurs
	SET_BIT(MCUCR, ISC00);				// Set the ISC00 bit in the MCUCR register to 1
	CLR_BIT(MCUCR, ISC01);				// Set the ISC01 bit in the MCUCR register to 0
	
	#endif
}

																	/* Interrupt 1 Initialization */

void MEXTI_INT1_Init()
{
	// Global Interrupt Enable
	SET_BIT(SREG, 7);

	// External Interrupt Request 1 Enable
	SET_BIT(GICR, INT1);

	#if 	INT1_TRIG == FALLING_EDGE
	// Configure the interrupt to work when the falling edge occurs
	CLR_BIT(MCUCR, ISC10);				// Set the ISC10 bit in the MCUCR register to 0
	SET_BIT(MCUCR, ISC11);              // Set the ISC11 bit in the MCUCR register to 1
	
	#elif	INT1_TRIG == RISING_EDGE
	// Configure the interrupt to work when the rising edge occurs
	SET_BIT(MCUCR, ISC10);				// Set the ISC10 bit in the MCUCR register to 1
	SET_BIT(MCUCR, ISC11);				// Set the ISC11 bit in the MCUCR register to 1
	
	#elif	INT1_TRIG == LOW_LEV
	// Configure the interrupt to work when the rising edge occurs
	CLR_BIT(MCUCR, ISC10);				// Set the ISC10 bit in the MCUCR register to 0
	CLR_BIT(MCUCR, ISC11);				// Set the ISC11 bit in the MCUCR register to 0
	
	#elif	INT1_TRIG == LOGIC_CHANGE
	// Configure the interrupt to work when the rising edge occurs
	SET_BIT(MCUCR, ISC10);				// Set the ISC10 bit in the MCUCR register to 1
	CLR_BIT(MCUCR, ISC11);				// Set the ISC11 bit in the MCUCR register to 0
	
	#endif
}

																	/* Interrupt 2 Initialization */
																	
void MEXTI_INT2_Init()
{
	// Global Interrupt Enable
	SET_BIT(SREG, 7);

	// External Interrupt Request 2 Enable
	SET_BIT(GICR, INT2);

	#if 	INT2_TRIG == FALLING_EDGE
	// Configure the interrupt to work when the falling edge occurs
	CLR_BIT(MCUCSR, ISC2);
	
	#elif	INT2_TRIG == RISING_EDGE
	// Configure the interrupt to work when the rising edge occurs
	SET_BIT(MCUCSR, ISC2);
	
	#endif
}
