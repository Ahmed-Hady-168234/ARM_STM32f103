/**
 * @file EXTI_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the EXTI Driver the User shouldn't see this
 * @version V01
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
 

typedef struct{
    volatile uint32 IMR;        /*10.3.1 Interrupt mask register*/
    volatile uint32 EMR;        /*10.3.2 Event mask register*/
    volatile uint32 RTSR;       /*10.3.3 Rising trigger selection register(Enable/Disable Rising Edge)*/
    volatile uint32 FTSR;       /*10.3.4 Falling trigger selection register(Enable/Disable Falling Edge)*/
    volatile uint32 SWIER;      /*10.3.5 Software interrupt event register*/
    volatile uint32 PR;         /*10.3.6 Pending register*/
}EXTI_t;

/*No Derefrence */
#define EXTI ((volatile EXTI_t*) 0x40010400)



/*CONFIGURATION External interrupt Modes*/
#define EXTI_RISING_MODE        1
#define EXTI_FALLING_MODE       3
#define EXTI_ON_CHANGE_MODE     5



#endif
