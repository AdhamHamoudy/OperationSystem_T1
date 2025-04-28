CC = gcc
CFLAGS = -Wall -Wextra

all: findPhone add2PB

findPhone: findPhone.o
	$(CC) $(CFLAGS) -o findPhone findPhone.o

add2PB: add2PB.o
	$(CC) $(CFLAGS) -o add2PB add2PB.o

findPhone.o: findPhone.c
	$(CC) $(CFLAGS) -c findPhone.c

add2PB.o: add2PB.c
	$(CC) $(CFLAGS) -c add2PB.c

clean:
	rm -f findPhone add2PB *.o
