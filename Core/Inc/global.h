#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "main.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "average_filter.h"
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
#include "EEPROM_emulation.h"

//#define TEST_BOARD
// #define TEST_MOTOR
//#define TEST_SERVO
// #define TEST_7_SEG
// #define TEST_SINGLE_LED
// #define TEST_IR
// #define TEST_ULTRASONIC
// #define TEST_ENCODER
// #define TEST_BTN
// #define TEST_SW
extern uint8_t sSeg_data[NUMS_OF_SEG];

void init_system(void);

#endif
