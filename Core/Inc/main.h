/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "global.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern DMA_HandleTypeDef hdma_adc1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim10;
extern UART_HandleTypeDef huart3;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_2_Pin GPIO_PIN_2
#define BTN_2_GPIO_Port GPIOE
#define BTN_3_Pin GPIO_PIN_3
#define BTN_3_GPIO_Port GPIOE
#define BTN_4_Pin GPIO_PIN_4
#define BTN_4_GPIO_Port GPIOE
#define BTN_1_Pin GPIO_PIN_1
#define BTN_1_GPIO_Port GPIOC
#define trigger_Pin GPIO_PIN_3
#define trigger_GPIO_Port GPIOC
#define IR1_Pin GPIO_PIN_0
#define IR1_GPIO_Port GPIOA
#define ECHO_L_Pin GPIO_PIN_1
#define ECHO_L_GPIO_Port GPIOA
#define ECHO_M_Pin GPIO_PIN_2
#define ECHO_M_GPIO_Port GPIOA
#define ECHO_R_Pin GPIO_PIN_3
#define ECHO_R_GPIO_Port GPIOA
#define IR2_Pin GPIO_PIN_4
#define IR2_GPIO_Port GPIOA
#define IR3_Pin GPIO_PIN_5
#define IR3_GPIO_Port GPIOA
#define IR4_Pin GPIO_PIN_6
#define IR4_GPIO_Port GPIOA
#define IR5_Pin GPIO_PIN_7
#define IR5_GPIO_Port GPIOA
#define BATT_Pin GPIO_PIN_0
#define BATT_GPIO_Port GPIOB
#define SW_1_Pin GPIO_PIN_12
#define SW_1_GPIO_Port GPIOD
#define SW_2_Pin GPIO_PIN_13
#define SW_2_GPIO_Port GPIOD
#define MOTOR_R1_Pin GPIO_PIN_6
#define MOTOR_R1_GPIO_Port GPIOC
#define MOTOR_R0_Pin GPIO_PIN_7
#define MOTOR_R0_GPIO_Port GPIOC
#define MOTOR_L1_Pin GPIO_PIN_8
#define MOTOR_L1_GPIO_Port GPIOC
#define MOTOR_L0_Pin GPIO_PIN_9
#define MOTOR_L0_GPIO_Port GPIOC
#define LED_1_Pin GPIO_PIN_8
#define LED_1_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_9
#define LED_2_GPIO_Port GPIOA
#define LED_3_Pin GPIO_PIN_10
#define LED_3_GPIO_Port GPIOA
#define LED_4_Pin GPIO_PIN_11
#define LED_4_GPIO_Port GPIOA
#define LED_5_Pin GPIO_PIN_12
#define LED_5_GPIO_Port GPIOA
#define ES_L_Pin GPIO_PIN_6
#define ES_L_GPIO_Port GPIOD
#define ES_R_Pin GPIO_PIN_7
#define ES_R_GPIO_Port GPIOD
#define EN_L1_Pin GPIO_PIN_4
#define EN_L1_GPIO_Port GPIOB
#define EN_L0_Pin GPIO_PIN_5
#define EN_L0_GPIO_Port GPIOB
#define SERVO_Pin GPIO_PIN_8
#define SERVO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
