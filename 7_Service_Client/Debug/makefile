################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include libuavcan/libuavcan_drivers/stm32/driver/src/subdir.mk
-include libuavcan/libuavcan/src/transport/subdir.mk
-include libuavcan/libuavcan/src/protocol/subdir.mk
-include libuavcan/libuavcan/src/node/subdir.mk
-include libuavcan/libuavcan/src/marshal/subdir.mk
-include libuavcan/libuavcan/src/driver/subdir.mk
-include libuavcan/libuavcan/src/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
7_Service_Client.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
7_Service_Client.list \


# All Target
all:
	+make pre-build && make main-build

# Main-build Target
main-build: 7_Service_Client.elf secondary-outputs

# Tool invocations
7_Service_Client.elf: $(OBJS) $(USER_OBJS) C:\Users\Raimondas\STM32CubeIDE\workspace_1.0.1\UAVCAN-examples\7_Service_Client\STM32F446ZETX_FLASH.ld
	arm-none-eabi-g++ -o "7_Service_Client.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Raimondas\STM32CubeIDE\workspace_1.0.1\UAVCAN-examples\7_Service_Client\STM32F446ZETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="7_Service_Client.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

7_Service_Client.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "7_Service_Client.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

pre-build:
	python ../../modules/libuavcan/libuavcan/dsdl_compiler/libuavcan_dsdlc ../../modules/libuavcan/dsdl/uavcan
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build

-include ../makefile.targets
