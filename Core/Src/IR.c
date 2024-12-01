#include "IR.h"

void IR_Init(IR *ir, ADC_HandleTypeDef *hadc)
{
    ir->ADC_t = hadc;
    for (int i = 0; i < NUMS_OF_IR; i++)
    {
        ir->data[i] = 0;
    }
}

void IR_update(IR *ir)
{
    HAL_ADC_Start_DMA(ir->ADC_t, (uint32_t *) (ir->data), NUMS_OF_IR);
    HAL_Delay(10);
    HAL_ADC_Stop_DMA(ir->ADC_t);
}
