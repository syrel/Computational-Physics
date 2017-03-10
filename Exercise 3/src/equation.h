//
// Created by Aliaksei Syrel on 10.03.17.
//

#ifndef EXERCISE_3_EQUATION_H
#define EXERCISE_3_EQUATION_H

#include "results.h"

/**
 * I represent a quadratic equation:
 * ax^2 + bx + c = 0
 *
 * x0 and x1 are my solution, they may be equal.
 */

typedef struct equation {
    float a;
    float b;
    float c;
    float x0;
    float x1;
} Equation;


/**
 * Computes discriminant of an equation D = (b^2 - 4ac).
 * @param anEquation an equation of which we want to compute discriminant
 * @return discriminant for given
 */
float compute_discriminant(Equation* anEquation);

/**
 * Asks user to enter parameters for a given quadratic equation
 * @param anEquation an equation to configure
 * @return result of the operation
 */
result ask_equation(Equation* anEquation);

/**
 * Solves an equation if possible and store results in x0 and x1
 * @param anEquation
 * @return RESULT_OK if equation has solution in R
 */
result solve(Equation* anEquation);

#endif //EXERCISE_3_EQUATION_H
