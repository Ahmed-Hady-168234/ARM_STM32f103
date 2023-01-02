/**
 * @file NVIC_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the NVIC Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-07-20
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_Config.h"
#include "NVIC_private.h"

/**
 * @brief This Function Enables a specific Interrupt from 0 to 59
 * 
 * @param Copy_u8IntNumber The Interrupt number (from 0 to 59)
 */
void MNVIC_voidEnableInterrupt(uint8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber < NVIC_REGISTER0_LAST_INT_NUM)
    {
        /*Enable the required Intterupt*/
        /**Note That: Writing 0 has no Effect ... so in matter of time optmization i didn't use SET_BIT() function*/
        NVIC_ISER0 = 1<< Copy_u8IntNumber;

    }else if (Copy_u8IntNumber < NVIC_REGISTER1_LAST_INT_NUM)
    {
        /*Copy_u8IntNumber is num between 32 to 59 so we should map them to be in the range (from, 0 to 27)*/
        Copy_u8IntNumber = Copy_u8IntNumber - NVIC_REGISTER0_LAST_INT_NUM;
        /*Enable the required Intterupt*/
        NVIC_ISER1 = 1<< Copy_u8IntNumber;

    }else
    {
        /*Error*/
    }
    
}

/**
 * @brief This Function Disables a specific Interrupt from 0 to 59
 * 
 * @param Copy_u8IntNumber The Interrupt number (from 0 to 59)
 */
void MNVIC_voidDisableInterrupt(uint8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber < NVIC_REGISTER0_LAST_INT_NUM)
    {
        /*Disable the required Intterupt*/
        /**Note That: Writing 0 has no Effect ... so in matter of time optmization i didn't use SET_BIT() function*/
        NVIC_ICER0 = 1<< Copy_u8IntNumber;

    }else if (Copy_u8IntNumber < NVIC_REGISTER1_LAST_INT_NUM)
    {
        /*Copy_u8IntNumber is num between 32 to 59 so we should map them to be in the range (from, 0 to 27)*/
        Copy_u8IntNumber = Copy_u8IntNumber - NVIC_REGISTER0_LAST_INT_NUM;
        /*Disable the required Intterupt*/
        NVIC_ICER1 = 1<< Copy_u8IntNumber;

    }else
    {
        /*Error*/
    }
    
}


/**
 * @brief This Function Sets the Pending flag(For Matter Of Testing and Debugging) a specific Interrupt from 0 to 59
 * 
 * @param Copy_u8IntNumber The Interrupt number (from 0 to 59)
 */
void MNVIC_voidSetPendingFlag(uint8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber < NVIC_REGISTER0_LAST_INT_NUM)
    {
        /*Set the pending flag of the required Intterupt*/
        /**Note That: Writing 0 has no Effect ... so in matter of time optmization i didn't use SET_BIT() function*/
        NVIC_ISPR0 = 1<< Copy_u8IntNumber;
    }else if (Copy_u8IntNumber < NVIC_REGISTER1_LAST_INT_NUM)
    {
        /*Copy_u8IntNumber is num between 32 to 59 so we should map them to be in the range (from, 0 to 27)*/
        Copy_u8IntNumber = Copy_u8IntNumber - NVIC_REGISTER0_LAST_INT_NUM;
        /*Set the pending flag of the required Intterupt*/
        NVIC_ISPR1 = 1<< Copy_u8IntNumber;
    }else
    {
        /*Error*/
    }
    
}

/**
 * @brief This Function Clear the Pending flag of a specific Interrupt from 0 to 59
 * 
 * @param Copy_u8IntNumber The Interrupt number (from 0 to 59)
 */
void MNVIC_voidClearPendingFlag(uint8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber < NVIC_REGISTER0_LAST_INT_NUM)
    {
        /*Set the pending flag of the required Intterupt*/
        /**Note That: Writing 0 has no Effect ... so in matter of time optmization i didn't use SET_BIT() function*/
        NVIC_ICPR0 = 1<< Copy_u8IntNumber;
    }else if (Copy_u8IntNumber < NVIC_REGISTER1_LAST_INT_NUM)
    {
        /*Copy_u8IntNumber is num between 32 to 59 so we should map them to be in the range (from, 0 to 27)*/
        Copy_u8IntNumber = Copy_u8IntNumber - NVIC_REGISTER0_LAST_INT_NUM;
        /*Set the pending flag of the required Intterupt*/
        NVIC_ICPR1 = 1<< Copy_u8IntNumber;
    }else
    {
        /*Error*/
    }
    
}


/**
 * @brief This Function Gets the Active Flag of a specific Interrupt from 0 to 59
 * 
 * @param Copy_u8IntNumber The Interrupt number (from 0 to 59)
 * @return <pre>
 *uint8 represents the Active flag 
    0 means the INT is not Active
    1 means the INT is Active
    2 means input invalid
 */
uint8 MNVIC_u8GetActiveFlag(uint8 Copy_u8IntNumber)
{
    uint8 Loc_u8Result ;
    if(Copy_u8IntNumber < NVIC_REGISTER0_LAST_INT_NUM)
    {
        
        /*Get The Active Flag of the required Intterupt*/
        Loc_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
    }else if (Copy_u8IntNumber < NVIC_REGISTER1_LAST_INT_NUM)
    {
        /*Copy_u8IntNumber is num between 32 to 59 so we should map them to be in the range (from, 0 to 27)*/
        Copy_u8IntNumber = Copy_u8IntNumber - NVIC_REGISTER0_LAST_INT_NUM;
        /*Get The Active Flag of the required Intterupt*/
        Loc_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);

    }else
    {
        /*Error*/
        Loc_u8Result = 2;
    }
    
    return Loc_u8Result;

} 


/**
 * @brief This Function Sets the Group Priority and the sub priority for a specific Interrupt
 * 
 * @param Copy_s8InterruptID   The Interrupt number(Acording to the Vector table see Table 63. STM32F10 register description file page 204, 205, 206)
 * @param Copy_u8GroupPriority The Group priority for the required Interrupt
 * @param Copy_u8SubPriority   The sub   priority for the required Interrupt
 * 
 * @pre You should configure the Group and Sub priorities number, see NVIC_Config.h
 */
void MNVIC_voidSetPriorities(sint8 Copy_s8InterruptID, uint8 Copy_u8GroupPriority, uint8 Copy_u8SubPriority )
{
   /*Check if the interrupt is a Core Peripheral or External Peripheral*/
   /*Internal Interrupt*/
   if (Copy_s8InterruptID < 0)
   {
    /* code */
   }
   /*External Peripheral*/
   else if (Copy_s8InterruptID >= 0)
   {
        switch (NO_OF_GROUPS_AND_SUB_PRIORITIES)
        {
        case GROUP0_4BITS_SUB_0BITS:
            /*4 Bits for Group(16) and 0 Bits for sub(0)*/
            if (Copy_u8GroupPriority < GROUP0_GROUP_MAX_NUM)        /*Error Handling*/
            {
                /*No left shifting .. all the 4 bits for the group priority*/
                NVIC_IPR[Copy_s8InterruptID] = Copy_u8GroupPriority;
            }else
            {
                /*Error*/
            }         
            break;
        case GROUP1_3BITS_SUB_1BITS:/*3 Bits for Group(8)  and 1 Bits for sub(2)*/
            if (Copy_u8GroupPriority < GROUP1_GROUP_MAX_NUM && Copy_u8SubPriority < GROUP1_SUB_MAX_NUM)        /*Error Handling*/
            {
                /*Shift left by 1 (The number of sub priority bits) and then add the subpriority to the result*/
                /*left 3 bits for the group priority and the next 1 bit for the sub priority*/
                NVIC_IPR[Copy_s8InterruptID] =  Copy_u8SubPriority | (Copy_u8GroupPriority<<GROUP1_SUB_PRIORITY_BITS_NUM);
            }else
            {
                /*Error*/
            }            
            break;
        case GROUP2_2BITS_SUB_2BITS:/*2 Bits for Group(4)  and 2 Bits for sub(4)*/
            if (Copy_u8GroupPriority < GROUP2_GROUP_MAX_NUM && Copy_u8SubPriority < GROUP2_SUB_MAX_NUM)        /*Error Handling*/
            {
                /*Shift left by 2 (The number of sub priority bits) and then add the subpriority to the result*/
                /*left 2 bits for the group priority and the next 2 bits for the sub priority*/
                NVIC_IPR[Copy_s8InterruptID] =  Copy_u8SubPriority | (Copy_u8GroupPriority<<GROUP2_SUB_PRIORITY_BITS_NUM);
            }else
            {
                /*Error*/
            } 
            break;
        case GROUP3_1BITS_SUB_3BITS:/*1 Bits for Group(2)  and 3 Bits for sub(8)*/
            if (Copy_u8GroupPriority < GROUP3_GROUP_MAX_NUM && Copy_u8SubPriority < GROUP3_SUB_MAX_NUM)        /*Error Handling*/
            {
                /*Shift left by 3 (The number of sub priority bits) and then add the subpriority to the result*/
                /*left 1 bit for the group priority and the next 3 bits for the sub priority*/
                NVIC_IPR[Copy_s8InterruptID] =  Copy_u8SubPriority | (Copy_u8GroupPriority<<GROUP3_SUB_PRIORITY_BITS_NUM);
            }else
            {
                /*Error*/
            }             
            break;
        case GROUP4_0BITS_SUB_4BITS:/*0 Bits for Group(0)  and 4 Bits for sub(16)*/
            if (Copy_u8SubPriority < GROUP4_SUB_MAX_NUM)        /*Error Handling*/
            {
                /*No left shifting .. all the 4 bits for the sub priority*/
                NVIC_IPR[Copy_s8InterruptID] = Copy_u8SubPriority;
            }else
            {
                /*Error*/
            }             
            break;
        
        default:
            /*Error*/
            break;
        }
        /*Set the Configuration for the group and sub priorities to the SCB_AIRCR*/
        SCB_AIRCR = NO_OF_GROUPS_AND_SUB_PRIORITIES;

   }
   

} 