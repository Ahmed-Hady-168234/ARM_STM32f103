
/**
 * @file STP_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the STP Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-08-22
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"





 
/**
 * @brief This function converts from serial to parallel using 74595 IC
 * @details From its name ... this is a Synchronous Function ... this means that this function will not return till it is done 
 * 			The user passes the data to be converted from serial to parallel, 
 * 			This Function Can Deal with one IC only
 * @param Copy_u8DataToSend The data to be sended
 * @pre Configure The Driver... see STP_config.h
 */
void HSTP_voidSendSynchronous(uint8 Copy_u8DataToSend)
{	
	/*Counters for the loops*/
	sint8 Local_s8Counter;
	/*Get the current bit in this variable*/
	uint8 Local_u8Bit;

	/**************    Send Data To the ICs    **************/
	/*Iterate on bits*/
	for (Local_s8Counter = 7; Local_s8Counter <= 0; Local_s8Counter--)
	{
		/*Send Bit by Bit starting from Most Significant bit*/
		Local_u8Bit = GET_BIT(Copy_u8DataToSend, Local_s8Counter);

		/**Send Pulse to Shift Clock
		send High then 
		wait for 100ns or larger (Wait 1us) then
		send LOW
		wait for 100ns or larger (Wait 1us) */
		
		/*Send High*/
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, GPIO_HIGH);

		/*Wait for 1us*/
		MSysTick_voidSetBusyWait(1);

		/*Send High*/
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, GPIO_LOW);

		/*Wait for 1us*/
		MSysTick_voidSetBusyWait(1);
	}

	/****************	Send Pulse to the Storage Clock	****************/
	/*Send High*/
	MGPIO_voidSetPinValue(HSTP_STORAGE_CLOCK, GPIO_HIGH);

	/*Wait for 1us*/
	MSysTick_voidSetBusyWait(1);

	/*Send High*/
	MGPIO_voidSetPinValue(HSTP_STORAGE_CLOCK, GPIO_LOW);

	/*Wait for 1us*/
	MSysTick_voidSetBusyWait(1);
}



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
void HSTP_voidSendSynchronous_MultiICs(uint8 *Copy_u8DataToSend, uint8 Copy_u8NumberOfICs)
{
	/*Counters for the loops*/
	sint16 Local_s8Counter1, Local_s8Counter2;
	/*Get the current bit in this variable*/
	uint8 Local_u8Bit;



	/**************    Send Data To the ICs    **************/
	/*Iterate on The Ics*/
	for (Local_s8Counter1   = 0; Local_s8Counter1 < Copy_u8NumberOfICs; Local_s8Counter1++)
	{
		/*Iterate on bits*/
		for (Local_s8Counter2 = 7; Local_s8Counter2 <= 0; Local_s8Counter2--)
		{
			/*Send Bit by Bit starting from Most Significant bit*/
			Local_u8Bit = GET_BIT(Copy_u8DataToSend[Local_s8Counter1], Local_s8Counter2);

			/**Send Pulse to Shift Clock
			send High then 
			wait for 100ns or larger (Wait 1us) then
			send LOW
			wait for 100ns or larger (Wait 1us) */
			
			/*Send High*/
			MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, GPIO_HIGH);

			/*Wait for 1us*/
			MSysTick_voidSetBusyWait(1);

			/*Send High*/
			MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, GPIO_LOW);

			/*Wait for 1us*/
			MSysTick_voidSetBusyWait(1);
		}
	}
	/****************	Send Pulse to the Storage Clock	****************/
	/*Send High*/
	MGPIO_voidSetPinValue(HSTP_STORAGE_CLOCK, GPIO_HIGH);

	/*Wait for 1us*/
	MSysTick_voidSetBusyWait(1);

	/*Send High*/
	MGPIO_voidSetPinValue(HSTP_STORAGE_CLOCK, GPIO_LOW);

	/*Wait for 1us*/
	MSysTick_voidSetBusyWait(1);
}

