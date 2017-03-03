//
// Created by Aliaksei Syrel on 03.03.17.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "comparison.h"
#include "input.h"

#define INPUT_LENGTH 16

float cosinus(float degrees) {
    return (float) cos(degrees);
}

/**
 * 1 - x^2/2 + x^4/24
 * @param argument - value of x argument
 * @return result of computation
 */
float polynom(float argument) {
    return (float) (1 - pow(argument,2) + pow(argument,4) / 24);
}

int main() {

    float argument = 0;

    result rv = ask_float("Enter x [rad]:", INPUT_LENGTH, &argument);
    if (FAILED(rv)) {
        printf("Error(%d) while reading degrees\n", rv);
        exit(rv);
    }

    float cosResult = cosinus(argument);
    float polResult = polynom(argument);

    printf("cos(%f) = %f\n", argument, cosResult);
    printf("1 - x^2/2 + x^4/24 = %f\n", polResult);

    return 0;
}
