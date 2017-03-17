//
// Created by Aliaksei Syrel on 17.03.17.
//

#ifndef EXERCISE_4_STONE_H
#define EXERCISE_4_STONE_H

typedef struct Stone {
    float x0;       // start x coordinate
    float y0;       // start y coordinate
    float v;        // start velocity module
    float alpha;    // throwing angle in radians
    float g;        // free fall acceleration
} Stone;

/**
 * Computes a height of a stone above a lake surface at a given time
 * @param stone a stone model
 * @param time a delta time since throw at which to compute height
 * @return height of a stone at a given time
 */
float heightAt (Stone* stone, float time);

/**
 * Computes a distance of a stone from observer (coordinate 0,0)
 * @param stone a stone model
 * @param time a delta time since throw at which to compute distance
 * @return distance of a stone at a given time
 */
float distanceAt (Stone* stone, float time);

/**
 * Compute at which time stone will drop in a lake
 * @param stone a stone model
 * @return drop time
 */
float dropTime (Stone* stone);

#endif //EXERCISE_4_STONE_H
