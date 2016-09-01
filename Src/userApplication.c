#include "userApplication.h"
#include "wizSystem.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "blynk.h"
//#include "loopback.h"

/************************************* macro define *******************************/

#define COLOR_RED	0
#define COLOR_GREEN	1
#define COLOR_BLUE	2

///////////////////////////
// Blynk Client Settings //
///////////////////////////
#define SOCK_BLYNK_CLIENT		0
//uint8_t auth[] = "Your Blynk App Auth Token";	// You should get Auth Token in the Blynk App
uint8_t auth[] = "0093bb590e9d40429d3818090a852ca9";	// You should get Auth Token in the Blynk App
uint8_t blynk_server_ip[4] = {188, 166, 177, 186};		// Blynk cloud server IP (blynk-cloud.com, 8442)

static uint8_t ledRed = 0;
static uint8_t ledGreen = 0;
static uint8_t ledBlue = 0;

void LEDCtrl(uint8_t color,uint8_t onoff);

/************************************* main function ******************************/
void userApplication(void const * argument)
{
	osSignalWait (0x01, osWaitForever);

	printf("[DB] start blynk...\r\n");
	/* Blynk client Initialization  */
	sockPool *sockP = sockPoolAlloc();
	blynk_begin(auth, blynk_server_ip, BLYNK_DEFAULT_PORT, sockP->netBuf, sockP->sockNo);

	while(1)
	{
		//LEDCtrl(COLOR_GREEN,1);
		//osDelay(1000);
		//LEDCtrl(COLOR_GREEN,0);
		//osDelay(1000);

		// Blynk process handler
   		blynk_run();
		//loopback_tcps(sockP->sockNo, sockP->netBuf, 5000);
		osDelay(30);
	}
}

void LEDCtrl(uint8_t color,uint8_t onoff)
{
	switch(color)
	{
		case COLOR_BLUE:
			if(onoff){
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
				ledRed = 1;
			}
			else{
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
				ledRed = 0;
			}
		break;
		case COLOR_GREEN:
			if(onoff){
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_RESET);
				ledGreen = 1;
			}
			else{
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_SET);
				ledGreen = 0;
			}
		break;
		case COLOR_RED:
			if(onoff){
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET);
				ledBlue = 1;
			}
			else{
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_SET);
				ledBlue = 0;
			}
		break;
		default:
		break;
	}
}
