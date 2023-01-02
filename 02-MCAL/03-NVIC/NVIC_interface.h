/**
 * @file NVIC_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the NVIC Driver that the User can see and use
 * @version V01
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


/*  Interrupts ID from Vector Table    */
#define NVIC_WWDG 0
#define NVIC_PVD    1
#define NVIC_TAMPER 2
#define NVIC_RTC    3
#define NVIC_FLASH  4
#define NVIC_RCC5   5
#define NVIC_EXTI0  6
#define NVIC_EXTI1  7
#define NVIC_EXTI2  8
#define NVIC_EXTI3  9
#define NVIC_EXTI4  10
#define NVIC_DMA1_Channel1  11
#define NVIC_DMA1_Channel2  12
#define NVIC_DMA1_Channel3  13
#define NVIC_DMA1_Channel4  14
#define NVIC_DMA1_Channel5  15
#define NVIC_DMA1_Channel6  16
#define NVIC_DMA1_Channel7  17
#define NVIC_ADC1_2         18
#define NVIC_CAN1_TX        19
#define NVIC_CAN1_RX0       20
#define NVIC_CAN1_RX1       21
#define NVIC_CAN1_SCE       22
#define NVIC_EXTI9_5        23
#define NVIC_TIM1_BRK       24
#define NVIC_TIM1_UP        25
#define NVIC_TIM1_TRG_COM   26
#define NVIC_TIM1_CC        27
#define NVIC_TIM2           28
#define NVIC_TIM3           29
#define NVIC_TIM4           30
#define NVIC_I2C1_EV        31
#define NVIC_I2C1_ER        32
#define NVIC_I2C2_EV        33
#define NVIC_I2C2_ER        34
#define NVIC_SPI1           35
#define NVIC_SPI2           36
#define NVIC_USART1         37
#define NVIC_USART2         38
#define NVIC_USART3         39

/*Macros for Group and Sub numbers(passed To MNVIC_voidSetPriorities()*/
#define NVIC_GROUP_PRIORITY_0  0
#define NVIC_GROUP_PRIORITY_1  1
#define NVIC_GROUP_PRIORITY_2  2
#define NVIC_GROUP_PRIORITY_3  3
#define NVIC_GROUP_PRIORITY_4  4
#define NVIC_GROUP_PRIORITY_5  5
#define NVIC_GROUP_PRIORITY_6  6
#define NVIC_GROUP_PRIORITY_7  7
#define NVIC_GROUP_PRIORITY_8  8
#define NVIC_GROUP_PRIORITY_9  9
#define NVIC_GROUP_PRIORITY_10 10
#define NVIC_GROUP_PRIORITY_11 11
#define NVIC_GROUP_PRIORITY_12 12
#define NVIC_GROUP_PRIORITY_13 13
#define NVIC_GROUP_PRIORITY_14 14
#define NVIC_GROUP_PRIORITY_15 15
#define NVIC_SUB_PRIORITY_0    0
#define NVIC_SUB_PRIORITY_1    1
#define NVIC_SUB_PRIORITY_2    2
#define NVIC_SUB_PRIORITY_3    3
#define NVIC_SUB_PRIORITY_4    4
#define NVIC_SUB_PRIORITY_5    5
#define NVIC_SUB_PRIORITY_6    6
#define NVIC_SUB_PRIORITY_7    7
#define NVIC_SUB_PRIORITY_8    8
#define NVIC_SUB_PRIORITY_9    9
#define NVIC_SUB_PRIORITY_10   10
#define NVIC_SUB_PRIORITY_11   11
#define NVIC_SUB_PRIORITY_12   12
#define NVIC_SUB_PRIORITY_13   13
#define NVIC_SUB_PRIORITY_14   14
#define NVIC_SUB_PRIORITY_15   15

/****************** The driver Functions ******************/
void MNVIC_voidInit(void);
void MNVIC_voidEnableInterrupt(uint8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(uint8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(uint8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(uint8 Copy_u8IntNumber);
uint8 MNVIC_u8GetActiveFlag(uint8 Copy_u8IntNumber);
void MNVIC_voidSetPriorities(sint8 Copy_s8InterruptID, uint8 Copy_u8GroupPriority, uint8 Copy_u8SubPriority );
#endif