//
// Created by Aliaksei Syrel on 22.06.17.
//

#include "math.h"
#include <stdio.h>
#include <stdlib.h>

double sample(double from, double to) {
    return (to - from) * (double) rand() / (double) RAND_MAX + from;
}

double f(double x) {
    return 1 / sqrt(2 * M_PI) * exp(-pow(x,2) / 2);
}

double integrate(double from, double to, size_t samples) {
    double integral = 0;

    for (size_t i = 0; i < samples; i++) {
        integral += f(sample(from, to));
    }

    return (to - from) / samples * integral;
}

int main() {
    printf("result = %f\n", integrate(-1, 1, 1000000));
}
