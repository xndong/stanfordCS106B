#include <iostream>
#include <vector>
#include <string>
#include "StringMap.h"

using namespace std;

int main()
{
    StringMap myMap;
    myMap.put("ak", "Alaska");
    myMap.put("ca", "California");
    myMap.put("mn", "Minnesota");
    myMap.put("ny", "New York");
    myMap.put("va", "Virginia");
    myMap.put("la", "Los Angelas");

    string lookup = myMap.get("la");
    cout << lookup << endl;

    myMap.put("la", "Louisiana");
    lookup = myMap.get("la");
    cout << lookup << endl;

    lookup = myMap.get("va");
    cout << lookup << endl;
    lookup = myMap.get("pa");
    cout << lookup << endl;
    return 0;
}
