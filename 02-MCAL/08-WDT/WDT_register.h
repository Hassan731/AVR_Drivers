/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 30 SEP 2021                    */
/*              NTI Diploma                    */
/*              WDT Driver                     */
/***********************************************/


#ifndef WDT_REGISTER_H
#define WDT_REGISTER_H


#define			MCUCSR				*((volatile u8*)0x54)				// MCU Control and Status Register

#define			WDTCR				*((volatile u8*)0x41)				// Watchdog Timer Control Register



#endif