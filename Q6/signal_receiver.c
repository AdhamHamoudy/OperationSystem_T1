#include <stdio.h>      // for printf(), fflush()
#include <stdlib.h>     // for exit()
#include <unistd.h>     // for getpid(), pause(), sleep()
#include <signal.h>     // for sigaction, SIGUSR1, SIGUSR2, SA_RESTART
#include <sys/types.h>  // for pid_t

volatile sig_atomic_t bit_count = 0;
volatile sig_atomic_t current_byte = 0;

// Signal handler: builds a byte bit by bit
void handle_signal(int sig) {
    current_byte <<= 1; // Shift current bits to the left by 1

    if (sig == SIGUSR2)
        current_byte |= 1; // Set the least significant bit to 1

    bit_count++;

    if (bit_count == 8) {
        printf("Received %d\n", current_byte); // Print the completed byte
        fflush(stdout); // Important to flush output inside a signal handler
        current_byte = 0;
        bit_count = 0;
    }
}

int main() {
    printf("My PID is %d\n", getpid()); // Display receiver's PID

    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART; // Restart syscalls after handling signals

    // Set up signal handlers for SIGUSR1 and SIGUSR2
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    // Wait indefinitely for incoming signals
    while (1) {
        pause(); // Sleep until a signal is received
    }

    return 0;
}
