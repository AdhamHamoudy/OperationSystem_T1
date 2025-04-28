#include <iostream>

int main() {
    int* ptr = (int*)0xdeadbeef; // Invalid memory address
    *ptr = 42; // Segmentation fault
    return 0;
}
