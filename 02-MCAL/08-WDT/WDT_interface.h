/***********************************************/
/* Author     : Hassan Mahmoud                 */
/* Date       : 30 SEP 2021                    */
/*              NTI Diploma                    */
/*              WDT Driver                     */
/***********************************************/


#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H


// Initializing WatchDog Timer
void MWDT_voidInit(void);


// Reset WatchDog Timer
void MWDT_voidRefresh(void);

#endif