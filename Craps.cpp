/**
 * File: Craps.cpp
 * -------------------------------
 */

/**
 * ctrl + d
 * 
 * shift + left arrow 选定 配合home end
 * alt + up/down arrow
 * ctrl +shift + k
 * alt + shift + up/down arrow
 * ctrl+f2 refactor
 */

#include <iostream>
#include "random.h"
using namespace std;

const int DICE_MIN = 1;
const int DICE_MAX = 6;
bool tryToMakePoint(int point);
int rollTwoDice();

int main()
{
    cout << "This program simulate the game of Craps." << endl
         << "----------------------------------------" << endl;
    int point = rollTwoDice();
    switch (point)
    {
    case 7:
    case 11:
        cout << "You naturally win the game!" << endl;
        break;
    case 2:
    case 3:
    case 12:
        cout << "You lose the game by crapping out" << endl;
        break;
    default:
        cout << "Your point is: " << point << endl;
        if (tryToMakePoint(point))
        {
            cout << "You made your point. You win." << endl;
        }
        else
        {
            cout << "You rolled point 7. You lose." << endl;
        }
    }
    return 0;
}

bool tryToMakePoint(int point)
{
    while (true)
    {
        int rollPoint = rollTwoDice();
        if (rollPoint == point)
            return true;
        else if (rollPoint == 7)
            return false;
    }
}

int rollTwoDice()
{
    cout << "Rolling the dice..." << endl;
    int d1 = randomInteger(DICE_MIN, DICE_MAX);
    int d2 = randomInteger(DICE_MIN, DICE_MAX);
    int total = d1 + d2;
    cout << "You rolled " << d1 << " and " << d2 << ". That's: " << total << endl;
    return total;
}
