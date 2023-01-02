/**
 * @file USART_private.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the Registers and the macros for the USART Driver the User shouldn't see this
 * @version V01
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/****************************************************************/
/*File Guard(Make Sure this file called one time in the .c file)*/
/****************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H


typedef struct
{
    volatile    uint32 SR;
    volatile    uint32 DR;
    volatile    uint32 BRR;
    volatile    uint32 CR1;
    volatile    uint32 CR2;
    volatile    uint32 CR3;
    volatile    uint32 GRPR;
    
}MUSART_Type;

#define    MUSART1 ((volatile    MUSART_Type *)0x40013800)






/*      USART CR1 Control Register register macros     */
#define     CR1_SBK     0    /*Send break*/
#define     CR1_RWU     1    /*Receiver wakeup*/
#define     CR1_RE      2    /*Receiver enable*/
#define     CR1_TE      3    /*Transmitter enable */
#define     CR1_IDLEIE  4    /*IDLE interrupt enable */
#define     CR1_RXNEIE  5    /*RXNE interrupt enable */
#define     CR1_TCIE    6    /*Transmission complete interrupt enable */
#define     CR1_TXEIE   7    /*TXE interrupt enable*/
#define     CR1_PEIE    8    /*PE interrupt enable*/
#define     CR1_PS      9    /*Parity selection*/
#define     CR1_PCE     10   /*Parity control enable*/
#define     CR1_WAKE    11   /*Wakeup method*/
#define     CR1_M       12   /*Word length*/
#define     CR1_UE      13   /*USART enable*/

/*      USART SR Status register register macros     */
#define     SR_PE          0       /*Parity error*/
#define     SR_FE          1       /*Framing error*/
#define     SR_NE          2       /*Noise error flag*/
#define     SR_ORE         3       /*Overrun error*/
#define     SR_IDLE        4       /*IDLE line detected*/
#define     SR_RXNE        5       /*Read data register not empty*/
#define     SR_TC          6       /*Transmission complete*/
#define     SR_TXE         7       /*Transmit data register empty*/
#define     SR_LBD         8       /*LIN break detection flag*/
#define     SR_CTS         9       /*CTS flag*/



#endif
