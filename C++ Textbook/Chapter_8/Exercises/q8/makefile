CC = g++
CFLAGS = -Wall -pedantic -Wextra -g

# Source Files and Target Executable
TARGET = main.exe
SOURCES = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

test: $(TARGET)
	powershell -ExecutionPolicy Bypass -File run_tests.ps1

clean:
	del /F $(TARGET)

.PHONY: all test clean