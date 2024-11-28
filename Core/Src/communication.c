#include "communication.h"

// Array of AT commands to send to the HC-08 module
char *send_command[NO_OF_COMMANDS] = {  
    "AT",                     // Test command
    "AT+VERSION",             // Query firmware version
    "AT+ROLE=S",              // Set role to slave
    "AT+ROLE=M",              // Set role to master
    "AT+CONT=0",              // Enable connection
    "AT+NAME=CEAC-MFV",       // Set module name
    "AT+ADDR=XINCAMON1234",   // Set module address
    "AT+CONT=?"               // Check connection status
};

// Initialize the HC-08 structure
void HC08_Init(HC08 *hc08, UART_HandleTypeDef *huart) {
    hc08->huart = huart;                          // Assign the UART handle
    memset(hc08->rev_buffer, 0, sizeof(hc08->rev_buffer)); // Clear the receive buffer
    hc08->rev_flag = 0;                           // Reset the receive flag
}

// Send an AT command to the HC-08 module
void HC08_SendCommand(HC08 *hc08, uint8_t command_id) {
    if (command_id >= 0 && command_id < NO_OF_COMMANDS) // Ensure command_id is valid 
    {                         
        char *command = send_command[command_id]; // Get the command from the array
        HAL_UART_Transmit(hc08->huart, (uint8_t *)command, strlen(command), 100); // Transmit the command
        HAL_UART_Transmit(hc08->huart, (uint8_t *)"\r\n", 2, 100); // Transmit end-of-line characters
    }
}

// Receive data from the HC-08 module
void HC08_ReceiveData(HC08 *hc08, char *data) {
    HAL_UART_Receive_IT(hc08->huart, (uint8_t *)data, strlen(data)); // Start receiving in interrupt mode
}

// Process the received data
void HC08_ProcessData(HC08 *hc08) {
    if (hc08->rev_flag) {                         // Check if data is received
        // TODO - Process the received data
    }
}

// Callback function called when data reception is complete
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    extern HC08 hc08_instance; // External HC-08 instance (declare in the main file)
    if (huart == hc08_instance.huart) { // Check if the interrupt belongs to HC-08's UART
        hc08_instance.rev_flag = 1;     // Set the receive flag
        HC08_ReceiveData(&hc08_instance, hc08_instance.rev_buffer); // Receive data
    }
}
