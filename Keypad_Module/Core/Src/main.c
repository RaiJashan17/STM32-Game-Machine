/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
char read_keypad (void)
{
	/* Make ROW 1 LOW and all other ROWs HIGH */
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_7, GPIO_PIN_RESET); //Pull the (GPIOA, GPIO_PIN_7)low
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_6, GPIO_PIN_SET);  // Pull the PA6 High
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_5, GPIO_PIN_SET);  // Pull the PA5 High
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_4, GPIO_PIN_SET);  // Pull the PA4 High

	if (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)))  // if the Col 1 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)));   // wait till the button is pressed
		return '1';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_2)))   // if the Col 2 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)));   // wait till the button is pressed
		return '2';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)))   // if the Col 3 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)));   // wait till the button is pressed
		return '3';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)))   // if the Col 4 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)));   // wait till the button is pressed
		return 'A';
	}

	/* Make ROW 2 LOW and all other ROWs HIGH */
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_7, GPIO_PIN_SET);  //Pull the (GPIOA, GPIO_PIN_7)low
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);  // Pull the PA6 High
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_5, GPIO_PIN_SET);  // Pull the PA5 High
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_4, GPIO_PIN_SET);  // Pull the PA4 High

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)))   // if the Col 1 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)));   // wait till the button is pressed
		return '4';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_2)))   // if the Col 2 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_2)));   // wait till the button is pressed
		return '5';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)))   // if the Col 3 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)));   // wait till the button is pressed
		return '6';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)))   // if the Col 4 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)));   // wait till the button is pressed
		return 'B';
	}


	/* Make ROW 3 LOW and all other ROWs HIGH */
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_7, GPIO_PIN_SET);  //Pull the (GPIOA, GPIO_PIN_7)low
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_6, GPIO_PIN_SET);  // Pull the PA6 High
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);  // Pull the PA5 High
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_4, GPIO_PIN_SET);  // Pull the PA4 High

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)))   // if the Col 1 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)));   // wait till the button is pressed
		return '7';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_2)))   // if the Col 2 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_2)));   // wait till the button is pressed
		return '8';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)))   // if the Col 3 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)));   // wait till the button is pressed
		return '9';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)))   // if the Col 4 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)));   // wait till the button is pressed
		return 'C';
	}


	/* Make ROW 4 LOW and all other ROWs HIGH */
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_7, GPIO_PIN_SET);  //Pull the (GPIOA, GPIO_PIN_7)low
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_6, GPIO_PIN_SET);  // Pull the PA6 High
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_5, GPIO_PIN_SET);  // Pull the PA5 High
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);  // Pull the PA4 High

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)))   // if the Col 1 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)));   // wait till the button is pressed
		return '*';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_2)))   // if the Col 2 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_2)));   // wait till the button is pressed
		return '0';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)))   // if the Col 3 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)));   // wait till the button is pressed
		return '#';
	}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)))   // if the Col 4 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3)));   // wait till the button is pressed
		return 'D';
	}

	return 0x11;  // /if nothing is pressed

}

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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  char key = 0x11;
  char message[4] = "0000";
  int count=0;
  int releaseflag=1;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  key = read_keypad();
	  if (count<4 & key!='*' & key!='\021' & releaseflag==1){
		  message[count]=key;
		  count+=1;
		  releaseflag=0;
	  }
	  else if (key=='*'){
		  message[0]='0';
		  message[1]='0';
		  message[2]='0';
		  message[3]='0';
		  count=0;
	  }
	  else if (count==4){
		  if(message[0]=='2' & message[1]=='B' & message[2]=='0' & message[3]=='9'){
			  //Send message to servo to open door
			  HAL_GPIO_WritePin (GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
			  HAL_Delay(1000);
			  message[0]='0';
			  message[1]='0';
			  message[2]='0';
			  message[3]='0';
			  count=0;
			  HAL_GPIO_WritePin (GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
		  }
		  else if(message[0]=='D' & message[1]=='1' & message[2]=='A' & message[3]=='7'){
			  HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
			  HAL_Delay(1000);
			  	  message[0]='0';
				  message[1]='0';
				  message[2]='0';
				  message[3]='0';
				  count=0;
				  HAL_GPIO_WritePin (GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
		  }
		  else if(message[0]=='3' & message[1]=='6' & message[2]=='5' & message[3]=='C'){
			  HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
			  HAL_Delay(1000);
			  message[0]='0';
			  message[1]='0';
			  message[2]='0';
			  message[3]='0';
			  count=0;
			  HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
		  }
		  else{
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
			  HAL_Delay(1000);
			  message[0]='0';
			  message[1]='0';
			  message[2]='0';
			  message[3]='0';
			  count=0;
			  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
		  }
	  }
	  else if (key=='\021'){
		  releaseflag=1;
		  HAL_Delay(100);
	  }else{
		  printf("Do Nothing");
	  }

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7
                           PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB1 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
