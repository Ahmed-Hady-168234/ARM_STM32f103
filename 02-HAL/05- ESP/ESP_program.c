
/**
 * @file ESP_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the ESP Driver Functions for Target stm32f10x
 * @version V01 
 * @date 2022-09-21
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "USART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

void HESP_voidInit(void)
{
	uint8 Local_u8Status =0 ;
	do 
	{
		/*Stop Echo*/
		MUSART1_voidTransmit(ESP_STOP_ECHO_COMMAND, sizeof( ESP_STOP_ECHO_COMMAND ) );

		/*Check if the command succeeded and the esp8266 responded with ok*/
		Local_u8Status = u8ValidateCommand();
	}while (Local_u8Status == NOT_VALIDATED);

	do 
	{
		/*Set Mode as Station mode*/
		MUSART1_voidTransmit(ESP_SELECT_STATION_MODE_COMMAND, sizeof( ESP_SELECT_STATION_MODE_COMMAND ) );
		/*Check if the command succeeded and the esp8266 responded with ok*/
		Local_u8Status = u8ValidateCommand();
	}while (Local_u8Status == NOT_VALIDATED);
}

ESP_returnType HESP_voidConnectWifi(uint8 *wifiName, uint8 wifiNameLength, uint8 *pass, uint8 passLength)
{
	
	/*Connect To WIFI Command:
			"AT+CWJAP_CUR=”wifiName”,”password”\r\n"
	*/

	ESP_returnType Local_ESPReturn = ESP_OK;

	/*Array to carry the command*/
	uint8 Local_pu8Command[ (ESP_WIFI_NAME_AND_PASSWORD_MAXIMUM_LENGTH + 30) ] ={"AT+CWJAP_CUR=\""};
	/*Counters used in the loops*/
	uint8 Local_u8Counter1, Local_u8Counter2,Local_u8Counter3;

	/*Loop to get the Wifi Name ...  note that 14 is the (AT+CWJAP_CUR=") length  */
	for ( Local_u8Counter1 = 14, Local_u8Counter3 = 0; Local_u8Counter3 <wifiNameLength ;Local_u8Counter1++, Local_u8Counter3++)
	{
		Local_pu8Command[ Local_u8Counter1 ] = wifiName[ Local_u8Counter3 ];
	}

	/*Add the (",") to the command */
	Local_pu8Command[Local_u8Counter1] = '\"';
	Local_u8Counter1++;
	Local_pu8Command[Local_u8Counter1] = ',';

	Local_u8Counter1++;
	Local_pu8Command[Local_u8Counter1] = '\"';
	Local_u8Counter1++;

	/*Add the password to the command*/
	for ( Local_u8Counter2 = 0; Local_u8Counter2 <passLength; Local_u8Counter2++,Local_u8Counter1++)
	{
		Local_pu8Command[Local_u8Counter1] = pass[Local_u8Counter2];
	}

	/*Add the ("\r\n) to the command */
	Local_pu8Command[Local_u8Counter1] = '\"';
	Local_u8Counter1++;

	Local_pu8Command[Local_u8Counter1] = '\r';
	Local_u8Counter1++;
	Local_pu8Command[Local_u8Counter1] = '\n';

	/*Send the command ...   		
	the command length is the constant characters in the command (which is 14 for the AT+CWJAP_CUR=" and 6 for the ","  "\r\n) +
	wifiName Length +
	Password Length */
	MUSART1_voidTransmit(Local_pu8Command, ((14+6)+wifiNameLength+passLength) );

	/*Check the response*/
	Local_ESPReturn = ESPCheckWifiConnection();

	return Local_ESPReturn;
		
}



ESP_returnType ESPCheckWifiConnection(void)
{
	/*TODO to be Implemented */

	return ESP_OK;
}



uint8 u8ValidateCommand(void)
{
	uint8 Local_u8Response[ESP_RESPONSE_ARRAY_LENGTH] = {0};
	uint8 i;
	uint8 Local_u8Temp;
	uint8 Local_u8ReturnStatus =0;

	/*Loop to get the data*/
	for (i = 0; i < ESP_RESPONSE_ARRAY_LENGTH; i++)
	{
		/*Recieve the response*/
		Local_u8Temp = MUSART1_u8Receive();
		/*Check if the receiving is done*/
		if (Local_u8Temp == USART_TIME_OUT)
		{
			/*Received the response break the loop*/
			break;
		}else
		{
			/*MISRA rules*/
			Local_u8Response[i] = Local_u8Temp;
		}		
	}
	/*Check if the return is ok*/
	if (Local_u8Response[0]=='o'&&
		Local_u8Response[0]=='k')
	{
		Local_u8ReturnStatus = VALIDATED;
	}else
	{
		Local_u8ReturnStatus = NOT_VALIDATED;
	}
	return Local_u8ReturnStatus;
}