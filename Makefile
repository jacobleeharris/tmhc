# Core directories
INCLUDE_DIR := include
SRC_DIR := src
ASM_DIR := asm
BUILD_DIR := build

# Compiler options
CC := tools/ee-gcc-3.2-040921/bin/ee-gcc
CXX := tools/ee-gcc-3.2-040921/bin/ee-g++
AS := mips-linux-gnu-as
LD := mips-linux-gnu-ld
OBJCOPY	:= mips-linux-gnu-objcopy

ASFLAGS	:= -march=r5900 -mabi=eabi -no-pad-sections -I$(INCLUDE_DIR)
CXXFLAGS := -Wall -Wextra -fno-exceptions -ffreestanding -I$(INCLUDE_DIR)

# Other
TARGET := $(BUILD_DIR)/tmhc.elf
S_FILES := $(shell find $(ASM_DIR) -name '*.s')
S_OBJ_FILES := $(patsubst %.s, $(BUILD_DIR)/%.s.o, $(S_FILES))
OBJ_FILES := S_OBJ_FILES

all: $(TARGET)
	$(OBJCOPY) -O binary $(TARGET) $(BUILD_DIR)/tmhc-rom.elf

# Compile .s files
$(BUILD_DIR)/%.s.o: %.s
	@mkdir -p $$(dirname $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Link .o files into resulting executable
$(TARGET): $(S_OBJ_FILES)
	@mkdir -p $$(dirname $@)
	$(LD) -T TMHC.ld -T config/undefined_funcs_auto.txt -T config/undefined_syms_auto.txt -o $@

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all clean
