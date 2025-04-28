#include "mandelbrot.h"
#include <math.h>

bool is_in_mandelbrot(double complex c, int N) {
    double complex z = 0;
    for (int i = 0; i < N; ++i) {
        z = z * z + c;
        if (cabs(z) > 2.0) {
            return false;
        }
    }
    return true;
}
