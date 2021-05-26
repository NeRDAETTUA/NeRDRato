#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include <xc.h>
#include <libpic30.h>
#include "uart.h"

int16_t main(void){
   
    initClock();
    
    initUart(115200);
      

    while(1){
        __delay_ms(100);
    }
}