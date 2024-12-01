/*
 * controller.c
 *
 *  Created on: Nov 30, 2024
 *      Author: HP
 */
#include "controller.h"

uint16_t base_pwm = BLE_MODE_1;
uint32_t rx_idx = 0;
void CEAC_BLE_Rev(char *buffer) {
	if (buffer[0] != 13) { // 13 is enter key
		switch (buffer[0]) {
		case '1':
			base_pwm = BLE_MODE_1;
			break;
		case '2':
			base_pwm = BLE_MODE_2;
			break;
		case '3':
			base_pwm = BLE_MODE_3;
			break;
		}
		message[rx_idx++] = buffer[0];
		if (rx_idx >= MESSAGE_SIZE)
			rx_idx = 0;
	} else {
		for (int i = 0; i < MESSAGE_SIZE; i++)
			message[i] = 0;
	}
}

void CEAC_BLE_Proc() {
	int forward = 0, backward = 0, left = 0, right = 0;
	int reset_flag = 0;
	for (int i = 0; i < MESSAGE_SIZE; i++) {
		switch (message[i]) {
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
		default: // reset state
			reset_flag = 1;
			break;
		}
		if (reset_flag) {
			forward = 0, backward = 0, left = 0, right = 0;
		}
	}

	if (forward > backward) {
		if (left > right) {
			set_motor(&motor[MOTOR_L], FORWARD, base_pwm - TURN_ADJUSTMENT);
			set_motor(&motor[MOTOR_R], FORWARD, base_pwm + TURN_ADJUSTMENT);
			set_servo(&servo, SERVO_LEFT);
		} else if (right > left) {
			set_motor(&motor[MOTOR_L], FORWARD, base_pwm + TURN_ADJUSTMENT);
			set_motor(&motor[MOTOR_R], FORWARD, base_pwm - TURN_ADJUSTMENT);
			set_servo(&servo, SERVO_RIGHT);
		} else {
			set_motor(&motor[MOTOR_L], FORWARD, base_pwm);
			set_motor(&motor[MOTOR_R], FORWARD, base_pwm);
			set_servo(&servo, SERVO_CENTER);
		}
	} else if (backward > forward) {
		if (left > right) {
			set_motor(&motor[MOTOR_L], BACKWARD, base_pwm - TURN_ADJUSTMENT);
			set_motor(&motor[MOTOR_R], BACKWARD, base_pwm + TURN_ADJUSTMENT);
			set_servo(&servo, SERVO_LEFT);
		} else if (right > left) {
			set_motor(&motor[MOTOR_L], BACKWARD, base_pwm + TURN_ADJUSTMENT);
			set_motor(&motor[MOTOR_R], BACKWARD, base_pwm - TURN_ADJUSTMENT);
			set_servo(&servo, SERVO_RIGHT);
		} else {
			set_motor(&motor[MOTOR_L], BACKWARD, base_pwm);
			set_motor(&motor[MOTOR_R], BACKWARD, base_pwm);
			set_servo(&servo, SERVO_CENTER);
		}
	} else {
		if (left > right) {
			set_motor(&motor[MOTOR_L], BACKWARD, base_pwm);
			set_motor(&motor[MOTOR_R], FORWARD, base_pwm);
			set_servo(&servo, SERVO_LEFT);
		} else if (right > left) {
			set_motor(&motor[MOTOR_L], FORWARD, base_pwm);
			set_motor(&motor[MOTOR_R], BACKWARD, base_pwm);
			set_servo(&servo, SERVO_RIGHT);
		} else {
			set_motor(&motor[MOTOR_L], STOP, 0);
			set_motor(&motor[MOTOR_R], STOP, 0);
			set_servo(&servo, SERVO_CENTER);
		}
	}
}

