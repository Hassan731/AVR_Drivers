/************************************************/
/* Author     : Hassan Mahmoud                  */
/* Date       : 25 DEC 2021                     */
/*              FREELANCING                     */
/*              PWM_WITHLCD                     */
/************************************************/

#ifndef		PWM_WITHLCD
#define		PWM_WITHLCD


//******************LCD PROGRAM STARTS*********************//

#define LCD_DATA PORTA          // port B is selected as LCD data port

#define ctrl PORTB              //  port D is selected as LCD command port

#define en PB5                  // enable signal is connected to port D pin 7

#define rw PB6                  // read/write signal is connected to port D pin 6

#define rs PB7                  // register select signal is connected to port D pin 5



void LCD_WriteCMD(unsigned char cmd);

void LCD_Init(void);

void LCD_WriteString(u8* STR_PTR);

void LCD_WriteChar(unsigned char data);

void LCD_WriteNumber(u32 Copy_u8num);

void LCD_Clear(void);







																	/* COMMANDS */
																	
																	
#define		CLEAR					 0x01										//Clear screen
#define		HOME					 0x02										//return home
#define		CRS_DEC					 0x04										//Cursor decrement
#define		DSP_SR					 0x05										//Display shifts to right
#define		CRS_INC					 0x06										//Cursor increment
#define		DSP_SL					 0x07										//Display shifts to left
#define		DIS_OFF					 0x08										//Cursor and display OFF
#define		CRS_POS_L				 0x10										//Cursor position Shifts to left
#define		CRS_POS_R				 0x14										//Cursor position shifts to right
#define		TWO_Line_8_bit			 0x38										//Using two lines, 8-bit mode
#define		TWO_LINE_4_BIT			 0x28										//Using two lines, 4-bit mode
#define		DSP_ON_CRS_OFF			 0x0C										//Display ON, cursor OFF
#define  	DSP_OFF_CRS_ON			 0x0A										//Display OFF, cursor ON
#define  	DSP_ON_CRS_BLIN			 0x0E										//Display ON, cursor blinking
#define  	ONE_LINE_8_BIT			 0x30										//For display in one line in 8-bit mode
#define  	ONE_LINE_4_BIT			 0x20										//For display in one line in 4-bit mode
#define  	DISP_CRS_BLINK			 0x0F										//Display data on cursor blinking
#define  	DATA_SL					 0x18										//Shift complete data to left side
#define  	DATA_SR					 0x1C										//Shift complete data to right side

#define 	FL_P0					 0x80   									//go to first  line position 0
#define 	FL_P1					 0x81   									//go to first  line position 1
#define 	FL_P2					 0x82   									//go to first  line position 2
#define 	SL_P0					 0xC0   									//go to second line position 0
#define 	SL_P1					 0xC1   									//go to second line position 1
#define 	SL_P2					 0xC2   									//go to second line position 2

#define  	EIGHT_BIT				 0x38    									//activate 8 bit mode


#endif
