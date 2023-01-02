/**
 * @file GPIO_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the GPIO Driver that the User can see and use
 * @version V01
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H



/*******************    GPIO Ports from A to G   ******************/
#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3
#define GPIOE 4
#define GPIOF 5
#define GPIOG 6

/******************     GPIO Pins from 0 to 15   ******************/
#define GPIO_PIN0  0
#define GPIO_PIN1  1
#define GPIO_PIN2  2
#define GPIO_PIN3  3
#define GPIO_PIN4  4
#define GPIO_PIN5  5
#define GPIO_PIN6  6
#define GPIO_PIN7  7
#define GPIO_PIN8  8
#define GPIO_PIN9  9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15

/******************      GPIO pins modes     ******************/
/*Output Mode with Max speed 10MHZ*/
#define OUTPUT_SPEED_10MHZ_PP   0b0001      /*General purpose output push-pull     max speed 10 MHz.  */
#define OUTPUT_SPEED_10MHZ_OD   0b0101      /*General purpose output Open-drain    max speed 10 MHz.  */
#define OUTPUT_SPEED_10MHZ_AFPP 0b1001      /*Alternate function output Push-pull  max speed 10 MHz.*/
#define OUTPUT_SPEED_10MHZ_AFOD 0b1101      /*Alternate function output Open-drain max speed 10 MHz.*/

/*Output Mode with Max speed 2MHZ*/
#define OUTPUT_SPEED_2MHZ_PP   0b0010      /*General purpose output push-pull     max speed 2 MHz.  */
#define OUTPUT_SPEED_2MHZ_OD   0b0110      /*General purpose output Open-drain    max speed 2 MHz.  */
#define OUTPUT_SPEED_2MHZ_AFPP 0b1010      /*Alternate function output Push-pull  max speed 2 MHz.*/
#define OUTPUT_SPEED_2MHZ_AFOD 0b1110      /*Alternate function output Open-drain max speed 2 MHz.*/

/*Output Mode with Max speed 50MHZ*/
#define OUTPUT_SPEED_50MHZ_PP   0b0011      /*General purpose output push-pull     max speed 50 MHz.  */
#define OUTPUT_SPEED_50MHZ_OD   0b0111      /*General purpose output Open-drain    max speed 50 MHz.  */
#define OUTPUT_SPEED_50MHZ_AFPP 0b1011      /*Alternate function output Push-pull  max speed 50 MHz.*/
#define OUTPUT_SPEED_50MHZ_AFOD 0b1111      /*Alternate function output Open-drain max speed 50 MHz.*/

/*INPUT Mode*/
#define INPUT_ANALOG            0b0000      /*Analog mode*/
#define INPUT_FLOATING          0b0100      /*Floating input (reset state)*/
#define INPUT_WITH_PULL_UP_DOWN 0b1000      /*Input with pull-up / pull-down*/

/*HIGH, LOW*/
#define GPIO_LOW  0
#define GPIO_HIGH 1

/****************** The driver Functions ******************/
void GPIO_voidSetPinDirection(uint8 copy_u8PORT, uint8 copy_u8PIN, uint8 copy_u8Mode);
void GPIO_voidSetPinValue(uint8 copy_u8PORT, uint8 copy_u8PIN, uint8 copy_u8Value);
uint8 GPIO_voidGetPinValue(uint8 copy_u8PORT, uint8 copy_u8PIN);
void GPIO_voidLockByPinNum(uint8 copy_u8PORT, uint8 copy_u8PIN);
void GPIO_voidLockByPortMask(uint8 copy_u8PORT, uint32 copy_u8PortMask);

#endif