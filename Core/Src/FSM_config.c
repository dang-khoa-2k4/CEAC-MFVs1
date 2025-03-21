#include "FSM_config.h"

MODE_CONFIG config_state;
static uint8_t btn_config_state = BUTTON_RELEASED;

static void handle_config_btn(void)
{
    if (!is_button_pressed(MODE_BUTTON) 
    && btn_config_state == BUTTON_PRESSED)
    {
        btn_config_state = BUTTON_RELEASED;
        switch (config_state)
        {
            case TEST_HW:
                config_state = SETUP_SERVO;
                break;
            case SETUP_SERVO:
                config_state = SETUP_COLOR;
                break;
            case SETUP_COLOR:
                config_state = TEST_HW;
                break;
            default:
                break;
        }
    }
}

static void test_hw()
{
    if (is_button_pressed(BTN_FORWARD))
    {
        // move forward
        run_forward();
    }
    else if (is_button_pressed(BTN_BACKWARD))
    {
        // move backward
        run_backward();
    }

    if (is_button_pressed(BTN_SERVO))
    {
        // move servo
        servo_left();
        HAL_Delay(1000);
        servo_right();
        HAL_Delay(1000);
        reset_state();
    }
}

static void servo_setup()
{
    if (is_button_pressed(INC_SERVO))
    {
        servo_middle += 10;
        set_servo(&servo, servo_middle);
    }
    else if (is_button_pressed(DEC_SERVO))
    {
        servo_middle -= 10;
        set_servo(&servo, servo_middle);
    }
    else if (is_button_pressed(SAVE_SERVO))
    {
        // save servo position
        eeprom_write(0, &servo_middle);
        // save to eeprom
    }
}

static void color_setup()
{
    uint16_t black, white;
    eeprom_read(EEPROM_BLACK, &black);
    eeprom_read(EEPROM_WHITE, &white);

    if (is_button_pressed(SET_WHITE))
    {
        white = ir.data[0];
    }
    else if (is_button_pressed(SET_BLACK))
    {
        black = ir.data[0];
    }
    else if (is_button_pressed(SET_SAVE))
    {
        // save color
        eeprom_write(EEPROM_BLACK, &black);
        eeprom_write(EEPROM_WHITE, &white);
        update_threshold();
    }
}

uint8_t config_init()
{
    config_state = INIT_CONFIG;
} 

void fsm_config_run()
{
    if (is_button_pressed(MODE_BUTTON))
    {
        btn_config_state = BUTTON_PRESSED;
    }
    switch (config_state)
    {
        case INIT_CONFIG:
            if (1)
            {
                config_state = TEST_HW;
                // setup display here
            }
            break;
        case TEST_HW:
            test_hw();
            break;
        case SETUP_SERVO:
            servo_setup();
            break;
        case SETUP_COLOR:
            color_setup();
            break;
        default:
            break;
    }
    handle_config_btn();
}

