/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 16 SEP 2021                    */
/*              NTI Diploma                    */
/*              ADC Driver                     */
/***********************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

																			/* Available Functions */
																				
// ADC Initialization
void MADC_voidInit();

// Read value from ADC
u16 MADC_u16Read(u8 Copy_u8Channel);


																			/* Available Channels */
		
#define 	ch0 			0
#define 	ch1 			1
#define 	ch2 			2
#define 	ch3 			3
#define 	ch4 			4
#define 	ch5				5
#define 	ch6				6
#define 	ch7				7


#endif