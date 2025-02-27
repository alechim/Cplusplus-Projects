CC = g++
CFLAGS = -Wall -g

all: 5.1 5.2

5.1: 5.1.cpp
	$(CC) $(CFLAGS) -o $@.exe $<

5.2: 5.2.cpp
	$(CC) $(CFLAGS) -o $@.exe $<

test_5.1: 5.1.exe
	powershell -ExecutionPolicy Bypass -File test_5.1.ps1

test_5.2: 5.2.exe
	powershell -ExecutionPolicy Bypass -File test_5.2.ps1

clean:
	del /F /Q 5.1.exe 5.2.exe

.PHONY: all clean test_5.1 test_5.2