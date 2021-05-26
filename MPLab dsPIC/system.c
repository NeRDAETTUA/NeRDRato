#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "system.h"

void initClock(){
    // FRCDIV FRC/1; PLLPRE 2; DOZE 1:8; PLLPOST 1:4; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3040;
    
    // TUN Center frequency; 
    OSCTUN = 0x00;
    
    // ROON disabled; ROSEL FOSC; RODIV 0; ROSSLP disabled; 
    REFOCON = 0x00;
    
    // PLLDIV 90; 
    PLLFBD = 0x5A;
    
    // AD1MD enabled; T3MD enabled; T4MD enabled; T1MD enabled; U2MD enabled; T2MD enabled; U1MD enabled; SPI2MD enabled; SPI1MD enabled; C1MD enabled; T5MD enabled; I2C1MD enabled; 
    PMD1 = 0x00;
    
    // IC4MD enabled; IC3MD enabled; OC1MD enabled; IC2MD enabled; OC2MD enabled; IC1MD enabled; OC3MD enabled; OC4MD enabled; 
    PMD2 = 0x00;
    
    // CMPMD enabled; CRCMD enabled; I2C2MD enabled; 
    PMD3 = 0x00;
    
    // CTMUMD enabled; REFOMD enabled; 
    PMD4 = 0x00;
    
    // PTGMD enabled; DMA0MD enabled; 
    PMD7 = 0x00;
    
    // CF no clock failure; NOSC FRCPLL; CLKLOCK unlocked; OSWEN Switch is Complete; 
    __builtin_write_OSCCONH((uint8_t) (0x01));
    __builtin_write_OSCCONL((uint8_t) (0x01));
    
    // Wait for Clock switch to occur
    while (OSCCONbits.OSWEN != 0);
    while (OSCCONbits.LOCK != 1);
}