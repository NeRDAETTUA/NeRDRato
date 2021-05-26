/*
 * File:   uart.c
 * Author: Diogo Silva
 *
 * Created on 11 April 2021, 18:13
 */

#include "uart.h"

/// Initialize the CircularBuffer
static volatile CircularBuffer buffer = {{0},0,0,0};

void insertBuffer(uint8_t byte){
    buffer.data[buffer.in++] = byte;
    buffer.size++;
    if(buffer.in >= BUFFER_SIZE)
        buffer.in = 0;
    
    return;
}

uint8_t popBuffer(){
    uint8_t byte = buffer.data[buffer.out++];
    buffer.size--;
    if(buffer.out >= BUFFER_SIZE)
        buffer.out = 0;
    
    return byte;
}

void initUart(uint32_t baudrate){
    /// Set pin RP36 as Uart 1 RX
    _U1RXR = 36;
    
    /// Set pin RP37 as Uart 1 TX
    _RP37R = 1;
    
    /// BRGVAL = (FCY)/(baudrate*4) - 1 when UART is in High-Speed mode
    uint32_t BRGVAL = ((FCY/baudrate)/4)-1;
    U1BRG = BRGVAL;
    
    /// High-Speed mode enabled
    U1MODEbits.BRGH = 1;
    
    /// Select one stop bit
    U1MODEbits.STSEL = 0;
    
    /// Select 8-bit data, no parity
    U1MODEbits.PDSEL = 0;
    
    /// Enable Uart 1
    U1MODEbits.UARTEN = 1; 
    
    /// Enable Uart 1 Transmit
    U1STAbits.UTXEN = 1; 
    
    /// Set Uart 1 RX Interrupt Flag to 0
    IFS0bits.U1RXIF = 0;
    
    /// Set Uart 1 RX Interrupt Priority to 6
    IPC2bits.U1RXIP = 6;
    
    /// Enable Uart 1 RX Interrupts
    IEC0bits.U1RXIE = 1;
        
    return;
}

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void){
    uint8_t byte = U1RXREG;
    
    insertBuffer(byte);
    
    /// If packet ending character(0x03) has been received process the received Message
    if(byte == 0x03)
        processUartMessage();
    
    IFS0bits.U1RXIF = 0;
}

void processUartMessage(){
    
    /// Discard buffer until message start byte(0x02)
    while(popBuffer() != 0x02);
    
    uint8_t message[MESSAGE_MAX_SIZE];
    uint8_t messageSize = 0;
    uint8_t byte;
    uint8_t subtractFlag = 0;
    
    while(messageSize < MESSAGE_MAX_SIZE){
        byte = popBuffer();
        
        if(byte == 0x03){
            break;
        }else if(subtractFlag){ /// To send 0x02 or 0x03 as data send 0x10 and 0x10 + the value you want to send in the next byte
            message[messageSize++] = byte - 0x10;
            subtractFlag = 0;
        }else if(byte == 0x10){
            subtractFlag = 1;
        }else{
            message[messageSize++] = byte;
        }
    }

    /// Message[1] indicates the type of message(Request or Command)
    if(message[1] == REQUEST){
        handleRequest(message, messageSize);
    }else if(message[1] == COMMAND){
        handleCommand(message, messageSize);
    }
    
    return;
}

void handleRequest(uint8_t* requestBuffer, uint8_t requestSize){
    return;
}

void handleCommand(uint8_t* commandBuffer, uint8_t commandSize){
    return;
}