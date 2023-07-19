CC = gcc
CFLAGS = -g -Wall
CFILES = main.c comparators.c 
IFILES = main.i comparators.i
SFILES = main.s comparators.s
OFILES = main.o comparators.o 
BINARY = task2

all: $(BINARY) $(OFILES) $(SFILES) $(IFILES)
	@echo make all done.
	
$(BINARY): $(OFILES)
	$(CC) $^ -o $@ 
	
%o: %s
	$(CC) -c $^ -o $@ 

%s: %i
	$(CC) -S $^ -o $@ 

%i: %c
	$(CC) $(CFLAGS) -E $^ -o $@ 
	
clean:
	rm -rf $(BINARY) $(OFILES) $(SFILES) $(IFILES)
