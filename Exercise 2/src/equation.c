//
// Created by Aliaksei Syrel on 02.03.17.
//

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "equation.h"
#include "results.h"


#define INPUT_LENGTH 16
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

/**
 * Query a number argument at a given index and store it at retArg address
 * @param arguments a list of arguments
 * @param index an index of a wanted number
 * @param retArg a pointer to returned number
 * @return
 *      RESULT_OK if argument at an index is an integer number
 *      ERROR_NOT_INTEGER if an argument at an index is not a valid number
 */
result to_number(const char *input, float *retArg) {
    char* endPtr;
    float number;
    errno = 0;

    number = strtof(input, &endPtr);

    // strtof allows us to handle string => float conversion errors.
    // check for possible errors and return ERROR_NOT_NUMBER if it is a case
    if (endPtr == input || *endPtr != '\0' || errno == ERANGE) {
        return ERROR_NOT_NUMBER;
    }

    *retArg = number;

    return RESULT_OK;
}


result ask_equation(Equation * anEquation) {
    char * inputParameterA = malloc(INPUT_LENGTH * sizeof(char));
    char * inputParameterB = malloc(INPUT_LENGTH * sizeof(char));
    float parameterA = 0.f;
    float parameterB = 0.f;


    result rv = RESULT_ERROR;
    while (FAILED(rv)) {
        printf("Enter parameter a:\n");
        scanf("%" STR(INPUT_LENGTH) "s", inputParameterA);
        rv = to_number(inputParameterA, &parameterA);
        if (FAILED(rv)) {
            printf("Wrong input, try again\n");
        }
    }

    rv = RESULT_ERROR;
    while (FAILED(rv)) {
        printf("Enter parameter b:\n");
        scanf("%" STR(INPUT_LENGTH) "s", inputParameterB);
        rv = to_number(inputParameterB, &parameterB);
        if (FAILED(rv)) {
            printf("Wrong input, try again\n");
        }
    }

    anEquation->a = parameterA;
    anEquation->b = parameterB;

    return RESULT_OK;
}

result solve_equation(Equation * anEquation) {
    if (anEquation->a == 0) {
        return ERROR_ZERO_DIVISION;
    }

    anEquation->x = -anEquation->b / anEquation->a;

    return RESULT_OK;
}

int main() {
    Equation anEquation;

    result rv = ask_equation(&anEquation);
    if (FAILED(rv)) {
        printf("Error(%d) while setting equation\n", rv);
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
