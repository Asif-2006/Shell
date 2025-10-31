# ============================================
# Makefile for Asif's Custom Mini Shell (v1.0)
# ============================================

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Output binary
TARGET = $(BIN_DIR)/myshell

# Collect all .c files in src/
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
# Convert each .c file into a corresponding .o file inside build/
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Default target
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET)
	@echo "✅ Build complete: $(TARGET)"

# Compile each .c file to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the shell
run: $(TARGET)
	@echo "🚀 Running Asif's Custom Shell..."
	./$(TARGET)

# Clean build and binaries
clean:
	@echo "🧹 Cleaning build files..."
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)
	rm -f $(BUILD_DIR)/* $(BIN_DIR)/*
	@echo "✅ Clean complete."


# For safety: tell Make that these are not file names
.PHONY: all clean run
