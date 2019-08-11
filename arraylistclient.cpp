#include <iostream>
#include "ArrayList.h"
using namespace std;
int main()
{
    ArrayList myArray;
    myArray.add(14);
    myArray.add(167);
    myArray.insert(0, 89);
    myArray.add(136);
    myArray.add(100);
    cout << myArray << endl;
    myArray.remove(4);
    cout << myArray << endl;
    myArray.clear();
    cout << myArray << endl;
    for (int i = 0; i < 500; i++)
        myArray.add(i);
    cout << myArray << endl;
    cout << myArray.capacity();
    return 0;
}