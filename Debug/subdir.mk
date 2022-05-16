################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ASTNodes.cpp \
../COBLL.cpp \
../Driver.cpp \
../IdentificationHandler.cpp \
../ProcedureHandler.cpp 

CPP_DEPS += \
./ASTNodes.d \
./COBLL.d \
./Driver.d \
./IdentificationHandler.d \
./ProcedureHandler.d 

OBJS += \
./ASTNodes.o \
./COBLL.o \
./Driver.o \
./IdentificationHandler.o \
./ProcedureHandler.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./ASTNodes.d ./ASTNodes.o ./COBLL.d ./COBLL.o ./Driver.d ./Driver.o ./IdentificationHandler.d ./IdentificationHandler.o ./ProcedureHandler.d ./ProcedureHandler.o

.PHONY: clean--2e-

