/**
 * @file SPI_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the SPI Driver the User shouldn't see this
 * @version V01
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

 
typedef struct
{
    volatile uint32  CR1    ;
    volatile uint32  CR2    ;
    volatile uint32  SR     ;
    volatile uint32  DR     ;
    volatile uint32  CRCPR  ;
    volatile uint32  RXCRCR ;
    volatile uint32  TXCRCR ;
    volatile uint32  I2SCFGR;
    volatile uint32  I2SPR  ;
}SPI_t;

void (*Global_CallBackFunc)(uint8) ;

#define     MSPI1    ((SPI_t *)0x40013000)

/*SPI CR2 Register bits*/
#define TXEIE       7 
#define RXNEIE      6
#define ERRIE       5
#define SSOE        2
#define TXDMAEN     1
#define RXDMAEN     0



/***********************    Configuration Macros    ***********************/

/*      SPI CR1 register macros     */
/* Clock Phase select*/
#define READ_THEN_WRITE 0
#define WRITE_THEN_READ 1

/*Clock polarity select*/
#define IDLE_LOW_RISING_IS_FIRST_EDGE     0
#define IDLE_HIGH_FALLING_IS_FIRST_EDGE   1

/*Master/Slave Select*/
#define SLAVE  0
#define MASTER  1

/*Baud Rate Select*/
#define APB2_CLOCK_DIV_2    0b000
#define APB2_CLOCK_DIV_4    0b001
#define APB2_CLOCK_DIV_8    0b010
#define APB2_CLOCK_DIV_16   0b011
#define APB2_CLOCK_DIV_32   0b100
#define APB2_CLOCK_DIV_64   0b101
#define APB2_CLOCK_DIV_128  0b110
#define APB2_CLOCK_DIV_256  0b111
#endif
