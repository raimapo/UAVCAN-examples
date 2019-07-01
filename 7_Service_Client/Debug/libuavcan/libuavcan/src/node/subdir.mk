################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_generic_publisher.cpp \
C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_generic_subscriber.cpp \
C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_global_data_type_registry.cpp \
C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_scheduler.cpp \
C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_service_client.cpp \
C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_timer.cpp 

OBJS += \
./libuavcan/libuavcan/src/node/uc_generic_publisher.o \
./libuavcan/libuavcan/src/node/uc_generic_subscriber.o \
./libuavcan/libuavcan/src/node/uc_global_data_type_registry.o \
./libuavcan/libuavcan/src/node/uc_scheduler.o \
./libuavcan/libuavcan/src/node/uc_service_client.o \
./libuavcan/libuavcan/src/node/uc_timer.o 

CPP_DEPS += \
./libuavcan/libuavcan/src/node/uc_generic_publisher.d \
./libuavcan/libuavcan/src/node/uc_generic_subscriber.d \
./libuavcan/libuavcan/src/node/uc_global_data_type_registry.d \
./libuavcan/libuavcan/src/node/uc_scheduler.d \
./libuavcan/libuavcan/src/node/uc_service_client.d \
./libuavcan/libuavcan/src/node/uc_timer.d 


# Each subdirectory must supply rules for building sources it contributes
libuavcan/libuavcan/src/node/uc_generic_publisher.o: C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_generic_publisher.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-DUAVCAN_CPP_VERSION=UAVCAN_CPP11' -DUSE_HAL_DRIVER '-DUAVCAN_STM32_FREERTOS=1' '-DUAVCAN_STM32_TIMER_NUMBER=2' -DSTM32F446xx -DDEBUG '-DUAVCAN_STM32_NUM_IFACES=1' -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Debug/dsdlc_generated -I../../modules/libuavcan/libuavcan_drivers/stm32/driver/include -I../../modules/libuavcan/libuavcan/include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"libuavcan/libuavcan/src/node/uc_generic_publisher.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
libuavcan/libuavcan/src/node/uc_generic_subscriber.o: C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_generic_subscriber.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-DUAVCAN_CPP_VERSION=UAVCAN_CPP11' -DUSE_HAL_DRIVER '-DUAVCAN_STM32_FREERTOS=1' '-DUAVCAN_STM32_TIMER_NUMBER=2' -DSTM32F446xx -DDEBUG '-DUAVCAN_STM32_NUM_IFACES=1' -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Debug/dsdlc_generated -I../../modules/libuavcan/libuavcan_drivers/stm32/driver/include -I../../modules/libuavcan/libuavcan/include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"libuavcan/libuavcan/src/node/uc_generic_subscriber.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
libuavcan/libuavcan/src/node/uc_global_data_type_registry.o: C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_global_data_type_registry.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-DUAVCAN_CPP_VERSION=UAVCAN_CPP11' -DUSE_HAL_DRIVER '-DUAVCAN_STM32_FREERTOS=1' '-DUAVCAN_STM32_TIMER_NUMBER=2' -DSTM32F446xx -DDEBUG '-DUAVCAN_STM32_NUM_IFACES=1' -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Debug/dsdlc_generated -I../../modules/libuavcan/libuavcan_drivers/stm32/driver/include -I../../modules/libuavcan/libuavcan/include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"libuavcan/libuavcan/src/node/uc_global_data_type_registry.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
libuavcan/libuavcan/src/node/uc_scheduler.o: C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_scheduler.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-DUAVCAN_CPP_VERSION=UAVCAN_CPP11' -DUSE_HAL_DRIVER '-DUAVCAN_STM32_FREERTOS=1' '-DUAVCAN_STM32_TIMER_NUMBER=2' -DSTM32F446xx -DDEBUG '-DUAVCAN_STM32_NUM_IFACES=1' -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Debug/dsdlc_generated -I../../modules/libuavcan/libuavcan_drivers/stm32/driver/include -I../../modules/libuavcan/libuavcan/include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"libuavcan/libuavcan/src/node/uc_scheduler.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
libuavcan/libuavcan/src/node/uc_service_client.o: C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_service_client.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-DUAVCAN_CPP_VERSION=UAVCAN_CPP11' -DUSE_HAL_DRIVER '-DUAVCAN_STM32_FREERTOS=1' '-DUAVCAN_STM32_TIMER_NUMBER=2' -DSTM32F446xx -DDEBUG '-DUAVCAN_STM32_NUM_IFACES=1' -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Debug/dsdlc_generated -I../../modules/libuavcan/libuavcan_drivers/stm32/driver/include -I../../modules/libuavcan/libuavcan/include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"libuavcan/libuavcan/src/node/uc_service_client.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
libuavcan/libuavcan/src/node/uc_timer.o: C:/Users/Raimondas/STM32CubeIDE/workspace_1.0.1/UAVCAN-examples/modules/libuavcan/libuavcan/src/node/uc_timer.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-DUAVCAN_CPP_VERSION=UAVCAN_CPP11' -DUSE_HAL_DRIVER '-DUAVCAN_STM32_FREERTOS=1' '-DUAVCAN_STM32_TIMER_NUMBER=2' -DSTM32F446xx -DDEBUG '-DUAVCAN_STM32_NUM_IFACES=1' -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Debug/dsdlc_generated -I../../modules/libuavcan/libuavcan_drivers/stm32/driver/include -I../../modules/libuavcan/libuavcan/include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"libuavcan/libuavcan/src/node/uc_timer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

