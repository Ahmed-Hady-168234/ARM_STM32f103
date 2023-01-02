/**
 * @file AFIO_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the AFIO Driver the User shouldn't see this
 * @version V01
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H
 
/*Base Address: 0x4001 0000 - 0x4001 03FF*/

typedef struct
{
    volatile uint32 EVCR;
    volatile uint32 MAPR;
    volatile uint32 EXTICR[4];
    volatile uint32 MAPR2;

}AFIO_t;

#define AFIO ((volatile AFIO_t*)0x40010000)

#define AFIO_NO_OF_BITS_PER_LINE 4

#endif
