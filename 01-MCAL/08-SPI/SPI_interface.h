/**
 * @file SPI_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the SPI Driver that the User can see and use
 * @version V01
 * @date 2022-09-02
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(uint8 Copy_u8DataToTransmit, uint8 *Copy_u8DataToReceive);/*Synchronous   ... SPI is Full duplex ... transmit and receive at the same time*/
void MSPI1_voidSendReceiveASynch(uint8 Copy_u8DataToTransmit, void (*CallBackFunction)(uint8));/*Asynchronous ... SPI is Full duplex ... transmit and receive at the same time*/

/*To use This Driver you should 
    Set Clock pin(usually it is A5) direction as output push pull
    Set MISO  pin(usually it is A6) direction as INPUT Floating (if needed)
    Set MOSI  pin(usually it is A7) direction as output push pull 

*/

#endif