/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "OAuthDataStructure.h"
#include "OAuth.h"

#include "time.h"
#include <stdio.h>

/* USER CODE BEGIN Includes */     

//extern unsigned char tempABuffer[2048];

/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/

/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void StartDefaultTask(void const * argument);
void tskDHCP(void const * argument);
void tskNTP(void const * argument);
void tskEthernetManager(void const * argument);
//void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Hook prototypes */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */
	
  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  unsigned int tickCounter,i;
  unsigned char timeStamp[20];
  unsigned char nonce[33] ={0,};
  //unsigned char updateStatus[33];
  OAuthDataStructure OauthDS;
  unsigned char * baseString;
  unsigned char * status;
  unsigned char * query;
  unsigned char* signature;
  unsigned char secretKey[] = "s3IbG4ouS5msJ1zzO1dnkFF2zdn29FK35fAUnOY1FngYCRoPZD&8FnSZJVVaE8lKMT3FjrRP2lgVjnx2DbcDx6mbSBnvcn9f";
  while(1)
  {

         /* baseString = 0;
          status = 0;
          query = 0;
          signature = 0;
          oauth_init(&OauthDS);
          oauth_setRequestMethod(&OauthDS,"POST");
          oauth_setBaseURL(&OauthDS,"https://api.twitter.com");
          oauth_setRequestURI(&OauthDS,"/1.1/statuses/update.json");
          sprintf(nonce,"time stamp: %llu\0", time(NULL));
          status = OAuthPercentEncoding(nonce);
          OAuthConcatenate(&query,query,"status=");
          OAuthConcatenate(&query,query,status);
          oauth_setRequestQuery(&OauthDS,query);

          oauthAddParameter(&OauthDS,"status",status);
          oauthAddParameter(&OauthDS,"oauth_consumer_key","OxoopYlk667ebumAR36PnOJix");
          oauthAddParameter(&OauthDS,"oauth_signature_method","HMAC-SHA1");
          oauthAddParameter(&OauthDS,"oauth_token","4664955252-k211bLBWAt5VmUKL24duTduRDAIY4G85sl0YMYy");
          oauthAddParameter(&OauthDS,"oauth_version","1.0");
	  
	  sprintf(timeStamp,"%llu\0",time(NULL));
          oauthAddParameter(&OauthDS,"oauth_timestamp",timeStamp);
          OAuthGenNonce(nonce,sizeof(nonce)-1);
          oauthAddParameter(&OauthDS,"oauth_nonce",nonce);
          baseString = OAuthMakeBaseString(&OauthDS);
          printf("%s\r\n",baseString);
          //make signature
          signature = OAuthCreateSignature(secretKey,baseString);
          printf("%s\r\n",signature);
          //add auth parameter
          oauthAddParameter(&OauthDS,"oauth_signature",signature);

          OauthHTTP(&OauthDS,tempABuffer);

          free(query);
          free(status);
          free(baseString);
          free(signature);
          list_destroy(&(OauthDS.OauthList));

          printf("%s\r\n",tempABuffer);*/

          userApplication();
  }
  /* USER CODE END StartDefaultTask */
}


/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
