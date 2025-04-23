CC = g++ -Wall -pedantic -Wextra -g
TARGET = asgn4.exe
SRCS = asgn4.cpp entrylog.cpp staff.cpp visitor.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
