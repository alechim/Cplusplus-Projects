CC = g++
CFLAGS = -Wall -g

SOURCES = main.cpp
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@.exe $^

test: $(EXECUTABLE)
	powershell -ExecutionPolicy Bypass -File run_tests.ps1

clean:
	rm -f $(EXECUTABLE)

.PHONY: all test clean