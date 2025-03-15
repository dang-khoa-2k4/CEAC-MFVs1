#ifndef _FSM_MAZE_H_
#define _FSM_MAZE_H_
#include <stdint.h>
#include "global.h"

typedef enum
{
    MAZE_ALGO_0,
    MAZE_ALGO_1,
    MAZE_ALGO_2
} MODE_MAZE;

extern MODE_MAZE maze_algo;

uint8_t maze_init();
void maze_run();

#endif 