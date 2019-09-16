#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int coordinatorFunction(vector<int> vec);
int coordinatorFunctionHelper(vector<int> vec, int index);

int main()
{
    int coordinator;
    int n;
    vector<int> myVec;
    cout << "Input the numbers of coordinators: " << endl;
    cin >> n;
    cout << "Input the coordinators: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> coordinator;
        myVec.push_back(coordinator);
    }
    int result = coordinatorFunction(myVec);
    cout << result << endl;
    return 0;
}

int coordinatorFunction(vector<int> vec)
{
    sort(vec.begin(), vec.end());
    if (vec.size() % 2 == 0)
    {
        int indexOne = (vec.size() - 1) / 2;
        int indexTwo = (vec.size() - 1) / 2 + 1;
        int sumOne = coordinatorFunctionHelper(vec, indexOne);
        int sumTwo = coordinatorFunctionHelper(vec, indexTwo);
        if (sumOne == sumTwo) // always equal...
        {
            cout << "both two numbers is ok." << endl;
        }
        return sumOne < sumTwo ? vec[indexOne] : vec[indexTwo];
    }
    else
    {
        int index = (vec.size() - 1) / 2;
        return vec[index];
    }
}
int coordinatorFunctionHelper(vector<int> vec, int index)
{
    int sumValue = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sumValue += abs(vec[index] - vec[i]);
    }
    return sumValue;
}