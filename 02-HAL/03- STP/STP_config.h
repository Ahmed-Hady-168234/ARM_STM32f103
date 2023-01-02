/**
 * @file STP_config.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Configuration for the STP Driver(User Should see and modify if needed)
 * @version V01
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STP_CONFIG_H
#define STP_CONFIG_H


/**
 * @brief Configuration ... Select The port and the pin for each pin .... please write in pairs
 * @details <pre><b>
 * Port Options:
 *               GPIOA, GPIOB, GPIOC
 * Pin  Options: GPIO_PIN0, GPIO_PIN1, GPIO_PIN2, .......,
 * </b></pre>
 * 
 */

/*
*/
#define HSTP_DATA_SERIAL     GPIOA, GPIO_PIN0
#define HSTP_SHIFT_CLOCK     GPIOA, GPIO_PIN1
#define HSTP_STORAGE_CLOCK   GPIOA, GPIO_PIN2

#endif
