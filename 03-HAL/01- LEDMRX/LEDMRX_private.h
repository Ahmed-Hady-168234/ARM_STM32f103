/**
 * @file LEDMRX_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the LEDMRX Driver User shouldn't see this
 * @version V01
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LEDMRX_PRIVATE_H
#define LEDMRX_PRIVATE_H

/** Register Definition */
     

#define LEDMRX_ROW_SIZE 8
#define LEDMRX_COL_SIZE 8

#define LEDMRX_FRAME_TIME 2500


typedef struct{
    uint8 portMap;
    uint8 pinMap;
}LEDMRX_config_t;

/**
 * @brief This Variable used to release or to pause the LEDMRX display
 */
uint8 Global_u8ReleasedFlag = TRUE;

uint32 Global_u32DisplaySpeed = 1000;
static void HLEDMRX_voidEnableRows(uint8 Copy_u8RowValue);
static void HLEDMRX_voidDisableAllCols(void);











#endif 
