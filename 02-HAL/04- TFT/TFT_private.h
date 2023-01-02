/**
 * @file TFT_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the TFT Driver User shouldn't see this
 * @version V01
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

/** Register Definition */
     



/*M*/
#define NUMBER_OF_PIXELS    20480   /*Number Of Pixels = 160*128 */
 
/*      TFT Commands        */
#define SLPOUT  0x11    /*Sleep Out*/
#define COLMOD  0x3A    /*Color Mode*/
#define DISPON  0x29    /*Display On*/
#define CASET   0x2A    /*Set X(Column) Address(Start, End)*/
#define RASET   0x2B    /*Set Y(Row)    Address(Start, End)*/
#define RAMWR   0x2C    /*Ram Write(Any Data sent after this command will be displayed)*/

/*        TFT Data          */
#define RGB444               0x03        /*4k Colors           (This parameter passed as data after the COLMOD command calling)*/
#define RGB565               0x05        /*65k Colors          (This parameter passed as data after the COLMOD command calling)*/
#define RGB666               0x06        /*262k Colors         (This parameter passed as data after the COLMOD command calling)*/
#define COLUMN_START         0           /*Column Start*/
#define COLUMN_END_BYTE1     0           /*Column End Byte1*/
#define COLUMN_END_BYTE2     127         /*Column End Byte2*/
#define ROW_START            0           /*Row Start*/
#define ROW_END_BYTE1        0         /*Row END Byte1*/
#define ROW_END_BYTE2        159         /*Row END Byte2*/


static void voidWriteCommand(uint8 Copy_u8Command);
static void voidWriteData(uint8 Copy_u8Command);

#endif 
