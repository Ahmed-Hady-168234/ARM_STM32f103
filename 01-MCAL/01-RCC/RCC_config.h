/**
 * @file RCC_config.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Configuration for the RCC Driver(User Should see and modify if needed)
 * @version V01
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/** Choose System Clock
 * RCC_HSE_Crystal
 * RCC_HSE_RC
 * RCC_HSI
 * RCC_PLL
*/
#define RCC_SYS_Clock RCC_HSE_Crystal

/*In case of selecting HSE...Choose to Enable(put ON) or Disable(put OFF) CSS*/
#define RCC_CSSON   ON

/*In case of selecting PLL... */

/*select the PLL multiplier from 2 to 16 
Caution: The PLL output frequency must not exceed 72 MHz.*/
#define RCC_PLL_MUL 2 

/**Select input to the PLL
 * HSI/2   put HSI2
 * HSE/2   put HSE2
 * HSE     put HSE
*/
#define RCC_PLL_INPUT   HSE2
#endif 
