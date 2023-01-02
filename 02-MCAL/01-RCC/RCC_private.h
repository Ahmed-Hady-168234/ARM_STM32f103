/**
 * @file RCC_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the RCC Driver User shouldn't see this
 * @version V01
 * @date 2022-07-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/** Register Definition */
    
#define RCC_CR          *((volatile uint32*)0x40021000)
#define RCC_CFGR        *((volatile uint32*)0x40021004)
#define RCC_CIR         *((volatile uint32*)0x40021008)
#define RCC_APB2RSTR    *((volatile uint32*)0x4002100C)
#define RCC_APB1RSTR    *((volatile uint32*)0x40021010)
#define RCC_AHBENR      *((volatile uint32*)0x40021014)
#define RCC_APB2ENR     *((volatile uint32*)0x40021018)
#define RCC_APB1ENR     *((volatile uint32*)0x4002101C)
#define RCC_BDCR        *((volatile uint32*)0x40021020)
#define RCC_CSR         *((volatile uint32*)0x40021024)



/**RCC_CR Register bits*/
#define HSION       0 
#define HSIRDY      1

#define HSEON       16
#define HSERDY      17
#define HSEBYP      18

#define CSSON      19

#define PLLON       24
#define PLLRDY      25



#define RCC_HSE_Crystal 0
#define RCC_HSE_RC      1
#define RCC_HSI         2
#define RCC_PLL         3

/*Input of the PLL*/
#define HSI2 3
#define HSE2 4
#define HSE 5
/**           PLL in RCC_CFGR            */

#define PLLSRC   16
#define PLLXTPRE 17
#define RCC_PLL_MUL_START_BIT 18
#define RCC_PLL_MAX_MUL 16
#define RCC_PLL_MIN_MUL 2  
#define RCC_PLL_CLR_MASk 0xffC0ffff         /*Mask used to clear the PLL bits in RCC_CFGR*/

#define ON  1
#define OFF 0























#endif 