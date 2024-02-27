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
#ifdef  TEST_PUTCH_BLOCKING_MODE

void Initialiser(void){
    uart_err_t  Res;
    
    myConfig.uartID = _UART2;   /**< Choosen UART is UART2  */
    myConfig.UxMODE = 0x8008;   /**< UART enabled, BRGH = 1, most standard config 8N1   */
    myConfig.UxSTA = 0x0400;    /**< UART enabled, BRGH = 1, most standard config 8N1   */
    myConfig.UxBRG = 103;       /**< 9600 bps @Fcy=4MHz and BRGH = 1                    */
    myConfig.RxIrqPrio = 4;     /**< Priority Interrupt level = 4 (default)             */
    
    Res = uart_init(&myDevice, &myConfig);
}

void mainTask(void){
    static uint8_t  Car='A';
    uart_err_t  Res;
    __delay_ms(500);
    Res = uart_putch(&myDevice,Car,UART_TX_BLOCKING_MODE);
    if (Car < 'Z') Car++;
    else Car = 'A';
}

// ISR if UART2 is used - Must be defined because interrupt is automaticaly activated
uint8_t Dummy;
void _ISR __attribute__((no_auto_psv))  _U2RXInterrupt(void){ 
    Dummy = U2RXREG;            /**< retrieve received byte - mandatory */
    IFS1bits.U2RXIF = 0;        /**< Clear IF ( ack interrupt )         */
}

#endif  /*  TEST_PUTCH_BLOCKING_MODE    */

#ifdef  TEST_PUTS

void Initialiser(void){
    uart_err_t  Res;
    
    myConfig.uartID = _UART2;   /**< Choosen UART is UART2  */
    myConfig.UxMODE = 0x8008;   /**< UART enabled, BRGH = 1, most standard config 8N1   */
    myConfig.UxSTA = 0x0400;    /**< UART enabled, BRGH = 1, most standard config 8N1   */
    myConfig.UxBRG = 103;       /**< 9600 bps @Fcy=4MHz and BRGH = 1                    */
    myConfig.RxIrqPrio = 4;     /**< Priority Interrupt level = 4 (default)             */
    
    Res = uart_init(&myDevice, &myConfig);
}

void mainTask(void){
    uart_err_t  Res;
    __delay_ms(500);
    Res = uart_puts(&myDevice,"Hello World !\n");
}

// ISR if UART2 is used - Must be defined because interrupt is automaticaly activated
uint8_t Dummy;
void _ISR __attribute__((no_auto_psv))  _U2RXInterrupt(void){ 
    Dummy = U2RXREG;            /**< retrieve received byte - mandatory */
    IFS1bits.U2RXIF = 0;        /**< Clear IF ( ack interrupt )         */
}

#endif  /*  TEST_PUTS    */


#ifdef  TEST_RX_ISR
uint8_t     CarRec = 0;
void Initialiser(void){
    uart_err_t  Res;
    
    myConfig.uartID = _UART2;   /**< Choosen UART is UART2  */
    myConfig.UxMODE = 0x8008;   /**< UART enabled, BRGH = 1, most standard config 8N1   */
    myConfig.UxSTA = 0x0400;    /**< UART enabled, BRGH = 1, most standard config 8N1   */
    myConfig.UxBRG = 103;       /**< 9600 bps @Fcy=4MHz and BRGH = 1                    */
    myConfig.RxIrqPrio = 4;     /**< Priority Interrupt level = 4 (default)             */
    
    Res = uart_init(&myDevice, &myConfig);
}

void mainTask(void){
    if (CarRec != 0){
        uart_putch(&myDevice,CarRec,UART_TX_BLOCKING_MODE);
        CarRec  = 0;
    }
}

// ISR if UART2 is used - Must be defined because interrupt is automaticaly activated
void _ISR __attribute__((no_auto_psv))  _U2RXInterrupt(void){ 
    CarRec = U2RXREG;            /**< retrieve received byte - mandatory */
    IFS1bits.U2RXIF = 0;        /**< Clear IF ( ack interrupt )         */
}

#endif  /*  TEST_PUTS    */
