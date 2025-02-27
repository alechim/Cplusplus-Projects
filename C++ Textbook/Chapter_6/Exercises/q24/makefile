CC = g++
CFLAGS = -Wall -g

all: main

main: main.cpp	
	$(CC) $(CFLAGS) -o $@.exe $^

test: main
	powershell -ExecutionPolicy Bypass -File run_tests.ps1

clean:
	del /F /Q main.exe

.PHONY: all test clean 