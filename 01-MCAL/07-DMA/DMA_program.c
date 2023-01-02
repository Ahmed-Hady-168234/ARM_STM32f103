/**
 * @file DMA_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the DMA Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-07-29
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "DMA_private.h"
#include "DMA_interface.h"
#include "DMA_Config.h"


void MDMA_voidChannelInit(void)
{
#ifdef CHANNEL_ID == CHANNEL_1
      /*1- MEM to MEM
        2- Very high
        3- Source size, Destination size = 32 bit
        4- MINC, DINC Activated
        5- No circular
        6- Direction:
        7- Transfer Interrupt Enable        
        */
    //DMA1 ->Channel[CHANNEL_ID].CCR = 
#elif CHANNEL_ID == CHANNEL_2
#elif CHANNEL_ID == CHANNEL_3
#elif CHANNEL_ID == CHANNEL_4
#elif CHANNEL_ID == CHANNEL_5
#elif CHANNEL_ID == CHANNEL_6
#elif CHANNEL_ID == CHANNEL_7
#endif
}

void MDMA_voidChannelStart(uint32 *Copy_Pu32SourceAddress, uint32 *Copy_Pu32DestinationAddress, uint16 Copy_u16BlockLength)
{
    /*Disable the Channel to make sure it will not make any transfer*/
    CLR_BIT(DMA1 ->Channel[CHANNEL_ID].CCR,0);

    /*Write The Source Address*/
    DMA1 ->Channel[CHANNEL_ID].CPAR = Copy_Pu32SourceAddress;

    /*Write The Source Address*/
    DMA1 ->Channel[CHANNEL_ID].CMAR = Copy_Pu32DestinationAddress;

    /*Write Block Length*/
    DMA1 ->Channel[CHANNEL_ID].CNDTR = Copy_u16BlockLength;

    /*Enable The Channel*/
    SET_BIT(DMA1 ->Channel[CHANNEL_ID].CCR,0);

}