/**
 * @file ESP_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the ESP Driver User shouldn't see this
 * @version V01
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ESP_PRIVATE_H
#define ESP_PRIVATE_H

     
#define ESP_STOP_ECHO_COMMAND    "ATE0"
#define ESP_START_ECHO_COMMAND   "ATE1"

#define ESP_SELECT_STATION_MODE_COMMAND  "AT_CWMODE=1\r\n"

/*Macros to check if the command is validated or not*/
#define NOT_VALIDATED 0
#define VALIDATED 1
#endif 
