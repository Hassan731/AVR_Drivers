/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 22 APR 2022                    */
/*              NTI Diploma                    */
/*              I2C Driver                     */
/***********************************************/


#ifndef I2C_interface_H
#define I2C_interface_H

/* Initialize I2C Communication */
void MI2C_voidInit(void);

/* Start I2C */
void MI2C_voidStart(void);

/* Write Data */
void MI2C_voidWrite(u8 data)

/* Read Data */
u8 MI2C_u8Read(u8 ackVal);

/* Stop I2C */
void MI2C_voidStop(void);

#endif