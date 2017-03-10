//
// Created by Aliaksei Syrel on 10.03.17.
//

#include <stdio.h>
#include <math.h>
#include "input.h"

#define INPUT_LENGTH 16

/*
 * Q: What does it do?
 * A: A program computes square roots of two float number and prints results.
 *
 * Q: What is the problem with it? (mathematically)
 * A: The first number is positive, while second one is negative.
 *    Floats do not represent complex numbers => square root can not be computed.
 */

int main()
{
    float number;

    result rv = ask_float("Please enter a number (x):", INPUT_LENGTH, &number);
    if (FAILED(rv)) {
        printf("Was unable to read the input");
        exit(rv);
    }

    if (number < .0) {
        printf("Entered number is smaller than zero, square root can not be computed in R\n");
        exit(1);
    }

    float root = sqrtf(number);

    printf("sqrt(%f) = %f\n",number, root);

    return EXIT_SUCCESS;
}
