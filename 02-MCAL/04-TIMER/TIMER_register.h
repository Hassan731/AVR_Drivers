/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 19 SEP 2021                    */
/*              NTI Diploma                    */
/*              TIMER Driver                   */
/***********************************************/


#ifndef TIMER_REGISTER_H
#define TIMER_REGISTER_H


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------   COMMON Registers   ---------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define 	TIMSK				*((volatile u8*)0x59)			  // Timer/Counter Interrupt Mask Register
#define 	TIFR				*((volatile u8*)0x58)			  // Timer/Counter Interrupt Flag Register

#define		SREG				*((volatile u8*)0x5F)			  // Status Register


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------   TIM0 Registers   ---------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define 	TCCR0				*((volatile u8*)0x53)			  // Timer/Counter Control Register
#define 	TCNT0				*((volatile u8*)0x52)			  // Timer/Counter Register
#define 	OCR0				*((volatile u8*)0x5C)			  // Output Compare Register


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------   TIM1 Registers   ---------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define		TCCR1A				 *((volatile u8*)0x4F)				// Timer/Counter1 Control Register A
#define		TCCR1B               *((volatile u8*)0x4E)              // Timer/Counter1 Control Register B
#define		TCNT1H               *((volatile u8*)0x4D)              // Timer/Counter1 High bits
#define		TCNT1L               *((volatile u8*)0x4C)              // Timer/Counter1 Low bits
																	   
#define		TCNT1				 *((volatile u16*)0x4C)             // Timer/Counter1 16-bit Register
																	   
#define		OCR1AH               *((volatile u8*)0x4B)              // Output Compare A High bits
#define		OCR1AL               *((volatile u8*)0x4A)              // Output Compare A Low bits
																	   
#define		OCR1A				 *((volatile u16*)0x4A)             // Output Compare A 16-bit Register
																	   
#define		OCR1BH               *((volatile u8*)0x49)              // Output Compare B High bits
#define		OCR1BL               *((volatile u8*)0x48)              // Output Compare B Low bits
																	   
#define		OCR1B				 *((volatile u16*)0x48)             // Output Compare B 16-bit Register
																	   
#define		ICR1H                *((volatile u8*)0x47)              // Input Capture Register 1 High bits
#define		ICR1L                *((volatile u8*)0x46)              // Input Capture Register 1 Low bits
																	   
#define		ICR1				 *((volatile u16*)0x46)             // Input Capture Register 1 16-bit Register
		

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------   TIM2 Registers   ---------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define		TCCR2				*((volatile u8*)0x45)				// Timer/Counter Control Register
#define		TCNT2				*((volatile u8*)0x44)               // Timer/Counter Register
#define		OCR2				*((volatile u8*)0x43)               // Output Compare Register
#define		ASSR				*((volatile u8*)0x42)				// Asynchronous Status Register
#define 	SFIOR				*((volatile u8*)0x50)				// Special Function IO Register


/* DDRx Registers to use in timers */
#define		DDRB			*((volatile u8*)0x37)
#define		DDRC			*((volatile u8*)0x34)
#define		DDRD			*((volatile u8*)0x31)
#endif