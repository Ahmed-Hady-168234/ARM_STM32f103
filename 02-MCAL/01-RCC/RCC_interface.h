/**
 * @file RCC_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the GPIO Driver that the User can see and use
 * @version V01
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H
 
 
 
#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

/*APB2 Peripherals*/
#define RCC_APB2_AFIOEN   0
#define RCC_APB2_IOPAEN   2
#define RCC_APB2_IOPBEN   3
#define RCC_APB2_IOPCEN   4
#define RCC_APB2_IOPDEN   5
#define RCC_APB2_IOPEEN   6
#define RCC_APB2_ADC1EN   9
#define RCC_APB2_ADC2EN   10
#define RCC_APB2_TIM1EN   11
#define RCC_APB2_SPI1EN   12
#define RCC_APB2_USART1EN 14


void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(uint8 Copy_u8BusId, uint8 Copy_u8PerId);
void RCC_voidDisableClock(uint8 Copy_u8BusId, uint8 Copy_u8PerId);


#endif 


