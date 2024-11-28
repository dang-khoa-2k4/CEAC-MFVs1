#include "led_display.h"

// Function to initialize the 7-segment display
void SevenSegment_Init(SevenSegment_t *seg, GPIO_TypeDef* data_ports, uint16_t data_pins[4]
                    , GPIO_TypeDef* le_port, uint16_t le_pin) {
    // Assign GPIO ports and pins for D0-D3
    for (int i = 0; i < 4; i++) {
        seg->data_port[i] = data_ports;
        seg->data_pin[i] = data_pins[i];
    }
    // Assign GPIO port and pin for LE
    seg->le_port = le_port;
    seg->le_pin = le_pin;

    // Set default state of LE to LOW
    HAL_GPIO_WritePin(seg->le_port, seg->le_pin, GPIO_PIN_RESET);
}

// Function to display a number on the 7-segment display
void SevenSegment_Display(SevenSegment_t *seg, uint8_t number) {
    if (number > 9) return; // Only numbers 0-9 are valid for display

    // Write the BCD value to the D0-D3 pins
    for (int i = 0; i < 4; i++) {
        HAL_GPIO_WritePin(seg->data_port[i], seg->data_pin[i], (number >> i) & 0x01);
    }

    // Toggle LE to latch the displayed value
    HAL_GPIO_WritePin(seg->le_port, seg->le_pin, GPIO_PIN_SET);
    // HAL_Delay(1); // Wait for a brief period to ensure LE stabilizes
    // HAL_GPIO_WritePin(seg->le_port, seg->le_pin, GPIO_PIN_RESET);
}

// Function to clear the 7-segment display
void SevenSegment_Clear(SevenSegment_t *seg) {
    // Set all D0-D3 pins to LOW
    for (int i = 0; i < 4; i++) {
        HAL_GPIO_WritePin(seg->data_port[i], seg->data_pin[i], GPIO_PIN_RESET);
    }

    // Toggle LE to update the cleared state
    HAL_GPIO_WritePin(seg->le_port, seg->le_pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(seg->le_port, seg->le_pin, GPIO_PIN_RESET);
}


void LED_Init(LED *led_array, GPIO_TypeDef **ports, uint16_t *pins) {
    for (int i = 0; i < NUMS_OF_SINGLE_LED; i++) {
        led_array[i].port = ports[i];
        led_array[i].pin = pins[i];
    }
}

void LED_On(LED *led) {
    HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_SET);
}

void LED_Off(LED *led) {
    HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_RESET);
}

void LED_Toggle(LED *led) {
    HAL_GPIO_TogglePin(led->port, led->pin);
}

void LED_All_On(LED *led_array) {
    for (int i = 0; i < NUMS_OF_SINGLE_LED; i++) {
        LED_On(&led_array[i]);
    }
}

void LED_All_Off(LED *led_array) {
    for (int i = 0; i < NUMS_OF_SINGLE_LED; i++) {
        LED_Off(&led_array[i]);
    }
}

void LED_All_Toggle(LED *led_array) {
    for (int i = 0; i < NUMS_OF_SINGLE_LED; i++) {
        LED_Toggle(&led_array[i]);
    }
}