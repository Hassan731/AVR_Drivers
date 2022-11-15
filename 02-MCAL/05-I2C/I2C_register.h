/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 22 APR 2022                    */
/*              NTI Diploma                    */
/*              I2C Driver                     */
/***********************************************/

#ifndef I2C_REGISTER_H
#define I2C_REGISTER_H


/* I2C Registers */

#define 	TWCR				*((volatile u8*)0x36)			// TWI Control Register – TWCR
#define 	TWDR				*((volatile u8*)0x03)			// TWI Data Register – TWDR
#define 	TWAR				*((volatile u8*)0x02)			// TWI (Slave) Address Register – TWAR
#define 	TWSR				*((volatile u8*)0x01)			// TWI Status Register – TWSR
#define 	TWBR				*((volatile u8*)0x00)			// TWI Bit Rate Register - TWBR


/* Status Register */
#define		SREG			*((volatile u8*)0x5F)					// Status Register

#endif