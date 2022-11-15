/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 16 SEP 2021                    */
/*              NTI Diploma                    */
/*              ADC Driver                     */
/***********************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*                                                                           Configurations MACROS 																					*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



				/* Select Reference Voltage */
				
				/*
					Reference Voltage for The ADC will be taken from AREF Pin
					Reference Voltage for The ADC will be taken from AVCC Pin
		            Reference Voltage for The ADC will be taken internally as 2.56V
																					*/
				
#define		V_REF			AREF						// Available sources:  AREF          AVCC		INT_2.56v




					/* Result Adjustment */
					/*
						Result Adjustment in the ADC Data Register 
																	*/
		   

#define		DATA_ADJUST				RIGHT				// User Can choose between:   RIGH    LEFT



					/* Auto Trigger Mode */
			
									/* when Auto Triggering of the ADC is enabled, 
										The ADC will start a conversion on a 
										positive edge of the selected trigger signal.
										The trigger source is selected by setting
										the ADC Trigger Select bits, ADTS in SFIOR. */	

#define 	AUTO_TRIG_EN				ON          // To Enable choose "ON" , To Disable choose "OFF"


					/* Prescaler */
					/*
						determine the division factor
						between the XTAL frequency and
						the input clock to the ADC
														*/
													
#define		PRESCALER					64			// User Can choose between: 2, 4, 8, 16, 32, 64, 128


#endif