#ifndef _FSM_BLE_H_
#define _FSM_BLE_H_
#include <stdint.h>
#include "global.h"

typedef enum
{
    INIT_BLE,
    SLEEPING,
    WAKEUP
} MODE_BLE;

extern MODE_BLE ble_state;

uint8_t ble_init();
void fsm_ble_run();

#endif 