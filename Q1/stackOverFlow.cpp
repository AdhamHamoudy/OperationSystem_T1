#include <iostream>

void infiniteRecursiveFunction() {
    infiniteRecursiveFunction(); // stack overflow
}

int main() {
    infiniteRecursiveFunction();
    return 0;
}
