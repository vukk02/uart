/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MAX_LEN 18
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint8_t *subString(uint8_t *s, int pos, int index);
bool StrCompare (uint8_t *pBuff, uint8_t *Sample, uint8_t nSize);
bool WriteCom(uint8_t *pBuff, uint8_t nSize);
bool ReadComm(uint8_t *pBuff, uint8_t nSize);
bool serialProcess(void);
void tochar(uint32_t u, uint8_t*y);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_ADC1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t nRxData[MAX_LEN];
uint8_t nTxData[MAX_LEN];
uint8_t strCommand[4];
uint8_t strOpt[3];
uint8_t strData[8];

bool bDataAvailable = false;
uint8_t STX[]= {0x02U};
uint8_t ETX[]= {0x03U};
uint8_t ACK[]= {0x06U}; 
uint8_t SYN[]= {0x16U};

uint32_t adc=0;
uint8_t buffer[5];
uint8_t led_control;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart1, (uint8_t *)nRxData, MAX_LEN);
	HAL_ADC_Start_DMA(&hadc1,&adc,1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		
		tochar(adc,buffer);
    serialProcess();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

}

/* USER CODE BEGIN 4 */
uint8_t *subString(uint8_t *s, int pos, int index)
{
  uint8_t *t = &s[pos];
  s[pos - 1] = '\0';
  for (int i = index; i<(strlen((char*)t)+1); i++)
  {
    t[i] = '\0';
  }
  return t;
}

bool StrCompare (uint8_t *pBuff, uint8_t *Sample, uint8_t nSize)
{
  for (int i =0 ; i <nSize; i++)
  {
    if(pBuff[i] != Sample[i])
    {
      return false;
    }
  }

  return true;
}

bool WriteCom(uint8_t *pBuff, uint8_t nSize)
{
  //return HAL_UART_Transmit(&huart1, pBuff, nSize, 1000);
	return HAL_UART_Transmit_IT(&huart1, pBuff, nSize);

}



bool ReadComm(uint8_t *pBuff, uint8_t nSize)
{
  if((pBuff[0] == STX[0] && (pBuff[17] == ETX[0])))
  {
    memcpy(strCommand, subString(pBuff, 1,4), 4);
    memcpy(strOpt, subString(pBuff, 5,3), 3);
    memcpy(strData, subString(pBuff, 8,8), 8);

    bDataAvailable = true;
  }
  else
  {
    bDataAvailable = false;
  }
  return bDataAvailable;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart ->Instance == huart1.Instance)
  {
    ReadComm(nRxData, MAX_LEN);
    HAL_UART_Receive_IT(&huart1, (uint8_t*)nRxData, MAX_LEN);
  }
}


bool serialProcess(void)
{
  uint8_t nIndex = 0;
	if(bDataAvailable == false)
	{	
  HAL_UART_Transmit(&huart1,buffer , 5, 1000);
		HAL_Delay(100);
	}
  if(bDataAvailable == true)
  {
  if(StrCompare(strCommand, (uint8_t *)"MOVL", 4))
  {
    memcpy(nTxData + nIndex, STX, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, strCommand, 4);
    nIndex+=4;
    memcpy(nTxData + nIndex, strOpt, 3);
    nIndex += 3;
    memcpy(nTxData + nIndex, strData, 8);
    nIndex+=8;
    memcpy(nTxData + nIndex, ACK, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, ETX, 1);

    WriteCom(nTxData, MAX_LEN);
  }

  else if(StrCompare(strCommand, (uint8_t *)"GPOS", 4))
  {
        memcpy(nTxData + nIndex, STX, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, strCommand, 4);
    nIndex+=4;
    memcpy(nTxData + nIndex, strOpt, 3);
    nIndex += 3;
    memcpy(nTxData + nIndex, strData, 8);
    nIndex+=8;
    memcpy(nTxData + nIndex, ACK, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, ETX, 1);

    WriteCom(nTxData, MAX_LEN);
  }

  else if(StrCompare(strCommand, (uint8_t *)"GVEL", 4))
  {
    memcpy(nTxData + nIndex, STX, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, (uint8_t *) strCommand, 4);
    nIndex+=4;
    memcpy(nTxData + nIndex, (uint8_t *) strOpt, 3);
    nIndex += 3;
    memcpy(nTxData + nIndex, (uint8_t *) strData, 8);
    nIndex+=8;
    memcpy(nTxData + nIndex, ACK, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, ETX, 1);
    nIndex += 1;

    WriteCom(nTxData, MAX_LEN);
  }

    else if(StrCompare(strCommand, (uint8_t *)"GSTT", 4))
  {
    memcpy(nTxData + nIndex, STX, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, (uint8_t *) strCommand, 4);
    nIndex+=4;
    memcpy(nTxData + nIndex, (uint8_t *) strOpt, 3);
    nIndex += 3;
    memcpy(nTxData + nIndex, (uint8_t *) strData, 8);
    nIndex+=8;
    memcpy(nTxData + nIndex, (uint8_t *) ACK, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, ETX, 1);
    nIndex += 1;
    
    WriteCom(nTxData, MAX_LEN);
  }
  
	else if(StrCompare(strCommand, (uint8_t *)"RESS", 4))
  {
	 led_control = 1;
    memcpy(nTxData + nIndex, STX, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, (uint8_t *) strCommand, 4);
    nIndex+=4;
    memcpy(nTxData + nIndex, (uint8_t *) strOpt, 3);
    nIndex += 3;
    memcpy(nTxData + nIndex, (uint8_t *) strData, 8);
    nIndex+=8;
    memcpy(nTxData + nIndex, (uint8_t *) ACK, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, ETX, 1);
    nIndex += 1;
    
    WriteCom(nTxData, MAX_LEN);
  }
  
  else if(StrCompare(strCommand, (uint8_t *)"SETT", 4))
  {
	led_control = 2;
    memcpy(nTxData + nIndex, STX, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, (uint8_t *) strCommand, 4);
    nIndex+=4;
    memcpy(nTxData + nIndex, (uint8_t *) strOpt, 3);
    nIndex += 3;
    memcpy(nTxData + nIndex, (uint8_t *) strData, 8);
    nIndex+=8;
    memcpy(nTxData + nIndex, (uint8_t *) ACK, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, ETX, 1);
    nIndex += 1;
    
    WriteCom(nTxData, MAX_LEN);
  }
  
  else if(StrCompare(strCommand, (uint8_t *)"TOGG", 4))
  {
	led_control =3;
    memcpy(nTxData + nIndex, STX, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, (uint8_t *) strCommand, 4);
    nIndex+=4;
    memcpy(nTxData + nIndex, (uint8_t *) strOpt, 3);
    nIndex += 3;
    memcpy(nTxData + nIndex, (uint8_t *) strData, 8);
    nIndex+=8;
    memcpy(nTxData + nIndex, (uint8_t *) ACK, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, ETX, 1);
    nIndex += 1;
    
    WriteCom(nTxData, MAX_LEN);
  }
  
    else 
  {
    memcpy(nTxData + nIndex, STX, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, (uint8_t *) "NULL", 4);
    nIndex+=4;
    memcpy(nTxData + nIndex, (uint8_t *) strOpt, 3);
    nIndex += 3;
    memcpy(nTxData + nIndex, (uint8_t *) strData, 8);
    nIndex+=8;
    memcpy(nTxData + nIndex, ACK, 1);
    nIndex += 1;
    memcpy(nTxData + nIndex, ETX, 1);
    nIndex += 1;
    
    WriteCom(nTxData, MAX_LEN);
  }

  bDataAvailable = false;
}


	if(led_control == 1)
		{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
		}
		
	if(led_control == 2)
		{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
		}
	if(led_control == 3)
		{
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		HAL_Delay(350);
		}
return true;
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_4)
	{
		
		bDataAvailable = true;
		//WriteCom(nTxData, MAX_LEN);
		//HAL_UART_Transmit_IT(&huart1, nTxData, MAX_LEN);
		
	}
	
	
}
void tochar(uint32_t u, uint8_t * y)
{
	uint32_t a=u;
	
	y[4]= a%10 + 0x30;
	a= a/10;
	y[3]= a%10 + 0x30;
	a= a/10;
	y[2]= a%10 + 0x30;
	a= a/10;
	y[1]= a + 0x30;
	y[0]=' ';
	
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
