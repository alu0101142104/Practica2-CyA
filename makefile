CC = g++
CFLAGS = -std=c++17 -g -Wall

F0  = Cadenas
F1  = Cliente
FH  = .h
FCC = .cc

IDIR = ../include/
ODIR = ../src/
LDIR = ../lib/

PROGRAM = $(F0)

all: $(PROGRAM)
$(PROGRAM): $(F1)$(F0)$(FCC) $(F0)$(FCC)
	$(CC) $(CFLAGS) $(F1)$(F0)$(FCC) $(F0)$(FCC) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	rm -rf fileout.txt