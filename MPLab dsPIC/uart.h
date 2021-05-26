/* 
 * File: uart.h
 * Author: Diogo Silva
 * Comments:
 * Revision history: 
 */

#ifndef UART_H
#define	UART_H

#include <xc.h>
#include "system.h"

#define BUFFER_SIZE 1024
#define MESSAGE_MAX_SIZE 30

/// Types of Uart messages
enum{
    REQUEST,
    COMMAND
};

/// CircularBuffer for UART RX
typedef struct buffer {
    uint8_t data[BUFFER_SIZE];
    uint16_t size;
    uint16_t in;
    uint16_t out;
} CircularBuffer;

/**
 * @param[in] byte
 * @brief Insert the given byte in the Circular Buffer
 */
void insertBuffer(uint8_t byte);

/**
 * @param[out] byte
 * @brief Pops the last byte from the buffer
 */
uint8_t popBuffer();

/**
 * @param[in] baudrate
 * @brief Initializes uart on pins RP36 and RP37 with specified baud rate
 */
void initUart(uint32_t baudrate);

/**
 * @brief Uart1 RX Interrupt
 */
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void);

/**
 * @brief Process the last Message received via UART
 */
void processUartMessage();

/**
 * @param[in] requestBuffer
 * @param[in] requestSize
 * @brief Answer the request sent from the UART
 */
void handleRequest(uint8_t* requestBuffer, uint8_t requestSize);

/**
 * @param[in] commandBuffer
 * @param[in] commandSize
 * @brief Handles a command received from the UART
 */
void handleCommand(uint8_t* commandBuffer, uint8_t commandSize);
#endif

