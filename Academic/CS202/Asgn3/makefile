# CS 202
# Make file for assignment 3
# Courtesy of Derek

# This is your compile command, no more linking by hand!
# Just type make && ./a.out

# This is what the compile flags mean
# g++ is the compiler
# -Wall shows all warnings
# -pedantic ensures strict iso c++
# -std=c++11 ensures this is compiled as c++11 and not c++14 or 98

CC	= g++ -Wall -pedantic -Wextra -std=c++11 -g
OBJS	= Main.o					# Only one implementation file
                        			# so only one object file
DEPS1	= PlayerClass.h				# Main depends on PlayerClass.h
DEPS2	= WeaponClass.h   			# Main depends on WeaponClass.h

all: Main               			# If you have multiple mains you will list them all here

# This creates the object file and compile requirements
# needed for main

# className: all object files it will create
Main: $(OBJS)
	$(CC) -o Main $(OBJS)

Main.o:	Main.cpp $(DEPS1) $(DEPS2)
	$(CC) -c Main.cpp

# This removes the object files so new ones
# can be created when recompiled
# If you didn't change your files and want to recompile
# anyways you need to type make clean
clean:
	rm	$(OBJS)
	                       						# This remove is PERMANENT!!!!!!!
												# Ensure you do NOT put your header
												# or c++ file as an object like I did
												# by mistake once in 202 and delete your
												# entire assignment before it's due!!
