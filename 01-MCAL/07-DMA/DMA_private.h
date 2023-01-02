/**
 * @file DMA_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the DMA Driver the User shouldn't see this
 * @version V01
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#define NUMBER_OF_CHANNELS  7
typedef struct
{
  volatile uint32 CCR;
  volatile uint32 CNDTR;
  volatile uint32 CPAR;
  volatile uint32 CMAR;
  volatile uint32 Reserved;
}DMA_channelGroup;

typedef struct
{
  volatile uint32 ISR;
  volatile uint32 IFCR;
  DMA_channelGroup Channel[NUMBER_OF_CHANNELS];
}DMA_t;


#define   DMA1  ((volatile DMA_t*)0x40020000)






#define CHANNEL_1 0
#define CHANNEL_2 1
#define CHANNEL_3 2
#define CHANNEL_4 3
#define CHANNEL_5 4
#define CHANNEL_6 5
#define CHANNEL_7 6
#endif
