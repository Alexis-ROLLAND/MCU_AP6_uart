/**
 * @file 
 * @author 	Alexis ROLLAND
 * @date	2024
 * @brief 	
 *  
 *
 */

#include "lib_uart_pic24_ll.h" // Inclusion du fichier .h  renommé

/* Directives de compilation - Macros		*/

/* Déclarations des variables globales 	*/

/*	Implémentation du code */
//------------------------------------------------------------------------------
uart_err_t  uart_init(uart_desc_t *pUart, const uart_config_t *pUartCFG){
    
    return UART_OK;
}
//------------------------------------------------------------------------------
uart_err_t      uart_putch(const uart_desc_t *pUart, uint8_t Car, uart_tx_blocking_t BlockingMode){
     
    
    return UART_OK;
}
//------------------------------------------------------------------------------
uart_err_t      uart_puts(const uart_desc_t *pUart, const uint8_t *pString){
    
    return UART_OK;
}
//------------------------------------------------------------------------------



