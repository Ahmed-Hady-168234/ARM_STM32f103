
/**
 * @file TFT_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the TFT Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-09-13
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


/**
 * @brief This Function Initializes the TFT Display Driver
 * @pre You should Configure the Driver see TFT_Config.h
 */
void HTFT_voidInit(void)
{
	/**1-		Reset Pulse			*/
	MGPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_HIGH);/*High*/
	MSysTick_voidSetBusyWait(100);					/*Wait 100us*/
	MGPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_LOW); /*Low*/
	MSysTick_voidSetBusyWait(1);					/*Wait 1us*/
	MGPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_HIGH);/*High*/
	MSysTick_voidSetBusyWait(100);					/*Wait 100us*/
	MGPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_LOW); /*Low*/
	MSysTick_voidSetBusyWait(100);					/*Wait 100us*/
	MGPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_HIGH);/*High*/
	MSysTick_voidSetBusyWait(120000);				/*Wait 120ms*/

	/**2-		Sleep Out				*/
	voidWriteCommand(SLPOUT);

	/**3-		Wait for 150ms			*/
	MSysTick_voidSetBusyWait(150000);				/*Wait 150ms*/


	/**4-		Color Mode				*/
	voidWriteCommand(COLMOD);
	voidWriteData(RGB565);/*The Color mode Parameter .... RGB565 65k with 40kByte flash memory */

	/**5-		Display On			*/
	voidWriteCommand(DISPON);
}


/**
 * @brief This Function Displays the image on the TFT Display
 * 
 * @param Copy_u16Image  The Image as array ... Const is to make sure the array 
 * will be placed in the flash(Enough space) not the RAM(no memory enough) like we did with the sound lecture21
 * @pre You should Initialize the driver in first see HTFT_voidInit()
 */
void HTFT_voidDisplayImage(const uint16 *Copy_u16Image)
{
	uint16	Local_u16Counter;
	/*		Set X(Comlumn) Address (0, 0) >>> (0, 127)		*/
	voidWriteCommand(CASET);
	/*Start (0,0)*/
	voidWriteData(COLUMN_START);/*The X(Column) parameter 1st byte*/
	voidWriteData(COLUMN_START);/*The X(Column) parameter 2nd byte*/
	/*End (0,127)*/
	voidWriteData(COLUMN_END_BYTE1);/*The X(Column) parameter 1st byte*/
	voidWriteData(COLUMN_END_BYTE2);/*The X(Column) parameter 2nd byte*/


	/*		Set Y(Comlumn) Address (0, 0) >>> (159, 127)		*/
	voidWriteCommand(RASET);
	/*Start (0,0)*/
	voidWriteData(ROW_START);/*The X(Column) parameter 1st byte*/
	voidWriteData(ROW_START);/*The X(Column) parameter 2nd byte*/
	/*End (0,159)*/
	voidWriteData(ROW_END_BYTE1);/*The X(Column) parameter 1st byte*/
	voidWriteData(ROW_END_BYTE2);/*The X(Column) parameter 2nd byte*/

	/*Ram Write(Any coming data will be displayed)*/
	voidWriteCommand(RAMWR);

	/*Write The Image on the screen*/
	for (Local_u16Counter = 0; Local_u16Counter < NUMBER_OF_PIXELS; Local_u16Counter++)
	{
		voidWriteData( (uint8) ( Copy_u16Image[Local_u16Counter] >> BYTE  ) );/*Send The Most Byte*/
		voidWriteData( (uint8) ( Copy_u16Image[Local_u16Counter] & 0x00ff ) );		   /*Send The Least Byte*/
	}
	
}

/**
 * @brief This Function is static(private to this driver) it is to send data to the TFT 
 * 
 * @param Copy_u8Data The Data to be sent
 */
static void voidWriteData(uint8 Copy_u8Data)
{
	/*Passed to the the SPI function*/
	uint8 Local_u8temp;
	/*Set A0(A0 is pin in the TFT Microcontroller to select data or command) to High*/	
	MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_HIGH);
	
	/*Send The Data to the TFT Micro*/
	MSPI1_voidSendReceiveSynch(Copy_u8Data, &Local_u8temp);

}

/**
 * @brief This Function is static(private to this driver) it is to send Commands to the TFT 
 * 
 * @param Copy_u8Command The Command to be sent
*/
static void voidWriteCommand(uint8 Copy_u8Command)
{
	/*Passed to the the SPI function*/
	uint8 Local_u8temp;
	
	/*Set A0(A0 is pin in the TFT Microcontroller to select data or command) to low*/	
	MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_LOW);

	/*Send The Data to the TFT Micro*/
	MSPI1_voidSendReceiveSynch(Copy_u8Command, &Local_u8temp);
	
}
