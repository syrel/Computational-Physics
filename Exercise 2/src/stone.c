//
// Created by Aliaksei Syrel on 02.03.17.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "stone.h"
#include "input.h"

#define INPUT_LENGTH 16

result solve_equation(Equation * anEquation) {
    if (anEquation->acceleration == 0) {
        return ERROR_ZERO_DIVISION;
    }

    anEquation->time = sqrtf(2 * anEquation->height / anEquation->acceleration);
    return RESULT_OK;
}

int main() {
    Equation anEquation;

    anEquation.acceleration = 9.81;

    result rv = ask_float("Enter stone drop height [m]:", INPUT_LENGTH, &anEquation.height);
    if (FAILED(rv)) {
        printf("Error(%d) while reading parameter a\n", rv);
        exit(rv);
    }

    rv = solve_equation(&anEquation);
    if (FAILED(rv)) {
        printf("Error(%d) while solving equation (acceleration a can not be 0)\n", rv);
        exit(1);
    }

    printf("If dropped from %fm stone would take %fsec to reach the ground\n", anEquation.height, anEquation.time);

    return 0;
}
