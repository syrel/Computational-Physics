//
// Created by Aliaksei Syrel on 03.03.17.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "comparison.h"
#include "input.h"

#define INPUT_LENGTH 16

float cosine(float degree) {
    return (float) cos(degree);
}

float polynomial(float argument) {
    return (float) (1 - pow(argument,2) + pow(argument,4) / 24);
}

/*
 * Q: compare the results for different values of x. Are they similar?
 * A: results are similar for x close to 0. Probably given polynom is a Taylor series of a cos function
 */

int main() {

    float argument = 0;

    result rv = ask_float("Enter x [rad]:", INPUT_LENGTH, &argument);
    if (FAILED(rv)) {
        printf("Error(%d) while reading degrees\n", rv);
        exit(rv);
    }

    float cosResult = cosine(argument);
    float polResult = polynomial(argument);

    printf("cos(%f) = %f\n", argument, cosResult);
    printf("1 - x^2/2 + x^4/24 = %f\n", polResult);

    return 0;
}
