/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 19 SEP 2021                    */
/*              NTI Diploma                    */
/*              TIMER Driver                   */
/***********************************************/


#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------   TIM0 Register Functions   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Timer 0 Initialization */
void MTIM0_init(void);

/* Timer 0 set time to execute ISR */
void MTIM0_SetTaskPeriodic(u32 time_ms, void (*copy_ptr)(void));

/* Timer 0 start */
void MTIM0_Start(void);

/* Timer 0 stop */
void MTIM0_Stop(void);

/* Generate Waveform on OC0 with Timer 0 */
void MTIM0_GenerateWavw(void);

/* PWM Initialization for Timer 0 */
void MTIM0_PWM_Init(void);

/* PWM Start for Timer 0 */
void MTIM0_PWM_Start(void);

/* PWM Stop for Timer 0 */
void MTIM0_PWM_Stop(void);

/* PWM Duty cycle */
void MTIM0_SetDutyCycle(u8 Copy_u8DutyCycle);




/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------   TIM1 Register Functions   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Timer 1 Initialization */
void MTIM1_init(void);

/* Timer 1 set time to execute ISR */
void MTIM1_SetTime(u32);

/* Timer 1 start */
void MTIM1_Start(void);

/* Timer 1 stop */
void MTIM1_Stop(void);

/* PWM Start for Timer 1 */
void MTIM1_PWM_Start(void);

/* PWM Stop for Timer 1 */
void MTIM1_PWM_Stop(void);

/* PWM Initialization for Timer 1 */
void MTIM1_PWM_Init(void);

/* PWM Duty cycle */
void MTIM1_SetDutyCycle(u8 Copy_u8DutyCycle_A, u8 Copy_u8DutyCycle_B);


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------   TIM2 Register Functions   --------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Timer 2 Initialization */
void MTIM2_init(void);

/* Timer 2 set time to execute ISR */
void MTIM2_SetTaskPeriodic(u32 time_ms, void (*copy_ptr)(void));

/* Timer 2 start */
void MTIM2_Start(void);

/* Timer 2 stop */
void MTIM2_Stop(void);

/* Generate Waveform on OC2 with Timer 2 */
void MTIM2_GenerateWavw(void);

/* PWM Initialization for Timer 2 */
void MTIM2_PWM_Init(void);

/* PWM Start for Timer 2 */
void MTIM2_PWM_Start(void);

/* PWM Stop for Timer 2 */
void MTIM2_PWM_Stop(void);

/* PWM Duty cycle */
void MTIM2_SetDutyCycle(u8 Copy_u8DutyCycle);

#endif