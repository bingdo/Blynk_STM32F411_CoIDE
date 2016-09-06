/**
 * @file	gpioHandler.h
 * @brief	Header File for GPIO Handler Example
 * @version 1.0
 * @date	2014/08/23
 * @par Revision
 *			2014/08/23 - 1.0 Release
 * @author	
 * \n\n @par Copyright (C) 1998 - 2016 WIZnet. All rights reserved.
 */

#ifndef __GPIOHANDLER_H
#define __GPIOHANDLER_H

#include "stm32f4xx_hal.h"

#define D0_PIN							GPIO_PIN_3
#define D0_GPIO_PORT					GPIOA

#define D1_PIN							GPIO_PIN_2
#define D1_GPIO_PORT					GPIOA

#define D2_PIN							GPIO_PIN_10
#define D2_GPIO_PORT					GPIOA

#define D3_PIN							GPIO_PIN_3
#define D3_GPIO_PORT					GPIOB

#define D4_PIN							GPIO_PIN_5
#define D4_GPIO_PORT					GPIOB

#define D5_PIN							GPIO_PIN_4
#define D5_GPIO_PORT					GPIOB

#define D6_PIN							GPIO_PIN_10
#define D6_GPIO_PORT					GPIOB

#define D7_PIN							GPIO_PIN_8
#define D7_GPIO_PORT					GPIOA

#define D8_PIN							GPIO_PIN_9
#define D8_GPIO_PORT					GPIOA

#define D9_PIN							GPIO_PIN_7
#define D9_GPIO_PORT					GPIOC

// Data IO Direction
typedef enum
{
  NotUsed 	= 0,
  Input 	= 1,
  Output 	= 2
} IO_Direction_Type;

//Data IO
typedef enum
{
  D0 = 0,
  D1 = 1,
  D2 = 2,
  D3 = 3,
  D4 = 4,
  D5 = 5,
  D6 = 6,
  D7 = 7,
  D8 = 8,
  D9 = 9
} IO_Type;

#define IOn		10

// ADC
typedef enum
{
  A0 = 0,
  A1 = 1,
  A2 = 2,
  A3 = 3
} ADC_Type;

void GPIO_Configuration(void);

void IO_Init(IO_Type io);
void IO_On(IO_Type io);
void IO_Off(IO_Type io);
void IO_Toggle(IO_Type io);
uint8_t get_IO_Status(IO_Type io);
extern uint8_t IOdata[IOn];
uint16_t get_ADC_val(uint8_t index);

#endif

