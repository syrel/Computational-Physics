//
// Created by Aliaksei Syrel on 02.03.17.
//

#ifndef EXERCISE_2_EQUATION_H
#define EXERCISE_2_EQUATION_H

#include "results.h"

typedef struct equation {
    float a;
    float b;
    float x;
} Equation;

result solve_equation(Equation * anEquation);

#endif //EXERCISE_2_EQUATION_H
