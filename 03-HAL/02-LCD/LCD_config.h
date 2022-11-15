/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 9 SEP 2021                     */
/*              NTI Diploma                    */
/*              LCD Driver                     */
/***********************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


#define  LCD_PORT        DIOC                   // choose the port to be connected with data pins   ---<  DIOA   DIOB   DIOC    DIOD  >---
#define  RS              DIOA, PIN0             // Register Selection pin is attached to PIN0 in port A
#define  R_W             DIOA, PIN1             // Read/Write pin is attached to PIN1 in port A
#define  E               DIOA, PIN2             // Enable pin is attached to PIN2 in port A

#define WRITING_MODE     Eight_BIT_MODE         // Mode of writing   ----<  Eight_BIT_MODE         Four_BIT_MODE   >----

#define  D4              DIOC, PIN0             // D4 pin is attached to PIN0 in port C
#define  D5              DIOC, PIN1             // D4 pin is attached to PIN1 in port C
#define  D6              DIOC, PIN2             // D4 pin is attached to PIN2 in port C
#define  D7              DIOC, PIN3             // D4 pin is attached to PIN3 in port C




#endif