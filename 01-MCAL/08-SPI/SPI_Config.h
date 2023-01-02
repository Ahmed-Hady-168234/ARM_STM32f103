/**
 * @file SPI_Config.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Configuration for the SPI Driver(User Should see and modify if needed)
 * @version V01
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H
 
/*Write it in pair  port,pin*/
#define MSPI1_SLAVE_PORT_PIN GPIOA, GPIO_PIN4

/*Clock Phase select... options: READ_THEN_WRITE,
                                 WRITE_THEN_READ*/
#define MSP1_CR1_CLOCK_PHASE    READ_THEN_WRITE

/*Clock Polarity select... options IDLE_LOW_RISING_IS_FIRST_EDGE,
                                   IDLE_HIGH_FALLING_IS_FIRST_EDGE*/
#define MSP1_CR1_CLOCK_POLARITY IDLE_LOW_RISING_IS_FIRST_EDGE

/*Master/Slave select.... options MASTER,
                                  SLAVE*/
#define MSP1_CR1_MASTER_SLAVE   MASTER

/*Master/Slave select....(For SPI1) options APB2_CLOCK_DIV_2
                                            APB2_CLOCK_DIV_4
                                            APB2_CLOCK_DIV_8
                                            APB2_CLOCK_DIV_16
                                            APB2_CLOCK_DIV_32
                                            APB2_CLOCK_DIV_64
                                            APB2_CLOCK_DIV_128
                                            APB2_CLOCK_DIV_256
                                            */
#define MSP1_CR1_BAUD_RATE  APB2_CLOCK_DIV_2  

#endif