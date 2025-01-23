/*
 * controller.h
 *
 *  Created on: Nov 30, 2024
 *      Author: HP
 */

#ifndef INC_CEAC_BLE_H_
#define INC_CEAC_BLE_H_

#include "main.h"

#define PWM_MODE_1 100
#define PWM_MODE_2 255
#define PWM_MODE_3 500
#define SERVO_LEFT map(45, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE)
#define SERVO_CENTER map(90, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE)
#define SERVO_RIGHT map(135, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE)

void ctrller_Init(UART_HandleTypeDef *UART_pointer);
void ctrller_Rev(char *buffer);
void ctrller_run();

#endif /* INC_CEAC_BLE_H_ */
