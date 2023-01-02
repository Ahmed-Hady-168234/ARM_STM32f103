/**
 * @file EXTI_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the EXTI Driver that the User can see and use
 * @version V01
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/*Macro Notifies the maximum number of lines to avoid Magic Numbers*/
#define MAXIMUM_LINES_NUMBER 16

/****************** The driver Functions ******************/
void MEXTI_voidInit(void);
void MEXTI_voidEnableEXTI(uint8 Copy_u8Line);
void MEXTI_voidDisableEXTI(uint8 Copy_u8Line);
void MEXTI_voidSwTrigger(uint8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(uint8 Copy_u8Line, uint8 Copy_u8ExtiMode);


#endif