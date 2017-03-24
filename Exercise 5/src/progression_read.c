//
// Created by Aliaksei Syrel on 24.03.17.
//

#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE * file;
    file = fopen("progression.txt", "r");

    if (!file) {
        printf("Error opening a file\n");
        exit(1);
    }

    while (!feof(file)) {
        int number;
        fscanf(file, "%d\n", &number);
        printf("%d\n", number);
    }
}
