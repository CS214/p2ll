OBJS= sorted-list.o main.o

CC= gcc

CFLAGS= -Wall -g

sl: $(OBJS)
	$(CC) -o sl $(OBJS)

sorted-list.o: sorted-list.c sorted-list.h
	$(CC) -c $(CFLAGS) sorted-list.c

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f sl $(OBJS)