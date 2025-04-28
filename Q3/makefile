CC = gcc
CFLAGS = -Wall -g -fPIC
LDFLAGS = -lm
TARGET = main
LIB = libmandelbrot.so

all: $(TARGET)

# Build the shared object
$(LIB): mandelbrot.o
	$(CC) -shared -o $(LIB) mandelbrot.o $(LDFLAGS)

# Object for the shared library
mandelbrot.o: mandelbrot.c mandelbrot.h
	$(CC) $(CFLAGS) -c mandelbrot.c

# Build the main program
main: main.o $(LIB)
	$(CC) -o $(TARGET) main.o -L. -lmandelbrot $(LDFLAGS)

main.o: main.c mandelbrot.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o *.so $(TARGET)
run: main
	LD_LIBRARY_PATH=. ./main

clean:
	rm -f *.o *.so $(TARGET)