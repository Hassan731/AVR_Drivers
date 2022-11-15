/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 30 SEP 2021                    */
/*              NTI Diploma                    */
/*              DC MOTOR DRIVER                */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DC_MOTOR_private.h"
#include "DC_MOTOR_config.h"
#include "DC_MOTOR_interface.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"



// Initialize MOTOR
void HDCMOTOR_voidInit(void)
{
	// PWM Initialize
	
}

// Set Direction
void HDCMOTOR_voidSetDirection(u8 Copy_u8Direction)
{
	// Reverse the two pins
	
}

// Set Speed
void HDCMOTOR_voidSetSpeed(u16 Copy_u16Speed)
{
	// PWM Set Duty Cycle
	
	#if		TIMER_USED	== TIM0
		MTIM0_SetDutyCycle(Copy_u16Speed/rated_rpm);
		
	#elif 	TIMER_USED	== TIM1
		MTIM1_SetDutyCycle(Copy_u16Speed/rated_rpm);
	
	#elif 	TIMER_USED	== TIM2
		MTIM2_SetDutyCycle(Copy_u16Speed/rated_rpm);
		
	#endif
	
}

// Start
void HDCMOTOR_voidStart(void)
{
	// PWM Start
	
}

// Stop
void HDCMOTOR_voidStop(void)
{
	// PWM Stop
	
}

// Motor Lock
void HDCMOTOR_voidLock(void)
{
	// Set both pins to hgih
	
}



