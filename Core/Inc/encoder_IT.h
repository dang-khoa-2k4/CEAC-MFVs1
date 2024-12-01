/*
 * encoder.h
 *
 *  Created on: Jan 6, 2024
 *      Author: HP
 */

#ifndef ENCODER_2PHASE_ENCODER_H_
#define ENCODER_2PHASE_ENCODER_H_
#include "main.h"
#include "PWMcontrol.h"

#define NUMS_OF_ENC 2
#define ENC_BL 0 // Back-left motor
#define ENC_BR 1 // Back-right motor
#define MAX_COUNTER ((1 << 16) - 1)
#define TIME_SAMPLING  1 // ms
	/* USER DEFINE	*/
#define enc1_GPIO_Port GPIOA
#define enc1_A_Pin GPIO_PIN_8
#define enc1_B_Pin GPIO_PIN_9
#define enc2_GPIO_Port GPIOD
#define enc2_A_Pin GPIO_PIN_14
#define enc2_B_Pin GPIO_PIN_15

#define MAX_RPM 5000
#define PULSE_PER_REVOLUTION 98

//enum DIRECTION {
//	BACKWARD = -1, STOP = 0, FORWARD = 1
//};

typedef struct Encoder// two phase enc
{
	int16_t _RPM;
	int16_t _PWM;
	uint16_t current;
	uint16_t counter2X;
	GPIO_TypeDef *encPort;
	uint16_t encPin_A, encPin_B;
	int8_t Direction;
	int8_t state;
} Encoder;

extern Encoder enc[NUMS_OF_ENC];
void encInit(); 		  		// run for test
void encIT(uint16_t GPIO_Pin);	// run for test < put in EXTI >
void encRun();					// run for test < put in sche >
void Encoder_Init(Encoder *enc, GPIO_TypeDef *EncPort, uint16_t PinA,
		uint16_t PinB);
uint16_t Encoder_getval(Encoder *enc);

void Encoder_updateCount(Encoder *enc); // put in IRQHandle
void Encoder_updateRPM(Encoder *enc); 	// put in Schedule

#endif /* ENCODER_2PHASE_ENCODER_H_ */
