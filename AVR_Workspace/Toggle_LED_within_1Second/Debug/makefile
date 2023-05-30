################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
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
Toggle_LED_within_1Second.lss \

FLASH_IMAGE += \
Toggle_LED_within_1Second.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Toggle_LED_within_1Second.elf secondary-outputs

# Tool invocations
Toggle_LED_within_1Second.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Toggle_LED_within_1Second.map -mmcu=atmega32 -o "Toggle_LED_within_1Second.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Toggle_LED_within_1Second.lss: Toggle_LED_within_1Second.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Toggle_LED_within_1Second.elf  >"Toggle_LED_within_1Second.lss"
	@echo 'Finished building: $@'
	@echo ' '

Toggle_LED_within_1Second.hex: Toggle_LED_within_1Second.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Toggle_LED_within_1Second.elf  "Toggle_LED_within_1Second.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Toggle_LED_within_1Second.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Toggle_LED_within_1Second.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Toggle_LED_within_1Second.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
