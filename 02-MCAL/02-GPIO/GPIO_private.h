/**
 * @file GPIO_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the GPIO Driver the User shouldn't see this
 * @version V01
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/*GPIO Base Adresses for ports From A to G*/
#define GPIOA_BASE_ADDRESS 0x40010800
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIOC_BASE_ADDRESS 0x40011000
#define GPIOD_BASE_ADDRESS 0x40011400
#define GPIOE_BASE_ADDRESS 0x40011800
#define GPIOF_BASE_ADDRESS 0x40011C00
#define GPIOG_BASE_ADDRESS 0x40012000


/*                  Registers Addresses for PORT A                    */
#define GPIOA_CRL  *((volatile uint32 *) (GPIOA_BASE_ADDRESS + 0x00 ) )
#define GPIOA_CRH  *((volatile uint32 *) (GPIOA_BASE_ADDRESS + 0x04 ) ) 
#define GPIOA_IDR  *((volatile uint32 *) (GPIOA_BASE_ADDRESS + 0x08 ) ) /*Input Data Register*/
#define GPIOA_ODR  *((volatile uint32 *) (GPIOA_BASE_ADDRESS + 0x0C ) ) /*Output Data Register*/
#define GPIOA_BSRR *((volatile uint32 *) (GPIOA_BASE_ADDRESS + 0x10 ) )
#define GPIOA_BRR  *((volatile uint32 *) (GPIOA_BASE_ADDRESS + 0x14 ) )
#define GPIOA_LCKR *((volatile uint32 *) (GPIOA_BASE_ADDRESS + 0x18 ) )

/*                  Registers Addresses for PORT B                    */
#define GPIOB_CRL  *((volatile uint32 *) (GPIOB_BASE_ADDRESS + 0x00 ) )
#define GPIOB_CRH  *((volatile uint32 *) (GPIOB_BASE_ADDRESS + 0x04 ) )
#define GPIOB_IDR  *((volatile uint32 *) (GPIOB_BASE_ADDRESS + 0x08 ) )
#define GPIOB_ODR  *((volatile uint32 *) (GPIOB_BASE_ADDRESS + 0x0C ) )
#define GPIOB_BSRR *((volatile uint32 *) (GPIOB_BASE_ADDRESS + 0x10 ) )
#define GPIOB_BRR  *((volatile uint32 *) (GPIOB_BASE_ADDRESS + 0x14 ) )
#define GPIOB_LCKR *((volatile uint32 *) (GPIOB_BASE_ADDRESS + 0x18 ) )


/*                  Registers Addresses for PORT C                    */
#define GPIOC_CRL  *((volatile uint32 *) (GPIOC_BASE_ADDRESS + 0x00 ) )
#define GPIOC_CRH  *((volatile uint32 *) (GPIOC_BASE_ADDRESS + 0x04 ) )
#define GPIOC_IDR  *((volatile uint32 *) (GPIOC_BASE_ADDRESS + 0x08 ) )
#define GPIOC_ODR  *((volatile uint32 *) (GPIOC_BASE_ADDRESS + 0x0C ) )
#define GPIOC_BSRR *((volatile uint32 *) (GPIOC_BASE_ADDRESS + 0x10 ) )
#define GPIOC_BRR  *((volatile uint32 *) (GPIOC_BASE_ADDRESS + 0x14 ) )
#define GPIOC_LCKR *((volatile uint32 *) (GPIOC_BASE_ADDRESS + 0x18 ) )

/*                  Registers Addresses for PORT D                    */
#define GPIOD_CRL  *((volatile uint32 *) (GPIOD_BASE_ADDRESS + 0x00 ) )
#define GPIOD_CRH  *((volatile uint32 *) (GPIOD_BASE_ADDRESS + 0x04 ) )
#define GPIOD_IDR  *((volatile uint32 *) (GPIOD_BASE_ADDRESS + 0x08 ) )
#define GPIOD_ODR  *((volatile uint32 *) (GPIOD_BASE_ADDRESS + 0x0C ) )
#define GPIOD_BSRR *((volatile uint32 *) (GPIOD_BASE_ADDRESS + 0x10 ) )
#define GPIOD_BRR  *((volatile uint32 *) (GPIOD_BASE_ADDRESS + 0x14 ) )
#define GPIOD_LCKR *((volatile uint32 *) (GPIOD_BASE_ADDRESS + 0x18 ) )

/*                  Registers Addresses for PORT E                    */
#define GPIOE_CRL  *((volatile uint32 *) (GPIOE_BASE_ADDRESS + 0x00 ) )
#define GPIOE_CRH  *((volatile uint32 *) (GPIOE_BASE_ADDRESS + 0x04 ) )
#define GPIOE_IDR  *((volatile uint32 *) (GPIOE_BASE_ADDRESS + 0x08 ) )
#define GPIOE_ODR  *((volatile uint32 *) (GPIOE_BASE_ADDRESS + 0x0C ) )
#define GPIOE_BSRR *((volatile uint32 *) (GPIOE_BASE_ADDRESS + 0x10 ) )
#define GPIOE_BRR  *((volatile uint32 *) (GPIOE_BASE_ADDRESS + 0x14 ) )
#define GPIOE_LCKR *((volatile uint32 *) (GPIOE_BASE_ADDRESS + 0x18 ) )

/*                  Registers Addresses for PORT E                    */
#define GPIOF_CRL  *((volatile uint32 *) (GPIOF_BASE_ADDRESS + 0x00 ) )
#define GPIOF_CRH  *((volatile uint32 *) (GPIOF_BASE_ADDRESS + 0x04 ) )
#define GPIOF_IDR  *((volatile uint32 *) (GPIOF_BASE_ADDRESS + 0x08 ) )
#define GPIOF_ODR  *((volatile uint32 *) (GPIOF_BASE_ADDRESS + 0x0C ) )
#define GPIOF_BSRR *((volatile uint32 *) (GPIOF_BASE_ADDRESS + 0x10 ) )
#define GPIOF_BRR  *((volatile uint32 *) (GPIOF_BASE_ADDRESS + 0x14 ) )
#define GPIOF_LCKR *((volatile uint32 *) (GPIOF_BASE_ADDRESS + 0x18 ) )


/*                  Registers Addresses for PORT G                    */
#define GPIOG_CRL  *((volatile uint32 *) (GPIOG_BASE_ADDRESS + 0x00 ) )
#define GPIOG_CRH  *((volatile uint32 *) (GPIOG_BASE_ADDRESS + 0x04 ) )
#define GPIOG_IDR  *((volatile uint32 *) (GPIOG_BASE_ADDRESS + 0x08 ) )
#define GPIOG_ODR  *((volatile uint32 *) (GPIOG_BASE_ADDRESS + 0x0C ) )
#define GPIOG_BSRR *((volatile uint32 *) (GPIOG_BASE_ADDRESS + 0x10 ) )
#define GPIOG_BRR  *((volatile uint32 *) (GPIOG_BASE_ADDRESS + 0x14 ) )
#define GPIOG_LCKR *((volatile uint32 *) (GPIOG_BASE_ADDRESS + 0x18 ) )


/*Last pin number the CRL register is 7*/
#define LAST_CRL_PINS_NUMBER 8
/*Last pin number the CRH register is 15*/
#define LAST_CRH_PINS_NUMBER 16


#endif
