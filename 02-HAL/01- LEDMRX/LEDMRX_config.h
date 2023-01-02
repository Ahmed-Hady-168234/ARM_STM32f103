/**
 * @file LEDMRX_config.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Configuration for the LEDMRX Driver(User Should see and modify if needed)
 * @version V01
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H


/**
 * @brief Configuration ... select the port and the pin for each row/col
 * 
 */
#define LEDMRX_ROW0_PIN     GPIOA,0
#define LEDMRX_ROW1_PIN     GPIOA,1
#define LEDMRX_ROW2_PIN     GPIOA,2
#define LEDMRX_ROW3_PIN     GPIOA,3
#define LEDMRX_ROW4_PIN     GPIOA,4
#define LEDMRX_ROW5_PIN     GPIOA,5
#define LEDMRX_ROW6_PIN     GPIOA,6
#define LEDMRX_ROW7_PIN     GPIOA,7


#define LEDMRX_COL0_PIN     GPIOB,0
#define LEDMRX_COL1_PIN     GPIOB,1
#define LEDMRX_COL2_PIN     GPIOB,5
#define LEDMRX_COL3_PIN     GPIOB,6
#define LEDMRX_COL4_PIN     GPIOB,7
#define LEDMRX_COL5_PIN     GPIOB,8
#define LEDMRX_COL6_PIN     GPIOB,9
#define LEDMRX_COL7_PIN     GPIOB,10

/*This is the factor used in speeding up/down the display
    Speed Up  : Divide   The Delay Counter by LEDMRX_SPEED_UP_DOWN_FACTOR
    Speed DOWN: Multiply The Delay Counter by LEDMRX_SPEED_UP_DOWN_FACTOR
    It should be 1 < LEDMRX_SPEED_UP_DOWN_FACTOR < 100 
    */
#define LEDMRX_SPEED_UP_DOWN_FACTOR 10


#endif
