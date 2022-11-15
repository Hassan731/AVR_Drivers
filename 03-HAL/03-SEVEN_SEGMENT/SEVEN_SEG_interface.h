/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 13 SEP 2021                    */
/*              NTI Diploma                    */
/*              7-SEGMENT Driver               */
/***********************************************/

#ifndef   SEVEN_SEG_INTERFACE_H
#define  SEVEN_SEG_INTERFACE_H

// Initializing Seven Segment
void HSEVENSEG_voidInit(void);

// Add Seven Segment enable pin
void HSEVENSEG_voidAddSeg(u8 Copy_u8Port, u8 Copy_u8Pin);

// Send Number to be displayed
void HSEVENSEG_voidDispaly(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Numbre);

// Disable Segment
void HSEVENSEG_voidDisable(u8 Copy_u8Port, u8 Copy_u8Pin);

// Convert number to binary for seven segment
u8 GetBinaryNumber(u8 x);

// Count down function
void HSEVENSEG_voidCOUNTDWN(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Numbre);

// Count down function
void HSEVENSEG_voidCOUNTUP(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Numbre);


#endif
