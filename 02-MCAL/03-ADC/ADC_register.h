/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 16 SEP 2021                    */
/*              NTI Diploma                    */
/*              ADC Driver                     */
/***********************************************/

#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

#define		ADMUX			*((volatile u8*)0x27)

#define		ADCSRA			*((volatile u8*)0x26)

#define		ADCL			*((volatile u8*)0x24)

#define		ADCH			*((volatile u8*)0x25)

#define		SFIOR			*((volatile u8*)0x50)


// To access the ADCL and ADCH in one step for Right Adjust
#define		ADC_DATA		*((volatile u16*)0x24)

#endif