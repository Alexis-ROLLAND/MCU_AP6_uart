/**
 * @file 
 * @author 	Alexis ROLLAND
 * @date	2024-02
 * @brief 	
 *  
 *
 */

#include "lib_test_lib_uart_ll_pic24_.h" // Inclusion du fichier .h "Applicatif" renommé

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/
uart_config_t   myConfig;   /**< Configuration structure (concrete) */
uart_desc_t     myDevice;   /**< Device descriptor  */


/*	Implémentation du code */
#if  (CURRENT_TEST == TEST_PUTCH_BLOCKING_MODE)

void Initialiser(void){
    
    
}

void mainTask(void){
    
}



#endif  /*  TEST_PUTCH_BLOCKING_MODE    */

#if  (CURRENT_TEST == TEST_PUTS)

void Initialiser(void){
    
}

void mainTask(void){
    
}

#endif  /*  TEST_PUTS    */


#if  (CURRENT_TEST == TEST_RX_ISR)
uint8_t     CarRec = 0;
void Initialiser(void){
    
}

void mainTask(void){
    
    
}

// ISR if UART2 is used - Must be defined because interrupt is automaticaly activated
void _ISR __attribute__((no_auto_psv))  _U2RXInterrupt(void){ 
    
}

#endif  /*  TEST_PUTS    */
