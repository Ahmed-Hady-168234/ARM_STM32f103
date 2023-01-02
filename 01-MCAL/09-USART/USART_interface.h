/**
 * @file USART_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the USART Driver that the User can see and use
 * @version V01
 * @date 2022-09-12
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


void MUSART1_voidInit(void);
void MUSART1_voidTransmit(uint8 *Copy_Pu8arr, uint8 Copy_u8DataSize);
uint8 MUSART1_u8Receive(void);


#endif