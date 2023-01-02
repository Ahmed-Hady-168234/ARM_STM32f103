
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

#include"SysTick_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"
/*Array Of Tasks 	Array of Structs*/
Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

/**
 * @brief This Function Creates a task
 * 
 * @param Copy_u8Priority 		The Task Priority 
 * @param Copy_u16Periodicity  	The Task Periodicity
 * @param Copy_voidTaskHanlder 	The Task Handler(pointer to function)
 * @param Copy_u8FirstDelay 	The first delay(denotes when the task should start after the schedular starts)
 * @return OS_returnType 
 * <pre><b>
 * return options
 * 		OS_E_OK: 			The Task state is set Successfully
 * 		OS_WRONG_INPUT:  	ERROR invalid input parameter
 * 								may be The Task Priority is not in range or
 *									   The periodicity is 0
 *									   The Task Handler Points to NULL
 * </b></pre>
 */
OS_returnType SOS_voidCreateTask(uint8 Copy_u8Priority, uint16 Copy_u16Periodicity, void (*Copy_voidTaskHanlder) (void), uint8 Copy_u8FirstDelay)
{
	/*Variable to return*/
	OS_returnType Local_OSReturnStatus = OS_E_OK;
	/*ERROR Handling*/
	if (Copy_u8Priority < NUMBER_OF_TASKS	||/*Is the priority input is in range?*/
		Copy_u16Periodicity > 0				||/*Is the periodicity is larger than zero*/
		Copy_voidTaskHanlder != NULL)		  /*Is Task Handler Doesn't point to NULL*/
	{
		OS_Tasks[Copy_u8Priority].periodicity = Copy_u16Periodicity;
		OS_Tasks[Copy_u8Priority].taskHandler = Copy_voidTaskHanlder;
		OS_Tasks[Copy_u8Priority].firstDealy = Copy_u8FirstDelay;
		OS_Tasks[Copy_u8Priority].state = TASK_READY;
	}else
	{
		/*The Task Priority should be in range ... should be less Than NUMBER_OF_TASKS*/
		/*The periodicity should be at least 1*/
		/*The Task Handler Can't Point to NULL*/
		Local_OSReturnStatus = OS_WRONG_INPUT;

	}
	return Local_OSReturnStatus;
}

/**
 * @brief   This Function Starts The OS
 * @details This Function Starts The OS by initializing the SysTick and starting The periodic Timer
 * @pre You Should Configure The driver see OS_config.h also you should Create At least one Task
 */
void SOS_voidStart(void)
{
	/*Initialization */
	MSysTick_voidInit();
	/*Tick => 1 msec*/
	/*HSE 8mhz/8 = 1us so 1000 us = 1ms*/
	MSysTick_voidSetIntervalPeriodic(TICK_TIME_IN_US,SOS_voidSchedular);
}

/**
 * @brief This is the Schedular Function it is called every TICK_TIME_IN_US to Run the task that has the turn
 * @pre You Should Call SOS_voidStart() to let the Schedular run
 */
void SOS_voidSchedular(void)
{
	uint8 i;
	/*Iterate on the Tasks*/
	for ( i = 0; i < NUMBER_OF_TASKS; i++)
	{
		/*ERROR Handling*/
		/*Check If the Handler Exist*/
		if (OS_Tasks[i].taskHandler != NULL)
		{
			/*Check If the Task is In ready State*/
			if (OS_Tasks[i].state == TASK_READY)
			{
				if ( OS_Tasks[i].firstDealy == 0)
				{
					OS_Tasks[i].firstDealy = OS_Tasks[i].periodicity-1;/*The first delay becomes the periodicity*/
					OS_Tasks[i].taskHandler();
				}else
				{
					OS_Tasks[i].firstDealy--;
				}
			}else
			{
				/*The Task can't run unless it is in ready state*/
				/*Do Nothing .. MISRA Rules*/
			}
		}else
		{
			/*Task Handler Can't point to null(There is no function to call)*/
			/*ERROR ... Do Nothing .. MISRA Rules*/
		}
	}
}

/**
 * @brief This Function Sets the Task State to Ready
 * 
 * @param Copy_u8TaskId The function's ID
 * @return OS_returnType /pre><b>
 * return options
 * 		OS_E_OK: 			The Task state is set Successfully
 * 		OS_TASK_NOT_EXIST:  ERROR There is no Task Exist to set 
 * </b></pre>
 */
OS_returnType SOS_voidResumeTask(uint8 Copy_u8TaskId)
{
	/*Variable to return*/
	OS_returnType Local_OSReturnStatus = OS_E_OK;
	/*Error Handling*/
	/*Check if the Task is Exist*/
	if (OS_Tasks[Copy_u8TaskId].taskHandler != NULL)
	{
		/*Set The Task State to Ready*/
		OS_Tasks[Copy_u8TaskId].state = TASK_READY;
	}else
	{
		/*There is no Task to set its state*/
		/*ERROR .. MISRA Rules*/
		Local_OSReturnStatus = OS_TASK_NOT_EXIST;
	}
	return Local_OSReturnStatus;
}

/**
 * @brief This Function Sets the Task State to Suspended
 * 
 * @param Copy_u8TaskId The function's ID
 * @return OS_returnType /pre><b>
 * return options
 * 		OS_E_OK: 			The Task state is set Successfully
 * 		OS_TASK_NOT_EXIST:  ERROR There is no Task Exist to set 
 * </b></pre>
 */
OS_returnType SOS_voidSuspendTask(uint8 Copy_u8TaskId)
{
	/*Variable to return*/
	OS_returnType Local_OSReturnStatus = OS_E_OK;
	/*Error Handling*/
	/*Check if the Task is Exist*/
	if (OS_Tasks[Copy_u8TaskId].taskHandler != NULL)
	{
		/*Set The Task State to Ready*/
		OS_Tasks[Copy_u8TaskId].state = TASK_SUSPENDED;
	}else
	{
		/*There is no Task to set its state*/
		/*ERROR .. MISRA Rules*/
		Local_OSReturnStatus = OS_TASK_NOT_EXIST;
	}
	return Local_OSReturnStatus;
}

/**
 * @brief This Function Deletes a task
 * 
 * @param Copy_u8TaskId The function's ID
 * @return OS_returnType /pre><b>
 * return options
 * 		OS_E_OK: 			The Task state is set Successfully
 * 		OS_TASK_NOT_EXIST:  ERROR There is no Task Exist to delete 
 * </b></pre>
 */
OS_returnType SOS_voidDeleteTask(uint8 Copy_u8TaskId)
{
	/*Variable to return*/
	OS_returnType Local_OSReturnStatus = OS_E_OK;
	/*Error Handling*/
	/*Check if the Task is Exist*/
	if (OS_Tasks[Copy_u8TaskId].taskHandler != NULL)
	{
		/*Delete The Task... make the task handler points to NULL*/
		OS_Tasks[Copy_u8TaskId].taskHandler = NULL;
	}else
	{
		/*There is no Task to set its state*/
		/*ERROR .. MISRA Rules*/
		Local_OSReturnStatus = OS_TASK_NOT_EXIST;
	}
	return Local_OSReturnStatus;
}