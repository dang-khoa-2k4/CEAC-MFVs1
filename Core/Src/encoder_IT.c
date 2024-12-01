/*
 * encoder.c
 *
 *  Created on: Jan 6, 2024
 *      Author: HP
 */

#include <encoder_IT.h>

Encoder enc[NUMS_OF_ENC];

void encInit() {
	Encoder_Init(&enc[ENC_BL], enc1_GPIO_Port, enc1_A_Pin, enc1_B_Pin);
	Encoder_Init(&enc[ENC_BR], enc2_GPIO_Port, enc2_A_Pin, enc2_B_Pin);
	// More init later
}
void encIT(uint16_t GPIO_Pin) {
	UNUSED(GPIO_Pin);
	switch (GPIO_Pin) {
	case enc1_A_Pin:
	case enc1_B_Pin:
		Encoder_updateCount(&enc[ENC_BL]);
		break;
	case enc2_A_Pin:
	case enc2_B_Pin:
		Encoder_updateCount(&enc[ENC_BR]);
		break;
	default:
	}
}
void encRun() {
	Encoder_updateRPM(&enc[ENC_BL]);
	Encoder_updateRPM(&enc[ENC_BR]);
}

void Encoder_Init(Encoder *enc, GPIO_TypeDef *encPort, uint16_t PinA,
		uint16_t PinB) {
	enc->_RPM = 0;
	enc->_PWM = 0;
	enc->counter2X = 0;
	enc->Direction = STOP;
	enc->current = 0;
	enc->encPort = encPort;
	enc->encPin_A = PinA;
	enc->encPin_B = PinB;
	uint8_t phaseA = (HAL_GPIO_ReadPin(encPort, PinA) == 1);
	uint8_t phaseB = (HAL_GPIO_ReadPin(encPort, PinB) == 1);
	enc->state = (phaseA << 1) | phaseB;
}
uint16_t Encoder_getval(Encoder *enc) {
	return (enc->counter2X / 2);
}

void Encoder_updateCount(Encoder *enc) {
	uint8_t phaseA = (HAL_GPIO_ReadPin(enc->encPort, enc->encPin_A) == 1);
	uint8_t phaseB = (HAL_GPIO_ReadPin(enc->encPort, enc->encPin_B) == 1);
	uint8_t currentState = (phaseA << 1) | phaseB;
	switch ((enc->state << 2) | currentState) {
	case 0b0001: // 00 -> 01
	case 0b0111: // 01 -> 11
	case 0b1110: // 11 -> 10
	case 0b1000: // 10 -> 00
		enc->counter2X++;
		enc->Direction = FORWARD;
		break;
	case 0b0010: // 00 -> 10
	case 0b1011: // 10 -> 11
	case 0b1101: // 11 -> 01
	case 0b0100: // 01 -> 00
		enc->counter2X--;
		enc->Direction = BACKWARD;
		break;
	default:
		enc->Direction = STOP;
		break;
	}
	enc->state = currentState;
}
void Encoder_updateRPM(Encoder *enc) {
	uint16_t diff_pulse = (Encoder_getval(enc) - enc->current + MAX_COUNTER)
			% MAX_COUNTER;
	int32_t pulses_per_second = (diff_pulse * 1000) / TIME_SAMPLING; // pulse/sec
	enc->_RPM = (pulses_per_second * 60) / PULSE_PER_REVOLUTION;
	enc->current = Encoder_getval(enc);

	if (enc->_RPM > MAX_RPM) {
		enc->_RPM = MAX_RPM;
	} else if (enc->_RPM < -MAX_RPM) {
		enc->_RPM = -MAX_RPM;
	}
}

