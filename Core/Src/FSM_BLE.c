#include "FSM_BLE.h"

MODE_BLE ble_state;
static uint8_t btn_ble_state = BUTTON_RELEASED;

static void handle_ble_btn(void)
{
    if (!is_button_pressed(MODE_BUTTON) 
    && btn_ble_state == BUTTON_PRESSED)
    {
        btn_ble_state = BUTTON_RELEASED;
        switch (ble_state)
        {
            case SLEEPING:
                ble_state = WAKEUP;
                sSeg_Display(seg[0], 1);
                sSeg_Display(seg[1], 0);
                sSeg_Display(seg[2], 1);
                HC08_SendCommand(&hc08, SET_WAKEUP);
                break;
            case WAKEUP:
                ble_state = SLEEPING;
                sSeg_Display(seg[0], 1);
                sSeg_Display(seg[1], 0);
                sSeg_Display(seg[2], 2);
                HC08_SendCommand(&hc08, SET_SLEEP);
                break;
        }
    }
}

uint8_t ble_init()
{
    ble_state = INIT_BLE;
}

void fsm_ble_run()
{
    if (is_button_pressed(MODE_BUTTON))
    {
        btn_ble_state = BUTTON_PRESSED;
    }
    switch (ble_state)
    {
    case INIT_BLE:
        ble_state = WAKEUP;
        break;
    case SLEEPING:
        // display sleep
        break;
    case WAKEUP:
        // display wakeup

        // process data
        HC08_ProcessData(&hc08);
        break;
    default:
        break;
    }
    handle_ble_btn();
}
