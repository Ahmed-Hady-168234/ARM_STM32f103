/**
 * @file NVIC_Config.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Configuration for the NVIC Driver(User Should see and modify if needed)
 * @version V01
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/**Select The Number of Groups and sub Priorities
    options:
    
            GROUP0_4BITS_SUB_0BITS  >> 4 Bits for Group(16) and 0 Bits for sub(0)
            GROUP1_3BITS_SUB_1BITS  >> 3 Bits for Group(8)  and 1 Bits for sub(2)
            GROUP2_2BITS_SUB_2BITS  >> 2 Bits for Group(4)  and 2 Bits for sub(4)
            GROUP3_1BITS_SUB_3BITS  >> 1 Bits for Group(2)  and 3 Bits for sub(8)
            GROUP4_0BITS_SUB_4BITS  >> 0 Bits for Group(0)  and 4 Bits for sub(16)
*/
#define			NO_OF_GROUPS_AND_SUB_PRIORITIES		GROUP0_4BITS_SUB_0BITS



#endif