//
// Created by Aliaksei Syrel on 21.02.17.
//

#ifndef RESULTS_H
#define RESULTS_H

#define result int

#define RESULT_OK 0
#define RESULT_ERROR 1 << 1
#define ERROR_NOT_INTEGER 2 << 1
#define ERROR_NOT_NUMBER 3 << 1
#define ERROR_OUT_OF_BOUNDS 4 << 1
#define ERROR_ZERO_DIVISION 5 << 1
#define ERROR_UNSOLVABLE 6 << 1

#define FAILED(x) x != RESULT_OK
#define SUCCEED(x) x == RESULT_OK

#endif //RESULTS_H
