CC=gcc
CFLAGS=-Wall -Werror -pedantic -O3

align: edit_distance.o main.o
	$(CC) edit_distance.o main.o -o align

main.o: Main.c
	$(CC) $(CFLAGS) -c Main.c -o main.o

edit_distance.o:EditDistance.c
	$(CC) $(CFLAGS) -c EditDistance.c -o edit_distance.o

clean:
	rm -f *.o *~ align
