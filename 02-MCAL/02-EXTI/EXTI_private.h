/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 15 SEP 2021                    */
/*              NTI Diploma                    */
/*              Interrupt Driver               */
/***********************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


/* Private MACROS */
#define		FALLING_EDGE			0
#define		RISING_EDGE				1
#define		LOW_LEV					2
#define		LOGIC_CHANGE			3


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ---------------------------------------------------------------------  Registers Bits ---------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */

/* MCU Control Register – MCUCR */

#define 	ISC00				0				// Interrupt Sense Control 0 Bit 0 
#define		ISC01				1				// Interrupt Sense Control 0 Bit 1
#define 	ISC10				2               // Interrupt Sense Control 1 Bit 0
#define		ISC11				3               // Interrupt Sense Control 1 Bit 1



/* MCU Control and Status Register – MCUCSR */

#define 	ISC2				6				// Interrupt Sense Control 2



/* General Interrupt Control Register – GICR */

#define 	INT2				5				// External Interrupt Request 2 Enable
#define		INT0				6				// External Interrupt Request 0 Enable
#define 	INT1				7               // External Interrupt Request 1 Enable


/* General Interrupt Flag Register – GIFR */

#define 	INTF2				5				// External Interrupt Request 2 Enable
#define		INTF0				6				// External Interrupt Request 0 Enable
#define 	INTF1				7               // External Interrupt Request 1 Enable
		



#endif