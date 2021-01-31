#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include <xc.h>
#include <libpic30.h>

int16_t main(void){
    _TRISA0 = 0;

    while(1){
        _LATA0 = 0;
        __delay_ms(1000);
        _LATA0 = 1;
        __delay_ms(1000);
    }
}