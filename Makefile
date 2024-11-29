# Core directories
INCLUDE_DIR := include
SRC_DIR := src
ASM_DIR := asm
BUILD_DIR := build

# Compiler options
CC := tools/ee-gcc2.95.3-136/bin/ee-gcc.exe
AS := mipsel-linux-gnu-as
LD := mipsel-linux-gnu-ld
OBJCOPY	:= mipsel-linux-gnu-objcopy

ASFLAGS	:= -march=r5900 -mabi=eabi -no-pad-sections -I$(INCLUDE_DIR)
CXXFLAGS := -nostdinc -Wall -fno-exceptions -ffreestanding -x c++ -O2 -G8 -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/tmhc -I$(INCLUDE_DIR)/sdk

# Other
WIBO := tools/wibo-0.6.14/wibo
TARGET := $(BUILD_DIR)/tmhc.elf
S_FILES := $(shell find $(ASM_DIR)/data $(ASM_DIR)/sdk $(ASM_DIR)/tmhc -name '*.s')
S_OBJ_FILES := $(patsubst %.s, $(BUILD_DIR)/%.s.o, $(S_FILES))
CPP_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
CPP_OBJ_FILES := $(patsubst %.cpp, $(BUILD_DIR)/%.cpp.o, $(CPP_FILES))

all: rom

rom: $(TARGET)
	$(OBJCOPY) -O binary $(TARGET) $(BUILD_DIR)/tmhc-rom.elf

# Compile .cpp files
$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $$(dirname $@)
	$(WIBO) $(CC) $(CXXFLAGS) -v -c -o $@ $< && mipsel-linux-gnu-strip $@ -N dummy_symbol_name

# Compile .s files
$(BUILD_DIR)/%.s.o: %.s
	@mkdir -p $$(dirname $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Link .o files into resulting executable
$(TARGET): $(S_OBJ_FILES) $(CPP_OBJ_FILES)
	@mkdir -p $$(dirname $@)
	$(LD) -Map config/tmhc.map -T TMHC.ld -T config/undefined_funcs_auto.txt -T config/undefined_syms_auto.txt -o $@

clean:
	@rm -rf $(BUILD_DIR)

splat:
	@rm -rf $(ASM_DIR)
	python3 -m splat split config/tmhc.yaml

.PHONY: all clean
