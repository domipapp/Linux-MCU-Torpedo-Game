################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../autogen/sl_board_default_init.c \
../autogen/sl_device_init_clocks.c \
../autogen/sl_event_handler.c \
../autogen/sl_iostream_handles.c 

OBJS += \
./autogen/sl_board_default_init.o \
./autogen/sl_device_init_clocks.o \
./autogen/sl_event_handler.o \
./autogen/sl_iostream_handles.o 

C_DEPS += \
./autogen/sl_board_default_init.d \
./autogen/sl_device_init_clocks.d \
./autogen/sl_event_handler.d \
./autogen/sl_iostream_handles.d 


# Each subdirectory must supply rules for building sources it contributes
autogen/sl_board_default_init.o: ../autogen/sl_board_default_init.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DconfigNUM_SDK_THREAD_LOCAL_STORAGE_POINTERS=2' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFM32GG_STK3700/config" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf/config" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf/autogen" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/RTOS2/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/cmsis/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/portable/GCC/ARM_CM3" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O3 -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_board_default_init.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_device_init_clocks.o: ../autogen/sl_device_init_clocks.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DconfigNUM_SDK_THREAD_LOCAL_STORAGE_POINTERS=2' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFM32GG_STK3700/config" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf/config" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf/autogen" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/RTOS2/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/cmsis/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/portable/GCC/ARM_CM3" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O3 -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_device_init_clocks.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_event_handler.o: ../autogen/sl_event_handler.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DconfigNUM_SDK_THREAD_LOCAL_STORAGE_POINTERS=2' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFM32GG_STK3700/config" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf/config" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf/autogen" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/RTOS2/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/cmsis/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/portable/GCC/ARM_CM3" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O3 -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_event_handler.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_iostream_handles.o: ../autogen/sl_iostream_handles.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DconfigNUM_SDK_THREAD_LOCAL_STORAGE_POINTERS=2' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFM32GG_STK3700/config" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/drivers" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf/config" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf/autogen" -I"/Users/dominikpapp/SimplicityStudio/v5_workspace/hf" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/RTOS2/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/cmsis/Include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/include" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/portable/GCC/ARM_CM3" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"/Users/dominikpapp/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O3 -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_iostream_handles.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


