//
// Created by Aliaksei Syrel on 02.03.17.
//

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

#include "input.h"

result to_float(const char * aString, float *retArg) {
    char* endPtr;
    float number;
    errno = 0;

    number = strtof(aString, &endPtr);

    // strtof allows us to handle string => float conversion errors.
    // check for possible errors and return ERROR_NOT_NUMBER if it is a case
    if (endPtr == aString || *endPtr != '\0' || errno == ERANGE) {
        return ERROR_NOT_NUMBER;
    }

    *retArg = number;

    return RESULT_OK;
}

result to_int(const char * aString, int *retArg) {
    char* endPtr;
    long number;
    errno = 0;

    number = strtol(aString, &endPtr, 10); // base it 10, we want decimal numbers

    // strtol allows us to handle string => long conversion errors.
    // check for possible errors and return ERROR_NOT_INTEGER if it is a case
    if (endPtr == aString || *endPtr != '\0' || ((number == LONG_MIN || number == LONG_MAX) && errno == ERANGE)) {
        return ERROR_NOT_INTEGER;
    }

    if (number < INT_MIN || number > INT_MAX) {
        return ERROR_NOT_INTEGER;
    }

    // it is safe to cast long to integer here, we performed a check before
    *retArg = (int) number;

    return RESULT_OK;
}

result ask_float(const char * question, size_t maxLength, float *retArg) {
    char * inputParameter = malloc(maxLength * sizeof(char));
    char * scanfArgument = malloc(((int)((ceil(log10(maxLength))+1)*sizeof(char)) + 2) * sizeof(char));  // + 2 for %s
    sprintf(scanfArgument, "%%%zus", maxLength);

    float parameter = 0.f;

    result rv = RESULT_ERROR;
    while (FAILED(rv)) {
        printf("%s\n", question);
        scanf(scanfArgument, inputParameter);
        rv = to_float(inputParameter, &parameter);
        if (FAILED(rv)) {
            printf("Wrong input, try again\n");
        }
    }

    free(inputParameter);
    free(scanfArgument);

    *retArg = parameter;

    return RESULT_OK;
}

result ask_int(const char * question, size_t maxLength, int *retArg) {
    char * inputParameter = malloc(maxLength * sizeof(char));
    char * scanfArgument = malloc(((int)((ceil(log10(maxLength))+1)*sizeof(char)) + 2) * sizeof(char));  // + 2 for %s
    sprintf(scanfArgument, "%%%zus", maxLength);

    int parameter = 0;

    result rv = RESULT_ERROR;
    while (FAILED(rv)) {
        printf("%s\n", question);
        scanf(scanfArgument, inputParameter);
        rv = to_int(inputParameter, &parameter);
        if (FAILED(rv)) {
            printf("Wrong input, try again\n");
        }
    }

    free(inputParameter);
    free(scanfArgument);

    *retArg = parameter;

    return RESULT_OK;
}
