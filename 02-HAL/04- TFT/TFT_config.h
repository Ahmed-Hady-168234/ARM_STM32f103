/**
 * @file TFT_config.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Configuration for the TFT Driver(User Should see and modify if needed)
 * @version V01
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H


/*TFT A0 pin(A0 is pin in the TFT Microcontroller to select data or command) 
    Write it In Pair   PORT,PIN
        options for Port  GPIOA, GPIOB, GPIOC
        options for pin   GPIO_PIN0, GPIO_PIN1, GPIO_PIN2,......
*/
#define TFT_A0_PIN      GPIOA,GPIO_PIN2

/*TFT Reset Pin
    Write it In Pair   PORT,PIN
        options for Port  GPIOA, GPIOB, GPIOC
        options for pin   GPIO_PIN0, GPIO_PIN1, GPIO_PIN2,......
*/
#define TFT_RESET_PIN   GPIOA, GPIO_PIN1


#endif
