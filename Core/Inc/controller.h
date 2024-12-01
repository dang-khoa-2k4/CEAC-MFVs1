/*
 * controller.h
 *
 *  Created on: Nov 30, 2024
 *      Author: HP
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include "main.h"
#include "PWMcontrol.h"
#include "encoder_IT.h"

#define BLE_MODE_1 100
#define BLE_MODE_2 255
#define BLE_MODE_3 500
#define TURN_ADJUSTMENT 50
#define SERVO_LEFT map(45, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE)
#define SERVO_CENTER map(90, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE)
#define SERVO_RIGHT map(135, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE)

void CEAC_BLE_Rev(char *buffer);
void CEAC_BLE_Proc();

#endif /* INC_CONTROLLER_H_ */
