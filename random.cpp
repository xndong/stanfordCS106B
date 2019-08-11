/**
 * File : random.cpp
 * -----------------------
 * This file implent the interface random.h, including fuctions, constant values and types(if applicable).
 */
#include "random.h"
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

/*Function Prototype*/
void initRandomSeed();

/**
 * Implement notes: constant value PI
 * --------------------------
 */
extern const double PI = 3.1415926;

/**
 * Implement notes: randomInteger
 * -----------------
 * Docstring: 
 */
int randomInteger(int start, int end)
{
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(end) - start + 1);
    return int(floor(start + s));
}
/**
 * Implement notes: randomFloat
 * ----------------------------------------
 */
double randomFloat(double start, double end)
{
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (end - start);
    return start + s;
}
/**
 * Implement notes: randomChance
 * -------------------------------------
 */
bool randomChance(double probability)
{
    initRandomSeed();
    return randomFloat(0, 1) < probability;
}
/**
 * Implement notes: setRandomSeed
 * --------------------------------------
 */
void setRandomSeed(int seed)
{
    initRandomSeed();
    srand(seed);
}

void initRandomSeed()
{
    static bool initialized = false;
    if (!initialized)
    {
        srand(int(time(NULL)));
        initialized = true;
    }
}