/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 19 SEP 2021                    */
/*              NTI Diploma                    */
/*              TIMER Driver                   */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/interrupt.h>

#include "TIMER_register.h"
#include "TIMER_private.h" 
#include "TIMER_config.h"
#include "TIMER_interface.h"


/* Declaring a pointer to function For Callback Function */
void (*ISR_CALLBACK) (void);

/* Declaring Global variables */
u8  num_of_OV, rem_ticks;

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------   TIM0 Register Functions   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Timer 0 Initialization */
void MTIM0_init(void)
{
	// Select Timer Mode
	#if 	TIM0_MODE == NORMAL
		CLR_BIT(TCCR0, WGM00);				// Set WGM00 bit in TCCR0 to 0
		CLR_BIT(TCCR0, WGM01);				// Set WGM01 bit in TCCR0 to 0
		
	#elif	TIM0_MODE == CTC
		CLR_BIT(TCCR0, WGM00);				// Set WGM00 bit in TCCR0 to 0
		SET_BIT(TCCR0, WGM01);              // Set WGM01 bit in TCCR0 to 1
		
	#endif
	
	//	Enable Global Interrupt
	SET_BIT(SREG,7);						// Set Global Interrupt Enable bit in SREG Register to 1	
	
	// Enable Timer/Counter0 Overflow Interrupt
	SET_BIT(TIMSK,TOIE0);					// Set TOIE0 bit in TIMSK to 1
}

/* Timer 0 set time to execute ISR */
void MTIM0_SetTaskPeriodic(u32 time_ms, void (*copy_ptr)(void))
{
	// Declaring Variables
	u32 Total_Ticks;
	
	// Declaring a variable to hold Tick Time
	u8 tick_time;
	
	// put the address of the callback function in a Global pinter to function to call it in the ISR
	ISR_CALLBACK = copy_ptr;
	
	// Calculate Tick Time
	tick_time = TIM0_CLK_PRESCALER / ( SYSTEM_CLOCK / 1000000);		// Result will be in micro-second
	
	Total_Ticks = ( time_ms * 1000 ) / tick_time; 					// Total Ticks for timer
	
	#if 	TIM0_MODE == NORMAL
		
		num_of_OV = Total_Ticks / 256;								// number of overflows needed to reach the time desired
		
		rem_ticks = Total_Ticks % 256;								// reminder ticks after overflows needed to reach the time desired
		
		
		if(rem_ticks != 0)
		{
			TCNT0 = 255 - rem_ticks;								// if the remainder of overflows needed isn't zero, put the reminder ticks in counter register to be counted
			num_of_OV++;
		}
		
	#elif 	TIM0_MODE == CTC
		
		OCR0 = OCR_VALUE;											// put the value to be compared with counter
		
		num_of_OV = Total_Ticks / OCR_VALUE;						// number of overflows needed to reach the time desired
		                                        
		rem_ticks = Total_Ticks % OCR_VALUE;         				// reminder ticks after overflows needed to reach the time desired
		
		if(rem_ticks != 0)
		{
			TCNT0 = 255 - rem_ticks;								// if the remainder of overflows needed isn't zero, put the reminder ticks in counter register to be counted
			num_of_OV++;
		}
		
	#endif
	
}

/* Timer 0 start */
void MTIM0_Start(void)
{
	// Select Clock Prescaler
	#if 	TIM0_CLK_PRESCALER == 1
		SET_BIT(TCCR0,CS00);					// Set CS00 bit in TCCR0 to 1
		CLR_BIT(TCCR0,CS01);					// Set CS01 bit in TCCR0 to 0
		CLR_BIT(TCCR0,CS02);					// Set CS02 bit in TCCR0 to 0
	
	#elif 	TIM0_CLK_PRESCALER == 8
		CLR_BIT(TCCR0,CS00);					// Set CS00 bit in TCCR0 to 0
		SET_BIT(TCCR0,CS01);					// Set CS01 bit in TCCR0 to 1
		CLR_BIT(TCCR0,CS02);					// Set CS02 bit in TCCR0 to 0
		
	#elif 	TIM0_CLK_PRESCALER == 64
		SET_BIT(TCCR0,CS00);					// Set CS00 bit in TCCR0 to 1
		SET_BIT(TCCR0,CS01);					// Set CS01 bit in TCCR0 to 1
		CLR_BIT(TCCR0,CS02);					// Set CS02 bit in TCCR0 to 0
	
	#elif 	TIM0_CLK_PRESCALER == 256
		CLR_BIT(TCCR0,CS00);					// Set CS00 bit in TCCR0 to 0
		CLR_BIT(TCCR0,CS01);					// Set CS01 bit in TCCR0 to 0
		SET_BIT(TCCR0,CS02);					// Set CS02 bit in TCCR0 to 1
	
	#elif 	TIM0_CLK_PRESCALER == 1024
		SET_BIT(TCCR0,CS00);					// Set CS00 bit in TCCR0 to 1
		CLR_BIT(TCCR0,CS01);					// Set CS01 bit in TCCR0 to 0
		SET_BIT(TCCR0,CS02);					// Set CS02 bit in TCCR0 to 1
		
	#elif	TIM0_CLK_PRESCALER == EXT_FALLING
		CLR_BIT(TCCR0,CS00);					// Set CS00 bit in TCCR0 to 0
		SET_BIT(TCCR0,CS01);					// Set CS01 bit in TCCR0 to 1
		SET_BIT(TCCR0,CS02);					// Set CS02 bit in TCCR0 to 1
		
	#elif	TIM0_CLK_PRESCALER == EXT_RISING
		SET_BIT(TCCR0,CS00);					// Set CS00 bit in TCCR0 to 1
		SET_BIT(TCCR0,CS01);					// Set CS01 bit in TCCR0 to 1
		SET_BIT(TCCR0,CS02);					// Set CS02 bit in TCCR0 to 1
		
		
	#endif
	
		
}

/* Timer 0 stop */
void MTIM0_Stop(void)
{
	// No Clock Source - Stop Timer 0
	CLR_BIT(TCCR0,CS00);						// Set CS00 bit in TCCR0 to 0
	CLR_BIT(TCCR0,CS01);                        // Set CS01 bit in TCCR0 to 0
	CLR_BIT(TCCR0,CS02);                        // Set CS02 bit in TCCR0 to 0
}


/* Generate Waveform on OC0 with Timer 0 */
void MTIM0_GenerateWavw(void)
{	
	// Set OC0 pin to be output
	SET_BIT(DDRB, 4);							// Set OC0 pin in DDRB to output
	
	// Select toggle mode on CTC
	SET_BIT(TCCR0,COM00);						// Set COM00 bit in TCCR0 to 1
	CLR_BIT(TCCR0,COM01);                       // Set COM01 bit in TCCR0 to 0
	
	// Put value into OCR0 register
	OCR0 = OCR_WAVE;
	
	// Start Timer
	MTIM0_Start();
}


/* PWM Initialization for Timer 0 */
void MTIM0_PWM_Init(void)
{
	// Set PB3 as output to use it as OCR0
	SET_BIT(DDRB, 3);
		
	// Select MODE
	#if		TIM0_PWM_MODE == FAST_NON_INVERTED
	
		// Select Fast PWM MODE
		SET_BIT(TCCR0, WGM00);					// Set WGM00 bit in TCCR0 to 1
		SET_BIT(TCCR0, WGM01);                  // Set WGM01 bit in TCCR0 to 1
		
		// Select non-inverted mode
		CLR_BIT(TCCR0, COM00);					// Set COM00 bit in TCCR0 to 0
		SET_BIT(TCCR0, COM01);                  // Set COM01 bit in TCCR0 to 1
		
	#elif	TIM0_PWM_MODE == FAST_INVERTED
	
		// Select Fast PWM MODE
		SET_BIT(TCCR0, WGM00);					// Set WGM00 bit in TCCR0 to 1
		SET_BIT(TCCR0, WGM01);                  // Set WGM01 bit in TCCR0 to 1
	
		// Select inverted mode
		SET_BIT(TCCR0, COM00);					// Set COM00 bit in TCCR0 to 1
		SET_BIT(TCCR0, COM01);                  // Set COM01 bit in TCCR0 to 1
		
	#elif		TIM0_PWM_MODE == PHASE_CORRECT_NON_INVERTED
		
		// Select Phase Correct PWM MODE
		SET_BIT(TCCR0, WGM00);					// Set WGM00 bit in TCCR0 to 1
		CLR_BIT(TCCR0, WGM01);                  // Set WGM01 bit in TCCR0 to 0
		
		// Select NON-INVERTED MODE 	-->  Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting
		CLR_BIT(TCCR0, COM00);					// Set COM00 bit in TCCR0 to 0
		SET_BIT(TCCR0, COM01);                  // Set COM01 bit in TCCR0 to 1
		
	
	#elif		TIM0_PWM_MODE == PHASE_CORRECT_INVERTED
		
		// Select Phase Correct PWM MODE
		SET_BIT(TCCR0, WGM00);					// Set WGM00 bit in TCCR0 to 1
		CLR_BIT(TCCR0, WGM01);                  // Set WGM01 bit in TCCR0 to 0
		
		// Select INVERTED MODE        -->  Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting
		SET_BIT(TCCR0, COM00);					// Set COM00 bit in TCCR0 to 0
		SET_BIT(TCCR0, COM01);                  // Set COM01 bit in TCCR0 to 1
	
	
	#endif
	
}

/* PWM Start for Timer 0 */
void MTIM0_PWM_Start(void)
{
	MTIM0_Start();				// Start Timer
		
}


/* PWM Stop for Timer 0 */
void MTIM0_PWM_Stop(void)
{
		MTIM0_Stop();			// Stop Timer
}


/* PWM Duty cycle for Timer 0 */
void MTIM0_SetDutyCycle(u8 Copy_u8DutyCycle)
{
	#if 		TIM0_PWM_MODE == FAST_NON_INVERTED
	
		// Set a number in OCR Register														// Duty Cycle = T_ON / T-total = ( OCR / 256 )  *100
		if((Copy_u8DutyCycle <= 100) && (Copy_u8DutyCycle > 0))
		{
			OCR0 = (Copy_u8DutyCycle * 256) / 100 - 1;
		}
		else if(Copy_u8DutyCycle == 0)
		{
			OCR0 = 0;
		}
		
	#elif		TIM0_PWM_MODE == FAST_INVERTED
		
		// Set a number in OCR Register														// Duty Cycle = T_ON / T-total = ( ( 256 - OCR ) / 256 ) * 100
		if((Copy_u8DutyCycle <= 100) && (Copy_u8DutyCycle > 0))
		{
			OCR0 = (( 100 - Copy_u8DutyCycle ) * 256)/ 100 - 1;
		}
		else if(Copy_u8DutyCycle == 0)
		{
			OCR0 = 0xFF;
		}
	
	#elif		TIM0_PWM_MODE == PHASE_CORRECT_NON_INVERTED
		
		// Set a number in OCR Register														// Duty Cycle = T_ON / T-total = ( 2 * OCR / 512 )  *100
		if((Copy_u8DutyCycle <= 100) && (Copy_u8DutyCycle > 0))
		{
			OCR0 = (Copy_u8DutyCycle * 256) / 100 ;
		}
		else if(Copy_u8DutyCycle == 0)													
		{
			OCR0 = 0;
		}
	
	#elif		TIM0_PWM_MODE == PHASE_CORRECT_INVERTED
		
		// Set a number in OCR Register														// Duty Cycle = T_ON / T-total = ( 512 - ( 2 * OCR ) / 512 )  *100
		if((Copy_u8DutyCycle <= 100) && (Copy_u8DutyCycle > 0))
		{
			OCR0 = ( ( 100- Copy_u8DutyCycle ) * 256) / 100 ;
		}
		else if(Copy_u8DutyCycle == 0)													
		{
			OCR0 = 0;
		}
																							

	#endif
	

}
	
																		/* Timer 0 ISR Functions */
																		
// ISR for Normal Mode
ISR(TIMER0_OVF_vect)
{
	// Initialize a counter for overflows 
	static u32 counter;
	counter++;
	
	if(counter == num_of_OV)
	{
		// Call the function to be executed
		ISR_CALLBACK();
	
		counter = 0;
		TCNT0 = 255 - rem_ticks;
	}
	
}

// ISR for CTC Mode
ISR(TIMER0_COMP_vect)
{
	// Initialize a counter for overflows 
	static u32 counter;
	counter++;
	
	if(counter == num_of_OV)
	{
		// Call the function to be executed
		ISR_CALLBACK();
	
		counter = 0;
		TCNT0 = 255 - rem_ticks;
	}
	
}




/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------   TIM1 Register Functions   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/* Timer 1 Initialization */
void MTIM1_init(void)
{
	#if 	TIM1_MODE == NORMAL
		CLR_BIT(TCCR1A, WGM10);		// Set WGM10 bit in TCCR1A register to 0
		CLR_BIT(TCCR1A, WGM11);     // Set WGM11 bit in TCCR1A register to 0
		CLR_BIT(TCCR1B, WGM12);     // Set WGM12 bit in TCCR1B register to 0
		CLR_BIT(TCCR1B, WGM13);     // Set WGM13 bit in TCCR1B register to 0
		
	#elif	TIM1_MODE == CTC
		CLR_BIT(TCCR1A, WGM10);		// Set WGM10 bit in TCCR1A register to 0
		CLR_BIT(TCCR1A, WGM11); 	// Set WGM11 bit in TCCR1A register to 0
		SET_BIT(TCCR1B, WGM12); 	// Set WGM12 bit in TCCR1B register to 1
		CLR_BIT(TCCR1B, WGM13); 	// Set WGM13 bit in TCCR1B register to 0
		
	#endif
}


/* Timer 1 start */
void MTIM1_Start(void)
{
	// Select Clock Prescaler
	#if 	TIM1_CLK_PRESCALER == 1
		SET_BIT(TCCR1B,CS10);					// Set CS10 bit in TCCR1B to 1
		CLR_BIT(TCCR1B,CS11);					// Set CS11 bit in TCCR1B to 0
		CLR_BIT(TCCR1B,CS12);					// Set CS12 bit in TCCR1B to 0

	#elif 	TIM1_CLK_PRESCALER == 8
		CLR_BIT(TCCR1B,CS10);					// Set CS10 bit in TCCR1B to 0
		SET_BIT(TCCR1B,CS11);					// Set CS11 bit in TCCR1B to 1
		CLR_BIT(TCCR1B,CS12);					// Set CS12 bit in TCCR1B to 0

	#elif 	TIM1_CLK_PRESCALER == 64
		SET_BIT(TCCR1B,CS10);					// Set CS10 bit in TCCR1B to 1
		SET_BIT(TCCR1B,CS11);					// Set CS11 bit in TCCR1B to 1
		CLR_BIT(TCCR1B,CS12);					// Set CS12 bit in TCCR1B to 0

	#elif 	TIM1_CLK_PRESCALER == 256
		CLR_BIT(TCCR1B,CS10);					// Set CS10 bit in TCCR1B to 0
		CLR_BIT(TCCR1B,CS11);					// Set CS11 bit in TCCR1B to 0
		SET_BIT(TCCR1B,CS12);					// Set CS12 bit in TCCR1B to 1

	#elif 	TIM1_CLK_PRESCALER == 1024
		SET_BIT(TCCR1B,CS10);					// Set CS10 bit in TCCR1B to 1
		CLR_BIT(TCCR1B,CS11);					// Set CS11 bit in TCCR1B to 0
		SET_BIT(TCCR1B,CS12);					// Set CS12 bit in TCCR1B to 1

	#elif	TIM1_CLK_PRESCALER == EXT_FALLING
		CLR_BIT(TCCR1B,CS10);					// Set CS10 bit in TCCR1B to 0
		SET_BIT(TCCR1B,CS11);					// Set CS11 bit in TCCR1B to 1
		SET_BIT(TCCR1B,CS12);					// Set CS12 bit in TCCR1B to 1

	#elif	TIM1_CLK_PRESCALER == EXT_RISING
		SET_BIT(TCCR1B,CS10);					// Set CS10 bit in TCCR1B to 1
		SET_BIT(TCCR1B,CS11);					// Set CS11 bit in TCCR1B to 1
		SET_BIT(TCCR1B,CS12);					// Set CS12 bit in TCCR1B to 1


	#endif


}

/* Timer 1 stop */
void MTIM1_Stop(void)
{
	// No Clock Source - Stop Timer 1
	CLR_BIT(TCCR1B,CS10);						 // Set CS10 bit in TCCR1B to 0
	CLR_BIT(TCCR1B,CS11);                        // Set CS11 bit in TCCR1B to 0
	CLR_BIT(TCCR1B,CS12);                        // Set CS12 bit in TCCR1B to 0
}

/* PWM Start for Timer 1 */
void MTIM1_PWM_Start(void)
{
	MTIM1_Start();				// Start Timer

}


/* PWM Stop for Timer 1 */
void MTIM1_PWM_Stop(void)
{
		MTIM1_Stop();			// Stop Timer
}

/* PWM Initialization for Timer 1 */
void MTIM1_PWM_Init()
{
	// Set PD4 as output to use it as OCRB
	SET_BIT(DDRD, 4);

	// Set PD5 as output to use it as OC1A
	SET_BIT(DDRD, 5);

	#if	 TIM1_MODE == PWM_FAST_1

		// Select mode NO.14 Fast PWM MODE
		CLR_BIT(TCCR1A, WGM10);		// Set WGM10 bit in TCCR1A register to 0
		SET_BIT(TCCR1A, WGM11); 	// Set WGM11 bit in TCCR1A register to 1
		SET_BIT(TCCR1B, WGM12); 	// Set WGM12 bit in TCCR1B register to 1
		SET_BIT(TCCR1B, WGM13); 	// Set WGM13 bit in TCCR1B register to 1

		// change the top value making it equal to ICR1
		ICR1 = ((SYSTEM_CLOCK / (PWM1_freq * TIM1_CLK_PRESCALER))-1);


	#elif TIM1_MODE == PWM_FAST_8BIT

		// Select mode NO.5 PWM_FAST_8BIT MODE
		SET_BIT(TCCR1A, WGM10);		// Set WGM10 bit in TCCR1A register to 1
		CLR_BIT(TCCR1A, WGM11); 	// Set WGM11 bit in TCCR1A register to 0
		SET_BIT(TCCR1B, WGM12); 	// Set WGM12 bit in TCCR1B register to 1
		CLR_BIT(TCCR1B, WGM13); 	// Set WGM13 bit in TCCR1B register to 0

	#elif TIM1_MODE == PWM_FAST_9BIT

		// Select mode NO.6 PWM_FAST_9BIT MODE
		CLR_BIT(TCCR1A, WGM10);		// Set WGM10 bit in TCCR1A register to 0
		SET_BIT(TCCR1A, WGM11); 	// Set WGM11 bit in TCCR1A register to 1
		SET_BIT(TCCR1B, WGM12); 	// Set WGM12 bit in TCCR1B register to 1
		CLR_BIT(TCCR1B, WGM13); 	// Set WGM13 bit in TCCR1B register to 0

	#elif TIM1_MODE == PWM_FAST_10BIT

		// Select mode NO.7 PWM_FAST_10BIT MODE
		SET_BIT(TCCR1A, WGM10);		// Set WGM10 bit in TCCR1A register to 1
		SET_BIT(TCCR1A, WGM11); 	// Set WGM11 bit in TCCR1A register to 1
		SET_BIT(TCCR1B, WGM12); 	// Set WGM12 bit in TCCR1B register to 1
		CLR_BIT(TCCR1B, WGM13); 	// Set WGM13 bit in TCCR1B register to 0

	#elif TIM1_MODE == PWM_PHASE_CORRECT_8BIT

		// Select mode NO.1 PWM_FAST_8BIT MODE
		SET_BIT(TCCR1A, WGM10);		// Set WGM10 bit in TCCR1A register to 1
		CLR_BIT(TCCR1A, WGM11); 	// Set WGM11 bit in TCCR1A register to 0
		CLR_BIT(TCCR1B, WGM12); 	// Set WGM12 bit in TCCR1B register to 0
		CLR_BIT(TCCR1B, WGM13); 	// Set WGM13 bit in TCCR1B register to 0

	#elif TIM1_MODE == PWM_PHASE_CORRECT_9BIT

		// Select mode NO.2 PWM_FAST_8BIT MODE
		CLR_BIT(TCCR1A, WGM10);		// Set WGM10 bit in TCCR1A register to 0
		SET_BIT(TCCR1A, WGM11); 	// Set WGM11 bit in TCCR1A register to 1
		CLR_BIT(TCCR1B, WGM12); 	// Set WGM12 bit in TCCR1B register to 0
		CLR_BIT(TCCR1B, WGM13); 	// Set WGM13 bit in TCCR1B register to 0

	#elif TIM1_MODE == PWM_PHASE_CORRECT_10BIT

		// Select mode NO.3 PWM_FAST_8BIT MODE
		SET_BIT(TCCR1A, WGM10);		// Set WGM10 bit in TCCR1A register to 1
		SET_BIT(TCCR1A, WGM11); 	// Set WGM11 bit in TCCR1A register to 1
		CLR_BIT(TCCR1B, WGM12); 	// Set WGM12 bit in TCCR1B register to 0
		CLR_BIT(TCCR1B, WGM13); 	// Set WGM13 bit in TCCR1B register to 0


	#endif

			/* ------------------------------------------------------------------ FAST PWM TYPE -------------------------------------------------------------------- */

	/* Select PWM Type for OC1A channel */

	// Select non-inverted mode
	#if 	FAST_PWM_A == NON_INVERTED
	CLR_BIT(TCCR1A, COM1A0);					// Set COM1A0 bit in TCCR1A to 0
	SET_BIT(TCCR1A, COM1A1);                    // Set COM1A1 bit in TCCR1A to 1

	// Select inverted mode
	#elif	FAST_PWM_A == INVERTED
	SET_BIT(TCCR1A, COM1A0);					// Set COM1A0 bit in TCCR1A to 1
	SET_BIT(TCCR1A, COM1A1);                    // Set COM1A1 bit in TCCR1A to 1

	// select Toggle mode
	#elif 	FAST_PWM_A == TOGGLE
	SET_BIT(TCCR1A, COM1A0);					// Set COM1A0 bit in TCCR1A to 1
	CLR_BIT(TCCR1A, COM1A1);                    // Set COM1A1 bit in TCCR1A to 0

	#endif


	/* Select PWM Type for OC1B channel */

	// Select non-inverted mode
	#if 	FAST_PWM_B == NON_INVERTED
	CLR_BIT(TCCR1A, COM1B0);					// Set COM1B0 bit in TCCR1A to 0
	SET_BIT(TCCR1A, COM1B1);                    // Set COM1B1 bit in TCCR1A to 1

	// Select inverted mode
	#elif 	FAST_PWM_B == INVERTED
	SET_BIT(TCCR1A, COM1B0);					// Set COM1B0 bit in TCCR1A to 1
	SET_BIT(TCCR1A, COM1B1);                    // Set COM1B1 bit in TCCR1A to 1

	// Select Toggle mode
	#elif 	FAST_PWM_B == TOGGLE
	SET_BIT(TCCR1A, COM1B0);					// Set COM1B0 bit in TCCR1A to 1
	CLR_BIT(TCCR1A, COM1B1);                    // Set COM1B1 bit in TCCR1A to 0

	#endif


	/* ---------------------------------------------------------------------------- PHASE CORRECT PWM TYPE ----------------------------------------------------------------------- */

	/* Select PWM Type for OC1A channel */

	// Select non-inverted mode
	#if 	PHASE_CORRECT_PWM_A == PHASE_CORRECT_CNT_DWN
	CLR_BIT(TCCR1A, COM1A0);					// Set COM1A0 bit in TCCR1A to 0
	SET_BIT(TCCR1A, COM1A1);                    // Set COM1A1 bit in TCCR1A to 1

	// Select inverted mode
	#elif	PHASE_CORRECT_PWM_A == PHASE_CORRECT_CNT_UP
	SET_BIT(TCCR1A, COM1A0);					// Set COM1A0 bit in TCCR1A to 1
	SET_BIT(TCCR1A, COM1A1);                    // Set COM1A1 bit in TCCR1A to 1

	// select Toggle mode
	#elif 	PHASE_CORRECT_PWM_A == TOGGLE
	SET_BIT(TCCR1A, COM1A0);					// Set COM1A0 bit in TCCR1A to 1
	CLR_BIT(TCCR1A, COM1A1);                    // Set COM1A1 bit in TCCR1A to 0

	#endif


	/* Select PWM Type for OC1B channel */

	// Select non-inverted mode
	#if 	PHASE_CORRECT_PWM_B == PHASE_CORRECT_CNT_DWN
	CLR_BIT(TCCR1A, COM1B0);					// Set COM1B0 bit in TCCR1A to 0
	SET_BIT(TCCR1A, COM1B1);                    // Set COM1B1 bit in TCCR1A to 1

	// Select inverted mode
	#elif 	PHASE_CORRECT_PWM_B == PHASE_CORRECT_CNT_UP
	SET_BIT(TCCR1A, COM1B0);					// Set COM1B0 bit in TCCR1A to 1
	SET_BIT(TCCR1A, COM1B1);                    // Set COM1B1 bit in TCCR1A to 1

	// Select Toggle mode
	#elif 	PHASE_CORRECT_PWM_B == TOGGLE
	SET_BIT(TCCR1A, COM1B0);					// Set COM1B0 bit in TCCR1A to 1
	CLR_BIT(TCCR1A, COM1B1);                    // Set COM1B1 bit in TCCR1A to 0

	#endif

}
void MTIM1_SetDutyCycle(u8 Copy_u8DutyCycle_A, u8 Copy_u8DutyCycle_B)
{
	#if	TIM1_MODE == PWM_FAST_1

		// Set duty cycle for OC1A ( i set it as non-inverted )

		// Set a number in OCR1A Register														// Duty Cycle = T_ON / T-total = ( OCR / TOP )  *100
		if((Copy_u8DutyCycle_A <= 100) && (Copy_u8DutyCycle_A > 0))
		{
			OCR1A = ((Copy_u8DutyCycle_A * ICR1) / 100) - 1;
		}
		else if(Copy_u8DutyCycle_A == 0)
		{
			OCR1A = 0;
		}

		// Set duty cycle for OC1B ( i set it as inverted )

		// Set a number in OCR1B Register														// Duty Cycle = T_ON / T-total = ( OCR / TOP )  *100
		if((Copy_u8DutyCycle_B <= 100) && (Copy_u8DutyCycle_B > 0))
		{
			OCR1B = (((100 - Copy_u8DutyCycle_B) * ICR1) / 100) - 1;
		}
		else if(Copy_u8DutyCycle_B == 0)
		{
			OCR1B = 0;
		}

	#endif
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------   TIM2 Register Functions   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/* Timer 2 start */
void MTIM2_Start(void)
{
	// Select Clock Prescaler
	#if 	TIM2_CLK_PRESCALER == 1
		SET_BIT(TCCR2,CS20);					// Set CS20 bit in TCCR2 to 1
		CLR_BIT(TCCR2,CS21);					// Set CS21 bit in TCCR2 to 0
		CLR_BIT(TCCR2,CS22);					// Set CS22 bit in TCCR2 to 0

	#elif 	TIM2_CLK_PRESCALER == 8
		CLR_BIT(TCCR2,CS20);					// Set CS20 bit in TCCR2 to 0
		SET_BIT(TCCR2,CS21);					// Set CS21 bit in TCCR2 to 1
		CLR_BIT(TCCR2,CS22);					// Set CS22 bit in TCCR2 to 0

	#elif 	TIM2_CLK_PRESCALER == 64
		SET_BIT(TCCR2,CS20);					// Set CS20 bit in TCCR2 to 1
		SET_BIT(TCCR2,CS21);					// Set CS21 bit in TCCR2 to 1
		CLR_BIT(TCCR2,CS22);					// Set CS22 bit in TCCR2 to 0

	#elif 	TIM2_CLK_PRESCALER == 256
		CLR_BIT(TCCR2,CS20);					// Set CS20 bit in TCCR2 to 0
		CLR_BIT(TCCR2,CS21);					// Set CS21 bit in TCCR2 to 0
		SET_BIT(TCCR2,CS22);					// Set CS22 bit in TCCR2 to 1

	#elif 	TIM2_CLK_PRESCALER == 1024
		SET_BIT(TCCR2,CS20);					// Set CS20 bit in TCCR2 to 1
		CLR_BIT(TCCR2,CS21);					// Set CS21 bit in TCCR2 to 0
		SET_BIT(TCCR2,CS22);					// Set CS22 bit in TCCR2 to 1

	#elif	TIM2_CLK_PRESCALER == EXT_FALLING
		CLR_BIT(TCCR2,CS20);					// Set CS20 bit in TCCR2 to 0
		SET_BIT(TCCR2,CS21);					// Set CS21 bit in TCCR2 to 1
		SET_BIT(TCCR2,CS22);					// Set CS22 bit in TCCR2 to 1

	#elif	TIM2_CLK_PRESCALER == EXT_RISING
		SET_BIT(TCCR2,CS20);					// Set CS20 bit in TCCR2 to 1
		SET_BIT(TCCR2,CS21);					// Set CS21 bit in TCCR2 to 1
		SET_BIT(TCCR2,CS22);					// Set CS22 bit in TCCR2 to 1


	#endif

}

/* Timer 2 stop */
void MTIM2_Stop(void)
{

	// No Clock Source - Stop Timer 2
	CLR_BIT(TCCR2,CS20);						// Set CS00 bit in TCCR0 to 0
	CLR_BIT(TCCR2,CS21);                        // Set CS01 bit in TCCR0 to 0
	CLR_BIT(TCCR2,CS22);                        // Set CS02 bit in TCCR0 to 0
}

/* PWM Initialization for Timer 2 */
void MTIM2_PWM_Init(void)
{
	// Set PB3 as output to use it as OCR0
	SET_BIT(DDRD,7);

	// Select MODE
	#if			TIM2_PWM_MODE == FAST_NON_INVERTED

		// Select Fast PWM MODE
		SET_BIT(TCCR2, WGM20);					// Set WGM00 bit in TCCR2 to 1
		SET_BIT(TCCR2, WGM21);                  // Set WGM01 bit in TCCR2 to 1

		// Select non-inverted mode
		CLR_BIT(TCCR2, COM20);					// Set COM00 bit in TCCR2 to 0
		SET_BIT(TCCR2, COM21);                  // Set COM01 bit in TCCR2 to 1

	#elif		TIM2_PWM_MODE == FAST_INVERTED

		// Select Fast PWM MODE
		SET_BIT(TCCR2, WGM20);					// Set WGM00 bit in TCCR2 to 1
		SET_BIT(TCCR2, WGM21);                  // Set WGM01 bit in TCCR2 to 1

		// Select inverted mode
		SET_BIT(TCCR2, COM20);					// Set COM00 bit in TCCR2 to 1
		SET_BIT(TCCR2, COM21);                  // Set COM01 bit in TCCR2 to 1

	#elif		TIM2_PWM_MODE == PHASE_CORRECT_NON_INVERTED

		// Select Phase Correct PWM MODE
		SET_BIT(TCCR2, WGM20);					// Set WGM00 bit in TCCR2 to 1
		CLR_BIT(TCCR2, WGM21);                  // Set WGM01 bit in TCCR2 to 0

		// Select NON-INVERTED MODE 	-->  Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting
		CLR_BIT(TCCR2, COM20);					// Set COM00 bit in TCCR2 to 0
		SET_BIT(TCCR2, COM21);                  // Set COM01 bit in TCCR2 to 1


	#elif		TIM2_PWM_MODE == PHASE_CORRECT_INVERTED

		// Select Phase Correct PWM MODE
		SET_BIT(TCCR2, WGM20);					// Set WGM00 bit in TCCR2 to 1
		CLR_BIT(TCCR2, WGM21);                  // Set WGM01 bit in TCCR2 to 0

		// Select INVERTED MODE        -->  Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting
		SET_BIT(TCCR2, COM20);					// Set COM00 bit in TCCR2 to 0
		SET_BIT(TCCR2, COM21);                  // Set COM01 bit in TCCR2 to 1


	#endif
}

/* PWM Start for Timer 2 */
void MTIM2_PWM_Start(void)
{
	MTIM2_Start();
}

/* PWM Stop for Timer 2 */
void MTIM2_PWM_Stop(void)
{
	MTIM2_Stop();
}

/* PWM Duty cycle */
void MTIM2_SetDutyCycle(u8 Copy_u8DutyCycle)
{
	#if 		TIM2_PWM_MODE == FAST_NON_INVERTED

		// Set a number in OCR Register														// Duty Cycle = T_ON / T-total = ( OCR / 256 )  *100
		if((Copy_u8DutyCycle <= 100) && (Copy_u8DutyCycle > 0))
		{
			OCR2 = (Copy_u8DutyCycle * 256) / 100 - 1;
		}
		else if(Copy_u8DutyCycle == 0)
		{
			OCR2 = 0;
		}

	#elif		TIM2_PWM_MODE == FAST_INVERTED

		// Set a number in OCR Register														// Duty Cycle = T_ON / T-total = ( ( 256 - OCR ) / 256 ) * 100
		if((Copy_u8DutyCycle <= 100) && (Copy_u8DutyCycle > 0))
		{
			OCR2 = (( 100 - Copy_u8DutyCycle ) * 256)/ 100 - 1;
		}
		else if(Copy_u8DutyCycle == 0)
		{
			OCR2 = 0xFF;
		}

	#elif		TIM2_PWM_MODE == PHASE_CORRECT_NON_INVERTED

		// Set a number in OCR Register														// Duty Cycle = T_ON / T-total = ( 2 * OCR / 512 )  *100
		if((Copy_u8DutyCycle <= 100) && (Copy_u8DutyCycle > 0))
		{
			OCR2 = (Copy_u8DutyCycle * 256) / 100 ;
		}
		else if(Copy_u8DutyCycle == 0)
		{
			OCR2 = 0;
		}

	#elif		TIM2_PWM_MODE == PHASE_CORRECT_INVERTED

		// Set a number in OCR Register														// Duty Cycle = T_ON / T-total = ( 512 - ( 2 * OCR ) / 512 )  *100
		if((Copy_u8DutyCycle <= 100) && (Copy_u8DutyCycle > 0))
		{
			OCR2 = ( ( 100- Copy_u8DutyCycle ) * 256) / 100 ;
		}
		else if(Copy_u8DutyCycle == 0)
		{
			OCR2 = 0;
		}


	#endif


}
