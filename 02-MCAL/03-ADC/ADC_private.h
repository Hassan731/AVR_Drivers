/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 16 SEP 2021                    */
/*              NTI Diploma                    */
/*              ADC Driver                     */
/***********************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

																	/* Some Private MACROS */

/* ADC Reference Voltage */						
#define			AREF			0				// Reference Voltage for The ADC will be taken from AREF Pin
#define 		AVCC			1				// Reference Voltage for The ADC will be taken from AVCC Pin
#define 	   INT_2V			2				// Reference Voltage for The ADC will be taken internally as 2.56V


/* Result Adjustment */
#define 		RIGHT			0				// Right Adjustment
#define			LEFT			1				// Left Adjustment

/* ON-OFF MACROS */
#define 		ON				1
#define			OFF				0


																	/* Bits MACROS for each Register in ADC */
																	
/* ADC Multiplexer Selection Register â€“ ADMUX */
#define		MUX0				0				// Channel and Gain Selection bit0
#define		MUX1				1				// Channel and Gain Selection bit1
#define		MUX2				2				// Channel and Gain Selection bit2
#define		MUX3				3				// Channel and Gain Selection bit3
#define		MUX4				4				// Channel and Gain Selection bit4
#define		ADLAR				5				// ADC Left Adjust Result bit
#define		REFS0				6				// Reference voltage select bit0
#define		REFS1				7				// Reference voltage select bit1


/* ADC Control and Status Register A â€“ ADCSRA */
#define		ADPS0				0				// ADC Prescaler Select bit0
#define		ADPS1				1				// ADC Prescaler Select bit1
#define		ADPS2				2				// ADC Prescaler Select bit2
#define		ADIE				3				// ADC Interrupt Enable
#define		ADIF				4				// ADC Interrupt Flag
#define		ADATE				5				// ADC Auto Trigger Enable
#define		ADSC				6				// ADC Start Conversion
#define		ADEN				7				// ADC Enable


/* Special FunctionIO Register â€“ SFIOR */
#define		ADTS0				5				// ADC Auto Trigger Source bit0
#define		ADTS1				6				// ADC Auto Trigger Source bit1
#define		ADTS2				7				// ADC Auto Trigger Source bit2



#endif
