# Core directories
INCLUDE_DIR := include
SRC_DIR := src
ASM_DIR := asm
BUILD_DIR := build

# Compiler options
CXX := tools/ee-gcc2.95.3-136/bin/ee-gcc
AS := mipsel-linux-gnu-as
LD := mipsel-linux-gnu-ld
OBJCOPY	:= mipsel-linux-gnu-objcopy

ASFLAGS	:= -march=r5900 -mabi=eabi -no-pad-sections -I$(INCLUDE_DIR)
CXXFLAGS := -Wall -Wextra -fno-exceptions -ffreestanding -x c++ -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/tmhc

# Other
TARGET := $(BUILD_DIR)/tmhc.elf
TARGET_REBUILT := $(BUILD_DIR)/tmhc-rebuilt.elf
S_FILES := $(shell find $(ASM_DIR) -name '*.s')
S_OBJ_FILES := $(patsubst %.s, $(BUILD_DIR)/%.s.o, $(S_FILES))
CPP_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
CPP_OBJ_FILES := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))

all:

rom: $(TARGET)
	$(OBJCOPY) -O binary $(TARGET) $(BUILD_DIR)/tmhc-rom.elf

elf: $(TARGET_REBUILT)
	$(OBJCOPY) -O binary $(TARGET_REBUILT) $(BUILD_DIR)/tmhc-rebuilt-rom.elf

# Compile .cpp files
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $$(dirname $@)
	$(CC) $(CXXFLAGS) -c -o $@ $<

# Compile .s files
$(BUILD_DIR)/%.s.o: %.s
	@mkdir -p $$(dirname $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Link .o files into resulting executable
$(TARGET): $(S_OBJ_FILES)
	@mkdir -p $$(dirname $@)
	$(LD) -T TMHC.ld -T config/undefined_funcs_auto.txt -T config/undefined_syms_auto.txt -o $@

$(TARGET_REBUILT): $(CPP_OBJ_FILES)
	$(CC) -o $@ $<

clean:
	@rm -rf $(BUILD_DIR)

splat:
	@rm -rf $(ASM_DIR)
	python3 -m splat split config/tmhc.yaml

.PHONY: all clean
