//
// Created by Aliaksei Syrel on 02.03.17.
//

#ifndef EXERCISE_2_INPUT_H
#define EXERCISE_2_INPUT_H

#include <stdlib.h>
#include "results.h"

/**
 * Converts a string representation of a number to a float and store it at a retArg address
 * @param aString a null terminated string representation to convert
 * @param retArg a pointer to returned float
 * @return
 *      RESULT_OK if conversion was successful
 *      ERROR_NOT_NUMBER if an argument at an index is not a valid float
 */
result to_float(const char * aString, float *retArg);

/**
 * Converts a string representation of a number to an integer and store it at a retArg address
 * @param aString a null terminated string representation to convert
 * @param retArg a pointer to returned integer
 * @return
 *      RESULT_OK if conversion was successful
 *      ERROR_NOT_INTEGER if an argument at an index is not a valid integer
 */
result to_int(const char * aString, int *retArg);

result ask_float(const char * question, size_t maxLength, float *retArg);
result ask_int(const char * question, size_t maxLength, int *retArg);


#endif //EXERCISE_2_INPUT_H
