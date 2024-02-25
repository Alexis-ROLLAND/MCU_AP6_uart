/**
 * @file 
 * @author 	Alexis ROLLAND
 * @date	
 * @brief 	
 *  
 *
 */


#include "lib_AP6_uart.h" // Inclusion du fichier .h "Applicatif" renommé

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/
uint8_t CarRec = 'A';   /**< Init CarRec variable with dummy value ('A')    */

/*	Implémentation du code */
//------------------------------------------------------------------------------
void Initialiser(void){
    U2MODE = 0x8008;    /**< UART enabled, BRGH = 1, most standard config 8N1  */
    U2STA = 0x0400;     /**< UART enabled, BRGH = 1, most standard config 8N1  */
    U2BRG = 103;        /**< 9600 bps @Fcy=4MHz and BRGH = 1                   */
    
    IFS1bits.U2RXIF = 0;    /**< Clear IF (security)    */    
    IPC7bits.U2RXIP = 4;    /**< Set Uart Interrupt priority to 4 (default ISR prioriry)    */
    IEC1bits.U2RXIE = 1;    /**< Enable UART RX Interrupt   */
}
//------------------------------------------------------------------------------
void mainTask(void){
    __delay_ms(250);            /**< Wait 250ms                     */
    while(U2STAbits.UTXBF);     /**< Wait while TX Buffer is Full   */
    U2TXREG = CarRec;           /**< Send Byte                      */
}
//------------------------------------------------------------------------------
// ISR if UART2 is used
void _ISR __attribute__((no_auto_psv))  _U2RXInterrupt(void){ 
    CarRec = U2RXREG;           /**< Get received byte update CarRec variable   */
    IFS1bits.U2RXIF = 0;        /**< Clear IF ( ack interrupt )                 */
}
//------------------------------------------------------------------------------
