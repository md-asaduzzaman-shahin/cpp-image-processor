# Compiler settings - Can be customized.
CC = g++
CFLAGS = -Wall -g

# Target executable name
TARGET = image_tool

# Build the executable
all: $(TARGET)

$(TARGET): src/main.cpp
	$(CC) $(CFLAGS) -o $(TARGET) src/main.cpp

# Clean up build files (Good practice)
clean:
	rm -f $(TARGET)