#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int INITIAL_VALUE = 0;
int main()
{
    vector<vector<int>> twoDimensionVector(8, vector<int>(5, INITIAL_VALUE));
    for (auto row : twoDimensionVector)
    {
        for (auto rowElement : row)
            cout << rowElement << " ";
        cout << endl;
    }
    return 0;
}