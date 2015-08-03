BOARD_TAG				:= attiny84
ARDUINO_PORT			:= /dev/ttyUSB0
ARDUINO_LIBS			:= TinyWireS
ARDUINO_VAR_PATH		:= $(HOME)/sketchbook/hardware/attiny/variants
USER_LIB_PATH			:= $(realpath ./lib)
BOARDS_TXT				:= $(HOME)/sketchbook/hardware/attiny/boards.txt

CXXFLAGS				+= -std=gnu++11
CFLAGS					+= -std=gnu++11

ISP_PORT				:= /dev/ttyUSB0
ISP_PROG				:= stk500v1
AVRDUDE_ISP_BAUDRATE	:= 19200

include $(HOME)/git/Arduino-Makefile/Arduino.mk

# vi: noexpandtab ts=4
