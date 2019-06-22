#ifndef CHIP_UAVCAN_CONFIG_H
#define CHIP_UAVCAN_CONFIG_H

#include <stm32f4xx.h>

#define STM32F4XX

#define CAN1_TX_IRQHandler CAN1_TX_IRQHandler
#define CAN1_RX0_IRQHandler CAN1_RX0_IRQHandler
#define CAN1_RX1_IRQHandler CAN1_RX1_IRQHandler

#define STM32_PCLK1 (42000000ul)
#define STM32_TIMCLK1 (84000000ul)

#endif
