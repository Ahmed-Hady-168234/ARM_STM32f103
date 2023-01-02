/**
 * @file AFIO_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the AFIO Driver that the User can see and use
 * @version V01
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H



/****************** The driver Functions ******************/
void MAFIO_voidSetEXTIConfig(uint32 Copy_u8Line, uint32 Copy_u8PortMap);
#endif