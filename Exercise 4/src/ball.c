//
// Created by Aliaksei Syrel on 17.03.17.
//

#include <math.h>
#include <stdio.h>

#include "ball.h"
#include "equation.h"
#include "input.h"

#define INPUT_LENGTH 16
#define PRINT_INTERVAL 0.1

// y = y0 + v*t*sin(alpha) - g*t^2 / 2
float heightAt (Stone* stone, float time) {
    float drop = dropTime(stone);
    time = fminf(time, drop);
    return (stone->y0) + ((stone->v) * time * sinf(stone->alpha)) - ((stone->g) * powf(time, 2) / 2.0);
}

// x = x0 + v*t*cos(alpha)
float distanceAt (Stone* stone, float time) {
    float drop = dropTime(stone);
    time = fminf(time, drop);
    return (stone->x0) + (stone->v) * time * cosf(stone->alpha);
}

// g*t^2/2 - v*sin(alpha)*t - y0 = 0
float dropTime (Ball* ball) {
    Equation equation;
    equation.a = ball->g / 2.0f;
    equation.b = -1 * ball->v * sinf(ball->alpha);
    equation.c = -1 * ball->y0;
    result rv = solve(&equation);
    if (FAILED(rv)) {
        printf("Error(%d): was unable to find drop time\n", rv);
        exit(rv);
    }
    return fmaxf(equation.x0, equation.x1);
}

inline float toRadians(float degrees) {
    return (float) (degrees / (180.0 / M_PI));
}

int main() {
    Stone stone;
    stone.x0 = 0;
    stone.y0 = 2;
    stone.g = 9.81;

    float velocity, angle;

    ask_float("Enter start velocity module", INPUT_LENGTH, &velocity);
    if (velocity < 0) {
        printf("Velocity must be non-negative but it was: %f\n", velocity);
        exit(1);
    }
    ask_float("Enter start angle in degrees [0-90]", INPUT_LENGTH, &angle);
    if (angle < 0 || angle > 90) {
        printf("Angle must be within an interval [0-90] but it was: %f\n", angle);
        exit(1);
    }

    stone.v = velocity;
    stone.alpha = toRadians(angle);

    float drop = dropTime(&stone);
    for (float time = 0; time < drop; time += PRINT_INTERVAL) {
        float x = distanceAt(&stone, time);
        float y = heightAt(&stone, time);

        printf("At %fses stone is at (%f,%f)\n", time, x, y);
    }

    printf("Stone dropped in the water at %fsec\n", drop);
}














