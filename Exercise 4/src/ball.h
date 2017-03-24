//
// Created by Aliaksei Syrel on 17.03.17.
//

#ifndef EXERCISE_4_BALL_H
#define EXERCISE_4_BALL_H

typedef struct _ball {
    float x0;       // start x coordinate
    float y0;       // start y coordinate
    float v;        // start velocity module
    float alpha;    // throwing angle in radians
    float g;        // free fall acceleration
    float loose;    // what percent of energy does ball loose when it hits the ground
} Ball;

/**
 * Computes a height of a ball above a field surface at a given time
 * @param stone a ball model
 * @param time a delta time since throw at which to compute height
 * @return height of a ball at a given time
 */
float heightAt (Ball* ball, float time);

/**
 * Computes a distance of a ball from observer (coordinate 0,0)
 * @param stone a ball model
 * @param time a delta time since throw at which to compute distance
 * @return distance of a ball at a given time
 */
float distanceAt (Ball* ball, float time);

/**
 * Compute at which time ball will drop next time
 * @param stone a ball model
 * @return drop time
 */
float dropTime (Ball* ball);

#endif //EXERCISE_4_BALL_H
