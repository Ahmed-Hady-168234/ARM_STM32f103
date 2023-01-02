/**
 * @file FPEC_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the FPEC(Flash memory Program/Erase Controller) Driver the User shouldn't see this
 * @version V01
 * @date 2022-10-05
 * @details Adding a configurable time out for any waiting loop
 * @copyright Copyright (c) 2022
 * 
 */

/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H


/*0x40022000    AHB */
typedef struct 
{
    volatile uint32 ACR;
    volatile uint32 KEYR;
    volatile uint32 OPTKEYR;
    volatile uint32 SR;
    volatile uint32 CR;
    volatile uint32 AR;
    volatile uint32 OBR;
}FPEC_Type;



#define FPEC    ((volatile FPEC_Type *)0x40022000)


/*      Flash control register (FLASH_CR) macros     */
#define     CR_PG        0
#define     CR_PER       1
#define     CR_MER       2 
#define     CR_OPTPG     4
#define     CR_OPTER     5
#define     CR_STRT      6
#define     CR_LOCK      7
#define     CR_OPTWRE    9
#define     CR_ERRIE     10
#define     CR_EOPIE     12



/*      Flash status register (FLASH_SR) macros     */
#define SR_BSY       0
#define SR_PGERR     1
#define SR_WRPRTERR  2
#define SR_EOP       3



#endif
