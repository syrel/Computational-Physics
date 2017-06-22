//
// Created by Aliaksei Syrel on 22.06.17.
//

#include <math.h>
#include <stdlib.h>
#include "stdio.h"

typedef struct generator {
    int seed;
    int a;
    int previous;
    int (*generator)(struct generator*);
} generator;

int generator_func(generator* gen) {
    return ((gen->a) * (gen->previous)) % ((1 << 13) - 1);
}

int get_next(generator* gen) {
    if (gen->previous == 0) {
        gen->previous = gen->seed;
    }

    int next = gen->generator(gen);
    gen->previous = next;
    return next;
}

int find_period(generator* gen) {
    gen->previous = 0;

    int inital = get_next(gen);
    int period = 1;

    while (inital != get_next(gen)) {
        period++;
    }
    return period;
}

int throw_dice(generator* gen) {
    return (get_next(gen) % 6) + 1;
}

void throw_dice_times(generator* gen, size_t times, int* results) {
    for (size_t i = 0; i < times; i++) {
        results[i] = throw_dice(gen);
    }
}

void fill_bins(int* throws, size_t amount, size_t* results) {
    for (size_t i = 0; i < amount; i++) {
        results[throws[i]-1]++;
    }
}

int main() {
    generator gen81;
    gen81.seed = 1;
    gen81.a = 81;
    gen81.generator = &generator_func;
    printf("period for %d = %d\n", gen81.a, find_period(&gen81));

    generator gen83;
    gen83.seed = 1;
    gen83.a = 83;
    gen83.generator = &generator_func;
    printf("period for %d = %d\n", gen83.a, find_period(&gen83));

    generator gen85;
    gen85.seed = 1;
    gen85.a = 85;
    gen85.generator = &generator_func;
    printf("period for %d = %d\n", gen85.a, find_period(&gen85));

    int* throws = malloc(3000 * sizeof(int));
    size_t* bins = calloc(6, sizeof(size_t));

    throw_dice_times(&gen81, 3000, throws);
    fill_bins(throws, 3000, bins);

    for (size_t i = 0; i < 6; i++) {
        printf("bin(%ld) = %ld\n", i+1, bins[i]);
    }
}
