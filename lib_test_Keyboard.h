/**
 * @file  
 * @author 	Alexis ROLLAND
 * @date	2024-2
 * @brief 	Test app for Grove 12-Channel Capacitor touch Keypad (header)
 *  
 *
 */
#ifndef	__LIB_TEST_KEYBOARD_H__
#define	__LIB_TEST_KEYBOARD_H__

#ifndef FCY
#define FCY 4000000UL
#endif

//#define TEST_SIMPLE_DECODE
//#define TEST_GET_MULTICODE_SIZED
#define TEST_GET_MULTICODE_UNSIZED

#include <libpic30.h>
#include <xc.h>
#include <stdio.h>  // for sprintf function

#include "lib_uart_pic24_ll.h"

/**
 * @brief Global init function/task 
 * 
 * @param	None
 * 
 * @return  Nothing 
 *
 */
void Initialiser(void);

/**
 * @brief  
 * 
 * @param	
 * 
 * @return   
 *
 */
void    mainTask(void);
 
 /**
 * @brief   Transcode function between raw "keyboard code" to ASCII code
 *      Keyboard Code       ASCII
 *      0xE1                '1'
 *      0xE2                '2'
 *      ...                 ...
 *      0xEA                '*'
 *      0xEB                '0'
 *      0xEC                '#'
 * 
 * @param[IN] : Code - Raw Keyboard Code	
 * 
 * @return   ASCII code or -1 (error) if provided Code is incorrect( <0xE1 or >0xEC )
 *
 */
int8_t  Decode(uint8_t Code); 

/**
 * @brief   Receive codes until reception of 'StopCode' (ASCII), creates a 'C' string with ASCII values
 * 
 * @param[in]   pCode : Address of the received code (one byte)
 * @param       StopCode : Validation code (last code of the message) - ASCII value
 * @param[out]  pStr : Address of the target string ('C' formatted)   	
 * 
 * @return   void
 *
 * @Attention Blocking function 
 */ 
void    getMulticodeUnsized(uint8_t *pCode, uint8_t StopCode,uint8_t *pStr);
 

/**
 * @brief   Receive NbCar codes, creates a 'C' string with ASCII values
 * 
 * @param[in]   pCode : Address of the received code (one byte)
 * @param       NbCar : Number of characters to receive
 * @param[out]  pStr : Address of the target string ('C' formatted)   	
 * 
 * @return   void
 *
 * @Attention Blocking function 
 */
void    getMulticodeSized(uint8_t *pCode, uint8_t NbCar,uint8_t *pStr);

#endif  /*  __LIB_TEST_KEYBOARD_H__ */



