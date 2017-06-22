//
// Created by Aliaksei Syrel on 21.06.17.
//

#include <stddef.h>
#include <stdio.h>
#include "math.h"

double precision() {
    return 10e-7;
}

double f(double x) {
    return 1 / sqrt(2 * M_PI) * exp(-pow(x,2) / 2);
}

double integrate_parts(double from, double to, size_t parts) {
    double delta = (to - from) / parts;

    double integral = (f(to) + f (from)) / 2;

    for (size_t index = 1; index < parts; index++) {
        integral += f(from + delta * index);
    }

    return integral * delta;
}

double integrate(double from, double to) {
    size_t parts = 2;
    double integral = integrate_parts(from, to, parts);

    double refinedIntegral;

    while(fabs((refinedIntegral = integrate_parts(from, to, parts * 2)) - integral) > precision() * fabs(integral)){
        parts *= 2;
        integral = refinedIntegral;
    }

    return refinedIntegral;
}

int main() {
    printf("from -%d to %d = %f\n", 1 , 1, integrate(-1,1));
    printf("from -%d to %d = %f\n", 2 , 2, integrate(-2,2));
    printf("from -%d to %d = %f\n", 3 , 3, integrate(-3,3));
    printf("from -%d to %d = %f\n", 4 , 4, integrate(-4,4));
    printf("from -%d to %d = %f\n", 5 , 5, integrate(-5,5));
}
