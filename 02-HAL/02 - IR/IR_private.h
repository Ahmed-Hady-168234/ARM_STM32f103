/**
 * @file IR_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the IR Driver User shouldn't see this
 * @version V01
 * @date 2022-08-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef IR_PRIVATE_H
#define IR_PRIVATE_H

/** Register Definition */
     



/*volatile because them changed only in Interrupt*/
volatile uint8  u8StartFlag = FALSE;/*Tells you if it is the first falling edge(the start bit)*/
volatile uint32 u32FrameData[50] = {0};/*Array to put the data in*/
volatile uint8  u8EdgeCounter    = 0;/*Counter to count the number of edges... used with u32FrameData array*/






#endif 
