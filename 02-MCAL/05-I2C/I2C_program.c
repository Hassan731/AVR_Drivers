/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 22 APR 2022                    */
/*              NTI Diploma                    */
/*              I2C Driver                     */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <math.h>

#include "I2C_register.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"




void MI2C_voidInit(void){

	/* set prescaler bits to zero */
	CLR_BIT(TWSR, TWPS0);			// Set TWPS0 bit in TWSR register to 0
	CLR_BIT(TWSR, TWPS1);			// Set TWPS1 bit in TWSR register to 0
	
	/* SCL Frequancy is 50K for XTAL = 8MHz */
	TWBR Value = ((SYSTEM_CLOCK/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))));
	
	/* 	Enable Global Interrupt in SREG Register		*/		
	SET_BIT(SREG, 7);						// Set interrupt bit in SREG to 1
	
	/* Enable Interrupt Request */
	SET_BIT(TWCR, TWIE);					// Set TWIE bit in TWCR register to 1	
	
	/* Enable TWI module */
	SET_BIT(TWCR, TWEN);  

}

void MI2C_voidStart(void){

	
	/* Satrt I2C */
	SET_BIT(TWCR, TWSTA);					// Set TWSTA bit in TWCR register to 1

	/* Clear TWINT bit by writing 1 to it */
	SET_BIT(TWCR, TWINT);					// Set TWINT bit in TWCR register to 1
	
	/* Wait untill making sure the TWINT bit is cleared */
	while (!(GET_BIT(TWCR, TWINT)));

}

void MI2C_voidWrite(u8 data){
	
	/* Write data to Data register */
	TWDR = data;
	
	/* Enable TWI module */
	SET_BIT(TWCR, TWEN); 
	
	/* Clear TWINT bit by writing 1 to it */
	SET_BIT(TWCR, TWINT);					// Set TWINT bit in TWCR register to 1
	
	/* Wait untill making sure the TWINT bit is cleared */
	while (!(GET_BIT(TWCR, TWINT)));

}

u8 MI2C_u8Read(u8 ackVal){

	if (ackVal == 1)
	{
		/* Enable Acknowledge Bit */
		SET_BIT(TWCR, TWEA);					// Set TWEA bit in TWCR register to 1
	}
	
	/* Enable TWI module */
	SET_BIT(TWCR, TWEN); 
	
	/* Clear TWINT bit by writing 1 to it */
	SET_BIT(TWCR, TWINT);					// Set TWINT bit in TWCR register to 1
	
	/* Wait untill making sure the TWINT bit is cleared */
	while (!(GET_BIT(TWCR, TWINT)));
	
	/* return data */
	return TWDR;

}

void MI2C_voidStop(void){

	/* Satrt I2C */
	SET_BIT(TWCR, TWSTO);					// Set TWSTO bit in TWCR register to 1

	/* Clear TWINT bit by writing 1 to it */
	SET_BIT(TWCR, TWINT);					// Set TWINT bit in TWCR register to 1
	
	for (int k = 0; k < 100; k++ ){                   // wait for a short time
		
		asm("NOP");
	
	}
}