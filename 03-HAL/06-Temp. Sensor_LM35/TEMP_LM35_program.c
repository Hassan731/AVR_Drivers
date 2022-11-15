/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 17 SEP 2021                    */
/*              NTI Diploma                    */
/*              Temp. Sensor                   */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"

#include "TEMP_LM35_private.h"
#include "TEMP_LM35_config.h"
#include "TEMP_LM35_interface.h"


																			/* LM35 Initialization */
																			
void HTEMP_voidInit()
{
	MADC_voidInit();
}

																				/* LM35 Read */
																				
u8 HTEMP_u8Read()
{
	// Declaring Variables
	u16 value;		// Declaring a variable to hold Value from ADC
	u8 temp;		// Declaring a variable to hold Temperatur evalue
	
	// Read ADC 
	value = MADC_u16Read(TEMP_SEN_CH);
	
	// Calcultae Temperatur
	temp = value * (500.0 / 1023.0);
	
	return temp;
	
}