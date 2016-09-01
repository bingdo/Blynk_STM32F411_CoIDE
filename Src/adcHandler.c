/**
 * @file	adcHandler.c
 * @brief	ADC Handler Example
 * @version 1.0
 * @date	2016/08/23
 * @par Revision
 *			2016/08/23 - 1.0 Release
 * @author	
 * \n\n @par Copyright (C) 1998 - 2016 WIZnet. All rights reserved.
 */

#include "adcHandler.h"

/* ADC handler declaration */
ADC_HandleTypeDef    AdcHandle;

/* Variable used to get converted value */
__IO uint16_t uhADCxConvertedValue = 0;

/**
  * @brief  Configures ADC
  * @param  None
  * @return None
  */
void ADC_Configuration(void)
{
	ADC_ChannelConfTypeDef sConfig;

	/*##-1- Configure the ADC peripheral #######################################*/
	AdcHandle.Instance = ADCx;

	AdcHandle.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
	AdcHandle.Init.Resolution = ADC_RESOLUTION_12B;
	AdcHandle.Init.ScanConvMode = DISABLE;
	AdcHandle.Init.ContinuousConvMode = ENABLE;
	AdcHandle.Init.DiscontinuousConvMode = DISABLE;
	AdcHandle.Init.NbrOfDiscConversion = 0;
	AdcHandle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	AdcHandle.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
	AdcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	AdcHandle.Init.NbrOfConversion = 1;
#if defined(ADC_POL)
	AdcHandle.Init.DMAContinuousRequests = DISABLE;
	AdcHandle.Init.EOCSelection = DISABLE;
#elif defined(ADC_INT)
	AdcHandle.Init.DMAContinuousRequests = DISABLE;
	AdcHandle.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
#endif

	if(HAL_ADC_Init(&AdcHandle) != HAL_OK)
	{
		/* Initialization Error */
		//Error_Handler();
	}

	/*##-2- Configure ADC regular channel ######################################*/
	sConfig.Channel = ADCx_CHANNEL;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_84CYCLES;//ADC_SAMPLETIME_3CYCLES;
	sConfig.Offset = 0;

	if(HAL_ADC_ConfigChannel(&AdcHandle, &sConfig) != HAL_OK)
	{
		/* Channel Configuration Error */
		//Error_Handler();
	}

#if defined(ADC_INT)
	/*##-3- Start the conversion process #######################################*/
	if (HAL_ADC_Start_IT(&AdcHandle) != HAL_OK)
	{
		/* Start Conversation Error */
		//Error_Handler();
	}
#endif
}

/**
 * @brief To get adc value of A0 ~ A3 from a WIZnet module.
 * @param index The sequence for A0 ~ A3 registration
 * @return adc value (uint16_t)
 */
uint16_t get_ADC_val(uint8_t index)
{
	uint16_t adc_value = 0;

#if 0
	switch(index)
	{
		case A0:
			adc_value = 100;
			break;
		case A1:
			adc_value = 200;
			break;
		case A2:
			adc_value = 300;
			break;
		case A3:
			adc_value = 400;
			break;
		default:
			adc_value = 500;
			break;
	}
#else
#if defined(ADC_POL)
	HAL_ADC_Start(&AdcHandle);
	HAL_ADC_PollForConversion(&AdcHandle,10);
	adc_value = (uint16_t)HAL_ADC_GetValue(&AdcHandle);
	HAL_ADC_Stop(&AdcHandle);
#elif defined(ADC_INT)
	HAL_ADC_Start(&AdcHandle);
	adc_value = (uint16_t)HAL_ADC_GetValue(&AdcHandle);
#endif
#endif

	return adc_value;
}

/**
  * @brief  Conversion complete callback in non blocking mode
  * @param  AdcHandle : AdcHandle handle
  * @note   This example shows a simple way to report end of conversion, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
{
  /* Get the converted value of regular channel */
  uhADCxConvertedValue = HAL_ADC_GetValue(AdcHandle);
}
