# Compiler and flags
CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lm

# Executable name
TARGET = mandelbrot

# Source file
SRC = mandelbrot.c

# Default target - build the program
all: $(TARGET)

# Rule to build the program
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Clean temporary and output files
clean:
	rm -f $(TARGET) *.o core*
