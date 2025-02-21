# @file Makefile
# @author Noah Melton and Jose Jaime
# @date 2025-02-20
# @brief Makefile for Image Stacker project
# Makefile for compliling the Image Stacker project

# Compiler
CC = g++

# Target Executable Name
TARGET = stacker

# Compile with all errors and warnings
CFLAGS = -c -Wall -Wextra

# Default Target
all: $(TARGET)

#Link all object files into the final executable
