/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 19 SEP 2021                    */
/*              NTI Diploma                    */
/*              TIMER Driver                   */
/***********************************************/


#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

						/*  MODES MACROS */
						
/* Common Modes */
#define			NORMAL								0
#define			CTC									1

/* Tim0 Clock Modes MACROS */
#define 		EXT_FALLING							0
#define 		EXT_RISING							1

/* TIMER 0 MODES */
#define 		FAST_NON_INVERTED					2
#define			FAST_INVERTED						3
#define			PHASE_CORRECT_CNT_DWN				4
#define			PHASE_CORRECT_CNT_UP				5

/* TIMER 1 MODES */
#define			PWM_PHASE_CORRECT_8BIT				2
#define			PWM_PHASE_CORRECT_9BIT				3
#define			PWM_PHASE_CORRECT_10BIT				4
#define			PWM_FAST_8BIT						5
#define			PWM_FAST_9BIT						6
#define			PWM_FAST_10BIT						7
#define			PWM_PH_F_CORRECT_1					8
#define			PWM_PH_F_CORRECT_2					9
#define			PWM_PHASE_CORRECT_1					10
#define			PWM_PHASE_CORRECT_2					11
#define			CTC_1								12
#define			PWM_FAST_1							13
#define			PWM_FAST_2							14

/* TIMER 1 PWM TYPE PRIVATE MACROS */
#define 		INVERTED							0
#define 		NON_INVERTED						1
#define			TOGGLE								3

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------   COMMON Registers Bits   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Timer/Counter Interrupt Mask Register – TIMSK */
#define		TOIE0						0			// Timer/Counter0 Overflow Interrupt Enable bit
#define		OCIE0						1			// Timer/Counter0 Output Compare Match Interrupt Enable bit
#define		TOIE1						2			// Timer/Counter1, Overflow Interrupt Enable
#define		OCIE1B						3           // Timer/Counter1, Output Compare B Match Interrupt Enable
#define		OCIE1A						4           // Timer/Counter1, Output Compare A Match Interrupt Enable
#define		TICIE1						5           // TICIE1: Timer/Counter1, Input Capture Interrupt Enable
#define		TOIE2						6           // Timer/Counter2 Overflow Interrupt Enable
#define		OCIE2						7           // Timer/Counter2 Output Compare Match Interrupt Enable


/* Timer/Counter Interrupt Flag Register – TIFR */
#define		TOV0						0			// Timer/Counter0 Overflow Flag
#define		OCF0						1			// Output Compare Flag 0
#define		TOV1						2			// Timer/Counter1, Overflow Flag
#define		OCF1B						3           // OCF1B: Timer/Counter1, Output Compare B Match Flag
#define		OCF1A						4           // OCF1A: Timer/Counter1, Output Compare A Match Flag
#define		ICF1						5           // Timer/Counter1, Input Capture Flag
#define		TOV2						6           // Timer/Counter2 Overflow Flag
#define		OCF2						7           // Output Compare Flag 2


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------   TIM0 Register Bits   -------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Timer/Counter Control Register – TCCR0 */
#define 	CS00						0			// Clock Select bit 0
#define 	CS01						1			// Clock Select bit 1
#define 	CS02						2			// Clock Select bit 2
#define		WGM01						3			// Waveform Generation Mode bit 1
#define		COM00						4			// Compare Match Output Mode bit 0
#define 	COM01						5			// Compare Match Output Mode bit 1
#define		WGM00						6			// Waveform Generation Mode bit 0
#define		FOC0						7			// Force Output Compare bit



/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------   TIM1 Register Bits   -------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Timer/Counter1 Control Register A - TCCR1A */
#define 	WGM10						0			// Waveform Generation Mode bit0 for timer 1
#define 	WGM11                       1           // Waveform Generation Mode bit1 for timer 1
#define 	FOC1B                       2           // Force Output Compare for Compare unit B
#define 	FOC1A                       3           // Force Output Compare for Compare unit A
#define 	COM1B0                      4           // Compare Output Mode for Compare unit B bit0
#define 	COM1B1                      5           // Compare Output Mode for Compare unit B bit1
#define 	COM1A0                      6           // Compare Output Mode for Compare unit A bit0
#define 	COM1A1                      7           // Compare Output Mode for Compare unit A bit1


/* Timer/Counter1 Control Register B - TCCR1B */
#define		CS10						0			// Clock Select bit 0
#define		CS11                        1           // Clock Select bit 1
#define		CS12                        2           // Clock Select bit 2
#define		WGM12                       3           // Waveform Generation Mode bit2 for timer 1
#define		WGM13                       4           // Waveform Generation Mode bit3 for timer 1
#define		ICES1                       6           // Input Capture Edge Select
#define		ICNC1                       7           // Input Capture Noise Canceler



/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------   TIM2 Register Bits   -------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Timer/Counter Control Register – TCCR2 */
#define		CS20						0			// Clock Select bit 0
#define		CS21						1           // Clock Select bit 1
#define		CS22						2           // Clock Select bit 2
#define		WGM21						3           // Waveform Generation Mode bit 1
#define		COM20						4           // Compare Match Output Mode bit 0
#define		COM21						5           // Compare Match Output Mode bit 1
#define		WGM20						6           // Waveform Generation Mode bit 0
#define		FOC2						7           // Force Output Compare bit


/* Asynchronous Status Register – ASSR */
#define		TCR2UB						0			// Timer/Counter Control Register2 Update Busy
#define		OCR2UB						1           // Output Compare Register2 Update Busy
#define		TCN2UB						2           // Timer/Counter2 Update Busy
#define		AS2							3           // Asynchronous Timer/Counter2


/* Special Function IO Register – SFIOR */
#define		PSR2						1			// Prescaler Reset Timer/Counter2


#endif