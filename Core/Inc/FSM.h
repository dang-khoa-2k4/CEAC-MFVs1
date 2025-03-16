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

extern HC08 hc08;
extern Encoder enc;
extern ultraSonic sensor1;
extern ultraSonic sensor2;
extern ultraSonic sensor3;
extern ultraSonic temp;
extern average_filter filter1;
extern average_filter filter2;
extern average_filter filter3;
extern IR ir;

uint8_t fsm_init();
void fsm_run();

#endif 