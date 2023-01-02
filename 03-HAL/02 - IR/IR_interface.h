/**
 * @file IR_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the IR Driver that the User can see and use
 * @version V01
 * @date 2022-08-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H
 

typedef uint8 IR_returnType;
#define IR_POWER_BUTTON         ((IR_returnType) 69)
#define IR_MUTE_BUTTON          ((IR_returnType) 70)

void MIR_voidGetFrame(void);
IR_returnType MIR_u8GetData(void);


/**<pre><b><
 * HOW TO USE THIS DRIVER:
 * 1- Initialize The RCC Driver(Call RCC_voidInitSysClock()).
 * 2- Enable The clock of the required peripheral bus(The bus that you will enable its External Interrupt) ...
 *       for example use GPIOA PIN0 then enable the clock in APB2 bus(Call RCC_voidEnableClock()).
 * 3- Set The pin direction to INPUT_FLOATING (set GPIOA PIN0 as INPUT_FLOATING .. Call GPIO_voidSetPinDirection() )
 * 4- Set MIR_voidGetFrame() as The External interrupt call back function ...(pass MIR_voidGetFrame to MEXTI_voidSetCallBack() ).
 * 5- Initialize The EXTI (Call MEXTI_voidInit()).
 * 6- Initialize The NVIC (Call MNVIC_voidInit()).
 * 7- Enable The Interrupt (in out Example we use NVIC_EXTI0 .. so call MNVIC_voidEnableInterrupt() and pass  NVIC_EXTI0 to it).
 * 8- Initialize The SysTick Driver ( Call MSysTick_voidInit() ).
 * 9- Receive The Data by calling MIR_u8GetData()
 * /b></pre>
*/



#endif 


