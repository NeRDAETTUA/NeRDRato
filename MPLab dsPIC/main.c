#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include <xc.h>
#include <libpic30.h>

#define BAUDRATE 9600
#define BRGVAL ((FCY/BAUDRATE)/16)-1

int16_t main(void){
    
    _U1RXR = 36;
    _RP37R = 1;
    U1BRG = BRGVAL;
    U1MODEbits.STSEL = 0;
    U1MODEbits.PDSEL = 0;
    U1MODEbits.BRGH = 0;
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;

    while(1){
        U1TXREG = 'a';
        __delay_ms(1000);
    }
}