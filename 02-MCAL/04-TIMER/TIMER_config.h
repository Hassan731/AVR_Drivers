/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 19 SEP 2021                    */
/*              NTI Diploma                    */
/*              TIMER Driver                   */
/***********************************************/


#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------   TIM0 Register Configurations   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* General Configurations */
#define 	SYSTEM_CLOCK					8000000					// System clock in HZ (Min = 1000000)
#define 	TIM0_CLK_PRESCALER				1					// choose from: 1 ,8, 64, 256, 1024, EXT_FALLING, EXT_RISING
#define 	TIM0_MODE						NORMAL					// choose from: NORMAL , CTC

/* CTC MODE Configurations */
#define 	OCR_VALUE						125						// OCR can be a value between 0 -> 255

/* PWM MODE Configurations */
#define		TIM0_PWM_MODE				FAST_NON_INVERTED           // choose from: FAST_NON_INVERTED , FAST_INVERTED , PHASE_CORRECT_CNT_DWN , PHASE_CORRECT_CNT_UP


																	// You can change the value of the PWM by setting the duty cycle
																	// You can change the frequency of the PWM by changing the configurations according to the following equations:
																	
																	/*
																		--> Wave frequency  in Fast PWM MODE = (System Clock) / (TIM0_CLK_PRESCALER * 256)

																		--> Wave frequency  in Phase Correct PWM MODE = (System Clock) / (TIM0_CLK_PRESCALER * 510)
																	*/

/* Wave Generation Configurations */
#define 	OCR_WAVE						0						// OCR can be a value between 0 -> 255			

																	/*
																		Wave_Frequancy = (System Clock) / (2 * TIM0_CLK_PRESCALER * (1+OCR_WAVE) )
																	
																		For Max Frequency -> put OCR = 0 and prescaler to 1
																	*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------   TIM1 Register Configurations   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define 	TIM1_CLK_PRESCALER				1							// choose from: 1, 8, 64, 256, 1024
#define 	TIM1_MODE						PWM_FAST_1					// choose from Timer1 Modes


/* Fast PWM mode Configurations */
#define 	FAST_PWM_A					INVERTED						// choose from : INVERTED, NON_INVERTED, TOGGLE
#define 	FAST_PWM_B					INVERTED						// choose from : INVERTED, NON_INVERTED, TOGGLE

#define 	PWM1_freq						100000						// Frequency of pwm at PWM_FAST_1 mode in Hz  /* Note to always set the prescaler to 1 when activating PWM_FAST_1 mode */

/* Phase correct and phase&frequency corect modes configurations */	
#define		PHASE_CORRECT_PWM_A			PHASE_CORRECT_CNT_UP			// choose from : PHASE_CORRECT_CNT_UP, PHASE_CORRECT_CNT_DWN, TOGGLE															
#define		PHASE_CORRECT_PWM_B			PHASE_CORRECT_CNT_UP			// choose from : PHASE_CORRECT_CNT_UP, PHASE_CORRECT_CNT_DWN, TOGGLE															
																					
							

													/*
													Timer1 Modes:
															
													Timer/Counter Mode of 								TOP						Update of 					TOV1 Flag Set 
													Operation TOP																OCR1x					    	on

													NORMAL												0xFFFF 					Immediate 						MAX
													CTC													OCR1A 					Immediate 						MAX
													PWM_PHASE_CORRECT_8BIT								0x00FF 					TOP 							BOTTOM			
													PWM_PHASE_CORRECT_9BIT								0x01FF 					TOP 							BOTTOM			
													PWM_PHASE_CORRECT_10BIT								0x03FF					TOP 							BOTTOM				
													PWM_FAST_8BIT										0x00FF 					BOTTOM 							TOP				
													PWM_FAST_9BIT										0x01FF 					BOTTOM 							TOP				
													PWM_FAST_10BIT										0x03FF 					BOTTOM 							TOP
													PWM_PH_F_CORRECT_1									ICR1 					BOTTOM 							BOTTOM					
													PWM_PH_F_CORRECT_2									OCR1A 					BOTTOM 							BOTTOM				
													PWM_PHASE_CORRECT_1									ICR1 					TOP 							BOTTOM						
													PWM_PHASE_CORRECT_2									OCR1A 					TOP 							BOTTOM						
													CTC_1												ICR1 					Immediate 						MAX	
													PWM_FAST_1											ICR1 					BOTTOM 							TOP						
													PWM_FAST_2											OCR1A 					BOTTOM 							TOP
							
													*/
																		
							
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------   TIM2 Register Configurations   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define 	TIM2_CLK_PRESCALER				1					// choose from: 8, 64, 256, 1024
#define 	TIM2_MODE						NORMAL					// choose from: NORMAL , CTC
#define		TIM2_PWM_MODE				FAST_NON_INVERTED           // choose from: FAST_NON_INVERTED , FAST_INVERTED , PHASE_CORRECT_CNT_DWN , PHASE_CORRECT_CNT_UP
																							
																							
#endif
