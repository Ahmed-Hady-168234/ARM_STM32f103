/**
 * @file SysTick_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the SysTick Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-07-29
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "SysTick_private.h"
#include "SysTick_interface.h"
#include "SysTick_Config.h"

/*Variable used to save the call back function passed by the user*/
void (*CallBackFunc) (void);

/*isIntervalSingle Flag 1 if the running timer is Interval single(Run one)
                        0 if the running timer is Interval single(Run Multiple Times)*/
uint8 isIntervalSingle;

/**
 * @brief Initializes the Driver
 * @pre Set The configuration ... file SysTick_Config.h
 */
void MSysTick_voidInit(void)
{

#if   SYSTICK_CLOCK_SOURCE == SYSTICK_AHB 
    /*Set AHB Clock Source as the timer Clock Source*/
    SET_BIT(STK_CTRL,STK_CTRL_CLKSOURCE);
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV_BY_8
    /*Set AHB Clock Source as the timer Clock Source*/
    CLR_BIT(STK_CTRL,STK_CTRL_CLKSOURCE);
#else
    #error("Worng Configurations");
#endif
}

/**
 * @brief This Function acts like function dealy(), it waits(Stucks) till the ticks finishes
 * 
 * @param Copy_u32Ticks Number Of Ticks To wait
 * @pre You Should Call the MSysTick_voidInit() in first
 * @return <pre><b>
 *  SysTick_returnType... 
 * return options
 *      SYSTICK_OK the >> function successfully finished the work with .. no errors and the call Back Function will be called when the timer is done
 *      SYSTICK_ANOTHER_TIMER_IS_RUNNING >> there is another running timer .. error
 *      SYSTICK_TICKS_EXCEEDED_MAX_VALUE >> The input Ticks value Exceeded MAXIMUM_COUNT_VALUE (2^24)
 * </b></pre>
 */
SysTick_returnType MSysTick_voidSetBusyWait(uint32 Copy_u32Ticks)
{
    /*SysTick Return Type*/
    SysTick_returnType Local_sysTickReturn = SYSTICK_OK;

    /*Check if the Ticks didn't Exced the MAXIMUM_COUNT_VALUE*/
    if(Copy_u32Ticks <= MAXIMUM_COUNT_VALUE )
    {
        /*Check if there is any Timer Is Running*/
        if (STK_VAL == 0)
        {
            /*Disable The Interrupt*/
            CLR_BIT(STK_CTRL,STK_CTRL_TICKINT);
            /*Set the Count Value*/
            STK_LOAD = Copy_u32Ticks;
            /*Let the Counter start*/
            SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
            /* Wait till The Ticks Finishes */
            while (GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG) == 0);
        }else
        {
            /*Set the return as error*/
            Local_sysTickReturn = SYSTICK_ANOTHER_TIMER_IS_RUNNING;
        }
    }else
    {
        /*MISRA rules*/
        /*Set the return as error*/
        Local_sysTickReturn = SYSTICK_TICKS_EXCEEDED_MAX_VALUE;
    }

    return Local_sysTickReturn;
}

/**
 * @brief This Function Sets a timer for one time call back the functions when the timer is done
 * @param Copy_u32Ticks Number of counts That the timer will work on
 * @param Copy_ptr Pointer to function.. a call back function to the required function to run when the timer is done
 * @return <pre><b>
 *  SysTick_returnType... 
 * return options
 *      SYSTICK_OK the >> function successfully finished the work with .. no errors and the call Back Function will be called when the timer is done
 *      SYSTICK_ANOTHER_TIMER_IS_RUNNING >> there is another running timer .. error
 *      SYSTICK_NULL_POINTER >> The pointer to function is NULL
 * </b></pre>
 * @pre You Should Call the MSysTick_voidInit() in first
 */
SysTick_returnType MSysTick_voidSetIntervalSingle(uint32 Copy_u32Ticks, void (*Copy_ptr)(void) )/*ASynchronous Function */
{
    /*SysTick Return Type*/
    SysTick_returnType Local_sysTickReturn = SYSTICK_OK;
    /*Error Handling.. check the ptr != NULL*/
    if (Copy_ptr != NULL)
    {
        /*Check if there is any Timer Is Running*/
        if (STK_VAL == 0)
        {
            /*Enable The Interrupt*/
            SET_BIT(STK_CTRL,STK_CTRL_TICKINT);
            /*Set the Count Value*/
            STK_LOAD = Copy_u32Ticks;
            /*Set The Interval Flag as single(Timer Run One time)*/
            isIntervalSingle = TRUE;
            /*Let the Counter start*/
            SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
            /*Save the pointer to function to call in the ISR*/
            CallBackFunc = Copy_ptr;
        }else
        {
            /*Set the return as error*/
            Local_sysTickReturn = SYSTICK_ANOTHER_TIMER_IS_RUNNING;
        }
    }else
    {
        /*MISRA rules*/
        /*Set the return as error*/
        Local_sysTickReturn = SYSTICK_NULL_POINTER;
    }
    return Local_sysTickReturn;
}

/**
 * @brief This is the ISR... SysTick Interrupt Handler.. used to call the call back function, used in side this file only
 */
void SysTick_Handler(void)
{
    /*Check if there is any CallBackFunc*/
    if (CallBackFunc != NULL)
    {
       	CallBackFunc();
        CallBackFunc = NULL;

        /*Check if the Timer is Interval Single(Run one time)*/
        if (isIntervalSingle == TRUE)
        {
            /*Don't Repeat the Timer*/
            MSysTick_voidStopInterval();
        }else
        {
            /*Do Nothing ... MISRA rules*/
        }
    }else
    {
        /*Do Nothing ... MISRA rules*/
    }
    
}

/**
 * @brief This Function Sets a timer for Multiple times call back the functions when the timer is done
 * @param Copy_u32Ticks Number of counts That the timer will work on
 * @param Copy_ptr Pointer to function.. a call back function to the required function to run when the timer is done
 * @return <pre><b>
 *  SysTick_returnType... 
 * return options
 *      SYSTICK_OK the >> function successfully finished the work with .. no errors and the call Back Function will be called when the timer is done
 *      SYSTICK_ANOTHER_TIMER_IS_RUNNING >> there is another running timer .. error
 *      SYSTICK_NULL_POINTER >> The pointer to function is NULL
 * </b></pre>
 * @pre You Should Call the MSysTick_voidInit() in first
 */
SysTick_returnType MSysTick_voidSetIntervalPeriodic(uint32 Copy_u32Ticks, void (*Copy_ptr)(void) )/*ASynchronous Function */
{
    /*SysTick Return Type*/
    SysTick_returnType Local_sysTickReturn = SYSTICK_OK;
    /*Error Handling.. check the ptr != NULL*/
    if (Copy_ptr != NULL)
    {
        /*Check if there is any Timer Is Running*/
        if (STK_VAL == 0)
        {
            /*Enable The Interrupt*/
            SET_BIT(STK_CTRL,STK_CTRL_TICKINT);
            /*Set the Count Value*/
            STK_LOAD = Copy_u32Ticks;
            /*Set The Interval Flag as Periodic(Timer Run Multiple times)*/
            isIntervalSingle = FALSE;
            /*Let the Counter start*/
            SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
            /*Save the pointer to function to call in the ISR*/
            CallBackFunc = Copy_ptr;
        }else
        {
            /*Set the return as error*/
            Local_sysTickReturn = SYSTICK_ANOTHER_TIMER_IS_RUNNING;
        }
    }else
    {
        /*MISRA rules*/
        /*Set the return as error*/
        Local_sysTickReturn = SYSTICK_NULL_POINTER;
    }
    return Local_sysTickReturn;
}

/**
 * @brief This Function Stops the Timer
 * 
 */
void MSysTick_voidStopInterval(void)
{
    /*Writing zeros will stop the counter*/
    STK_VAL  = 0;
    STK_LOAD = 0;
}

/**
 * @brief This Function gets the Elapsed Time (total time minus the remaining time)
 * 
 * @return uint32 Denotes the total amount of elapsed time or ticks
 */
uint32 MSysTick_u32GetElapsedTime(void)
{
    /*Variable to return*/
    uint32 Local_elapsedTime;
    /*The Elapsed Time is total time minus the remaining time*/
    Local_elapsedTime = STK_LOAD - STK_VAL;

    return Local_elapsedTime;
}
/**
 * @brief 
 * 
 * @return uint32 Denotes the total amount of time or ticks
 */
uint32 MSysTick_u32GetRemainingTime(void)
{
    /*The remaining time is in STK_VAL*/
    return STK_VAL;
}