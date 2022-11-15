/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 12 SEP 2021                    */
/*              NTI Diploma                    */
/*              KEYPAD Driver                  */
/***********************************************/


#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

																		  /* KEYPAD DIMENSIONS */
#define           ROWS          	 4
#define          COULMNS       		 4

																		/* Pins connected to rows */
																			
#define			  ROW1			 DIOA, PIN0    
#define			  ROW2			 DIOA, PIN1
#define			  ROW3			 DIOA, PIN2
#define			  ROW4			 DIOA, PIN3

																		/* Pins connected to coulmns */


#define			 COULMN1         DIOA, PIN4   
#define			 COULMN2         DIOA, PIN5 
#define			 COULMN3         DIOA, PIN6 
#define			 COULMN4         DIOA, PIN7         


																		/* Arrays of rows and coulmns */

u8 rows[ROWS][2]        = {{ROW1}, {ROW2}, {ROW3}, {ROW4}};

u8 coulmns[COULMNS][2]  = {{COULMN1}, {COULMN2}, {COULMN3}, {COULMN4}};


																/*		Buttons on the KEYPAD by order		*/
																
u8 buttons[4][4] = { 
					{ '7' , '8' , '9' , '/' },
					{ '4' , '5' , '6' , '*' },
					{ '1' , '2' , '3' , '-' },
					{ 'c' , '0' , '=' , '+' },
					
               };


#endif
