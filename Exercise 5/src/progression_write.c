//
// Created by Aliaksei Syrel on 24.03.17.
//

#include <stdlib.h>
#include <stdio.h>

#define MAX 20

int main() {
    FILE * file;
    file = fopen("progression.txt", "w");

    if (!file) {
        printf("Error opening a file\n");
        exit(1);
    }

    int basis = 2;
    int power = 2;

    int number = basis;
    for (int i = 0; i < MAX; i++) {
        fprintf(file, "%d\n", number);
        number *= power;
    }
}
