/************************************************/
/* Author     : Hassan Mahmoud                  */
/* Date       : 25 DEC 2021                     */
/*              FREELANCING                     */
/*              PWM_WITHLCD                     */
/************************************************/

#include "avr/io.h"
#include "util/delay.h"

#include "STD_TYPES.h"

#include "LCD.h"

void LCD_Init(void)
{

LCD_WriteCMD(0x38);           // initialization in 8bit mode of 16X2 LCD

_delay_ms(1);

LCD_WriteCMD(0x01);          // make clear LCD

_delay_ms(1);

LCD_WriteCMD(0x02);          // return home

_delay_ms(1);

LCD_WriteCMD(0x06);          // make increment in cursor

_delay_ms(1);

LCD_WriteCMD(0x80);          // Ã¢â‚¬Å“8Ã¢â‚¬ï¿½ go to first line and Ã¢â‚¬Å“0Ã¢â‚¬ï¿½ is for 0th position

_delay_ms(1);

LCD_WriteCMD(0x0C);          // display on, cursor off

_delay_ms(1);


}



//**************sending command on LCD***************//

void LCD_WriteCMD(unsigned char cmd)

{

LCD_DATA = cmd;      // data lines are set to send command

PORTB  &= ~(1<<rs);  // RS sets 0

PORTB  &= ~(1<<rw);  // RW sets 0

PORTB  |= (1<<en);   // make enable from high to low

_delay_ms(100);

PORTB  &= ~(1<<en);


}



//*****************write data on LCD*****************//

void LCD_WriteChar(unsigned char data)

{

LCD_DATA= data;       // data lines are set to send command

PORTB  |= (1<<rs);    // RS sets 1

PORTB  &= ~(1<<rw);   // RW sets 0

PORTB  |= (1<<en);    // make enable from high to low

_delay_ms(10);

PORTB &= ~(1<<en);


}

void LCD_WriteString(u8* STR_PTR)
{
	u8 i =0;

	while(STR_PTR[i] != '\0')
	{
		LCD_WriteChar(STR_PTR[i]);
		++i;
	}
}

void LCD_WriteNumber(u32 Copy_u8num)
{
	// Initializing Variables
	u32 rem = 0;
	u8 arr [17];
	s8 i = 0;

	// Storing each digit in an array
	while(Copy_u8num != 0)
	{
		rem = Copy_u8num % 10;
		arr[i] = rem + 48;
		i++;
		Copy_u8num = Copy_u8num / 10;
	}
	i--;

	// Sending char by char to the LCD
	while(i > -1)
	{
		LCD_WriteChar(arr[i]);

	    i--;
	}

}

void LCD_Clear(void)
{
	LCD_WriteCMD(0x01);
}
