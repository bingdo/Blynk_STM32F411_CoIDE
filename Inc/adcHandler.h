/**
 * @file	adcHandler.h
 * @brief	Header File for ADC Handler Example
 * @version 1.0
 * @date	2016/08/23
 * @par Revision
 *			2016/08/23 - 1.0 Release
 * @author	
 * \n\n @par Copyright (C) 1998 - 2016 WIZnet. All rights reserved.
 */

#ifndef __ADCHANDLER_H
#define __ADCHANDLER_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_adc.h"
#include "stm32f4xx.h"

//#define ADC_POL
#define ADC_INT

/* Definition for ADCx clock resources */
#define ADCx                            ADC1
#define ADCx_CLK_ENABLE()               __HAL_RCC_ADC1_CLK_ENABLE()
#define ADCx_CHANNEL_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()

#define ADCx_FORCE_RESET()              __HAL_RCC_ADC_FORCE_RESET()
#define ADCx_RELEASE_RESET()            __HAL_RCC_ADC_RELEASE_RESET()

/* Definition for ADCx Channel Pin */
#define ADCx_CHANNEL_PIN                GPIO_PIN_1
#define ADCx_CHANNEL_GPIO_PORT          GPIOA

/* Definition for ADCx's Channel */
#define ADCx_CHANNEL                    ADC_CHANNEL_1

#if defined(ADC_INT)
/* Definition for ADCx's NVIC */
#define ADCx_IRQn                       ADC_IRQn
#endif


#define ADC1_0_PIN		GPIO_PIN_0
#define ADC1_0_PORT		GPIOA
#define ADC1_0_CH		ADC_CHANNEL_0

#define ADC1_1_PIN		GPIO_PIN_1
#define ADC1_1_PORT		GPIOA
#define ADC1_1_CH		ADC_CHANNEL_1

#define ADC1_4_PIN		GPIO_PIN_4
#define ADC1_4_PORT		GPIOA
#define ADC1_4_CH		ADC_CHANNEL_4

#define ADC1_8_PIN		GPIO_PIN_0
#define ADC1_8_PORT		GPIOB
#define ADC1_8_CH		ADC_CHANNEL_8

void ADC_Configuration(void);
uint16_t get_ADC_val(uint8_t index);
extern __IO uint16_t uhADCxConvertedValue;

#endif

