//
// Created by Aliaksei Syrel on 02.03.17.
//

#ifndef EXERCISE_2_STONE_H
#define EXERCISE_2_STONE_H

#include "results.h"

typedef struct equation {
    float height;
    float acceleration;
    float time;
} Equation;

result solve_equation(Equation * anEquation);

#endif //EXERCISE_2_STONE_H
