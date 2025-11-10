/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
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

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//define ON/OFF
#define ON 			1
#define OFF 		0

//define states
#define RED 		1
#define GREEN		2
#define YELLOW 		3

#define INIT 0
#define RED_GREEN 	1
#define RED_YELLOW 	2
#define GREEN_RED 	3
#define YELLOW_RED  4
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void control_red1(uint8_t state);
void control_yellow1(uint8_t state);
void control_green1(uint8_t state);
void control_red2(uint8_t state);
void control_yellow2(uint8_t state);
void control_green2(uint8_t state);

void _display7SEG(int num);
void display7SEG(int num);
const uint8_t seg_table[10] = {
    0b1000000, // 0
    0b1111001, // 1
    0b0100100, // 2
    0b0110000, // 3
    0b0011001, // 4
    0b0010010, // 5
    0b0000010, // 6
    0b1111000, // 7
    0b0000000, // 8
    0b0010000  // 9
};
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  uint8_t 	state 	= INIT;
  uint8_t 	state2  = 1;
  uint32_t 	counter = 0;
  uint32_t 	tick	= 0;
  while (1)
  {
	  switch (state) {

		  case RED_GREEN:
			  control_red1(ON);  control_yellow1(OFF); control_green1(OFF);
			  control_red2(OFF); control_yellow2(OFF); control_green2(ON);

			  if (counter >= 300) {  // redRED1(3s), greenYELLOW1(3s)
				  state = RED_YELLOW;
				  counter = 0;
			  }
			  break;

		  case RED_YELLOW:
			  control_red1(ON);  control_yellow1(OFF); control_green1(OFF);
			  control_red2(OFF); control_yellow2(ON);  control_green2(OFF);

			  if (counter >= 200) {  // redRED1(2s), yellowYELLOW1(2s)
				  state = GREEN_RED;
				  counter = 0;
			  }
			  break;

		  case GREEN_RED:
			  control_red1(OFF);  control_yellow1(OFF); control_green1(ON);
			  control_red2(ON);   control_yellow2(OFF); control_green2(OFF);

			  if (counter >= 300) {  // greenRED1(3s), redYELLOW1(3s)
				  state = YELLOW_RED;
				  counter = 0;
			  }
			  break;

		  case YELLOW_RED:
			  control_red1(OFF);  control_yellow1(ON);  control_green1(OFF);
			  control_red2(ON);   control_yellow2(OFF); control_green2(OFF);

			  if (counter >= 200) {  // yellowRED1(2s), redYELLOW1(3s)
				  state = RED_GREEN;
				  counter = 0;
			  }
			  break;
		  default:
			  state = RED_GREEN;
			  counter = 0;
			  break;
	  }
	  ++counter;

	  switch (state2) {

	  	  case RED:
	  		  display7SEG(5 - tick/100 % 5); // print 5->1
	  		  if (tick >= 500) {
	  			  state2 = GREEN;
	  			  tick = 0;
	  		  }
	  		  break;

	  	  case GREEN:
			  display7SEG(3 - tick/100 % 3); // print 3->1
			  if (tick >= 300) {
				  state2 = YELLOW;
				  tick = 0;
			  }
			  break;

	  	  case YELLOW:
			  display7SEG(2 - tick/100 % 2); // print 2->1
			  if (tick >= 200) {
				  state2 = RED;
				  tick = 0;
			  }
			  break;
	  	  default:
	  		  break;
	  }
	  ++tick;

	  HAL_Delay(10) ;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
                          |LED_E_Pin|LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RED1_Pin YELLOW1_Pin GREEN1_Pin RED2_Pin
                           YELLOW2_Pin GREEN2_Pin */
  GPIO_InitStruct.Pin = RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
                          |YELLOW2_Pin|GREEN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_A_Pin LED_B_Pin LED_C_Pin LED_D_Pin
                           LED_E_Pin LED_F_Pin LED_G_Pin */
  GPIO_InitStruct.Pin = LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
                          |LED_E_Pin|LED_F_Pin|LED_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void control_red1(uint8_t state) {
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, state);
}
void control_yellow1(uint8_t state) {
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, state);
}
void control_green1(uint8_t state) {
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, state);
}
void control_red2(uint8_t state) {
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, state);
}
void control_yellow2(uint8_t state) {
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, state);
}
void control_green2(uint8_t state) {
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, state);
}


void display7SEG(int num) {
    if (num < 0 || num > 9) return;
    uint8_t pattern = seg_table[num];
    HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, pattern & 0x01);
    HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, (pattern >> 1) & 0x01);
    HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, (pattern >> 2) & 0x01);
    HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, (pattern >> 3) & 0x01);
    HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, (pattern >> 4) & 0x01);
    HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, (pattern >> 5) & 0x01);
    HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, (pattern >> 6) & 0x01);
}
void _display7SEG(int num) {
	display7SEG(9-num);
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
