#include <stdio.h>
#include <complex.h>
#include "mandelbrot.h"

int main() {
    double real, imag;

    while (1) {
        printf("Enter real and imaginary parts: ");
        if (scanf("%lf %lf", &real, &imag) != 2) {
            fprintf(stderr, "Invalid input\n");
            return 1;
        }

        // Exit if input is 0 + 0i
        if (real == 0.0 && imag == 0.0) {
            break;
        }

        double complex c = real + imag * I;
        if (is_in_mandelbrot(c, 1000)) {
            printf("The number is in the Mandelbrot set.\n");
        } else {
            printf("The number is NOT in the Mandelbrot set.\n");
        }
    }

    return 0;
}
