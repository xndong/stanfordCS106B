#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int> &vec, int low, int high);
int getIndex(vector<int> &vec, int pivotValue, int low, int high);
void printVector(vector<int> vec);
void swap(vector<int> &vec, int indexOne, int indexTwo);

int main()
{
    vector<int> vec = {1, 5, 8, 2, 42, 47, 16, 9, 10, 56, 74, 15, 21, 108, 0, 48, 64, 99, 7, 42};
    quicksort(vec, 0, vec.size() - 1);
    printVector(vec);
    return 0;
}
//ascent order
void quicksort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        //partition
        int startIndex = 0;
        int currentIndex = 0;
        int pivotIndex = (high + low) / 2;
        int pivotValue = vec.at(pivotIndex);
        swap(vec, pivotIndex, high);
        startIndex = getIndex(vec, pivotValue, low, high);
        for (currentIndex = startIndex; currentIndex < high; currentIndex++)
        {
            if (vec.at(currentIndex) < pivotValue)
            {
                swap(vec, startIndex, currentIndex);
                startIndex++;
            }
        }
        swap(vec, startIndex, high);
        //conquer ---> recursive
        quicksort(vec, low, startIndex - 1);
        quicksort(vec, startIndex + 1, high);
    }
}

int getIndex(vector<int> &vec, int pivotValue, int low, int high)
{
    for (int i = low; i < high; i++)
    {
        if (vec.at(i) > pivotValue)
            return i;
    }
}

void printVector(vector<int> vec)
{
    for (auto element : vec)
        cout << element << " ";
    cout << endl;
}

void swap(vector<int> &vec, int indexOne, int indexTwo)
{
    int tmp = vec[indexOne];
    vec[indexOne] = vec[indexTwo];
    vec[indexTwo] = tmp;
}