/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 27 SEP 2021                    */
/*              NTI Diploma                    */
/*              SPI Driver                     */
/***********************************************/

#ifndef SPI_INTERFACE_H
#define	SPI_INTERFACE_H

/* Initializing SPI */
void MSPI_voidInit(void);


/* Transmit and Recieve Data */
void MSPI_voidTransiever(u8 Copy_u8TransmittedData, u8 *Copy_RecievedData);


/* Slave Select */
void MSPI_voidSlaveSelect(u8 Copy_u8SlavePin);

#endif