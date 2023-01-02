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

/*CONFIGURATION External Interrupt Lines Macros for avoiding Magic Numbers*/
#define     EXTI_LINE0      0
#define     EXTI_LINE1      1
#define     EXTI_LINE2      2
#define     EXTI_LINE3      3
#define     EXTI_LINE4      4
#define     EXTI_LINE5      5
#define     EXTI_LINE6      6
#define     EXTI_LINE7      7
#define     EXTI_LINE8      8
#define     EXTI_LINE9      9
#define     EXTI_LINE10     10
#define     EXTI_LINE11     11
#define     EXTI_LINE12     12
#define     EXTI_LINE13     13
#define     EXTI_LINE14     14
#define     EXTI_LINE15     15

/****************** The driver Functions ******************/
void MEXTI_voidInit(void);
void MEXTI_voidEnableEXTI(uint8 Copy_u8Line);
void MEXTI_voidDisableEXTI(uint8 Copy_u8Line);
void MEXTI_voidSwTrigger(uint8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(uint8 Copy_u8Line, uint8 Copy_u8ExtiMode);
void MEXTI_voidSetSetCallBack(uint8 Copy_u8Line, void (* Copy_voidPtr)(void));



#endif