/*
 * PWMcontrol.c
 *
 *  Created on: Nov 22, 2023
 *      Author: Khoa_Nguyen
 */
#include "PWMcontrol.h"

PWMcontrol servo;
PWMcontrol motor[2];
uint16_t speed = DEFAULT_SPEED;
uint16_t servo_middle = SERVO_MIDDLE_DEFAULT;

void Motor_Init(PWMcontrol *PWMcontrol, TIM_HandleTypeDef *htim, uint32_t Channel1, uint32_t Channel2)
{
    PWMcontrol->htim = htim;
    PWMcontrol->Channel1 = Channel1;
    PWMcontrol->Channel2 = Channel2;
    HAL_TIM_PWM_Start(htim, Channel1);
    HAL_TIM_PWM_Start(htim, Channel2);
    __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel1, 0);
    __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel2, 0);
    return;
}

void Servo_Init(PWMcontrol *PWMcontrol, TIM_HandleTypeDef *htim, uint32_t Channel, uint16_t PWM_middle)
{
    PWMcontrol->htim = htim;
    PWMcontrol->Channel1 = Channel;
	HAL_TIM_PWM_Start(htim, Channel);
    __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel1, PWM_middle);
    return;
}

void set_motor(PWMcontrol *PWMcontrol, int8_t direction, uint16_t PWM)
{
    PWM = PWM > MAX_PULSE_WIDTH ? MAX_PULSE_WIDTH : PWM;

    if (direction == BACKWARD)
    {
        __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel1, PWM);
        __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel2, 0);
    }
    else if (direction == FORWARD)
    {
        __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel1, 0);
        __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel2, PWM);
    }
    else
    {
        __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel1, 0);
        __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel2, 0);
    }
    return;
}

void set_servo(PWMcontrol *PWMcontrol, uint16_t PWM)
{
    PWM = PWM > SERVO_LEFT  ? SERVO_LEFT 
        : PWM < SERVO_RIGHT ? SERVO_RIGHT : PWM;
    __HAL_TIM_SET_COMPARE(PWMcontrol->htim, PWMcontrol->Channel1, PWM);
    return;
}

void c()
{
	set_servo(&servo, servo_middle);
}

void run_forward()
{
	HAL_Delay(100);
	set_motor(&motor[1], FORWARD, DEFAULT_SPEED);
}

void run_backward()
{
	HAL_Delay(100);
	set_motor(&motor[1], BACKWARD, DEFAULT_SPEED);
}

void servo_left()
{
	set_servo(&servo, SERVO_LEFT);
}

void servo_right()
{
	set_servo(&servo, SERVO_RIGHT);
}

