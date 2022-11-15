/*
 * main.c
 *
 *  Created on: Sep 15, 2021
 *      Author: Hassan Mahmoud
 */

#include <stdio.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

u32 STR2INT(u8* arr);
void INT2STR(f32 num, u8* arr);
void arrzero(u8* arr);
f32 Calculate(u8 op1, u8 op2, u8 State);

int main()
{
	// Declaring variable for the KEYPAD Read
	u8 value;

	// Declaring Arithmetic Flags
	u8 MATH_FLAG;

	// Initialize an array to hold result in char form
	u8 res[50];

	// Initializing an array to read all input
	u8 input[40];

	// Initializing a counter
	u8 i = 0;

	// Declaring Variables for mathematical operations
	f32 num1, num2, result;

	// Initializing LCD to port D
	HLCD_voidLcdInit();

	// Initializing KEYPAD rows to pins 0 -> 3 and columns to 4 -> 7 from Port A
	HKEYPAD_voidInit();

	// Set pin B0 for the led to be output
	HLED_voidLedInit(DIOB, PIN0);

	// Set pin B0 for the led to be output
	HLED_voidLedInit(DIOB, PIN1);

	while(1)
		{
			value = HKEYPAD_u8Read();


			if(value != 0)
			{

			switch(value)
			{

			case 'c':
				HLCD_voidWriteCMD(CLEAR);
				HLED_voidLedOff(DIOB, PIN1);

				HLED_voidLedOn(DIOB, PIN0);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN0);

				break;

			case '9':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);
				break;

			case '8':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);
				break;

			case '7':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);
				break;

			case '6':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);
				break;

			case '5':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);
				break;

			case '4':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);
				break;

			case '3':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);
				break;

			case '2':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);
				break;

			case '1':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);

				break;

			case '0':
				input[i] = value;
				i++;

				HLCD_voidWriteChar(value);
				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);
				break;

			case '/':
				num1 = STR2INT(input);
				arrzero(input);
				i =0;
				MATH_FLAG = 4;

			//	HLCD_voidWriteChar(' ');
				HLCD_voidWriteChar(value);
			//	HLCD_voidWriteChar(' ');


				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);

				break;

			case '*':
				num1 = STR2INT(input);
				arrzero(input);
				i =0;
				MATH_FLAG = 3;

			//	HLCD_voidWriteChar(' ');
				HLCD_voidWriteChar(value);
			//	HLCD_voidWriteChar(' ');

				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);

				break;

			case '-':
				num1 = STR2INT(input);
				arrzero(input);
				i =0;
				MATH_FLAG = 2;

			//	HLCD_voidWriteChar(' ');
				HLCD_voidWriteChar(value);
			//	HLCD_voidWriteChar(' ');


				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);

				break;

			case '+':
				num1 = STR2INT(input);
				arrzero(input);
				i =0;
				MATH_FLAG = 1;

				HLCD_voidWriteChar(value);



				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);

				break;

			case '=':
				num2 = STR2INT(input);
				arrzero(input);
				i =0;

				// Clear LCD
				//HLCD_voidClear();

				HLCD_voidWriteChar(value);


				// Doing Calculations

				result = Calculate(num1, num2, MATH_FLAG);


				// Send result to LCD

				HLCD_voidWriteNumber(result);

				HLED_voidLedOff(DIOB, PIN0);

				HLED_voidLedOn(DIOB, PIN1);
				_delay_ms(10);
				HLED_voidLedOff(DIOB, PIN1);

				break;


			default:

				HLED_voidLedOff(DIOB, PIN0);
				HLED_voidLedOff(DIOB, PIN1);

				break;

			}
			}
		}
}


u32 STR2INT(u8* arr)
{
	// Initializing a counter
	u32 i;

	sscanf(arr, "%lu", &i);

	return i;

}

void INT2STR(f32 num, u8* arr)
{
	sprintf(arr, "%f", num);
}

void arrzero(u8* arr)
{
	u8 i;

	for(i = 0; i > 40; i++)
	{
		arr[i] = 0;
	}

}

f32 Calculate(u8 op1, u8 op2, u8 State)
{

	switch(State)
	{
	// ADD Case
	case 1:
		return (op1 + op2);
		break;

	// SUB Case
	case 2:
		return (op1 - op2);
		break;

	// MUL Case
	case 3:
		return (op1 * op2);
		break;

	// SUB Case
	case 4:
		return (op1 / op2);
		break;

	default:
		return 0;
		break;

	}
}
