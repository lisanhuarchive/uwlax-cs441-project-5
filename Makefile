#
# Josh Hursey
# CS 441/541: Project 5
#
#####################################################################
#
# Type "make" to compile your code
# 
# Type "make clean" to remove the executable (and any object files)
#
#####################################################################
CC=gcc
CFLAGS=-Wall -g -O0
LDFLAGS=-lm

#
# List all of the binary programs you want to build here
# Separate each program with a single space
#
all: check_mode

#
# Project main program
#
check_mode: check_mode.c check_mode.h support.o
	$(CC) -o check_mode $(CFLAGS) check_mode.c support.o $(LDFLAGS)

support.o: support.c support.h
	$(CC) -c -o support.o $(CFLAGS) support.c
#
# Cleanup the files that we have created
#
clean: check-clean
	$(RM) check_mode
	$(RM) -rf *.dSYM *.o

#
# Tests
#
include given-tests/Makefile
