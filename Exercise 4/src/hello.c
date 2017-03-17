//
// Created by Aliaksei Syrel on 17.03.17.
//

#include <stdio.h>
#include "input.h"

#define INPUT_LENGTH 16

int main()
{
    int count;

    result rv = ask_int("Enter how many time to repeat:", INPUT_LENGTH, &count);
    if (FAILED(rv)) {
        printf("Error(%d) reading input", rv);
        exit(rv);
    }

    for (int i = 0; i < count; i++) {
        printf("Hello World %d\n" , i);
    }
    return 0;
}
