//
// Created by Aliaksei Syrel on 02.03.17.
//

#include <stdlib.h>
#include <stdio.h>

#include "equation.h"
#include "input.h"

#define INPUT_LENGTH 16

result solve_equation(Equation * anEquation) {
    if (anEquation->a == 0) {
        return ERROR_ZERO_DIVISION;
    }

    anEquation->x = -anEquation->b / anEquation->a;

    return RESULT_OK;
}

int main() {
    Equation anEquation;

    result rv = ask_float("Enter parameter a:", INPUT_LENGTH, &anEquation.a);
    if (FAILED(rv)) {
        printf("Error(%d) while reading parameter a\n", rv);
        exit(rv);
    }

    rv = ask_float("Enter parameter b:", INPUT_LENGTH, &anEquation.b);
    if (FAILED(rv)) {
        printf("Error(%d) while reading parameter b\n", rv);
        exit(rv);
    }

    rv = solve_equation(&anEquation);
    if (FAILED(rv)) {
        printf("Error(%d) while solving equation (parameter a can not be 0)\n", rv);
        exit(1);
    }

    printf("Equation: %f * x + %f = 0\n", anEquation.a, anEquation.b);
    printf("Solution: x = %f\n", anEquation.x);

    return 0;
}
