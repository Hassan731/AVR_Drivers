/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 30 SEP 2021                    */
/*              NTI Diploma                    */
/*              WDT Driver                     */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_register.h"
#include "WDT_private.h"
#include "WDT_config.h"
#include "WDT_interface.h"


// Initializing WatchDog Timer
void MWDT_voidInit(void)
{
	// Select a prescaler
	
	
	// Enable WTD 
	
}


// Reset WatchDog Timer
void MWDT_voidRefresh(void)
{
	// Reset using assembly instruction
	asm("WDR");
}


