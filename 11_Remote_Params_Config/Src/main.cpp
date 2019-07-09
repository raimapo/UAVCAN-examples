/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <uavcan_stm32/uavcan_stm32.hpp>
#include <uavcan/uavcan.hpp>

#include <uavcan/protocol/param_server.hpp>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define CAN_THRAD_STACK_SIZE 512

#define DEBUG_BUFFER_SIZE    (256)
#define DEBUG_TIMEOUT        (1000)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart3;

PCD_HandleTypeDef hpcd_USB_OTG_FS;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */
uint32_t defaultTaskBuffer[ CAN_THRAD_STACK_SIZE ];
osStaticThreadDef_t defaultTaskControlBlock;

osSemaphoreId DEBUG_TX_completeID;
osSemaphoreDef(DEBUG_TX_complete);
uint8_t DEBUG_TX_Buffer[DEBUG_BUFFER_SIZE] = {0};  //!< Debug buffer.
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_USB_OTG_FS_PCD_Init(void);


/* USER CODE BEGIN PFP */
extern "C" {
	void StartDefaultTask(void const * argument);
}

bool DEBUG_Init(void);
void DEBUG_Printf(const char *fmt, ...);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
constexpr unsigned NodePoolSize = 8192;
uavcan_stm32::CanInitHelper<> can;

uavcan::Node<NodePoolSize>& getNode() {
    static uavcan::Node<NodePoolSize> node(can.driver, uavcan_stm32::SystemClock::instance());
    return node;
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
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  /* USER CODE BEGIN 2 */
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_CAN1_CLK_ENABLE();

  __HAL_RCC_GPIOD_CLK_ENABLE();
  /**CAN1 GPIO Configuration
  PD0     ------> CAN1_RX
  PD1     ------> CAN1_TX
  */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  DEBUG_Init();
  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadStaticDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, CAN_THRAD_STACK_SIZE, defaultTaskBuffer, &defaultTaskControlBlock);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48CLKSOURCE_PLLQ;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USB_OTG_FS Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_OTG_FS_PCD_Init(void)
{

  /* USER CODE BEGIN USB_OTG_FS_Init 0 */

  /* USER CODE END USB_OTG_FS_Init 0 */

  /* USER CODE BEGIN USB_OTG_FS_Init 1 */

  /* USER CODE END USB_OTG_FS_Init 1 */
  hpcd_USB_OTG_FS.Instance = USB_OTG_FS;
  hpcd_USB_OTG_FS.Init.dev_endpoints = 6;
  hpcd_USB_OTG_FS.Init.speed = PCD_SPEED_FULL;
  hpcd_USB_OTG_FS.Init.dma_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
  hpcd_USB_OTG_FS.Init.Sof_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.low_power_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.lpm_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.vbus_sensing_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.use_dedicated_ep1 = DISABLE;
  if (HAL_PCD_Init(&hpcd_USB_OTG_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_OTG_FS_Init 2 */

  /* USER CODE END USB_OTG_FS_Init 2 */

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_Btn_Pin */
  GPIO_InitStruct.Pin = USER_Btn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD3_Pin LD2_Pin */
  GPIO_InitStruct.Pin = LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = USB_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OverCurrent_Pin */
  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
bool DEBUG_Init(void)
{
    if ((DEBUG_TX_completeID = osSemaphoreCreate(osSemaphore(DEBUG_TX_complete), 1)) == NULL)
    {
        return false;
    }
    return true;
}

void DEBUG_Printf(const char *fmt, ...)
{
    uint16_t i = 0;
    va_list args;
    if (osSemaphoreWait(DEBUG_TX_completeID, 1000) == osOK)
    {
        va_start(args, fmt);
        i = vsnprintf((char*) DEBUG_TX_Buffer, DEBUG_BUFFER_SIZE - 1, fmt, args);
        DEBUG_TX_Buffer[i] = 0x00;

        uint16_t retry = 4096;

        while ((retry--)&&(HAL_UART_Transmit(&huart3, &DEBUG_TX_Buffer[0], strlen((char*)&DEBUG_TX_Buffer[0]), 0xFFF) != HAL_OK));

        va_end(args);
        osSemaphoreRelease(DEBUG_TX_completeID);
    }
    return;
}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN 5 */
	uint32_t value = 1000000;

	can.init(value);

	getNode().setName("org.test.RemoteParamsConfig");
	getNode().setNodeID(5);


	if (getNode().start() < 0) {
		DEBUG_Printf("UAVCAN start fail\r\n");
	    while (1);
	}

    /*
     * This would be our configuration storage.
     */
    static struct Parametrai
    {
        unsigned param1 = 42;
        float param2 = 0.123456F;
        double param3 = 1e-5;
        std::string text = "Hello world!";
    } configuration;

    /*
     * Now, we need to define some glue logic between the server (below) and our configuration storage (above).
     * This is done via the interface uavcan::IParamManager.
     */
    class : public uavcan::IParamManager
    {
    	void getParamNameByIndex(Index index, Name& out_name) const override {
    		if (index == 0) { out_name = "param1"; }
            if (index == 1) { out_name = "param2"; }
            if (index == 2) { out_name = "param3"; }
            if (index == 3) { out_name = "text"; }
        }

    	void assignParamValue(const Name& name, const Value& value) override {
    		if (name == "param1") {
    			/*
    			 * Parameter "foo" is an integer, so we accept only integer values here.
    			 */
    			if (value.is(uavcan::protocol::param::Value::Tag::integer_value))
    				configuration.param1 = *value.as<uavcan::protocol::param::Value::Tag::integer_value>();
    		} else if (name == "param2") {
    			if (value.is(uavcan::protocol::param::Value::Tag::real_value))
    				configuration.param2 = *value.as<uavcan::protocol::param::Value::Tag::real_value>();
    		} else if (name == "param3") {
    			if (value.is(uavcan::protocol::param::Value::Tag::real_value))
    				configuration.param3 = *value.as<uavcan::protocol::param::Value::Tag::real_value>();
    		} else if (name == "text") {
    			if (value.is(uavcan::protocol::param::Value::Tag::string_value))
    				configuration.text = value.as<uavcan::protocol::param::Value::Tag::string_value>()->c_str();
    		} else
    			DEBUG_Printf("Can't assign parameter. Check if type is correct\r\n");
    	}

    	void readParamValue(const Name& name, Value& out_value) const override {
    		if (name == "param1")
    			out_value.to<uavcan::protocol::param::Value::Tag::integer_value>() = configuration.param1;
    		else if (name == "param2")
    			out_value.to<uavcan::protocol::param::Value::Tag::real_value>() = configuration.param2;
    		else if (name == "param3")
    			out_value.to<uavcan::protocol::param::Value::Tag::real_value>() = configuration.param3;
    		else if (name == "text")
    			out_value.to<uavcan::protocol::param::Value::Tag::string_value>() = configuration.text.c_str();
    		else
    			DEBUG_Printf("Can't read parameter. Check if type is correct\r\n");
    	}

    	int saveAllParams() override {
    		DEBUG_Printf("Save - this implementation does not require any action\r\n");
    		return 0;     // Zero means that everything is fine.
    	}

    	int eraseAllParams() override {
    		DEBUG_Printf("Erase - all params reset to default values\r\n");
    		configuration = Parametrai();
    		return 0;
    	}

    	/**
    	 * Note that this method is optional. It can be left unimplemented.
    	 */
    	void readParamDefaultMaxMin(const Name& name, Value& out_def, NumericValue& out_max, NumericValue& out_min) const override {
    		if (name == "param1") {
    			out_def.to<uavcan::protocol::param::Value::Tag::integer_value>() = Parametrai().param1;
    			out_max.to<uavcan::protocol::param::NumericValue::Tag::integer_value>() = 9000;
    			out_min.to<uavcan::protocol::param::NumericValue::Tag::integer_value>() = 0;
    		} else if (name == "param2") {
    			out_def.to<uavcan::protocol::param::Value::Tag::real_value>() = Parametrai().param2;
    			out_max.to<uavcan::protocol::param::NumericValue::Tag::real_value>() = 1;
    			out_min.to<uavcan::protocol::param::NumericValue::Tag::real_value>() = 0;
    		} else if (name == "param3") {
    			out_def.to<uavcan::protocol::param::Value::Tag::real_value>() = Parametrai().param3;
    			out_max.to<uavcan::protocol::param::NumericValue::Tag::real_value>() = 1;
    			out_min.to<uavcan::protocol::param::NumericValue::Tag::real_value>() = 0;
    		} else if (name == "text") {
    			out_def.to<uavcan::protocol::param::Value::Tag::string_value>() = Parametrai().text.c_str();
    			DEBUG_Printf("Limits for 'text' are not defined\r\n");
    		} else
    			DEBUG_Printf("Can't read the limits for parameter\r\n");
    	}
    } param_manager;

    /*
     * Initializing the configuration server.
     * A pointer to the glue logic object is passed to the method start().
     */
    uavcan::ParamServer server(getNode());

    const int server_start_res = server.start(&param_manager);
    if (server_start_res < 0)
    {
    	DEBUG_Printf("Failed to start ParamServer\r\n");
    }

    /*
     * Many embedded applications require a restart before the new configuration settings can
     * be applied, so it is highly recommended to also support the remote restart service.
     */
    class : public uavcan::IRestartRequestHandler {
    	bool handleRestartRequest(uavcan::NodeID request_source) override {
    		DEBUG_Printf("Got a remote restart request from %d\r\n", int(request_source.get()));
                /*
                 * We won't really restart, so return 'false'.
                 * Returning 'true' would mean that we're going to restart for real.
                 * Note that it is recognized that some nodes may not be able to respond to the
                 * restart request (e.g. if they restart immediately from the service callback).
                 */
    		return true;
    	}
    } restart_request_handler;

    /*
     * Installing the restart request handler.
     */
    getNode().setRestartRequestHandler(&restart_request_handler); // Done.

	getNode().setModeOperational();

  /* Infinite loop */
  for(;;)
  {
	    const int res = getNode().spin(uavcan::MonotonicDuration::fromMSec(500));
	    if (res < 0) {
	    	DEBUG_Printf("UAVCAN spin fail\r\n");
	    	while(1);
	    }  }
  /* USER CODE END 5 */ 
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
