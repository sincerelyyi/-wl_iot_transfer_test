TARGET = iot_stransfer
MCU = -mmcs51 -pstc15
SRC = $(wildcard *.c)
CC = sdcc
BUILD = build
OBJ = $(addprefix $(BUILD)/,$(notdir $(patsubst %.c, %.o, $(SRC))))
INC = -Istc_inc
CCFLAGS = -c -Wall  $(INC) $(MCU)

all: $(BUILD)/$(TARGET).hex $(BUILD)/$(TARGET).bin

$(BUILD)/$(TARGET).hex: $(SRC)
	$(CC) -o $@ $^
$(BUILD)/$(TARGET).bin: $(BUILD)/$(TARGET).hex
	sdobjcopy -I ihex -O binary  $^ $@

.PHONY: clean
clean:
	rm -f $(BUILD)/*
.PHONY: clear
clear:
	rm -f $(BUILD)/*.asm
	rm -f $(BUILD)/*.lst
	rm -f $(BUILD)/*.mem
	rm -f $(BUILD)/*.rst
	rm -f $(BUILD)/*.lk
	rm -f $(BUILD)/*.map
	rm -f $(BUILD)/*.rel
	rm -f $(BUILD)/*.sym

.PHONY: install
	find build/ -perm -u=x -type f -exec cp {} ~/usr/bin/ \; 
