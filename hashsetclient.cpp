#include <iostream>
#include <vector>
#include <string>
#include "HashSet.h"

using namespace std;

int main()
{
    int elements[13] = {17, 41, 9, 29, 41, 9, 29, 37, 81, 69, 20, 42, 55};
    int notfound[5] = {87, -3, -1, 7, 0};
    HashSet hashset;
    for (int n : elements)
    {
        hashset.add(n);
    }
    hashset.printStructure();

    bool flag = hashset.contains(87);
    cout << boolalpha << flag << endl;

    hashset.remove(81);
    hashset.remove(17);
    hashset.remove(29);
    hashset.printStructure();

    //hashset.clear();
    //hashset.printStructure();
    return 0;
}