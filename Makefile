CC=gcc
CFLAGS=-Wall -Werror -pedantic -O3

align: alignment.o main.o
	$(CC) alignment.o main.o -o align

main.o: Main.c
	$(CC) $(CFLAGS) -c Main.c -o main.o

alignment.o: Alignment.c
	$(CC) $(CFLAGS) -c Alignment.c -o alignment.o

clean:
	rm -f *.o *~ align
