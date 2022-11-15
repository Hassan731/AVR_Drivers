/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 30 SEP 2021                    */
/*              NTI Diploma                    */
/*              DC MOTOR DRIVER                */
/***********************************************/

#ifndef DC_MOTOR_INTERFACE_H
#define	DC_MOTOR_INTERFACE_H


// Initialize MOTOR
void HDCMOTOR_voidInit(void);

// Set Direction
void HDCMOTOR_voidSetDirection(u8 Copy_u8Direction);

// Set Speed
void HDCMOTOR_voidSetSpeed(u16 Copy_u8Speed);

// Start
void HDCMOTOR_voidStart(void);

// Stop
void HDCMOTOR_voidStop(void);

// Motor Lock
void HDCMOTOR_voidLock(void);



#endif