/*
 * controller.c
 *
 *  Created on: Nov 30, 2024
 *      Author: HP
 */
#include <CEAC_BLE.h>
#include "PWMcontrol.h"

uint16_t base_pwm = PWM_MODE_1;
uint32_t rx_idx = 0;
uint8_t reset_flag = 0, forward = 0, backward = 0, left = 0, right = 0;
UART_HandleTypeDef *pUart;
char buffer[1];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == pUart->Instance) {
		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
		ctrller_Rev(buffer);
		HAL_UART_Receive_IT(pUart, (uint8_t *)buffer, strlen(buffer));

	}
}
void ctrller_Init(UART_HandleTypeDef *UART_pointer) {
	char *send_command[8] =
			{ "AT", "AT+VERSION", "AT+ROLE=S", "AT+ROLE=M", "AT+CONT=0",
					"AT+NAME=CEAC-MFV", "AT+ADDR=XINCAMON1234", "AT+CONT=?" };
	pUart = UART_pointer;
	strcpy(message, "\0");
	HAL_UART_Transmit(pUart, (uint8_t *)send_command[2], strlen(send_command[2]), 100);
	HAL_UART_Transmit(pUart, (uint8_t *)send_command[4], strlen(send_command[2]), 100);
	HAL_UART_Transmit(pUart, (uint8_t *)send_command[5], strlen(send_command[2]), 100);
	HAL_UART_Transmit(pUart, (uint8_t *)send_command[6], strlen(send_command[2]), 100);
	HAL_UART_Receive_IT(pUart, (uint8_t *)buffer, strlen(buffer));
}
void ctrller_Rev(char *buffer) {
	if (buffer[0] != 13 || buffer[0] != 0) { // 13 is enter key and 0 is null char
		switch (buffer[0]) {
		case '1':
			base_pwm = PWM_MODE_1;
			break;
		case '2':
			base_pwm = PWM_MODE_2;
			break;
		case '3':
			base_pwm = PWM_MODE_3;
			break;
		case 'w':
			forward++;
			break;
		case 's':
			backward++;
			break;
		case 'a':
			left++;
			break;
		case 'd':
			right++;
			break;
		default: // command line, do not count direction
			reset_flag = 1;
			break;
		}
		message[rx_idx++] = buffer[0];
		if (rx_idx >= MESSAGE_SIZE) {
			memset(message, 0, sizeof(message));
			rx_idx = 0;
		}
	} else {
		reset_flag = 0;
		for (int i = 0; i < MESSAGE_SIZE; i++)
			message[i] = 0;
	}
}

void ctrller_run() {
	if (reset_flag == 1) {
		forward = 0, backward = 0, left = 0, right = 0;
	}

	if (left < right + 5 || left > right - 5) {			// the differ is 10 unit
		set_servo(&servo, SERVO_LEFT);
	} else if (right < left + 5 || right > left - 5) {
		set_servo(&servo, SERVO_RIGHT);
	} else {
		set_servo(&servo, SERVO_CENTER);
	}

	PWMcontrol *ctrlMotor = &motor[0];
	if (forward < backward + 5 || forward > backward - 5) {
		set_motor(ctrlMotor, FORWARD, (uint16_t)base_pwm);
	} else if (backward < forward + 5 || backward > forward - 5) {
		set_motor(ctrlMotor, BACKWARD, base_pwm);
	} else {
		set_motor(ctrlMotor, STOP, 0);
	}
}

