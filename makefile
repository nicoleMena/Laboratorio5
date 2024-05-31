# Nicole Mena Porras C14663
# este es el codigo que hice para makefile...
CC = gcc
CFLAGS = -Wall -g
all: main

main: main.o double_list.o
	$(CC) $(CFLAGS) -o main main.o double_list.o

main.o: main.c double_list.h
	$(CC) $(CFLAGS) -c main.c

double_list.o: double_list.c double_list.h
	$(CC) $(CFLAGS) -c double_list.c

clean:
	rm -f *.o main
# fin, gracias....
