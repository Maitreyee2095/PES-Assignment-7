################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Analog_in.c \
../source/Assignment_7.c \
../source/DAC_config.c \
../source/analog_out.c \
../source/autocorrelate.c \
../source/mtb.c \
../source/print_samples.c \
../source/semihost_hardfault.c \
../source/sin_trig.c \
../source/test_sin.c 

OBJS += \
./source/Analog_in.o \
./source/Assignment_7.o \
./source/DAC_config.o \
./source/analog_out.o \
./source/autocorrelate.o \
./source/mtb.o \
./source/print_samples.o \
./source/semihost_hardfault.o \
./source/sin_trig.o \
./source/test_sin.o 

C_DEPS += \
./source/Analog_in.d \
./source/Assignment_7.d \
./source/DAC_config.d \
./source/analog_out.d \
./source/autocorrelate.d \
./source/mtb.d \
./source/print_samples.d \
./source/semihost_hardfault.d \
./source/sin_trig.d \
./source/test_sin.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"E:\PES-Assignment-7\Assignment_7\board" -I"E:\PES-Assignment-7\Assignment_7\source" -I"E:\PES-Assignment-7\Assignment_7" -I"E:\PES-Assignment-7\Assignment_7\drivers" -I"E:\PES-Assignment-7\Assignment_7\CMSIS" -I"E:\PES-Assignment-7\Assignment_7\utilities" -I"E:\PES-Assignment-7\Assignment_7\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


