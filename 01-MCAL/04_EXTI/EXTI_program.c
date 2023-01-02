/**
 * @file EXTI_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the EXTI Driver Functions for Target stm32f10x
 * @version V02
 * @details Adding MEXTI_voidSetSetCallBack() Function
 * @date 2022-08-03
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_Config.h"
#include "EXTI_private.h"

/*Array of pointer to function used to save the call back function passed by the user*/
void (*CallBackFunc[MAXIMUM_LINES_NUMBER]) (void) = {NULL};


/**
 * @brief This the Initialization Function for EXTI Driver
 * @pre You Should Configure the Driver in first see EXTI_Config.h file
 */
void MEXTI_voidInit(void)
{
#if EXTI_MODE == EXTI_RISING_MODE
    /*Interrupt will happen on Rising Edge*/
    SET_BIT(EXTI -> RTSR, EXTI_LINE);
#elif EXTI_MODE == EXTI_FALLING_MODE
    /*Interrupt will happen on Falling Edge*/
    SET_BIT(EXTI -> FTSR, EXTI_LINE);
#elif EXTI_MODE == EXTI_ON_CHANGE_MODE
    /*Interrupt will happen on Change*/
    SET_BIT(EXTI -> RTSR, EXTI_LINE);/*On rising*/
    SET_BIT(EXTI -> FTSR, EXTI_LINE);/*On falling*/
#else #error "Wrong Mode And Line Choice (Configuration file)"
#endif

    /*Disable the Interrupt to make sure it will not work till calling MEXTI_voidEnableEXTI()*/
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
 * @param Copy_u8Line The line number (Shouldn't Exceed MAXIMUM_LINES_NUMBER)
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
 * @brief Used to change mode for specific line in run time
 * 
 * @param Copy_u8Line The Line number ( from 0 to MAXIMUM_LINES_NUMBER)
 * @param Copy_u8ExtiMode <pre>
 * EXTI Mode in which when the Interrupt will fire
 * options: 
 *      EXTI_RISING_MODE    The Interrupt will fire if there is a rising edge
 *      EXTI_FALLING_MODE   The Interrupt will fire if there is a falling edge
 *      EXTI_ON_CHANGE_MODE The Interrupt will fire if there is a Change in the signal(rising or falling edge) 
 * </pre>
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


/**
 * @brief This function Sets The Call Back Function
 * 
 * @param Copy_ptr Pointer to function.. a call back function to the required function to run when the timer is done
 */
void MEXTI_voidSetSetCallBack(uint8 Copy_u8Line, void (* Copy_voidPtr)(void))
{
    /*Error Handling.. check the ptr != NULL*/
    if (Copy_voidPtr != NULL)
    {
        if (Copy_u8Line < MAXIMUM_LINES_NUMBER)
        {
            CallBackFunc[Copy_u8Line] = Copy_voidPtr;

        }else
        {
            /*The Line Number Shouldn't Exceed MAXIMUM_LINES_NUMBER ... MISRA rules*/

        }
    }else
    {
        /*Error The pointer shouldn't = NULL ... MISRA rules*/
    }
    
}

/************************** Interrupts Handler ***************************/

/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI0_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE0]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE0);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI1_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE1]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE1);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI2_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE2]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE2);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI3_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE3]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE3);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI4_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE4]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE4);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI5_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE5]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE5);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI6_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE6]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE6);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI7_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE7]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE7);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI8_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE8]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE8);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI9_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE9]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE9);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI10_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE10]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE10);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI11_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE11]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE11);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI12_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE12]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE12);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI13_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE13]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE13);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI14_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE14]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE14);
}
/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void EXTI15_IRQHandler(void)
{
    CallBackFunc[EXTI_LINE15]();
    /*This bit is set when the selected edge event arrives on the external interrupt line. This bit is cleared by writing a ‘1’ into the bit.*/
    SET_BIT(EXTI -> PR, EXTI_LINE15);
}


