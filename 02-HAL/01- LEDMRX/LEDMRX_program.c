
/**
 * @file LEDMRX_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the LEDMRX Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-08-11
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"
#include "GPIO_interface.h"
#include "SysTick_interface.h"

/**
 * @brief Array contains the configuration paramater for the ports
 * 
 */
LEDMRX_config_t userPortPin_row[8]=
{   {LEDMRX_ROW0_PIN},
    {LEDMRX_ROW1_PIN},
    {LEDMRX_ROW2_PIN},
    {LEDMRX_ROW3_PIN},
    {LEDMRX_ROW4_PIN},
    {LEDMRX_ROW5_PIN},
    {LEDMRX_ROW6_PIN},
    {LEDMRX_ROW7_PIN}
};

/**
 * @brief Array contains the configuration paramater for the pins
 * 
 */
LEDMRX_config_t userPortPin_col[8]=
{   {LEDMRX_COL0_PIN},
    {LEDMRX_COL1_PIN},
    {LEDMRX_COL2_PIN},
    {LEDMRX_COL3_PIN},
    {LEDMRX_COL4_PIN},
    {LEDMRX_COL5_PIN},
    {LEDMRX_COL6_PIN},
    {LEDMRX_COL7_PIN}
};

/**
 * @brief Initialization of the driver
 * @pre Configure the project in first
 */
void HLEDMRX_voidInit(void)
{
    /*Initialize the Rows Direction*/
    GPIO_voidSetPinDirection(LEDMRX_ROW0_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinDirection(LEDMRX_ROW1_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinDirection(LEDMRX_ROW2_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinDirection(LEDMRX_ROW3_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinDirection(LEDMRX_ROW4_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinDirection(LEDMRX_ROW5_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinDirection(LEDMRX_ROW6_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinDirection(LEDMRX_ROW7_PIN, OUTPUT_SPEED_2MHZ_PP);
    

    /*Initialize the Columns Direction*/
    GPIO_voidSetPinDirection(LEDMRX_COL0_PIN, OUTPUT_SPEED_2MHZ_PP); 
    GPIO_voidSetPinDirection(LEDMRX_COL1_PIN, OUTPUT_SPEED_2MHZ_PP); 
    GPIO_voidSetPinDirection(LEDMRX_COL2_PIN, OUTPUT_SPEED_2MHZ_PP); 
    GPIO_voidSetPinDirection(LEDMRX_COL3_PIN, OUTPUT_SPEED_2MHZ_PP); 
    GPIO_voidSetPinDirection(LEDMRX_COL4_PIN, OUTPUT_SPEED_2MHZ_PP); 
    GPIO_voidSetPinDirection(LEDMRX_COL5_PIN, OUTPUT_SPEED_2MHZ_PP); 
    GPIO_voidSetPinDirection(LEDMRX_COL6_PIN, OUTPUT_SPEED_2MHZ_PP); 
    GPIO_voidSetPinDirection(LEDMRX_COL7_PIN, OUTPUT_SPEED_2MHZ_PP); 

}

/**
 * @brief This function Displays a word, char by char .. moving from left to right
 * 
 * @param Copy_u8Data Pointer to array contains the data to be displayed
 * @param Copy_u8WordSize size of the data array
 * @param Copy_u32DelayCounter Delay to move from Col to the next 
 */
LEDMRX_returnType HLEDMRX_voidDisplayMovingWord(uint8 *Copy_u8Data, uint8 Copy_u8WordSize, uint32 Copy_u32DelayCounter)
{
    uint8 i, /*Row ptr*/
    j,/*Col ptr*/ 
    prev_j_value=0,/*previous Row ptr Value*/
    prev_i_value=0;/*previous Col ptr Value*/
    
  
    uint8 Local_u8FrameColStartPtr,   /**Denotes the start and the end column of the current frame ... used in HLEDMRX_voidDisplayMovingWord()*/
    Local_u8NextColFlag;/*Flag raised when needed to move to the next column */

    uint32 Local_u32DelayCounter =0;
    Global_u32DisplaySpeed = Copy_u32DelayCounter;
    LEDMRX_returnType Local_LEDMRXReturn = LEDMRX_OK;/*Return variable*/
    Local_u8FrameColStartPtr = 0;
    Local_u8NextColFlag = 0;

    /*ERROR Handling*/
    if (Copy_u8Data != NULL)
    {  
        if (Copy_u8WordSize > 0 && Global_u32DisplaySpeed)
        {
            /*Keep printing the word forever*/
            while (1)
            {
                /*Loop to print a frame ()*/
                for (i = 0, j = Local_u8FrameColStartPtr; i < LEDMRX_ROW_SIZE; i++,j++)
                {
                    /*Note: For sure this is not the accurate way to handle the speed (it have an error +- LEDMRX_FRAME_TIME,
                    which is 2500 ms)... but it is fear enough for now*/
                    if ((Local_u32DelayCounter * LEDMRX_FRAME_TIME) >= Global_u32DisplaySpeed)
                    {
                        /*Set the next column flag*/
                        Local_u8NextColFlag = TRUE;
                        /*Clear The counter*/
                        Local_u32DelayCounter = 0;
                        /*Get out of the loop to move to the next column*/
                        break;
                    }else
                    {
                        /*Do Nothing .... MISRA rules*/
                    }
                    /*Reached The Last column(Copy_u8DataSize -1)?*/
                    if (j == Copy_u8WordSize)
                    {
                        /*Move To the first one*/
                        j = 0;
                    }else
                    {
                        /*Do Nothing .... MISRA rules*/
                    }

                    /*Disable the previous column*/
                    GPIO_voidSetPinValue(userPortPin_col[prev_i_value].portMap, userPortPin_col[prev_i_value].pinMap , GPIO_HIGH);
                    /*Enable the rows*/
                    HLEDMRX_voidEnableRows(Copy_u8Data[j]);    
                    /*Enable Column */
                    GPIO_voidSetPinValue(userPortPin_col[i].portMap, userPortPin_col[i].pinMap , GPIO_LOW);
                    /*Delay for 2.5ms*/
                    MSysTick_voidSetBusyWait(LEDMRX_FRAME_TIME);
                    /*Increment The speed counter (it used to measure the required delay)*/
                    Local_u32DelayCounter++;
                    prev_j_value = j;
                    prev_i_value = i;
                }

                /*Is it the time to move one column?*/
                if(Local_u8NextColFlag == TRUE && Global_u8ReleasedFlag == TRUE)
                {
                    /*Clear The flag*/
                    Local_u8NextColFlag = FALSE;
                    /*Reached the Edge of the word?*/
                    if (Local_u8FrameColStartPtr >=  Copy_u8WordSize)
                    {
                        /*Get back to the first frame col*/
                        Local_u8FrameColStartPtr = 0;
                    }else
                    {
                        /*Move to the next Column*/
                        Local_u8FrameColStartPtr++;
                    }
                }else
                {
                    /*Do Nothing .... MISRA rules*/
                }
            }
        }else
        {
            /*MISRA rules*/
            /*Set the return as error*/
            Local_LEDMRXReturn = LEDMRX_INVALID_NUMBER;
        }
    }else
    {
        /*MISRA rules*/
        /*Set the return as error*/
        Local_LEDMRXReturn = LEDMRX_NULL_POINTER;
    }
        return Local_LEDMRXReturn;
}

/**
 * @brief This function Displays a char
 * 
 * @param Copy_u8Data Pointer to array contains the data to be displayed
 * 
 */
LEDMRX_returnType HLEDMRX_voidDisplayChar(uint8 *Copy_u8Data)
{
    uint8 i ,prev_i_value=0;
    LEDMRX_returnType Local_LEDMRXReturn = LEDMRX_OK;/*Return variable*/
    /*ERROR Handling*/
    if (Copy_u8Data != NULL)
    {
        while (1)
        {
                /*Loop to print a frame ()*/
                for (i = 0 ; i < LEDMRX_ROW_SIZE; i++)
                {
                
                    /*Disable the previous column*/
                    GPIO_voidSetPinValue(userPortPin_col[prev_i_value].portMap, userPortPin_col[prev_i_value].pinMap , GPIO_HIGH);
                    /*Enable the rows*/
                    HLEDMRX_voidEnableRows(Copy_u8Data[i]);    
                    /*Enable Column */
                    GPIO_voidSetPinValue(userPortPin_col[i].portMap, userPortPin_col[i].pinMap , GPIO_LOW);
                    /*Delay for 2.5ms*/
                    MSysTick_voidSetBusyWait(2500);
                    /*Increment The speed counter (it used to measure the required delay)*/
                    prev_i_value = i;
                }
        }
    }else
    {
        /*MISRA rules*/
        /*Set the return as error*/
        Local_LEDMRXReturn = LEDMRX_NULL_POINTER;
    }
    return Local_LEDMRXReturn;
}
 
/**
 * @brief Enables the required rows values
 * 
 * @param Copy_u8RowValue the rows value
 */
void HLEDMRX_voidEnableRows(uint8 Copy_u8RowValue)
{
    uint8 Local_u8Bit;
    
    /*Get the bit and then put it on the GPIO*/
    Local_u8Bit = GET_BIT(Copy_u8RowValue,0);
    GPIO_voidSetPinValue(LEDMRX_ROW0_PIN, Local_u8Bit);

    /*Get the bit and then put it on the GPIO*/
    Local_u8Bit = GET_BIT(Copy_u8RowValue,1);
    GPIO_voidSetPinValue(LEDMRX_ROW1_PIN, Local_u8Bit);

    /*Get the bit and then put it on the GPIO*/
    Local_u8Bit = GET_BIT(Copy_u8RowValue,2);
    GPIO_voidSetPinValue(LEDMRX_ROW2_PIN, Local_u8Bit);

    /*Get the bit and then put it on the GPIO*/
    Local_u8Bit = GET_BIT(Copy_u8RowValue,3);
    GPIO_voidSetPinValue(LEDMRX_ROW3_PIN, Local_u8Bit);

    /*Get the bit and then put it on the GPIO*/
    Local_u8Bit = GET_BIT(Copy_u8RowValue,4);
    GPIO_voidSetPinValue(LEDMRX_ROW4_PIN, Local_u8Bit);

    /*Get the bit and then put it on the GPIO*/
    Local_u8Bit = GET_BIT(Copy_u8RowValue,5);
    GPIO_voidSetPinValue(LEDMRX_ROW5_PIN, Local_u8Bit);

    /*Get the bit and then put it on the GPIO*/
    Local_u8Bit = GET_BIT(Copy_u8RowValue,6);
    GPIO_voidSetPinValue(LEDMRX_ROW6_PIN, Local_u8Bit);

    /*Get the bit and then put it on the GPIO*/
    Local_u8Bit = GET_BIT(Copy_u8RowValue,7);
    GPIO_voidSetPinValue(LEDMRX_ROW7_PIN, Local_u8Bit);
}


void HLEDMRX_voidReleaseDisplay(void)
{
    /*Release The Display*/
    Global_u8ReleasedFlag = TRUE;
}

void HLEDMRX_voidPauseDisplay(void)
{
    /*Pause The Display*/
    Global_u8ReleasedFlag = FALSE;
}

void HLEDMRX_voidSpeedUpDisplay(void)
{
    if (1>= LEDMRX_SPEED_UP_DOWN_FACTOR)
    {
        /* code */
    }else
    {
        
    }
    
    
    Global_u32DisplaySpeed  = Global_u32DisplaySpeed/
}

void HLEDMRX_voidSlowDownDisplay(void)
{

}