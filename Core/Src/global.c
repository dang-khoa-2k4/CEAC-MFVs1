#include "global.h"

HC08 hc08;
Encoder enc;
ultraSonic sensor1;
ultraSonic sensor2;
ultraSonic sensor3;
ultraSonic temp;
average_filter filter1;
average_filter filter2;
average_filter filter3;
IR ir;

uint8_t sSeg_data[NUMS_OF_SEG] = {0};

void init_system(void)
{
    // Initialize the HC08
    HC08_Init(&hc08, &huart3);
    // Initialize the encoder
    Encoder_Init(&enc, &htim3);
    // Initialize the ultrasonic sensors
    ultraSonic_Init(&sensor1, &htim2, &filter1, ECHO_L_GPIO_Port, ECHO_L_Pin);
    ultraSonic_Init(&sensor2, &htim2, &filter2, ECHO_M_GPIO_Port, ECHO_M_Pin);
    ultraSonic_Init(&sensor3, &htim2, &filter3, ECHO_R_GPIO_Port, ECHO_R_Pin);
    // Initialize the IR sensor
    IR_Init(&ir, &hadc1);
    // Initialize the Display
    sSeg_init();
    LED_Init();
    // Initialize the EEPROM emulation
    eeprom_init(EEPROM_BEGIN, EEPROM_SIZE);
    // Initialize the Motor
    Motor_Init(&motor[1], &htim8, TIM_CHANNEL_3, TIM_CHANNEL_4);
    // Initialize the Servo
    uint16_t pulse_middle;
    eeprom_read(EEPROM_SERVO, &pulse_middle);
    servo_middle = pulse_middle < SERVO_RIGHT 
                && pulse_middle > SERVO_LEFT ? 
                SERVO_MIDDLE_DEFAULT : pulse_middle;
    Servo_Init(&servo, &htim10, TIM_CHANNEL_1, servo_middle);
    // Intro message
    // led display "HELLO" ***
    // Initialize the FSM
    fsm_init();
}