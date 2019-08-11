/**
 * File: random.h
 * -----------------------
 * This interface exports functions for generating random numbers
 */

#ifndef _random_h
#define _random_h

/**
 * Constant Value: PI
 * --------------------
 */
extern const double PI;

/**
 * Fuction: randomInterger
 * ------------------------
 * Usage: int value = randomInteger(start,end);
 * Docstring: This fuction is designed to generate random integers in a certain range,
 * from start to end. The parameters 'start' and 'end' are integers and the function
 * will return a random integer.
 */
int randomInteger(int start, int end);

/**
 * Function: randomFloat
 * --------------------------
 * Usage: double value = randomFloat(start,end)
 * Docstring: This function is designed to generate random float numbers in a certain range,
 * from start to end. The function parameter 'start' and 'end' are double float numbers and this 
 * function will return a double float number
 */
double randomFloat(double start, double end);

/**
 * Fuction: randomChance
 * -------------------------------
 * Usage: bool value = randomChance(probability);
 * Docstrings: this function take a double number 'probability' as function
 * parameter and return a bool value.
 */
bool randomChance(double probability);

/**
 * Fuction: setRandomSeed
 * ----------------------------------
 * Usage: setRandomSeed(seed)
 * Docstring:
 */
void setRandomSeed(int seed);

#endif