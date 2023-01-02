/**
 * @file EXTI_Config.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Configuration for the EXTI Driver(User Should see and modify if needed)
 * @version V01
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/*
    Select The External Interrupt Line 
        options:    EXTI_LINE0      
                    EXTI_LINE1      
                    EXTI_LINE2      
                    .
                    .
                    .
                    EXTI_LINE15      
*/
#define EXTI_LINE   EXTI_LINE0

/*
    Select The External Interrupt Mode
        Options:    EXTI_RISING_MODE        
                    EXTI_FALLING_MODE       
                    EXTI_ON_CHANGE_MODE
*/
#define EXTI_MODE   EXTI_RISING_MODE

#endif