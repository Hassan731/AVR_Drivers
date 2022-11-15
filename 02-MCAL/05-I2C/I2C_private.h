/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 22 APR 2022                    */
/*              NTI Diploma                    */
/*              I2C Driver                     */
/***********************************************/



#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H


/* TWI Control Register Bits – TWCR					*/

#define 	TWIE			0               // TWI Interrupt Enable
#define 	TWEN            2               // TWI Enable Bit
#define		TWWC            3               // TWI Write Collision Flag
#define		TWSTO           4               // TWI STOP Condition Bit
#define		TWSTA           5               // TWI START Condition Bit
#define		TWEA            6               // TWI Enable Acknowledge Bit
#define		TWINT	        7				// TWI Interrupt Flag



/* TWI Status Register Bits – TWSR                   */

#define 	TWPS0			0               // TWI Prescaler Bit 0
#define 	TWPS1           1               // TWI Prescaler Bit 1
#define		TWS3            3               // TWI Status Bit 3
#define		TWS4            4               // TWI Status Bit 4
#define		TWS5            5               // TWI Status Bit 5
#define		TWS6            6               // TWI Status Bit 6
#define		TWS7	        7				// TWI Status Bit 7





#endif