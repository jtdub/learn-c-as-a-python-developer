# Makefile for multi-file calculator
# Exercise 10.1

CC = cc
CFLAGS = -Wall -Wextra -g

# Target executable
TARGET = calculator

# Source files
SRCS = main.c operations.c display.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
# $< is the first dependency, $@ is the target
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dependencies (which .o files depend on which .h files)
main.o: main.c operations.h display.h
operations.o: operations.c operations.h
display.o: display.c display.h

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean
