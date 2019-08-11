#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    cout << "hello world" << endl;
    vector<string> msg{"hello", "C++", "world", "from", "VScode"};
    for (string &word : msg)
    {
        cin >> word;
    }
    for (const string word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}