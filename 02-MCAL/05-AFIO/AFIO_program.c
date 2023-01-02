/**
 * @file AFIO_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the AFIO Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-07-25
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_Config.h"
#include "AFIO_private.h"
#include "EXTI_interface.h"
#include "GPIO_interface.h"



/**
 * @brief This Function Selects the GPIO port To work with the required Line
 * 
 * @param Copy_u8Line The line number (Line 0 to MAXIMUM_LINES_NUMBER)
 * @param Copy_u8PortMap The port (GPIOA or GPIOB or GPIOC)
 */
void MAFIO_voidSetEXTIConfig(uint32 Copy_u8Line, uint32 Copy_u8PortMap)
{
    uint8 Local_registerIndex = 0;
    if (Copy_u8Line < MAXIMUM_LINES_NUMBER && 
        Copy_u8PortMap <= GPIOC)
    {
        /*Get The Index inside the EXTICRx register*/
        Local_registerIndex = Copy_u8Line / AFIO_NO_OF_BITS_PER_LINE;
        
        /*Select the correct EXTICR register (EXTICR1 or EXTICR2 or EXTICR3 or EXTICR4)*/
        Copy_u8Line = Copy_u8Line % AFIO_NO_OF_BITS_PER_LINE;
        
        /*Clear the bits*/
        AFIO -> EXTICR[Local_registerIndex] &=  ~(0X0f << Copy_u8Line*AFIO_NO_OF_BITS_PER_LINE);
        
        /*Select which GPIO port to work with A or B or C*/
        AFIO -> EXTICR[Local_registerIndex] |= Copy_u8PortMap << (Copy_u8Line * AFIO_NO_OF_BITS_PER_LINE);
    }else
    {
        /*Error*/
    }
}