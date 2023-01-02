
/**
 * @file IR_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the IR Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-08-22
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "NVIC_interface.h"
//#include "EXTI0_interface.h"


// void MIR_voidInit(void)
// {
//     	/*Initialize Clocks*/
// 	RCC_voidInitSysClock();
// 	/*Enable GPIOA Clock*/
// 	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPAEN);


// 	GPIO_voidSetPinDirection(GPIOA,GPIO_PIN0,INPUT_FLOATING);		/*A0 Input floating*/

//     /*EXTI*/
// 	/*Set call back before enabling the interrupt*/
// 	MEXTI_voidSetClllBack(voidGetFrame);
// 	MEXTI_voidInit();

//     /*NVIC*/
// 	MNVIC_voidInit();
// 	MNVIC_voidEnableInterrupt(NVIC_EXTI0);/*Enable EXTI0 interrupt*/



// 	/*SysTick*/
// 	MSysTick_voidInit();/*Enable SysTick on AHB/2 = 1mhz ... one tick/count = 1us*/

// }




/**
 * @brief This function will be called after 1sec of the last falling edge (after the frame is sent)
 * @details <pre><b>
 * According to NEC protocol
		u32FrameData[0] should have the start bit
		u32FrameData[1 to 8] should have the address 
		u32FrameData[8 to 16] should have the address inverted
		u32FrameData[17 to 24] should have the data
		u32FrameData[25 to 32] should have the data inverted

		note that 
			u32FrameData[0] .. the start bit .. should have number around 13500 which is the time required for the start bit
			in each byte if the number is around 1125 then the corresponding bit is 0
			in each byte if the number is around 2250 then the corresponding bit is 1
 * </b></pre>
 * @return uint8 represents the data
 */
IR_returnType MIR_u8GetData(void)
{
	uint8 i;
	IR_returnType Local_IRData = 0;

/*TODO Validate the frame .... Address == inverted Address && Data == inverted Data*/

	/*Check the Start bit*/
	if (u32FrameData[17 + i] % 1000 >= 10 && u32FrameData[17 + i] % 1000 <= 14 )/*Correct Start Bit*/
	{
		for (i = 0; i < 8; i++)
		{
			if (u32FrameData[17 + i] % 1000 == 1)
			{
				/*The bit is 0*/
				CLR_BIT(Local_IRData,i);
			}else if(u32FrameData[17 + i] % 1000 == 2)
			{
				/*The bit is 1*/
				SET_BIT(Local_IRData,i);

			}else
			{
				/*ERROR ... MISRA rules*/
			}
		}
	}else
	{
        /*MISRA Rules*/
		/*Incorrect Start bit .. Invalid frame ... ERROR*/
	}

/*Clear Everything*/
	u8StartFlag    = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter  = 0;

	/*Ready to get next pressed button*/
    return Local_IRData;
}

/**
 * @brief This Function Just gets the frame and save it
 */
void MIR_voidGetFrame(void)
{
	/*If it is the first time then it should be the start bit*/
	if(u8StartFlag == FALSE)
	{
 		/*Stop the running timer*/
		MSysTick_voidStopInterval();
		/*Run Another one*/
		MSysTick_voidSetIntervalSingle(1000000, MIR_u8GetData);
		u8StartFlag = TRUE;/*The start bit has come ... move to the next bits in the frame*/
	}
	else
	{
		u32FrameData[u8EdgeCounter]  = MSysTick_u32GetElapsedTime();
		/*Stop the running timer*/
		MSysTick_voidStopInterval();
		/*Run Another one*/
		MSysTick_voidSetIntervalSingle(1000000, MIR_u8GetData);

		u8EdgeCounter++;
	}
}