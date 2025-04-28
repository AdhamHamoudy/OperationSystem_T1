CC = gcc
CFLAGS = -Wall -Wextra

# Target executables
TARGETS = signal_receiver signal_sender

all: $(TARGETS)

signal_receiver: signal_receiver.c
	$(CC) $(CFLAGS) -o signal_receiver signal_receiver.c

signal_sender: signal_sender.c
	$(CC) $(CFLAGS) -o signal_sender signal_sender.c

clean:
	rm -f $(TARGETS) *.o

.PHONY: all clean