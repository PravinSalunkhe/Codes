################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/assign4.cpp \
../src/linkedlist.cpp \
../src/stackadt.cpp 

OBJS += \
./src/assign4.o \
./src/linkedlist.o \
./src/stackadt.o 

CPP_DEPS += \
./src/assign4.d \
./src/linkedlist.d \
./src/stackadt.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


