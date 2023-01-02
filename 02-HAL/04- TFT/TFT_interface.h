/**
 * @file TFT_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the TFT Driver that the User can see and use
 * @version V01
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H
 


void HTFT_voidInit(void);

/*Const is to make sure the array will be placed in the flash(Enough space) not the RAM(no memory enough) like we did with the sound lecture21*/
void HTFT_voidDisplayImage(const uint16 *Copy_u16Image);


/*You should Set Pins Direction ... TFT_A0_PIN, TFT_RESET_PIN as output push pull 2MHZ
 And Clock pin as output 10MHZ (usually pin A5, Alternative Function Push Pull)  
 AND MISO pin as output 10MHZ  (usually pin A7, Alternative Function Push Pull) */

	
#endif 


