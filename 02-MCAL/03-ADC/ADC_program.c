/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 16 SEP 2021                    */
/*              NTI Diploma                    */
/*              ADC Driver                     */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"


																				/* ADC Initialization */
																				
void MADC_voidInit()
{
	// Choosing Reference Voltage
	#if		V_REF == AREF
		CLR_BIT(ADMUX, REFS0);   // Make the REFS0 bit in the ADMUX equal 0
		CLR_BIT(ADMUX, REFS1);	 // Make the REFS1 bit in the ADMUX equal 0
										 
	#elif	V_REF == AVCC                
		SET_BIT(ADMUX, REFS0);   // Make REFS0 bit in the ADMUX equal 1
		CLR_BIT(ADMUX, REFS1);	 // Make REFS1 bit in the ADMUX equal 0
								
	#elif	V_REF == INT_2.56v          
		SET_BIT(ADMUX, REFS0);   // Make REFS0 bit in the ADMUX equal 1
		SET_BIT(ADMUX, REFS1);	 // Make REFS1 bit in the ADMUX equal 1
		
	#endif
	
	
	// Choosing Result Adjustment
	#if		DATA_ADJUST == RIGHT
		CLR_BIT(ADMUX, ADLAR);   // Make ADLAR bit in the ADMUX equal 0
								
	#elif	DATA_ADJUST == LEFT          
		SET_BIT(ADMUX, ADLAR);   // Make ADLAR bit in the ADMUX equal 1
		
	#endif
	
	
	// Choosing Auto Trigger Mode
	#if		AUTO_TRIG_EN == ON
		SET_BIT(ADCSRA, ADATE);   // Make ADATE bit the ADCSRA equal 1
								
	#elif 	AUTO_TRIG_EN == OFF   
		CLR_BIT(ADCSRA, ADATE);   // Make ADATE bit the ADCSRA equal 0
		
	#endif
	
	
	// Choosing Prescaler
	#if		PRESCALER == 2
		SET_BIT(ADCSRA, ADPS0);   // Make ADPS0 bit the ADCSRA equal 1
		CLR_BIT(ADCSRA, ADPS1);   // Make ADPS1 bit the ADCSRA equal 0
		CLR_BIT(ADCSRA, ADPS2);   // Make ADPS2 bit the ADCSRA equal 0
		
	#elif	PRESCALER == 4
		CLR_BIT(ADCSRA, ADPS0);   // Make ADPS0 bit the ADCSRA equal 0
		SET_BIT(ADCSRA, ADPS1);   // Make ADPS1 bit the ADCSRA equal 1
		CLR_BIT(ADCSRA, ADPS2);   // Make ADPS2 bit the ADCSRA equal 0
		
	#elif	PRESCALER == 8
		SET_BIT(ADCSRA, ADPS0);   // Make ADPS0 bit the ADCSRA equal 1
		SET_BIT(ADCSRA, ADPS1);   // Make ADPS1 bit the ADCSRA equal 1
		CLR_BIT(ADCSRA, ADPS2);   // Make ADPS2 bit the ADCSRA equal 0
		
	#elif	PRESCALER == 16
		CLR_BIT(ADCSRA, ADPS0);   // Make ADPS0 bit the ADCSRA equal 0
		CLR_BIT(ADCSRA, ADPS1);   // Make ADPS1 bit the ADCSRA equal 0
		SET_BIT(ADCSRA, ADPS2);   // Make ADPS2 bit the ADCSRA equal 1
		
	#elif	PRESCALER == 32
		SET_BIT(ADCSRA, ADPS0);   // Make ADPS0 bit the ADCSRA equal 1
		CLR_BIT(ADCSRA, ADPS1);   // Make ADPS1 bit the ADCSRA equal 0
		SET_BIT(ADCSRA, ADPS2);   // Make ADPS2 bit the ADCSRA equal 1
		
	#elif	PRESCALER == 64
		CLR_BIT(ADCSRA, ADPS0);   // Make ADPS0 bit the ADCSRA equal 0
		SET_BIT(ADCSRA, ADPS1);   // Make ADPS1 bit the ADCSRA equal 1
		SET_BIT(ADCSRA, ADPS2);   // Make ADPS2 bit the ADCSRA equal 1
		
	#elif	PRESCALER == 128
		SET_BIT(ADCSRA, ADPS0);   // Make ADPS0 bit the ADCSRA equal 1
		SET_BIT(ADCSRA, ADPS1);   // Make ADPS1 bit the ADCSRA equal 1
		SET_BIT(ADCSRA, ADPS2);   // Make ADPS2 bit the ADCSRA equal 1
	
	#endif
	
	
	
	// ADC Enable
	SET_BIT(ADCSRA, ADEN);   // Make ADEN bit the ADCSRA equal 1
	
	
}

																				/* Read value from ADC */
u16 MADC_u16Read(u8 Copy_u8Channel)
{
	// Declaring a variable of type u16 to hold converted data
	u16 Hold_Data;
	
	// Selecting channel
	switch(Copy_u8Channel)
	{
		// Channel 0 Selected
		case 0:	
			CLR_BIT(ADMUX, MUX0);   // Make MUX0 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX1);   // Make MUX1 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX2);   // Make MUX2 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX3);   // Make MUX3 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX4);   // Make MUX4 bit the ADMUX equal 0
			break;
			
		// Channel 1 Selected
		case 1:	
			SET_BIT(ADMUX, MUX0);   // Make MUX0 bit the ADMUX equal 1
			CLR_BIT(ADMUX, MUX1);   // Make MUX1 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX2);   // Make MUX2 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX3);   // Make MUX3 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX4);   // Make MUX4 bit the ADMUX equal 0
			break;
			
		// Channel 2 Selected
		case 2:	
			CLR_BIT(ADMUX, MUX0);   // Make MUX0 bit the ADMUX equal 0
			SET_BIT(ADMUX, MUX1);   // Make MUX1 bit the ADMUX equal 1
			CLR_BIT(ADMUX, MUX2);   // Make MUX2 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX3);   // Make MUX3 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX4);   // Make MUX4 bit the ADMUX equal 0
			break;
			
		// Channel 3 Selected
		case 3:	
			SET_BIT(ADMUX, MUX0);   // Make MUX0 bit the ADMUX equal 1
			SET_BIT(ADMUX, MUX1);   // Make MUX1 bit the ADMUX equal 1
			CLR_BIT(ADMUX, MUX2);   // Make MUX2 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX3);   // Make MUX3 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX4);   // Make MUX4 bit the ADMUX equal 0
			break;
			
		// Channel 4 Selected
		case 4:	
			CLR_BIT(ADMUX, MUX0);   // Make MUX0 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX1);   // Make MUX1 bit the ADMUX equal 0
			SET_BIT(ADMUX, MUX2);   // Make MUX2 bit the ADMUX equal 1
			CLR_BIT(ADMUX, MUX3);   // Make MUX3 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX4);   // Make MUX4 bit the ADMUX equal 0
			break;
			
		// Channel 5 Selected
		case 5:	
			SET_BIT(ADMUX, MUX0);   // Make MUX0 bit the ADMUX equal 1
			CLR_BIT(ADMUX, MUX1);   // Make MUX1 bit the ADMUX equal 0
			SET_BIT(ADMUX, MUX2);   // Make MUX2 bit the ADMUX equal 1
			CLR_BIT(ADMUX, MUX3);   // Make MUX3 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX4);   // Make MUX4 bit the ADMUX equal 0
			break;
			
		// Channel 6 Selected
		case 6:	
			CLR_BIT(ADMUX, MUX0);   // Make MUX0 bit the ADMUX equal 0
			SET_BIT(ADMUX, MUX1);   // Make MUX1 bit the ADMUX equal 1
			SET_BIT(ADMUX, MUX2);   // Make MUX2 bit the ADMUX equal 1
			CLR_BIT(ADMUX, MUX3);   // Make MUX3 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX4);   // Make MUX4 bit the ADMUX equal 0
			break;
			
		// Channel 7 Selected
		case 7:	
			SET_BIT(ADMUX, MUX0);   // Make MUX0 bit the ADMUX equal 1
			SET_BIT(ADMUX, MUX1);   // Make MUX1 bit the ADMUX equal 1
			SET_BIT(ADMUX, MUX2);   // Make MUX2 bit the ADMUX equal 1
			CLR_BIT(ADMUX, MUX3);   // Make MUX3 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX4);   // Make MUX4 bit the ADMUX equal 0
			break;
			
			// Make default as channel 0 selected
		default:
			CLR_BIT(ADMUX, MUX0);   // Make MUX0 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX1);   // Make MUX1 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX2);   // Make MUX2 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX3);   // Make MUX3 bit the ADMUX equal 0
			CLR_BIT(ADMUX, MUX4);   // Make MUX4 bit the ADMUX equal 0
			break;
		
		
	}

	
	// Start Conversion
	SET_BIT(ADCSRA, ADSC);   // Make ADSC bit the ADCSRA equal 1
	
	// wait for conversion completion and interrupt flag to be 1
	while(GET_BIT(ADCSRA, ADIF) == 0)
	{
		
	}
	
	// Checking Result Adjustment
	#if		DATA_ADJUST == RIGHT
		Hold_Data = ADC_DATA;																	// Store the ADCL and the first 2 bits of ADCH
								
	#elif	DATA_ADJUST == LEFT          
		Hold_Data = (((ADCL & 0xC0) >> 6) | 0b0000000000) | ((ADCH  | 0b0000000000) << 2);		// Store the last 2 bits of ADCL and ADCH
		
	#endif 
	
	
	
	// Return Result
	return Hold_Data;
}
















