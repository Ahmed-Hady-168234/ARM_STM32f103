/**
 * @file RCC_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the RCC Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-07-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
 

/**
 * @brief This Function Enables The clock of specified peripheral on it's bus
 * 
 * @param Copy_u8BusId the bus ID .. options(RCC_AHB, RCC_APB1, RCC_APB2)
 * @param Copy_u8PerId the peripheral ID .. options(for example porta, portb, portc , uart, adc, ......, etc)
 * @pre You should Call RCC_voidInitSysClock() in first
 */
void RCC_voidEnableClock(uint8 Copy_u8BusId, uint8 Copy_u8PerId){
    /**Check the length*/
    if (Copy_u8PerId < 32 )
    {
        
        /**which bus ?*/
        switch (Copy_u8BusId)
        {
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_u8PerId);
            break;
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_u8PerId);
            break;
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_u8PerId);
            break;  
        /*
        default: Return Error break;
        */
        }        
    }else{
        /** Return Error*/
    }
}

/**
 * @brief This Function Disables The clock of specified peripheral on it's bus
 * 
 * @param Copy_u8BusId the bus ID .. options(RCC_AHB, RCC_APB1, RCC_APB2)
 * @param Copy_u8PerId the peripheral ID .. options(for example porta, portb, portc , uart, adc, ......, etc)
 * @pre You should Call RCC_voidInitSysClock() in first
 */
void RCC_voidDisableClock(uint8 Copy_u8BusId, uint8 Copy_u8PerId){
    /**Check the length*/
    if (Copy_u8PerId < 32 )
    {
        /**which bus ?*/
        switch (Copy_u8BusId)
        {
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_u8PerId);
              
            break;
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_u8PerId);
            break;
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_u8PerId);
            break;
        
        /*
        default: Return Error break;
        */
        }
        
    }else{
        /** Return Error*/
    }
    
}


/**
 * @brief This Function initializes the RCC driver.
 * @pre You Should Modify the configuratio file in first... see RCC_config.h
 * 
 */
void RCC_voidInitSysClock(void){



#if RCC_SYS_Clock == RCC_HSE_Crystal

    RCC_CR   = 0x00010000;/*Enable HSE with no bypass*/
    RCC_CFGR = 0x00000001;

#elif RCC_SYS_Clock == RCC_HSE_RC
    RCC_CR   = 0x00050000;/*Enable HSE with bypass*/
    RCC_CFGR = 0x00000001;
    
#elif RCC_SYS_Clock == RCC_HSI
    /*SET_BIT(RCC_CR, HSION);*/

    RCC_CR   = 0x00000081;/*Enable HSE with no bypass*/
    RCC_CFGR = 0x00000000;
#elif RCC_SYS_Clock == RCC_PLL
    /*The Multiplier should be between RCC_PLL_MIN_MU and RCC_PLL_MAX_MULL*/
    if (RCC_PLL_MUL >= RCC_PLL_MIN_MUL
    &&  RCC_PLL_MUL <= RCC_PLL_MAX_MUL)
    {   
        /*clear the PLL bits*/
        RCC_CFGR &= RCC_PLL_CLR_MASk; 

        /**Step1 choose the PLL's input (HSI/2, HSE/2, HSE)*/

        #if RCC_PLL_INPUT == HSI2
            SET_BIT(RCC_CR, HSION);/*Enable HSI*/
            
            CLR_BIT(RCC_CFGR, PLLSRC);/*take HSI/2 as input*/

        #elif RCC_PLL_INPUT == HSE2
            SET_BIT(RCC_CR, HSEON);/*Enable HSE*/
            
            SET_BIT(RCC_CFGR, PLLSRC); /*take HSE as input*/
            SET_BIT(RCC_CFGR, PLLXTPRE);/*Divide HSE by 2*/

        #elif RCC_PLL_INPUT == HSE
            SET_BIT(RCC_CR, HSEON);/*Enable HSE*/

            SET_BIT(RCC_CFGR, PLLSRC);/*take HSI as input*/
            CLR_BIT(RCC_CFGR, PLLXTPRE);/*Don't Divide HSI */

        #else
            /*
            Return Error (wrong Choose of the pll input)
            */
        #endif


        
        /**Step2 put the multiplier bits.... note that the start bit is 2 not 0*/
        RCC_CFGR |= ((RCC_PLL_MUL-2)<<RCC_PLL_MUL_START_BIT);
        

        /**Step3 Enable PLL*/
        SET_BIT(RCC_CR, PLLON);
    }
    

#else
    /*Return error*/
#endif

}
