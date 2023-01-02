/**
 * @file SysTick_Config.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Configuration for the SysTick Driver(User Should see and modify if needed)
 * @version V01
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef SysTick_CONFIG_H
#define SysTick_CONFIG_H

/*
    Choose the Clock Source
    options:    
        SYSTICK_AHB                 (Select the AHB   Clock as source)
        SYSTICK_AHB_DIV_BY_8        (Select the AHB/8 Clock as source)
*/
#define SYSTICK_CLOCK_SOURCE SYSTICK_AHB_DIV_BY_8

/*
    What you want to Happen when the Timer finish?
    options:   
        FIRE_INTERRUPT          
        SET_FLAG
*/
#define SYSTICK_TIMER_FINISH_NOTIFICATION FIRE_INTERRUPT


/*To calculate when the Timer will finish, use this Equation
    OverFlowTime = CountValue * 1/SYSTICK_CLOCK_SOURCE
    
    For Example if you select AHB/8 and if AHB is using HSE_crystal with 8MHZ
    and CountValue = 1000
    then SYSTICK_CLOCK_SOURCE = 8/8 = 1MHZ
    and OverFlowTime = 1000 * 1/1MHZ = 1000 * 1us = 1ms

    so the timer will finish after 1 milli second
*/
#endif