/**
 * @file USART_Config.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Configuration for the USART Driver(User Should see and modify if needed)
 * @version V02
 * @date 2022-09-21
 * @details Adding a configurable time out for any waiting loop
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H
 

/*Choose the maximum number of iterations of waiting for request in a loop
it should not Exceed 65536*/
#define USART_REQUEST_TIME_OUT 10000

#endif