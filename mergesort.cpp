#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &vec, int low, int high);
void mergeOperation(vector<int> &vec, int low, int divide, int high);
void printVector(vector<int> vec);
void swap(vector<int> &vec, int indexOne, int indexTwo);
vector<int> mergeOperation2(vector<int> &sortedOne, vector<int> &sortedTwo);

int main()
{
    vector<int> vec = {1, 5, 8, 2, 42, 47, 16, 9, 10, 56, 74, 15, 21, 108, 0, 48, 64, 99, 7, 42};
    mergeSort(vec, 1, 5);
    printVector(vec);
    mergeSort(vec, 0, vec.size() - 1);
    printVector(vec);
    return 0;
}

void mergeSort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int divide = (low + high) / 2;
        mergeSort(vec, low, divide);
        mergeSort(vec, divide + 1, high);
        mergeOperation(vec, low, divide, high);
    }
}

void mergeOperation(vector<int> &vec, int low, int divide, int high) // vec[low ---> divide]  vec[divide+1 --->high]
{
    vector<int> sorted;
    int i = low, j = divide + 1;
    for (; i <= divide && j <= high;)
    {
        if (vec.at(i) < vec.at(j))
        {
            sorted.push_back(vec.at(i));
            i++;
        }
        else if (vec.at(i) >= vec.at(j))
        {
            sorted.push_back(vec.at(j));
            j++;
        }
    }
    if (i == divide + 1)
    {
        for (; j <= high; j++)
            sorted.push_back(vec.at(j));
    }
    else
    {
        for (; i <= divide; i++)
            sorted.push_back(vec.at(i));
    }
    for (int k = low, l = 0; k <= high; k++, l++)
    {
        vec.at(k) = sorted.at(l);
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
/**
 * merge sort的思路：
 * 如果我已经有了2个sorted的序列了，那能不能排序起来？显然是容易的，也就是mergeOperation2。
 * 所以，问题就变成我怎么得到sorted的序列。单个元素一定是有序的，所以我们就用递归的方法，不断调用自身，
 * 两次递归的参数原来的序列的左半和右半部分，直至递归到单个元素为止。
 * 然后就可以进行mergeOperation了(本质上和mergeOperation2做同样的事，只是函数参数不同)。使用low divide high来表示两个sorted序列: low ---> divide 以及 divide+1 ---> high.
 * 
*/

// merge的含义
vector<int> mergeOperation2(vector<int> &sortedOne, vector<int> &sortedTwo)
{
    vector<int> sorted;
    int i = 0, j = 0;
    for (; i < sortedOne.size() && j < sortedTwo.size();)
    {
        if (sortedOne.at(i) < sortedTwo.at(j))
        {
            sorted.push_back(sortedOne.at(i));
            i++;
        }
        else if (sortedOne.at(i) >= sortedTwo.at(j))
        {
            sorted.push_back(sortedTwo.at(j));
            j++;
        }
    }
    if (i == sortedOne.size())
    {
        for (; j < sortedTwo.size(); j++)
            sorted.push_back(sortedTwo.at(j));
    }
    else
    {
        for (; i < sortedOne.size(); i++)
            sorted.push_back(sortedOne.at(i));
    }
    return sorted;
}
