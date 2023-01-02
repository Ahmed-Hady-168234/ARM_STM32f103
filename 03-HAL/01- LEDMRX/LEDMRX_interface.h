/**
 * @file LEDMRX_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the LEDMRX Driver that the User can see and use
 * @version V02
 * @details Adding new functions 
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H
 



 typedef uint8 LEDMRX_returnType;

void HLEDMRX_voidInit(void);
LEDMRX_returnType HLEDMRX_voidDisplayChar(uint8 *Copy_u8Data);
LEDMRX_returnType HLEDMRX_voidDisplayMovingWord(uint8 *Copy_u8Data, uint8 Copy_u8DataSize, uint32 Copy_u32DelayCounter);
void HLEDMRX_voidReleaseDisplay(void);
void HLEDMRX_voidPauseDisplay(void);
void HLEDMRX_voidSpeedUpDisplay(void);
void HLEDMRX_voidSlowDownDisplay(void);


/*LEDMRX Return Types used to check if the function succeeded or there is a error */
#define LEDMRX_OK                            ((LEDMRX_returnType) 0)/*The function succeeded*/
#define LEDMRX_NULL_POINTER                  ((LEDMRX_returnType) 1)/*The input pointer passed is NULL*/
#define LEDMRX_INVALID_NUMBER                ((LEDMRX_returnType) 2)/*The input value passed is invalid*/


#endif 


