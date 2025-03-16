#ifndef _IR_SENSOR_
#define _IR_SENSOR_

#include "global.h"

#define NUMS_OF_IR 5

typedef struct 
{
    ADC_HandleTypeDef * ADC_t;
    uint16_t data[NUMS_OF_IR];
} IR;

extern IR ir;

void IR_Init(IR *ir, ADC_HandleTypeDef *hadc);
void IR_update(IR *ir);
#endif