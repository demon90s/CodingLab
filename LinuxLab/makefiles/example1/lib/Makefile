# Makefile 例子

# Which compiler
CC = gcc

# Where are include files kept
INCLUDE = .

# Options for development
CFLAGS = -g -Wall

# Options for release
# CFLAGS = -O -Wall

# Options for ar flags
ARFLAGS = Urv

LIBCORE = libcore.a

$(LIBCORE): $(LIBCORE)(core.o)

core.o: core.c core.h

clean:
	-rm -f libcore.a *.o
