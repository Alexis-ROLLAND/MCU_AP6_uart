/**
 * @file    lib_AP64_uart.h
 * @author 	Alexis ROLLAND
 * @date	2026-03
 * @brief 	
 */
#ifndef	__LIB_MCU_AP64_H__
#define	__LIB_MCU_AP64_H__

#ifndef FCY
#define FCY 4000000UL
#endif

#include <libpic30.h>
#include <xc.h>

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
 * @brief  Main Task - Must be called from the "while(1)"
 * 
 * @param   none	
 * 
 * @return   nothing
 *
 */
void    mainTask(void);
 
 /**
 * @brief  
 * 
 * @param	
 * 
 * @return   
 *
 */
 
 /**
 * @brief  
 * 
 * @param	
 * 
 * @return   
 *
 */
 
 


#endif      /*  __LIB_MCU_AP64_H__   */



