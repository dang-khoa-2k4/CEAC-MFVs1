#include "communication.h"

// Array of AT commands to send to the HC-08 module
char *send_command[NO_OF_COMMANDS] = {
	"AT",					// Test command
	"AT+VERSION",			// Query firmware version
	"AT+ROLE=S",			// Set role to slave
	"AT+ROLE=M",			// Set role to master
	"AT+CONT=0",			// Enable connection
	"AT+NAME=CEAC-MFV",		// Set module name
	"AT+ADDR=XINCAMON1234", // Set module address
	"AT+CONT=?",				// Check connection status
	"AT+MODE=2",				// Set module to sleep
	"AT+MODE=0"					// Wake up module
};

uint32_t extract_data = 0;
// Initialize the HC-08 structure
void HC08_Init(HC08 *hc08, UART_HandleTypeDef *huart)
{
	hc08->huart = huart;					  // Assign the UART handle
	memset(hc08->rev_buffer, 0, SIZE_BUFFER); // Clear the receive buffer
	hc08->rev_flag = 0;						  // Reset the receive flag
	// default setting
	HC08_SendCommand(hc08, SET_ROLE_SLAVE);
	HC08_SendCommand(hc08, SET_CONNECT);
	HC08_SendCommand(hc08, SET_NAME);

	HAL_UART_Receive_IT(hc08->huart, hc08->rev_buffer, SIZE_BUFFER);
}

// Send an AT command to the HC-08 module
void HC08_SendCommand(HC08 *hc08, uint8_t command_id)
{
	if (command_id >= 0 && command_id < NO_OF_COMMANDS) // Ensure command_id is valid
	{
		char *command = send_command[command_id];		   // Get the command from the array
		HAL_UART_Transmit(hc08->huart, (uint8_t *)command, // Transmit the command
						  sizeof(command), 100);
		HAL_UART_Transmit(hc08->huart, (uint8_t *)"\r\n", 2, 100); // Transmit end-of-line characters
	}
}

// Process the received data

void HC08_ProcessData(HC08 *hc08)
{
	if (hc08->rev_flag)
	{ // Check if data is received
	  // TODO - Process the received data
		extract_data = 0;
		for (int i = 0; i < 3; i++)
		{
			extract_data |= (hc08->rev_buffer[i + 5]) << (i * 8);
		}

		switch (extract_data)
		{
		case CTRL_END:
			/* code */
			LED_Toggle(led_array[0]);
			reset_state();
			break;
		case CTRL_UP:
			LED_Toggle(led_array[1]);
			run_forward();
			break;

		case CTRL_DOWN:
			LED_Toggle(led_array[2]);
			run_backward();
			break;

		case CTRL_LEFT:
			LED_Toggle(led_array[3]);
			servo_left();
			break;

		case CTRL_RIGHT:
			LED_Toggle(led_array[4]);
			servo_right();
			break;

			//        case CTRL_START:
			//            break;
			//
			//        case CTRL_SELECT:
			//            break;
			//
		case CTRL_TRIANGLE:
			HAL_Delay(100);
			set_motor(&motor[1], FORWARD, 0);
			break;
			//
			//        case CTRL_CIRCLE:
			//            break;
			//
			//        case CTRL_CROSS:
			//            break;
			//
			//        case CTRL_SQUARE:
			//            break;

		default:
			//			LED_All_Toggle(led_array);
			break;
		}
		hc08->rev_flag = 0;
		memset(hc08->rev_buffer, 0, SIZE_BUFFER);
	}
}

// Callback function called when data reception is complete
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	extern HC08 hc08; // External HC-08 instance (declare in the main file)
	if (huart == hc08.huart)
	{					   // Check if the interrupt belongs to HC-08's UART
		hc08.rev_flag = 1; // Set the receive flag
		HAL_UART_Receive_IT(hc08.huart, hc08.rev_buffer, SIZE_BUFFER);
	}
}
