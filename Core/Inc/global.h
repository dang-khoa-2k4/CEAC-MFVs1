#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdbool.h>
#include <stdint.h>
#include "main.h"
#include "average_filter.h"
#include <string.h>
#include <stdlib.h>

#include "ultraSonic.h"
#include "encoder.h"
#include "PID.h"
#include "PWMcontrol.h"
#include "IR.h"
#include "led_display.h"
#include "input_reading.h"
#include "scheduler.h"
#include "communication.h" 
#include "FSM_BLE.h"
#include "FSM_maze.h"
#include "FSM_config.h"
#include "FSM_line.h"

#define TEST_BOARD
// #define TEST_MOTOR
//#define TEST_SERVO
// #define TEST_7_SEG
// #define TEST_SINGLE_LED
// #define TEST_IR
// #define TEST_ULTRASONIC
// #define TEST_ENCODER
// #define TEST_BTN
// #define TEST_SW
#define TEST_BLE
#endif
