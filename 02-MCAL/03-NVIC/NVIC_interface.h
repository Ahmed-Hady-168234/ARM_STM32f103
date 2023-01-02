/**
 * @file NVIC_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the NVIC Driver that the User can see and use
 * @version V01
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H



/****************** The driver Functions ******************/
void MNVIC_voidEnableInterrupt(uint8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(uint8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(uint8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(uint8 Copy_u8IntNumber);
uint8 MNVIC_u8GetActiveFlag(uint8 Copy_u8IntNumber);
void MNVIC_voidSetPriorities(sint8 Copy_s8InterruptID, uint8 Copy_u8GroupPriority, uint8 Copy_u8SubPriority );

#endif