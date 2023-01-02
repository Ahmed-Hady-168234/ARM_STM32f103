/**
 * @file EXTI_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the EXTI Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-07-23
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_Config.h"
#include "EXTI_private.h"

/**
 * @brief This the Initialization Function for EXTI Driver
 * @pre You Should Configure the Driver in first see EXTI_Config.h file
 */
void MEXTI_voidInit(void)
{
#if EXTI_MODE == EXTI_RISING_MODE
    SET_BIT(EXTI -> RTSR, EXTI_LINE);
#elif EXTI_MODE == EXTI_FALLING_MODE
    SET_BIT(EXTI -> FTSR, EXTI_LINE);
#elif EXTI_MODE == EXTI_ON_CHANGE_MODE
    SET_BIT(EXTI -> RTSR, EXTI_LINE);/*On rising*/
    SET_BIT(EXTI -> FTSR, EXTI_LINE);/*On falling*/
#else #error "Wrong Mode And Line Choice (Configuration file)"
#endif

    /*Disable the Line*/
    CLR_BIT(EXTI -> IMR, EXTI_LINE);
}

/**
 * @brief This Function Enables the required line External interrupt
 * 
 * @param Copy_u8Line The Line number ( from 0 to MAXIMUM_LINES_NUMBER)
 * @pre You Should call MEXTI_voidInit() before calling this function
 * 
 */
void MEXTI_voidEnableEXTI(uint8 Copy_u8Line)
{
    if(Copy_u8Line < MAXIMUM_LINES_NUMBER)
    {
        /*Enable the Line*/
        SET_BIT(EXTI -> IMR, Copy_u8Line);
    }else
    {
        /*Error*/
    }
}

/**
 * @brief This Function Disables the required line External interrupt
 * 
 * @param Copy_u8Line The Line number ( from 0 to MAXIMUM_LINES_NUMBER)
 * @pre You Should call MEXTI_voidInit() before calling this function
 * 
 */
void MEXTI_voidDisableEXTI(uint8 Copy_u8Line)
{
    /*Line should be in range*/
    if(Copy_u8Line < MAXIMUM_LINES_NUMBER)
    {
        /*Disable the Line*/
        CLR_BIT(EXTI -> IMR, Copy_u8Line);
    }else
    {
        /*Error*/
    }
}

/**
 * @brief This function used to create Software Interrupt(used in Debugging and Testing)
 * 
 * @details Creates an SW interrupt by setting the corresponding interrupt bit pending flag
 * 
 * @param Copy_u8Line The line number
 * @pre You Should call MEXTI_voidInit()
 * 
 */
void MEXTI_voidSwTrigger(uint8 Copy_u8Line)
{
    /*Line should be in range*/
    if(Copy_u8Line < MAXIMUM_LINES_NUMBER)
    {
        /*Disable the Line*/
        CLR_BIT(EXTI -> SWIER, Copy_u8Line);
    }else
    {
        /*Error*/
    }
}

/**
 * @brief This Function Enables the required line External interrupt
 * 
 * @param Copy_u8Line The Line number ( from 0 to MAXIMUM_LINES_NUMBER)
 * @pre You Should call MEXTI_voidInit() before calling this function
 * 
 */

/**
 * @brief used to change mode for specific line in run time
 * 
 * @param Copy_u8Line The Line number ( from 0 to MAXIMUM_LINES_NUMBER)
 * @param Copy_u8ExtiMode <pre>
 * EXTI Mode in which when the Interrupt will fire
 * options: 
 *      EXTI_RISING_MODE    The Interrupt will fire if there is a rising edge
 *      EXTI_FALLING_MODE   The Interrupt will fire if there is a falling edge
 *      EXTI_ON_CHANGE_MODE The Interrupt will fire if there is a Change in the signal(rising or falling edge) 
 * </pre>
 * @pre You Should call MEXTI_voidInit() before calling this function
 */
void MEXTI_voidSetSignalLatch(uint8 Copy_u8Line, uint8 Copy_u8ExtiMode)
{
     /*Line should be in range*/
    if(Copy_u8Line < MAXIMUM_LINES_NUMBER)
    {
        /*Check the Mode*/
        switch (EXTI_MODE)
        {
        case EXTI_RISING_MODE:      SET_BIT(EXTI -> RTSR, EXTI_LINE);/*Rising Edge*/ break;
        case EXTI_FALLING_MODE:     SET_BIT(EXTI -> FTSR, EXTI_LINE);/*Falling Edge*/break;
        case EXTI_ON_CHANGE_MODE:   SET_BIT(EXTI -> RTSR, EXTI_LINE);/*On rising*/
                                    SET_BIT(EXTI -> FTSR, EXTI_LINE);/*On falling*/  break;   
        default:
            break;
        }
    }else
    {
        /*Error*/
    }
    
    
}