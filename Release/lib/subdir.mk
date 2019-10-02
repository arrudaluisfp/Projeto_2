################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\lib\buttons.cpp \
..\lib\buttons_events_handler.cpp \
..\lib\controller.cpp \
..\lib\lcd_handler.cpp \
..\lib\lm35_handler.cpp \
..\lib\sloeber.ino.cpp 

LINK_OBJ += \
.\lib\buttons.cpp.o \
.\lib\buttons_events_handler.cpp.o \
.\lib\controller.cpp.o \
.\lib\lcd_handler.cpp.o \
.\lib\lm35_handler.cpp.o \
.\lib\sloeber.ino.cpp.o 

CPP_DEPS += \
.\lib\buttons.cpp.d \
.\lib\buttons_events_handler.cpp.d \
.\lib\controller.cpp.d \
.\lib\lcd_handler.cpp.d \
.\lib\lm35_handler.cpp.d \
.\lib\sloeber.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
lib\buttons.cpp.o: ..\lib\buttons.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

lib\buttons_events_handler.cpp.o: ..\lib\buttons_events_handler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

lib\controller.cpp.o: ..\lib\controller.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

lib\lcd_handler.cpp.o: ..\lib\lcd_handler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

lib\lm35_handler.cpp.o: ..\lib\lm35_handler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

lib\sloeber.ino.cpp.o: ..\lib\sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\Jessen\Desktop\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"

	@echo 'Finished building: $<'
	@echo ' '


