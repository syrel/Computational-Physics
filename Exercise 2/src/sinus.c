//
// Created by Aliaksei Syrel on 02.03.17.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "input.h"

#define INPUT_LENGTH 16

/*
 * sin(x) in C accepts a double value of radians and returns a sinus of it with double precision.
 * User may use sinf(x) for float-based computations
 */

int main() {

    float degrees = 0;

    result rv = ask_float("Enter degrees [rad]:", INPUT_LENGTH, &degrees);
    if (FAILED(rv)) {
        printf("Error(%d) while reading degrees\n", rv);
        exit(rv);
    }

    float sinus = (float) sin(degrees);

    printf("sin(%f) = %f\n",degrees, sinus);

    return 0;
}
