/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 15 SEP 2021                    */
/*              NTI Diploma                    */
/*              Interrupt Driver               */
/***********************************************/

#ifndef EXTI_REGISTER_H
#define EXTI_REGISTER_H


#define		SREG			*((volatile u8*)0x5F)					// Status Register

#define		MCUCR			*((volatile u8*)0x55)					// Microcontroller Control Register

#define		MCUCSR			*((volatile u8*)0x54)					// Microcontroller Control and Status Register

#define		GICR			*((volatile u8*)0x5B)					// General Interrupt Control Register

#define		GIFR			*((volatile u8*)0x5A)					// General Interrupt Flag Register



#endif