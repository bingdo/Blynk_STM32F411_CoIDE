/**
 * @file	gpioHandler.c
 * @brief	GPIO Handler Example
 * @version 1.0
 * @date	2016/08/23
 * @par Revision
 *			2016/08/23 - 1.0 Release
 * @author	
 * \n\n @par Copyright (C) 1998 - 2016 WIZnet. All rights reserved.
 */

#include "gpioHandler.h"

uint8_t IOdata[IOn];

GPIO_TypeDef* IO_PORT[IOn] = {D0_GPIO_PORT, D1_GPIO_PORT, D2_GPIO_PORT, D3_GPIO_PORT,
							  D4_GPIO_PORT, D5_GPIO_PORT, D6_GPIO_PORT, D7_GPIO_PORT, D8_GPIO_PORT, D9_GPIO_PORT
							  };
const uint16_t IO_PIN[IOn] = {D0_PIN, D1_PIN, D2_PIN, D3_PIN,
							  D4_PIN, D5_PIN, D6_PIN, D7_PIN, D8_PIN, D9_PIN
							  };

/**
  * @brief  Configures GPIO
  * @param  None
  * @return None
  */
void GPIO_Configuration(void)
{
	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();

	IOdata[D0] = Output;
	IOdata[D1] = Output;
	IOdata[D2] = Output;
	IOdata[D3] = Output;
	IOdata[D4] = Output;
	IOdata[D5] = Output;
	IOdata[D6] = Output;
	IOdata[D7] = Output;
	IOdata[D8] = Output;
	IOdata[D9] = Output;

	for(int i = 0; i < IOn; i++)
	{
		if((IOdata[i] != NotUsed) && (IOdata[i] != 0xFF))
		{
			IO_Init(i);
		}
	}
}

/**
  * @brief	Configures GPIO for D0~D7
  * @param	io Specifies the GPIO to be configured.
  *   This parameter can be one of following parameters:
  * 	@arg D0 @arg D1 @arg D2 @arg D3 @arg D4
  * 	@arg D5 @arg D6 @arg D7
  * @return None
  */
void IO_Init(IO_Type io)
{
	GPIO_InitTypeDef	GPIO_InitStructure;

  	/* Configure the GPIO_IO pin */
  	GPIO_InitStructure.Pin = IO_PIN[io];
  	if(IOdata[io] == Input)
  		GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
  	else
		GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
  	GPIO_InitStructure.Speed = GPIO_SPEED_LOW;

  	HAL_GPIO_Init(IO_PORT[io], &GPIO_InitStructure);
}

/**
  * @brief	Turns selected GPIO On.
  * @param	io Specifies the GPIO to be set on.
  *   This parameter can be one of following parameters:
  * 	@arg D0 @arg D1 @arg D2 @arg D3 @arg D4
  * 	@arg D5 @arg D6 @arg D7
  * @return None
  */
void IO_On(IO_Type io)
{
	if(IOdata[io] == Output)
		HAL_GPIO_WritePin(IO_PORT[io],IO_PIN[io],GPIO_PIN_SET);
}

/**
  * @brief	Turns selected GPIO Off.
  * @param	io Specifies the GPIO to be set off.
  *   This parameter can be one of following parameters:
  * 	@arg D0 @arg D1 @arg D2 @arg D3 @arg D4
  * 	@arg D5 @arg D6 @arg D7
  * @return None
  */
void IO_Off(IO_Type io)
{
	if(IOdata[io] == Output)
		HAL_GPIO_WritePin(IO_PORT[io],IO_PIN[io],GPIO_PIN_RESET);
}

/**
  * @brief	Toggles the selected GPIO.
  * @param	io Specifies the GPIO to be toggled.
  *   This parameter can be one of following parameters:
  * 	@arg D0 @arg D1 @arg D2 @arg D3 @arg D4
  * 	@arg D5 @arg D6 @arg D7
  * @return None
  */
void IO_Toggle(IO_Type io)
{
	if(IOdata[io] == Output)
  		IO_PORT[io]->ODR ^= IO_PIN[io];
}

/**
  * @brief	To get the status of GPIO.
  * @param	io Specifies the GPIO to get a status
  *   This parameter can be one of following parameters:
  * 	@arg D0 @arg D1 @arg D2 @arg D3 @arg D4
  * 	@arg D5 @arg D6 @arg D7
  * @return The status of GPIO
  */
uint8_t get_IO_Status(IO_Type io)
{
	if(IOdata[io] == Input)
		return HAL_GPIO_ReadPin(IO_PORT[io],IO_PIN[io]);
	else if (IOdata[io] == Output)
		return HAL_GPIO_ReadPin(IO_PORT[io],IO_PIN[io]);
	else
		return 0;
}
