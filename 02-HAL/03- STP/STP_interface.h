/**
 * @file STP_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the STP Driver that the User can see and use
 * @version V01
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H
 



/**
 * @brief This function converts from serial to parallel using 74595 IC
 * @details From its name ... this is a Synchronous Function ... this means that this function will not return till it is done 
 * 			The user passes the data to be converted from serial to parallel, 
 * 			This Function Can Deal with one IC only
 * @param Copy_u8DataToSend The data to be sended
 * @pre Configure The Driver... see STP_config.h
 */
void HSTP_voidSendSynchronous(uint8 Copy_u8DataToSend);

/**
 * @brief This function converts from serial to parallel using 74595 IC
 * @details From its name ... this is a Synchronous Function ... this means that this function will not return till it is done 
 * 			The user passes the data to be converted from serial to parallel, 
 * 			This Function Can Deal with any number of ICs
 * @param Copy_u8DataToSend The data to be sended
 * @param Copy_u8NumberOfICs The Number Of ICs connected
 * @cond Note That the array length should be equal to Copy_u8NumberOfICs
 * @pre Configure The Driver... see STP_config.h
 */
void HSTP_voidSendSynchronous_MultiICs(uint8 *Copy_u8DataToSend, uint8 Copy_u8NumberOfICs);

#endif 


