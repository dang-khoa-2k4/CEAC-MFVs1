#ifndef _FSM_TEST_H_
#define _FSM_TEST_H_
#include <stdint.h>
#include "global.h"

typedef enum
{                                                                           
    TEST_HW = 0,
    SETUP_SERVO,
    SETUP_COLOR                 
} MODE_CONFIG;

extern MODE_CONFIG config_state;

uint8_t config_init();
void fsm_config_run();

#endif 