/**
 * @file DMA_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the DMA Driver that the User can see and use
 * @version V01
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


void MDMA_voidChannelInit(void);
void MDMA_voidChannelStart(uint32 *Copy_Pu32SourceAddress, uint32 *Copy_Pu32DestinationAddress, uint16 Copy_u16BlockLength);


#endif