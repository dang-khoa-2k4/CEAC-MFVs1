#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H

#include "global.h"

#define NUMS_OF_SINGLE_LED 5 // Number of LEDs to control
#define NUMS_OF_SEG 3 // Number of segments in a 7-segment display

// Structure definition for a 7-segment LED display
typedef struct {
    GPIO_TypeDef* data_port[4]; // GPIO ports for D0-D3 pins
    uint16_t data_pin[4];       // GPIO pins for D0-D3
    GPIO_TypeDef* le_port;      // GPIO port for LE (Latch Enable) pin
    uint16_t le_pin;            // GPIO pin for LE
} sSeg_t;

typedef struct {
    GPIO_TypeDef *port; // GPIO port for the LED
    uint16_t pin;       // GPIO pin for the LED
} LED;


extern sSeg_t seg[NUMS_OF_SEG];
extern LED led_array[NUMS_OF_SINGLE_LED];

/**
 * @brief Initializes the LEDs with a list of ports and pins.
 * @param led_array Array of LED structures.
 * @param ports Array of GPIO ports corresponding to the LEDs.
 * @param pins Array of GPIO pins corresponding to the LEDs.
 */
void LED_Init();

/**
 * @brief Turns on a specific LED.
 * @param led Pointer to the LED structure to turn on.
 */
void LED_On(LED led);

/**
 * @brief Turns off a specific LED.
 * @param led Pointer to the LED structure to turn off.
 */
void LED_Off(LED led);

/**
 * @brief Toggles the state of a specific LED.
 * @param led Pointer to the LED structure to toggle.
 */
void LED_Toggle(LED led);

/**
 * @brief Turns on all LEDs in the array.
 * @param led_array Array of LED structures.
 */
void LED_All_On(LED * led_array);

/**
 * @brief Turns off all LEDs in the array.
 * @param led_array Array of LED structures.
 */
void LED_All_Off(LED * led_array);

/**
 * @brief Toggles the state of all LEDs in the array.
 * @param led_array Array of LED structures.
 */
void LED_All_Toggle(LED *led_array);

void sSeg_init();

/**
 * @brief  Displays a number on the 7-segment display.
 * @param  *seg: Pointer to the 7-segment display structure.
 * @param  number: Number to be displayed (0-9).
 */
void sSeg_Display(sSeg_t *seg, uint8_t number);

/**
 * @brief  Clears the 7-segment display.
 * @param  *seg: Pointer to the 7-segment display structure.
 */
void sSeg_Clear(sSeg_t *seg);

#endif // SEVEN_SEGMENT_H
