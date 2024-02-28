/**
 * @file 
 * @author 	Alexis ROLLAND
 * @date	2024-02
 * @brief 	Test app for Grove 12-Channel Capacitor touch Keypad (source code)
 *  
 *
 */


#include "lib_test_Keyboard.h" // Inclusion du fichier .h "Applicatif" renommé

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/
uart_config_t   KeyboardCfg;
uart_config_t   ConsoleCfg;

uart_desc_t     KeyboardDevice;
uart_desc_t     ConsoleDevice;

uart_err_t      Res;

uint8_t         CodeKeyboard = 0;
uint8_t         msg[81];
/*	Implémentation du code */
void Initialiser(void){
    
    // Console Config (19200 8N1 - UART2)
    ConsoleCfg.uartID = _UART2;
    ConsoleCfg.UxMODE = 0x8008;    /**< UART enabled, BRGH = 1, most standard config 8N1   */
    ConsoleCfg.UxSTA = 0x0400;     /**< UART enabled, BRGH = 1, most standard config 8N1   */
    ConsoleCfg.UxBRG = 51;         /**< 19200 bps @Fcy=4MHz and BRGH = 1                    */
    ConsoleCfg.RxIrqPrio = 0;      /**< Priority Interrupt level = 0 (no Rx)             */
    Res = uart_init(&ConsoleDevice, &ConsoleCfg);
    
    // Keyboard Config (9600 8N1 - UART1)
    KeyboardCfg.uartID = _UART1;
    KeyboardCfg.UxMODE = 0x8008;   /**< UART enabled, BRGH = 1, most standard config 8N1   */
    KeyboardCfg.UxSTA = 0x0400;    /**< UART enabled, BRGH = 1, most standard config 8N1   */
    KeyboardCfg.UxBRG = 103;       /**< 9600 bps @Fcy=4MHz and BRGH = 1                    */
    KeyboardCfg.RxIrqPrio = 4;     /**< Priority Interrupt level = 4 (default)             */
    Res = uart_init(&KeyboardDevice, &KeyboardCfg);
    
    
    
    __delay_ms(100);
    uart_puts(&ConsoleDevice,"Test Grove Keyboard - Init OK\n");
}

#ifdef  TEST_SIMPLE_DECODE
void    mainTask(void){
    if (CodeKeyboard !=0){
        sprintf(msg,"Code received : %02X = %c\n",CodeKeyboard,Decode(CodeKeyboard));
        uart_puts(&ConsoleDevice,msg);
        CodeKeyboard = 0;
    }
}
#endif

#ifdef  TEST_GET_MULTICODE_SIZED
uint8_t Code[5];
void    mainTask(void){
    getMulticodeSized(&CodeKeyboard, 4,Code);
    sprintf(msg,"Code (sized) received : %s\n",Code);
    uart_puts(&ConsoleDevice,msg);
}
#endif

#ifdef  TEST_GET_MULTICODE_UNSIZED
uint8_t Code[21];
void    mainTask(void){
    getMulticodeUnsized(&CodeKeyboard, '*',Code);
    sprintf(msg,"Code (sized) received : %s\n",Code);
    uart_puts(&ConsoleDevice,msg);
}
#endif

const uint8_t   tabCar[13]={0,'1','2','3','4','5','6','7','8','9','*','0','#'};
int8_t  Decode(uint8_t Code){
    if ( (Code & 0xE0) != 0xE0 ) return -1;
    
    Code &= 0x0F;
    if ((Code < 1) || (Code >= 0x0D)) return -1;

    return tabCar[Code];
}

void    getMulticodeSized(uint8_t *pCode, uint8_t NbCar,uint8_t *pStr){
    uint8_t CodesRec = 0;
    while (CodesRec <= (NbCar-1)){
        while(*pCode == 0); /**< Waits for a new Code   */
        pStr[CodesRec] = Decode(*pCode);
        CodesRec++;
        *pCode = 0;
    }
    pStr[NbCar] = '\0';
    return;
}

void    getMulticodeUnsized(uint8_t *pCode, uint8_t StopCode,uint8_t *pStr){
    uint8_t CodesRec = 0;
    uint8_t AsciiCode;
    do {
        while(*pCode == 0); /**< Waits for a new Code   */
        AsciiCode = Decode(*pCode);
        pStr[CodesRec] = AsciiCode;
        CodesRec++;
        *pCode = 0;
    } while(AsciiCode != StopCode);
    pStr[CodesRec] = '\0';
    return;
}

// ISR for UART1 (Keyboard) 
void _ISR __attribute__((no_auto_psv))  _U1RXInterrupt(void){ 
    CodeKeyboard = U1RXREG;            /**< retrieve received byte - mandatory */
    IFS0bits.U1RXIF = 0;        /**< Clear IF ( ack interrupt )         */
}

// ISR if UART2 (console) is used - Must be defined because interrupt is automaticaly activated
void _ISR __attribute__((no_auto_psv))  _U2RXInterrupt(void){ 
    uint8_t Dummy = U2RXREG;            /**< retrieve received byte - mandatory */
    IFS1bits.U2RXIF = 0;        /**< Clear IF ( ack interrupt )         */
}