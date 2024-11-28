#ifndef HC08_H
#define HC08_H

#include "global.h"
// Define command indices
#define FW 0                  // Forward command index
#define BW 1                  // Backward command index
#define LEFT 2                // Left command index
#define RIGHT 3               // Right command index

#define TEST_COMMAND 0        // Test command index
#define CHECK_VERSION 1       // Check module version
#define SET_ROLE_SLAVE 2      // Set module role to slave
#define SET_ROLE_MASTER 3     // Set module role to master
#define SET_CONNECT 4         // Enable connection
#define SET_NAME 5            // Set module name
#define SET_ADDR 6            // Set module address
#define CHECK_CONNECT 7       // Check connection status

#define NO_OF_COMMANDS 8        // Number of commands
// Structure for HC-08 communication
typedef struct {
    UART_HandleTypeDef *huart;  // UART handle for communication
    char rev_buffer[50];        // Buffer to store received data
    uint8_t rev_flag;           // Flag to indicate data received
} HC08;

// HC-08 function prototypes
void HC08_Init(HC08 *hc08, UART_HandleTypeDef *huart);     // Initialize HC-08 module
void HC08_SendCommand(HC08 *hc08, uint8_t command_id);     // Send AT command to HC-08
void HC08_ReceiveData(HC08 *hc08, char *data);             // Receive data from HC-08
void HC08_ProcessData(HC08 *hc08);                        // Process received data

#endif
