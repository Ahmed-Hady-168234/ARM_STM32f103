/**
 * @file SysTick_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the SysTick Driver the User shouldn't see this
 * @version V01
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef SysTick_PRIVATE_H
#define SysTick_PRIVATE_H


/*Base Address 0xE000E010*/

/*SysTick Registers*/
#define STK_CTRL        *((volatile uint32*)0xE000E010)   
#define STK_LOAD        *((volatile uint32*)0xE000E014)   
#define STK_VAL         *((volatile uint32*)0xE000E018)   
#define STK_CALIB       *((volatile uint32*)0xE000E01C)   


/*Macros for selecting the clock source*/
#define SYSTICK_AHB          0
#define SYSTICK_AHB_DIV_BY_8 1

/*Macros for what will happen when the Timer is done Configuration */
#define FIRE_INTERRUPT 0
#define SET_FLAG       1

/*STK_CTRL Register bit Numbers (used to avoid Magic Numbers)*/
#define STK_CTRL_ENABLE     0
#define STK_CTRL_TICKINT    1
#define STK_CTRL_CLKSOURCE  2   
#define STK_CTRL_COUNTFLAG  16

/*Maximum Number that can be set to STK_LOAD
  STK_LOAD is 24 bits ... 2^24 bits = 16777216*/
#define MAXIMUM_COUNT_VALUE 16777216

/*SysTick Return Type used in the*/
typedef uint8 SysTick_returnType;

#endif
