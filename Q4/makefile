CC = gcc
CFLAGS = -Wall -Wextra --coverage
LDFLAGS = --coverage
Test_files = test1.txt test2.txt test3.txt test4.txt

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Run all predefined test files
exam:
	@for file in $(Test_files); do \
		echo "Running $$file..."; \
		./main < $$file; \
	done

# Run test with file entered manually
test:
	@read -p "Enter test file name: " file; \
	./main < $$file

# Generate code coverage report
gcov:
	gcov main.c

clean:
	@rm -f main main.o *.gcno *.gcda
