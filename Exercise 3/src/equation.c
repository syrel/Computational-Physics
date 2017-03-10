//
// Created by Aliaksei Syrel on 10.03.17.
//

#include <stdio.h>
#include <math.h>
#include "input.h"
#include "equation.h"

#define INPUT_LENGTH 16

/*
 * Q: Do you remember the formula to solve quadratic equations?
 * A:
 * First we need to compute a discriminant
 *      D = (b^2 - 4ac).
 * Then use formula that gives us two solutions:
 *      x0,1 = (-b +/- sqrt(D)) / 2a
 *
 * Q: What has to be considered mathematically?
 * We have to make sure that discriminant is non-negative, otherwise equation does not have solutions in R
 */


float compute_discriminant (Equation* anEquation) {
    return powf(anEquation->b, 2) - 4 * anEquation->a * anEquation->c;
}

result ask_equation(Equation* anEquation) {
    result rv = ask_float("Enter parameter a:", INPUT_LENGTH, &anEquation->a);
    if (FAILED(rv)) {
        printf("Failed to read parameter a\n");
        return rv;
    }
    rv = ask_float("Enter parameter b:", INPUT_LENGTH, &anEquation->b);
    if (FAILED(rv)) {
        printf("Failed to read parameter b\n");
        return rv;
    }
    rv = ask_float("Enter parameter c:", INPUT_LENGTH, &anEquation->c);
    if (FAILED(rv)) {
        printf("Failed to read parameter c\n");
        return rv;
    }

    return RESULT_OK;
}

result solve(Equation* anEquation) {
    float discriminant = compute_discriminant(anEquation);
    if (discriminant < 0) {
        return ERROR_UNSOLVABLE;
    }

    anEquation->x0 = (-anEquation->b + sqrtf(discriminant)) / (2 * anEquation->a);
    anEquation->x1 = (-anEquation->b - sqrtf(discriminant)) / (2 * anEquation->a);

    return RESULT_OK;
}

int main() {

    Equation equation;
    result rv = ask_equation(&equation);
    if (FAILED(rv)) {
        printf("Error(%d): was unable to configure equation\n", rv);
        exit(rv);
    }

    rv = solve(&equation);
    if(FAILED(rv)) {
        printf("Error(%d): Equation is unsolvable in R, discriminant is negative\n", rv);
        exit(rv);
    }

    printf("Equation %f * x^2 + %f * x + %f = 0\n", equation.a, equation.b, equation.c);
    if (equation.x0 == equation.x1) {
        printf("Has one solution: x = %f\n", equation.x0);
    }
    else {
        printf("Has two solutions: x0 = %f, x1 = %f\n", equation.x0, equation.x1);
    }

    return EXIT_SUCCESS;
}
