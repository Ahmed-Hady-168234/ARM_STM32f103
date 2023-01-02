/**
 * @file OS_interface.h
 * @author Ahmed Hady (ahmed168234@gmail.com)
 * @brief This file contains the function headers and the macros for the OS Driver that the User can see and use
 * @version V01
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H
 

 
typedef struct
{
    uint16 periodicity;
    void (*taskHandler) (void);
    uint8 firstDealy;
    TaskState state;
}Task;



#endif 
