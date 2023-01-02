/**
 * @file USART_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the USART Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-09-02
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"


#include "USART_private.h"
#include "USART_interface.h"
#include "USART_Config.h"


uint16 Global_u16TimeOut;
void MUSART1_voidInit(void)
{
    /*For Baud Rate = 9600HZ >>> Calculated using The Function in register description file ... 27.3.4 page 798
    Also it is described in detail in Lecture 20 */
    /*MUSART1 ->BRR = 0x0341;*/

    /*For Baud Rate = 115200HZ >>> Calculated using The Function in register description file ... 27.3.4 page 798
    Also it is described in detail in Lecture 20 */
    MUSART1 ->BRR = 0x0045;

    /*Control Register*/
    /*
    
    
    */
    /*1- Enable TX*/
    SET_BIT(MUSART1 -> CR1, CR1_TE);

    /*2- Enable RX*/
    SET_BIT(MUSART1 -> CR1, CR1_RE);

    /*3- Enable USART*/
    SET_BIT(MUSART1 -> CR1, CR1_UE);

    /*4- Clear The status Register*/
    MUSART1 -> SR = 0;
}

void MUSART1_voidTransmit(uint8 *Copy_Pu8arr, uint8 Copy_u8DataSize)
{
    uint8 Local_u8Counter;
    Global_u16TimeOut = 0;
    for (Local_u8Counter = 0; Local_u8Counter < Copy_u8DataSize; Local_u8Counter++)
    {
        MUSART1 -> DR = Copy_Pu8arr[ Local_u8Counter ];

        /*Loop tell the Transmission Complete*/
        while (GET_BIT(MUSART1 -> SR,SR_TC ) == 0 )
        {
            /*Do Nothing ... MISRA rules*/
            if (Global_u16TimeOut == USART_REQUEST_TIME_OUT)
            {
                /* Waited too match... Get out of the loop */
                break;
            }else
            {
                /*Increment the Time out counter*/
                Global_u16TimeOut++;
            }
            
        }

        
        
    }
    
}

uint8 MUSART1_u8Receive(void)
{
    uint8 Local_u8ReceivedData =0;
    Global_u16TimeOut = 0;
    /*Loop tell the Receive is Complete*/
    while (GET_BIT(MUSART1 -> SR,SR_RXNE) == 0)
    {
        /*Check if the time is out*/
        if (Global_u16TimeOut == USART_REQUEST_TIME_OUT)
        {
            /*Waited too match... Get out of the loop */
            break;
        }else
        {
            /*Increment the Time out counter*/
            Global_u16TimeOut++;
        }
    }
    if (Global_u16TimeOut == USART_REQUEST_TIME_OUT)
    {
        Local_u8ReceivedData = USART_TIME_OUT;
    }else
    {
        /*Anding with 0xff to receive only 8 bits (not 9)*/
        Local_u8ReceivedData = (MUSART1 -> DR) && 0xff;
    }
    
   
    

    return Local_u8ReceivedData;
}