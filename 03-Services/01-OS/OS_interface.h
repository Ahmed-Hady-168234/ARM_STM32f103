/**
 * @file OS_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the OS Driver that the User can see and use
 * @version V01
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H
 

OS_returnType SOS_voidCreateTask(uint8 Copy_u8Priority, uint16 Copy_u16Periodicity, void (*ptr) (void), uint8 Copy_u8FirstDelay);
/*
 * return options
 * 		OS_E_OK: 			The Task state is set Successfully
 * 		OS_WRONG_INPUT:  	ERROR invalid input parameter
 * 								may be The Task Priority is not in range or
 *									   The periodicity is 0
 *									   The Task Handler Points to NULL
*/

void SOS_voidStart(void);
void SOS_voidSchedular(void);
OS_returnType SOS_voidResumeTask(uint8 Copy_u8TaskId);
/*
 * return options
 * 		OS_E_OK: 			The Task state is set Successfully
 * 		OS_TASK_NOT_EXIST:  ERROR There is no Task Exist to set 
*/

OS_returnType SOS_voidSuspendTask(uint8 Copy_u8TaskId);
/*
 * return options
 * 		OS_E_OK: 			The Task state is set Successfully
 * 		OS_TASK_NOT_EXIST:  ERROR There is no Task Exist to set 
*/
OS_returnType SOS_voidDeleteTask(uint8 Copy_u8TaskId);
/*
 * return options
 * 		OS_E_OK: 			The Task state is set Successfully
 * 		OS_TASK_NOT_EXIST:  ERROR There is no Task Exist to delete 
*/

typedef uint8 TaskState;
#define TASK_DORMANT        ((TaskState)0)
#define TASK_READY          ((TaskState)1)
#define TASK_RUNNING        ((TaskState)2)
#define TASK_WAITING        ((TaskState)3)
#define TASK_SUSPENDED      ((TaskState)4)

typedef uint8 OS_returnType;
#define OS_E_OK             ((OS_returnType)0)
#define OS_WRONG_INPUT      ((OS_returnType)1)
#define OS_TASK_NOT_EXIST   ((OS_returnType)2)

#endif 
