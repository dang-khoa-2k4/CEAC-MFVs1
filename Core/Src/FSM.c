#include "FSM.h"

MODE fsm_state;
uint8_t seg_led[NUMS_OF_SEG];

static uint8_t btn_mode_state = BUTTON_RELEASED;

static void mode_press_handler(void)
{
    if (!is_button_pressed(MODE_BUTTON) && btn_mode_state == BUTTON_PRESSED)
    {
        btn_mode_state = BUTTON_RELEASED;

        switch (fsm_state)
        {
        case CONFIG:
            ble_init();
            fsm_state = BLE;
            break;
        case BLE:
            maze_init();
            fsm_state = LINE;   
            break;
        case LINE:
            config_init();
            fsm_state = CONFIG;
            break;
        default:
            break;
        }
    }
}

uint8_t fsm_init()
{
    fsm_state = CONFIG;   
}

void fsm_run()
{

}