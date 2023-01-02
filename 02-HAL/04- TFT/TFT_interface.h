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

/*TFT Return Type*/ 
typedef uint8 TFT_returnType;
#define TFT_E_OK             ((TFT_returnType)0x0)
#define TFT_INVALID_INPUT    ((TFT_returnType)0x1)

void HTFT_voidInit(void);

/*Const is to make sure the array will be placed in the flash(Enough space) not the RAM(no memory enough) like we did with the sound lecture21*/
void HTFT_voidDisplayImage(const uint16 *Copy_u16Image);

void HTFT_voidFillColor(uint16 Copy_u16Color);
TFT_returnType HTFT_voidDrawRect(uint8 Copy_u8X1, uint8 Copy_u8X2, uint8 Copy_u8Y1, uint8 Copy_u8Y2, uint16 Copy_u16Color);

/*You should Set Pins Direction ... TFT_A0_PIN, TFT_RESET_PIN as output push pull 2MHZ
 And Clock pin as output 10MHZ (usually pin A5, Alternative Function Push Pull)  
 AND MISO pin as output 10MHZ  (usually pin A7, Alternative Function Push Pull) */

	
#endif 


