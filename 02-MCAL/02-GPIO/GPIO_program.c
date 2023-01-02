/**
 * @file GPIO_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the GPIO Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-07-15
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#define CLR_PIN_MODE(REG,PIN_NUMBER)  REG &= ~( (0b1111)<<(PIN_NUMBER*4) )
#define SET_PIN_MODE(REG,PIN_NUMBER, PIN_MODE)  REG |= ( (PIN_MODE)<<(PIN_NUMBER*4) )

/**
 * @brief This Function Sets the Pin Mode
 * 
 * @param copy_u8PORT Refereces to the port .. options(GPIOA, GPIOB, GPIOC)
 * @param copy_u8PIN Pin Number ... options(PIN0, PIN1, ....., PIN15)
 * @param copy_u8Mode PiN Mode ... options(see GPIO Mode Options section in the  GPIO_interface.h file)
 * @pre you should Enable the peripheral clock in first (see RCC Driver)
 */
void GPIO_voidSetPinDirection(uint8 copy_u8PORT, uint8 copy_u8PIN, uint8 copy_u8Mode)
{

    /**Error Handling*/
    /*The port should be between A and G */
    if (copy_u8PORT > GPIOC)
    {
        /*Send ERROR */
    }
    /*Check The pin number is withing the range or not(from 0 to 15)*/
    else if(copy_u8PIN >= LAST_CRH_PINS_NUMBER)
    {
        /*Send ERROR */        
    }else
    {
        /*Everything is correct ... keep going*/
    
        /*Check The port*/
        switch (copy_u8PORT)
        {
        case GPIOA:
            /*Check if the required pin is in CRL register*/
            if (copy_u8PIN < LAST_CRL_PINS_NUMBER)
            {
                /*Clear The Pin Bits in first to clear the mode*/
                CLR_PIN_MODE(GPIOA_CRL, copy_u8PIN);
                /*Then Set the new Mode*/
                SET_PIN_MODE(GPIOA_CRL, copy_u8PIN, copy_u8Mode);
            }
            /*Check if the required pin is in CRH register*/
            else if(copy_u8PIN < LAST_CRH_PINS_NUMBER)
            {
                /*The pins in the CRH is from 8 to 15 .... but it is needed to start from 0 to 7 so we delete 8 */
                copy_u8PIN = copy_u8PIN - LAST_CRL_PINS_NUMBER;
                /*Clear The Pin Bits in first to clear the mode*/
                CLR_PIN_MODE(GPIOA_CRH, copy_u8PIN);
                /*Then Set the new Mode*/
                SET_PIN_MODE(GPIOA_CRH, copy_u8PIN, copy_u8Mode);
            }else
            {
                /*Pin number out of range (ERROR)*/
            }
            
            break;
        
        case GPIOB:
            /*Check if the required pin is in CRL register*/
            if (copy_u8PIN < LAST_CRL_PINS_NUMBER)
            {
                /*Clear The Pin Bits in first to clear the mode*/
                CLR_PIN_MODE(GPIOB_CRL, copy_u8PIN);
                /*Then Set the new Mode*/
                SET_PIN_MODE(GPIOB_CRL, copy_u8PIN, copy_u8Mode);
            }
            /*Check if the required pin is in CRH register*/
            else if(copy_u8PIN < LAST_CRH_PINS_NUMBER)
            {
                /*The pins in the CRH is from 8 to 15 .... but it is needed to start from 0 to 7 so we delete 8 */
                copy_u8PIN = copy_u8PIN - LAST_CRL_PINS_NUMBER;
                /*Clear The Pin Bits in first to clear the mode*/
                CLR_PIN_MODE(GPIOB_CRH, copy_u8PIN);
                /*Then Set the new Mode*/
                SET_PIN_MODE(GPIOB_CRH, copy_u8PIN, copy_u8Mode);
            }else
            {
                /*Pin number out of range (ERROR)*/
            }
            
            break;
        
        case GPIOC:
            /*Check if the required pin is in CRL register*/
            if (copy_u8PIN < LAST_CRL_PINS_NUMBER)
            {
                /*Clear The Pin Bits in first to clear the mode*/
                CLR_PIN_MODE(GPIOC_CRL, copy_u8PIN);
                /*Then Set the new Mode*/
                SET_PIN_MODE(GPIOC_CRL, copy_u8PIN, copy_u8Mode);
            }
            /*Check if the required pin is in CRH register*/
            else if(copy_u8PIN < LAST_CRH_PINS_NUMBER)
            {
                /*The pins in the CRH is from 8 to 15 ... but it is needed to start from 0 to 7 so we delete 8 */
                copy_u8PIN = copy_u8PIN - LAST_CRL_PINS_NUMBER;
                /*Clear The Pin Bits in first to clear the mode*/
                CLR_PIN_MODE(GPIOC_CRH, copy_u8PIN);
                /*Then Set the new Mode*/
                SET_PIN_MODE(GPIOC_CRH, copy_u8PIN, copy_u8Mode);
            }else
            {
                /*Pin number out of range (ERROR)*/
            }
            
            break;
        
        
        default:
            /*Error*/
            break;
        }
    }
}

/**
 * @brief This Function Sets the Pin value
 * 
 * @param copy_u8PORT Refereces to the port .. options(GPIOA, GPIOB, GPIOC)
 * @param copy_u8PIN Pin Number ... options(PIN0, PIN1, ....., PIN15)
 * @param copy_u8Value value that should be applied to the required pin
 * @pre You should Call GPIO_voidSetPinDirection() in first
 * @details<pre> Please Note that
 *      In <b>GPIOx_BSRR</b> regsiter(From bit 0 to 15) puting
 *          0: No action on the corresponding ODRx bit(Pin)
 *          1: Set the corresponding ODRx bit(Pin)
 *  
 *      In <b>GPIOx_BRR</b> regsiter(From bit 0 to 15) puting
 *          0: No action on the corresponding ODRx bit(Pin)
 *          1: Reset the corresponding ODRx bit(Pin)
 * </pre>
 */
void GPIO_voidSetPinValue(uint8 copy_u8PORT, uint8 copy_u8PIN, uint8 copy_u8Value)
{
    /**Error Handling*/
    /*The port should be between A and C */
    if (copy_u8PORT > GPIOC)
    {
        /*Send ERROR */
    }
    /*Check The pin number is withing the range or not(from 0 to 15)*/
    else if(copy_u8PIN >= LAST_CRH_PINS_NUMBER)
    {
        /*Send ERROR */        
    }else
    {
        /*Everything is correct ... keep going*/

        /*Check The port*/
        switch (copy_u8PORT)
        {
        case GPIOA:
            /*Is Value HIGH?*/
            if (copy_u8Value == GPIO_HIGH)
            {
                /*Set The Pin to HIGH*/
                /*SET_BIT(GPIOA_ODR, copy_u8PIN);*/
                GPIOA_BSRR = 1<< copy_u8PIN;
            }
            /*Is Value LOW?*/
            else if(copy_u8Value == GPIO_LOW)
            {
                /*Set The Pin to LOW*/
               /* CLR_BIT(GPIOA_ODR, copy_u8PIN);*/
                GPIOA_BRR = 1<< copy_u8PIN;

            }else
            {
                /*value should be HIGH or LOW .... send Error*/
            }
            break;
        
        case GPIOB:
            /*Is Value HIGH?*/
            if (copy_u8Value == GPIO_HIGH)
            {
                /*Set The Pin to HIGH*/
                /*SET_BIT(GPIOB_ODR, copy_u8PIN);*/
                GPIOB_BSRR = 1<< copy_u8PIN;
            }
            /*Is Value LOW?*/
            else if(copy_u8Value == GPIO_LOW)
            {
                /*Set The Pin to LOW*/
               /* CLR_BIT(GPIOB_ODR, copy_u8PIN);*/
                GPIOB_BRR = 1<< copy_u8PIN;

            }else
            {
                /*value should be HIGH or LOW .... send Error*/
            }
            break;
        
        case GPIOC:
            /*Is Value HIGH?*/
            if (copy_u8Value == GPIO_HIGH)
            {
                /*Set The Pin to HIGH*/
                /*SET_BIT(GPIOC_ODR, copy_u8PIN);*/
                GPIOC_BSRR = 1<< copy_u8PIN;
            }
            /*Is Value LOW?*/
            else if(copy_u8Value == GPIO_LOW)
            {
                /*Set The Pin to LOW*/
               /* CLR_BIT(GPIOC_ODR, copy_u8PIN);*/
                GPIOC_BRR = 1<< copy_u8PIN;

            }else
            {
                /*value should be HIGH or LOW .... send Error*/
            }
            break;

        default:
            /*Error*/
            break;
        }
    }
}

/**
 * @brief 
 * 
 * @param copy_u8PORT Refereces to the port .. options(GPIOA, GPIOB, GPIOC)
 * @param copy_u8PIN Pin Number ... options(PIN0, PIN1, ....., PIN15)
 * @pre You should Call GPIO_voidSetPinDirection() in first
 * @return uint8 that represents the Pin's Value
 */
uint8 GPIO_voidGetPinValue(uint8 copy_u8PORT, uint8 copy_u8PIN)
{
    /*Variable to return*/
	uint8 Loc_u8Result = 0;
    /*Error Handling*/
    /*The port should be between A and G */
    if (copy_u8PORT > GPIOG)
    {
        /*Send ERROR */
    }
    /*Check The pin number is within the range or not(from 0 to 15)*/
    else if(copy_u8PIN >= LAST_CRH_PINS_NUMBER)
    {
        /*Send ERROR */
    }else
    {
        /*Everything is correct ... keep going*/

        /*Check The port*/
        switch (copy_u8PORT)
        {
        case GPIOA:
            /*GET The Pin to HIGH*/
            Loc_u8Result = GET_BIT(GPIOA_IDR, copy_u8PIN);
            break;

        case GPIOB:
            /*GET The Pin to Value*/
            Loc_u8Result = GET_BIT(GPIOB_IDR, copy_u8PIN);
            break;

        case GPIOC:
            /*GET The Pin to Value*/
            Loc_u8Result = GET_BIT(GPIOC_IDR, copy_u8PIN);
            break;

        default:
            /*Error*/
            break;
        }
    }
    return Loc_u8Result;
}

/**
 * @brief This function Locks a specific pin (Can't change its Mode anymore)
 * 
 * @param copy_u8PORT Refereces to the port .. options(GPIOA, GPIOB, GPIOC)
 * @param copy_u8PIN Pin Number ... options(PIN0, PIN1, ....., PIN15)
 * @details This Function Locks a specific Pin so that no one Can Change the mode of that pin anymore
 */
void GPIO_voidLockByPinNum(uint8 copy_u8PORT, uint8 copy_u8PIN)
{
    /*Error Handling*/
    /*The port should be between A and C */
    if (copy_u8PORT > GPIOC)
    {
        /*Send ERROR */
    }
    /*Check The pin number if it is within the range or not(from 0 to 15)*/
    else if(copy_u8PIN >= LAST_CRH_PINS_NUMBER)
    {
        /*Send ERROR */
    }else
    {
        /*Everything is correct ... keep going*/

        /*Check The port*/
        switch (copy_u8PORT)
        {
        case GPIOA:
            /*Lock the Pin*/
            SET_BIT(GPIOA_LCKR,copy_u8PIN);

            /**Then Cofirm The lock using GPIOx_LCKR register*/
            /**LOCK key writing sequence(According to Data Sheet):*/
            SET_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Write 1*/
            CLR_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Write 0*/
            SET_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Write 1*/
            GET_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Read 0*/
            GET_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Read 1 (this read is optional but confirms that the lock is active)*/
            /**End of Lock sequence*/
            break;

        case GPIOB:
            /*Lock the Pin*/
            SET_BIT(GPIOB_LCKR, copy_u8PIN);

            /*Then Cofirm The lock using GPIOx_LCKR register*/
            /*LOCK key writing sequence:*/
            SET_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 1*/
            CLR_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 0*/
            SET_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 1*/
            GET_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Read 0*/
            GET_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Read 1 (this read is optional but confirms that the lock is active)*/
            /*End of Lock sequence*/
            break;

        case GPIOC:
            /*Lock the Pin*/
            SET_BIT(GPIOC_LCKR, copy_u8PIN);

            /*Then Cofirm The lock using GPIOx_LCKR register*/
            /*LOCK key writing sequence:*/
            SET_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 1*/
            CLR_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 0*/
            SET_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 1*/
            GET_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Read 0*/
            GET_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Read 1 (this read is optional but confirms that the lock is active)*/
            /*End of Lock sequence*/
            break;

        default:
            /*Error*/
            break;
        }
    }
}

/**
 * @brief This function Locks a Port by Mask
 * 
 * @param copy_u8PORT Refereces to the port .. options(GPIOA, GPIOB, GPIOC)
 * @param<pre>copy_u8PortMask Port Mask that the users chooses which pins to be locked and which to be not
 *              it consists of 16 bits each bit represents a pin from the 16 pins of the port
 *              if bit 0 then the coresponding pin will not be lokced
 *              if bit 1 then the coresponding pin will be locked </pre>
 * @details This Function Locks a port by mask so that no one Can Change the mode of the specified pins anymore
 */
void GPIO_voidLockByPortMask(uint8 copy_u8PORT, uint32 copy_u8PortMask)
{
    /*Error Handling*/
    /*The port should be between A and C */
    if (copy_u8PORT > GPIOC)
    {
        /*Send ERROR */
    }else
    {
        /*Everything is correct ... keep going*/

        /*Check The port*/
        switch (copy_u8PORT)
        {
        case GPIOA:
        
            /**First.. Lock the Pins using mask*/
            GPIOA_LCKR &= copy_u8PortMask;

            /**Then Cofirm The lock using GPIOx_LCKR register*/
            /**LOCK key writing sequence(According to Data Sheet):*/
            SET_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Write 1*/
            CLR_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Write 0*/
            SET_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Write 1*/
            GET_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Read 0*/
            GET_BIT(GPIOA_LCKR,GPIO_LCKR_LCKK_BIT) ;/**Read 1 (this read is optional but confirms that the lock is active)*/
            /**End of Lock sequence*/
            break;

        case GPIOB:
            /*Lock the Pins using mask*/
            GPIOB_LCKR &= copy_u8PortMask;
                        /*Then Cofirm The lock using GPIOx_LCKR register*/
            /*LOCK key writing sequence:*/
            SET_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 1*/
            CLR_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 0*/
            SET_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 1*/
            GET_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Read 0*/
            GET_BIT(GPIOB_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Read 1 (this read is optional but confirms that the lock is active)*/
            /*End of Lock sequence*/
            break;

        case GPIOC:
            /*Lock the Pins using mask*/
            GPIOC_LCKR &= copy_u8PortMask;

            /*Then Cofirm The lock using GPIOx_LCKR register*/
            /*LOCK key writing sequence:*/
            SET_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 1*/
            CLR_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 0*/
            SET_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Write 1*/
            GET_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Read 0*/
            GET_BIT(GPIOC_LCKR,GPIO_LCKR_LCKK_BIT) ;/*Read 1 (this read is optional but confirms that the lock is active)*/
            /*End of Lock sequence*/
            break;

        default:
            /*Error*/
            break;
        }
    }

}
