#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a = "0123456789";
    string b = "abcdefgh";
    int index = 0;
    for (auto iter = a.begin(); iter != a.end(); iter++)
    {
        if (*iter == '5' && index < 1)
        {
            iter = a.insert(iter, b.begin(), b.end());
            index++;
        }
        cout << *iter;
    }
    return 0;
}