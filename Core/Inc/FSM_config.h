#ifndef _FSM_TEST_H_
#define _FSM_TEST_H_
#include <stdint.h>
#include "global.h"

typedef enum
{   
    INIT_CONFIG = 0,                                                                        
    TEST_HW,
    SETUP_SERVO,
    SETUP_COLOR                 
} MODE_CONFIG;

extern MODE_CONFIG config_state;

typedef enum 
{
    BTN_FORWARD = 0,
    BTN_BACKWARD,
    BTN_SERVO
} BTN_TEST_HW;

typedef enum 
{
    INC_SERVO = 0,
    DEC_SERVO,
    SAVE_SERVO
} BTN_SERVO_SETUP;

typedef enum 
{
    SET_WHITE = 0,
    SET_BLACK,
    SET_SAVE
} BTN_COLOR_SETUP;

uint8_t config_init();
void fsm_config_run();

#endif 