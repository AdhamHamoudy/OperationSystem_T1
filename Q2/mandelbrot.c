#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <real> <imag> [N]\n", argv[0]);
        return 1;
    }

    double real = atof(argv[1]);
    double imag = atof(argv[2]);
    int N = (argc >= 4) ? atoi(argv[3]) : 1000;

    double complex c = real + imag * I;
    double complex z = 0;

    for (int i = 0; i < N; ++i) {
        z = z * z + c;
        if (cabs(z) > 2.0) {
            printf("The number is NOT in the Mandelbrot set.\n");
            return 0;
        }
    }

    printf("The number is in the Mandelbrot set.\n");
    return 0;
}
