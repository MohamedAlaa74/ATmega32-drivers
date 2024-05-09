################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WDT/subdir.mk
-include MCAL/USART/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/PWM/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/G_INT/subdir.mk
-include MCAL/GPT/subdir.mk
-include MCAL/EXT_INT/subdir.mk
-include MCAL/EEPROM/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include ECU/SEGMANT/subdir.mk
-include ECU/RELAY/subdir.mk
-include ECU/LED/subdir.mk
-include ECU/LCD/subdir.mk
-include ECU/KEYPAD/subdir.mk
-include ECU/ECU_init/subdir.mk
-include ECU/DC_MOTOR/subdir.mk
-include ECU/BTN/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Ghafar.lss \

FLASH_IMAGE += \
Ghafar.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Ghafar.elf secondary-outputs

# Tool invocations
Ghafar.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Ghafar.map -mmcu=atmega32 -o "Ghafar.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Ghafar.lss: Ghafar.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Ghafar.elf  >"Ghafar.lss"
	@echo 'Finished building: $@'
	@echo ' '

Ghafar.hex: Ghafar.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Ghafar.elf  "Ghafar.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Ghafar.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Ghafar.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Ghafar.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
