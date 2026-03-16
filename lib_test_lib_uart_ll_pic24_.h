/**
 * @file     
 * @author 	Alexis ROLLAND
 * @date	2026-03
 * @brief 	
 *  
 *
 */
#ifndef	__LIB_TEST_LIB_UART_LL_PIC24_H__
#define	__LIB_TEST_LIB_UART_LL_PIC24_H_

#ifndef FCY
#define FCY 4000000UL
#endif

#include <libpic30.h>
#include <xc.h>

#include "lib_uart_pic24_ll.h"

#define TEST_PUTCH_BLOCKING_MODE    1
#define TEST_PUTS 2
#define TEST_RX_ISR   3

#define CURRENT_TEST    TEST_PUTCH_BLOCKING_MODE

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
void mainTask();
 


#endif  /*  __LIB_TEST_LIB_UART_LL_PIC24_H_ */



