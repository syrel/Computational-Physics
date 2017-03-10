//
// Created by Aliaksei Syrel on 10.03.17.
//

#include <stdio.h>
#include <math.h>
#include "input.h"
#include "repeat.h"

#define INPUT_LENGTH 16

long repeat(signed int repeated, signed int amount) {

    return (long)floor(1.f/9.f * pow(10, amount)) * repeated;
}

int main() {

    int repeated;
    int amount;

    result rv = ask_int("Enter number to repeat (non-negative)", INPUT_LENGTH, &repeated);
    if (FAILED(rv)) {
        printf("Error(%d): Was unable to read input\n", rv);
        exit(rv);
    }
    if (repeated <= 0) {
        printf("Number to repeat must be positive, but it was %d\n", repeated);
        exit(1);
    }

    if (repeated > 9) {
        printf("Number to repeat must be within interval [0-9], but it was %d\n", repeated);
        exit(1);
    }

    rv = ask_int("Enter how many time to repeat (positive)", INPUT_LENGTH, &amount);
    if (FAILED(rv) || amount <= 0) {
        printf("Error(%d): Was unable to read input\n", rv);
        exit(rv);
    }
    if (amount <= 0) {
        printf("Number of how many times to repeat must be positive, but it was %d\n", amount);
        exit(1);
    }
    if (amount > 9) {
        printf("Number of how many times to repeat must be within interval [0-9], but it was %d\n", repeated);
        exit(1);
    }

    printf("f(%d,%d) = %ld\n", repeated, amount, repeat(repeated, amount));

    return EXIT_SUCCESS;
}
