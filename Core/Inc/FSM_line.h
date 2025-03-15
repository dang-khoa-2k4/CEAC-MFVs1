#ifndef _FSM_LINE_H_
#define _FSM_LINE_H_
#include <stdint.h>
#include "global.h"

typedef enum
{
    LINE_ALGO_0,
    LINE_ALGO_1,
    LINE_ALGO_2
} MODE_LINE;

extern MODE_LINE line_algo;

uint8_t line_init();
void line_run();

#endif 