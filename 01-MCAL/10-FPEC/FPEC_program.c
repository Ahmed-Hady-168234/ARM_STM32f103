/**
 * @file FPEC_program.c
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This File contains the source code of the FPEC(Flash memory Program/Erase Controller) Driver Functions for Target stm32f10x
 * @version V01
 * @date 2022-10-05
 * @copyright Copyright (c) 2022
 */
#include "STD_TYPES.h"

#include "BIT_MATH.h"


#include "FPEC_private.h"
#include "FPEC_interface.h"
#include "FPEC_Config.h"




void MFPEC_voidWriteToFlash(uint16 Copy_u16Data, uint32 Copy_u32Address)
{
    /*Check that no main Flash memory operation is ongoing by checking the BSY bit in the FLASH_SR register.*/
    while (GET_BIT(FPEC -> SR, SR_BSY) == 1);
    
    /*Set the PG bit in the FLASH_CR register (Flash programming chosen)*/
    SET_BIT(FPEC -> CR, CR_PG);

    
    /*Select the desired address to write on*/
    FPEC -> AR = Copy_u32Address;
    
    /*Perform the data write (half-word) at the desired address*/


    /*Wait for the BSY bit to be reset*/

    /*Read the programmed value and verify*/   

    /*Check the programmed value by reading the programmed address*/
  
    }
    
}
