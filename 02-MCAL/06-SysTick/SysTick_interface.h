/**
 * @file SysTick_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the SysTick Driver that the User can see and use
 * @version V01
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef SysTick_INTERFACE_H
#define SysTick_INTERFACE_H


/****************** API.. Driver Functions  ******************/
void MSysTick_voidInit(void);
SysTick_returnType MSysTick_voidSetBusyWait(uint32 Copy_u32Ticks);
SysTick_returnType MSysTick_voidSetIntervalSingle(uint32 Copy_u32Ticks, void (*Copy_ptr)(void) );/*ASynchronous Function */
SysTick_returnType MSysTick_voidSetIntervalPeriodic(uint32 Copy_u32Ticks, void (*Copy_ptr)(void) );/*ASynchronous Function */
void MSysTick_voidStopInterval(void);
uint32 MSysTick_u32GetElapsedTime(void);
uint32 MSysTick_u32GetRemainingTime(void);

/*SysTick Return Types used to check if the function succeeded or there is a error */
#define SYSTICK_OK                           ((SysTick_returnType) 0)/*The function succeeded*/
#define SYSTICK_ANOTHER_TIMER_IS_RUNNING     ((SysTick_returnType) 1)/*There is another running Timer*/
#define SYSTICK_TICKS_EXCEEDED_MAX_VALUE     ((SysTick_returnType) 2)/*The input Ticks value Exceeded MAXIMUM_COUNT_VALUE (2^24)*/
#define SYSTICK_NULL_POINTER                 ((SysTick_returnType) 3)/*The input pointer passed is NULL*/


#endif