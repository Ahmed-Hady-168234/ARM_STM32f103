/**
 * @file LEDMRX_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the LEDMRX Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-08-08
 * 
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


void HLEDMRX_voidEnableRows(uint8 Copy_u8RowValue);
void HLEDMRX_voidDisableAllCols(void);

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



void HLEDMRX_voidDisplay(uint8 *Copy_u8Data)
{
  while (1)
  {
        
    /*Column0*/
        /*Disable all columns*/
        HLEDMRX_voidDisableAllCols();
        /*Enable the rows*/
        HLEDMRX_voidEnableRows(Copy_u8Data[0]);    
        /*Enable Column 0*/
        GPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_LOW);
        /*Delay for 2.5ms*/
        MSysTick_voidSetBusyWait(2500);

    /*Column1*/
        /*Disable all columns*/
        HLEDMRX_voidDisableAllCols();
        /*Enable the rows*/
        HLEDMRX_voidEnableRows(Copy_u8Data[1]);    
        /*Enable Column 1*/
        GPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_LOW);
        /*Delay for 2.5ms*/
        MSysTick_voidSetBusyWait(2500);

    /*Column2*/
        /*Disable all columns*/
        HLEDMRX_voidDisableAllCols();
        /*Enable the rows*/
        HLEDMRX_voidEnableRows(Copy_u8Data[2]);    
        /*Enable Column 2*/
        GPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_LOW);
        /*Delay for 2.5ms*/
        MSysTick_voidSetBusyWait(2500);

    /*Column3*/
        /*Disable all columns*/
        HLEDMRX_voidDisableAllCols();
        /*Enable the rows*/
        HLEDMRX_voidEnableRows(Copy_u8Data[3]);    
        /*Enable Column 3*/
        GPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_LOW);
        /*Delay for 2.5ms*/
        MSysTick_voidSetBusyWait(2500);

    /*Column4*/
        /*Disable all columns*/
        HLEDMRX_voidDisableAllCols();
        /*Enable the rows*/
        HLEDMRX_voidEnableRows(Copy_u8Data[4]);    
        /*Enable Column 4*/
        GPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_LOW);
        /*Delay for 2.5ms*/
        MSysTick_voidSetBusyWait(2500);

    /*Column5*/
        /*Disable all columns*/
        HLEDMRX_voidDisableAllCols();
        /*Enable the rows*/
        HLEDMRX_voidEnableRows(Copy_u8Data[5]);    
        /*Enable Column 5*/
        GPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_LOW);
        /*Delay for 2.5ms*/
        MSysTick_voidSetBusyWait(2500);

    /*Column6*/
        /*Disable all columns*/
        HLEDMRX_voidDisableAllCols();
        /*Enable the rows*/
        HLEDMRX_voidEnableRows(Copy_u8Data[6]);    
        /*Enable Column 6*/
        GPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_LOW);
        /*Delay for 2.5ms*/
        MSysTick_voidSetBusyWait(2500);

    /*Column7*/
        /*Disable all columns*/
        HLEDMRX_voidDisableAllCols();
        /*Enable the rows*/
        HLEDMRX_voidEnableRows(Copy_u8Data[7]);    
        /*Enable Column 7*/
        GPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_LOW);
        /*Delay for 2.5ms*/
        MSysTick_voidSetBusyWait(2500);


  }

 
}

void HLEDMRX_voidDisableAllCols(void)
{
    /*Disable all columns*/
    GPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_HIGH);
    GPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_HIGH);
    GPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_HIGH);
    GPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_HIGH);
    GPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_HIGH);
    GPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_HIGH);
    GPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_HIGH);
    GPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_HIGH);
}


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