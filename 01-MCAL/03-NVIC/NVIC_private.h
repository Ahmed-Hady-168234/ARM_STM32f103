/**
 * @file NVIC_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the NVIC Driver the User shouldn't see this
 * @version V01
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*Base Address 0xE000E100*/
                    


#define NVIC_ISER0      *((volatile uint32 *)0xE000E100)/*Enable INTs from 0 to 31*/
#define NVIC_ISER1      *((volatile uint32 *)0xE000E104)/*Enable INTs from 32 to 59*/

#define NVIC_ICER0      *((volatile uint32 *)0xE000E180)/*Clear INTs from 0 to 31*/
#define NVIC_ICER1      *((volatile uint32 *)0xE000E184)/*Clear INTs from 32 to 59*/

#define NVIC_ISPR0      *((volatile uint32 *)0xE000E200)/*Set The Pending flag(For Matter Of Testing and Debugging) from INTs from 0 to 31*/
#define NVIC_ISPR1      *((volatile uint32 *)0xE000E204)/*Set The Pending flag(For Matter Of Testing and Debugging) from INTs from 32 to 59*/

#define NVIC_ICPR0      *((volatile uint32 *)0xE000E280)/*Clear The Pending flag(For Matter Of Testing and Debugging) from INTs from 0 to 31*/
#define NVIC_ICPR1      *((volatile uint32 *)0xE000E284)/*Clear The Pending flag(For Matter Of Testing and Debugging) from INTs from 32 to 59*/

#define NVIC_IABR0      *((volatile uint32 *)0xE000E300)/*Get The Active flag from INTs from 0 to 31*/
#define NVIC_IABR1      *((volatile uint32 *)0xE000E304)/*Get The Active flag from INTs from 32 to 59*/


/*                  Priority Registers                    */
/*Each Interrupt Has 8 bits, so i've defined the register as uint8 to be treated as array  NVIC_IPR[Int_num] and it is without Dereference */
#define NVIC_IPR       ((volatile uint8 *)0xE000E400)
/*                  Register From SCB(System Code Block) Core Peripheral                  */
#define SCB_AIRCR       *((volatile uint32 *)0xE000ED0C)/*Used To Put the Group and sub Priorities*/



/*This Macro passed to MNVIC_voidSetPriorities() .. parameter */
/*Choose The number of Gropus and Sub priorities*/
#define GROUP0_4BITS_SUB_0BITS 0x05FA0300 /* 4 Bits for Group(16) and 0 Bits for sub(0)*/
#define GROUP1_3BITS_SUB_1BITS 0x05FA0400 /* 3 Bits for Group(8)  and 1 Bits for sub(2)*/
#define GROUP2_2BITS_SUB_2BITS 0x05FA0500 /* 2 Bits for Group(4)  and 2 Bits for sub(4)*/
#define GROUP3_1BITS_SUB_3BITS 0x05FA0600 /* 1 Bits for Group(2)  and 3 Bits for sub(8)*/
#define GROUP4_0BITS_SUB_4BITS 0x05FA0700 /* 0 Bits for Group(0)  and 4 Bits for sub(16)*/

/*Macros used with the priority function to avoid the magic numbers, shows the total number in sub and group priorities for each GROUP */
#define GROUP0_GROUP_MAX_NUM 16 
#define GROUP0_SUB_MAX_NUM  0
#define GROUP1_GROUP_MAX_NUM 8 
#define GROUP1_SUB_MAX_NUM 2
#define GROUP2_GROUP_MAX_NUM 4 
#define GROUP2_SUB_MAX_NUM 4
#define GROUP3_GROUP_MAX_NUM 2 
#define GROUP3_SUB_MAX_NUM 8
#define GROUP4_GROUP_MAX_NUM 0
#define GROUP4_SUB_MAX_NUM 16

/*Macros used with the priority function to avoid the magic numbers .. shows the number of bits for the sub priority for each Group*/
#define GROUP0_SUB_PRIORITY_BITS_NUM 0
#define GROUP1_SUB_PRIORITY_BITS_NUM 1
#define GROUP2_SUB_PRIORITY_BITS_NUM 2
#define GROUP3_SUB_PRIORITY_BITS_NUM 3
#define GROUP4_SUB_PRIORITY_BITS_NUM 4

/*Macros used in the priority Function to avoid magic numbers
  Denotes the number of reserved bits in the IPR register for each Interrupt which is 4 bits
*/
#define NVIC_IPR_RESERVED_BITS_NUMBER   4

/*Macros used in the code to avoid Magic Numbers*/
#define NVIC_REGISTER0_LAST_INT_NUM 32
#define NVIC_REGISTER1_LAST_INT_NUM 60



#endif
