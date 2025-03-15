#ifndef _FSM_H_
#define _FSM_H_
#include <stdint.h>
#include "global.h"

typedef enum
{
    CONFIG = 0,
    BLE = 1,
    MAZE = 2,
    LINE = 3
} MODE;

extern MODE fsm_state;
extern uint8_t seg_led[NUMS_OF_SEG];

uint8_t fsm_init();
void fsm_run();

#endif 