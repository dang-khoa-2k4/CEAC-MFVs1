#include "ultraSonic.h"

void ultraSonic_Init(ultraSonic *sensor, TIM_HandleTypeDef *htim, average_filter *filter, GPIO_TypeDef *TrigPort, uint16_t TrigPin)
{
    sensor->htim = htim;
    sensor->pre_time = 0;
    sensor->distance = 0;
    sensor->TrigPort = TrigPort;
    sensor->TrigPin = TrigPin;
    sensor->echoHigh = false;
    sensor->filter = filter;
    HAL_GPIO_WritePin(sensor->TrigPort, sensor->TrigPin, 0);
    reset_buffer(sensor->filter);
}

void updateDistance(ultraSonic *sensor, uint32_t Channel)
{
    if (sensor->echoHigh == false) // rising edge detected
    {
        // capture start time
        sensor->pre_time = HAL_TIM_ReadCapturedValue(sensor->htim, Channel);
        // set capture to falling edge
        __HAL_TIM_SET_CAPTUREPOLARITY(sensor->htim, Channel,
                                     TIM_INPUTCHANNELPOLARITY_FALLING);
        sensor->echoHigh = true;
    }
    else    // falling edge detected
    {
        // capture end time and calculate difference time
        uint16_t cur_time = HAL_TIM_ReadCapturedValue(sensor->htim, Channel);
        uint32_t diffTime = 
        (cur_time - sensor->pre_time + TIMER_STEP_CYCLE) % TIMER_STEP_CYCLE;

        // calculate distance
        apply_filter(sensor->filter, diffTime);
        sensor->distance = ((SOUND_SPEED * STEP_TIMER) * (sensor->filter->out)) / 2.0; // in cm
        sensor->echoHigh = false;

        // set capture to rising edge
        __HAL_TIM_SET_CAPTUREPOLARITY(sensor->htim, Channel, TIM_INPUTCHANNELPOLARITY_RISING);
        HAL_TIM_IC_Stop_IT(sensor->htim, Channel);
    }
}

// throw into void SysTick_CallBack(void)
// {
//     //for example
//     static time = 0;
//     time++;
//     if (time == 25) //25ms
//     {
//         activeTrigger(&sensor);
//         time = 0;
//     }
// }

void activeTrigger(ultraSonic *sensor)
{
    HAL_GPIO_WritePin(sensor->TrigPort, sensor->TrigPin, 1);
    delay_us(sensor->htim, 10);
    HAL_GPIO_WritePin(sensor->TrigPort, sensor->TrigPin, 0);
}

void delay_us(TIM_HandleTypeDef *htim, uint16_t time)
{
	HAL_TIM_Base_Start(htim);
    htim->Instance->CNT = 0; // __HAL_TIM_SET_COUNTER(&htim, Cnt);
    while (htim->Instance->CNT < time); // while (__HAL_TIM_GET_COUNTER(&htim) < time)
    HAL_TIM_Base_Stop(htim);
}
