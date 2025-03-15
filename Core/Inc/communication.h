#ifndef HC08_H
#define HC08_H

#include "global.h"
#include "stm32f4xx_hal.h"
// Define command indices

#define SIZE_BUFFER 8

#define FW 0    // Forward command index
#define BW 1    // Backward command index
#define LEFT 2  // Left command index
#define RIGHT 3 // Right command index

#define TEST_COMMAND 0    // Test command index
#define CHECK_VERSION 1   // Check module version
#define SET_ROLE_SLAVE 2  // Set module role to slave
#define SET_ROLE_MASTER 3 // Set module role to master
#define SET_CONNECT 4     // Enable connection
#define SET_NAME 5        // Set module name
#define SET_ADDR 6        // Set module address
#define CHECK_CONNECT 7   // Check connection status

#define MODE_DIR 8
#define MODE_ACTION 16

#define CTRL_END 0x00
#define CTRL_UP 0x01 << MODE_DIR
#define CTRL_DOWN 0x02 << MODE_DIR
#define CTRL_LEFT 0x04 << MODE_DIR
#define CTRL_RIGHT 0x08 << MODE_DIR

#define CTRL_START 0x01 << MODE_ACTION
#define CTRL_SELECT 0x02 << MODE_ACTION
#define CTRL_TRIANGLE 0x04
#define CTRL_CIRCLE 0x08 << MODE_ACTION
#define CTRL_CROSS 0x10 << MODE_ACTION
#define CTRL_SQUARE 0x20 << MODE_ACTION

#define NO_OF_COMMANDS 8 // Number of commands
// Structure for HC-08 communication
typedef struct
{
    UART_HandleTypeDef *huart; // UART handle for communication
    uint8_t rev_buffer[SIZE_BUFFER];       // Buffer to store received data
    uint8_t rev_flag;          // Flag to indicate data received
} HC08;

extern uint32_t extract_data;

// HC-08 function prototypes
void HC08_Init(HC08 *hc08, UART_HandleTypeDef *huart); // Initialize HC-08 module
void HC08_SendCommand(HC08 *hc08, uint8_t command_id); // Send AT command to HC-08
//void HC08_ReceiveData(HC08 *hc08, uint8_t *data);         // Receive data from HC-08
void HC08_ProcessData(HC08 *hc08);                     // Process received data

#endif
