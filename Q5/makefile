CC = gcc
CFLAGS = -Wall -pg

TARGETS = n n2 n3

all: $(TARGETS)

n: n.c
	$(CC) $(CFLAGS) -o n n.c

n2: n2.c
	$(CC) $(CFLAGS) -o n2 n2.c

n3: n3.c
	$(CC) $(CFLAGS) -o n3 n3.c

profile-n: run-n
	mv gmon.out gmon_n.out
	gprof n gmon_n.out > profile_n.txt

profile-n2: run-n2
	mv gmon.out gmon_n2.out
	gprof n2 gmon_n2.out > profile_n2.txt

profile-n3: run-n3
	mv gmon.out gmon_n3.out
	gprof n3 gmon_n3.out > profile_n3.txt

clean:
	rm -f $(TARGETS) *.o gmon.out gmon_*.out

.PHONY: all clean run-n run-n2 run-n3 profile-n profile-n2 profile-n3