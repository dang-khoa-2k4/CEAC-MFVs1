/*
 * PWMcontrol.h
 *
 *  Created on: Nov 22, 2023
 *      Author: Khoa_Nguyen
 */

#ifndef _PWM_CONTROL_H_
#define _PWM_CONTROL_H_

#include "global.h"

#define MAX_PULSE_WIDTH 1023  // tim->ARR
#define DEFAULT_SPEED 800
#define SERVO_MIDDLE_DEFAULT 530
#define SERVO_LEFT 630
#define SERVO_RIGHT 430

enum DIRECTION
{
    BACKWARD = -1,
    STOP = 0,
    FORWARD = 1
};

typedef struct
{
    TIM_HandleTypeDef *htim;
    uint16_t Channel1;
    uint16_t Channel2;
} PWMcontrol;


extern PWMcontrol servo;
extern PWMcontrol motor[2];
extern uint16_t speed;
extern uint16_t servo_middle;
/**
  * @brief  Init Motor
  * @param  htim Timer handle of encoder module
  * @param  Channel
  *         This parameter can be one of the following values:
  *            @arg Channel1 : channel handle to go forward, can shorten when known fixed pins
  *            @arg Channel2 : channel handle to go backward, can shorten when known fixed pins
  *
*/
void Motor_Init(PWMcontrol *motor, TIM_HandleTypeDef *htim, uint32_t Channel1, uint32_t Channel2);

/**
  * @brief  Init Motor
  * @param  htim Timer handle of encoder module
*/
void Servo_Init(PWMcontrol *servo, TIM_HandleTypeDef *htim, uint32_t Channel, uint16_t PWM);

/**
  * @brief  Set speed and direction of motor
  * @param  direction is direction of rotation of the wheel
  * @param  PWM is duty cycle
*/
void set_motor(PWMcontrol *motor, int8_t direction, uint16_t PWM);
/**
  * @brief  Set angle of servo
  * @param  PWM is duty cycle
*/
void set_servo(PWMcontrol *servo, uint16_t PWM);

void reset_state();

void run_forward();

void run_backward();

void servo_left();

void servo_right();

// void HandleCar(PWMcontrol *MotorLeft, PWMcontrol *MotorRight, PWMcontrol *Servo);
#endif

