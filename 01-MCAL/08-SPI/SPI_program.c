/**
 * @file SPI_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the SPI Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-09-02
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_Config.h"




void MSPI1_voidInit(void)
{
	MSPI1 -> CR1 = 0x0347;
}


/*SPI is Full duplex ... transmit and receive at the same time*/
void MSPI1_voidSendReceiveSynch(uint8 Copy_u8DataToTransmit, uint8 *Copy_u8DataToReceive)

{
    
    /*TODO make the driver supports more than 1 slave (take slave id as argument)*/
    /*Clear for slave select pin .... assume 1 slave*/
    MGPIO_voidSetPinValue(MSPI1_SLAVE_PORT_PIN, GPIO_LOW);


    /*Send Data*/
    MSPI1 -> DR = Copy_u8DataToTransmit;
    
    /*Wait Bust Flag To finish*/
    while (GET_BIT(MSPI1 -> SR, 7) == 1)
    {
        /* Do Nothing .... just wait */
    }
    
    /*Return to the received data */
    *Copy_u8DataToReceive = MSPI1 -> DR;

    /*Set Slave Select Pin*/
    MGPIO_voidSetPinValue(MSPI1_SLAVE_PORT_PIN, GPIO_HIGH);
}



/*Asynchronous ... SPI is Full duplex ... transmit and receive at the same time*/
void MSPI1_voidSendReceiveASynch(uint8 Copy_u8DataToTransmit, void (*CallBackFunction)(uint8))
{
    /*TODO make the driver supports more than 1 slave (take slave id as argument)*/
    /*Clear for slave select pin .... assume 1 slave*/
    MGPIO_voidSetPinValue(MSPI1_SLAVE_PORT_PIN, GPIO_LOW);


    /*Send Data*/
    MSPI1 -> DR = Copy_u8DataToTransmit;
    

    Global_CallBackFunc = CallBackFunction;
    /*Enable Interrupt when Transfer buffer is empty(When Send is done)*/
    SET_BIT(MSPI1 -> CR2, TXEIE);
}


void SPI1_IRQHandler(void)
{
    /*Deliver the received Data to the Call Back Function*/
    Global_CallBackFunc(MSPI1 -> DR);

    /*Set Slave Select Pin*/
    MGPIO_voidSetPinValue(MSPI1_SLAVE_PORT_PIN, GPIO_HIGH);
}
