#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * Sends one byte (8 bits) to a receiver process using SIGUSR1 (for 0) and SIGUSR2 (for 1).
 * @param pid The process ID of the receiver.
 * @param byte The byte (number) to send.
 */
void send_byte(pid_t pid, unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        int bit = (byte >> i) & 1; // Extract the i-th bit

        if (bit == 0)
            kill(pid, SIGUSR1); // Send 0 as SIGUSR1
        else
            kill(pid, SIGUSR2); // Send 1 as SIGUSR2

        // Small delay to allow the receiver to handle the signal
        usleep(500); // microseconds (adjust if needed)
    }
}

int main() {
    pid_t receiver_pid;
    int message;

    // Ask the user for the receiver's PID
    printf("Enter receiver PID: ");
    if (scanf("%d", &receiver_pid) != 1) {
        fprintf(stderr, "Invalid PID input.\n");
        exit(1);
    }

    // Ask the user for the message to send
    printf("Enter message (0-255): ");
    if (scanf("%d", &message) != 1 || message < 0 || message > 255) {
        fprintf(stderr, "Invalid message. Must be a number between 0 and 255.\n");
        exit(1);
    }

    // Send the byte to the receiver
    send_byte(receiver_pid, (unsigned char)message);

    return 0;
}
