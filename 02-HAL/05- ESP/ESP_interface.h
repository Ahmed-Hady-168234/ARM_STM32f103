/**
 * @file ESP_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the ESP Driver that the User can see and use
 * @version V01
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

	
void HESP_voidInit(void);



/*ESP Return Type*/
typedef uint8 ESP_returnType;

/****************** API.. Driver Functions  ******************/


/*ESP Return Types used to check if the function succeeded or there is a error */
#define ESP_OK                               ((ESP_returnType) 0)/*The function succeeded*/
#define ESP_NULL_POINTER                     ((ESP_returnType) 1)/*The input pointer passed is NULL*/
#define ESP_WIFI_NOT_CONNECTED               ((ESP_returnType) 2)/*The Wifi is not connected*/


#endif 


