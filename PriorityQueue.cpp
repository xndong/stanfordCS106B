#include <iostream>
#include <vector>
#include "PriorityQueue.h"

using namespace std;

//constructor and destructor
PriorityQueue::PriorityQueue()
{
    vecPriorityQueue.push_back(-1);
}
PriorityQueue::PriorityQueue(vector<int> vec)
{
    vecPriorityQueue.push_back(-1);
    for (auto element : vec)
    {
        enqueue(element);
    }
}

PriorityQueue::~PriorityQueue()
{
}
//public member functions
void PriorityQueue::enqueue(int value)
{

    if (vecPriorityQueue.size() - 1 == 0)
    {
        vecPriorityQueue.push_back(value);
    }
    else
    {
        vecPriorityQueue.push_back(value);
        bubbleUp();
    }
}

int PriorityQueue::dequeue()
{
    int returnValue = vecPriorityQueue[1];
    if (vecPriorityQueue.size() == 1)
    {
        cout << "Empty prioty queue, can not excute dequeue()" << endl;
        return -1;
    }
    if (vecPriorityQueue.size() - 1 == 1)
    {
        vecPriorityQueue.pop_back();
        return returnValue;
    }
    else
    {
        int endData = vecPriorityQueue.back();
        vecPriorityQueue.pop_back();
        vecPriorityQueue[1] = endData;
        bubbleDown();
        return returnValue;
    }
}

int PriorityQueue::peek()
{
    return vecPriorityQueue[1];
}

void PriorityQueue::printRawPQ()
{
    cout << "{";
    for (auto iter = vecPriorityQueue.begin() + 1; iter != vecPriorityQueue.end(); iter++)
    {
        cout << *iter << ", ";
    }
    cout << "}";
    cout << endl;
}

void PriorityQueue::printOrderedPQ() //heap sort堆排序，will exhaust PQ
{
    cout << "{";
    while (!isEmpty())
    {
        cout << dequeue() << ", ";
    }
    cout << "}";
    cout << endl;
}

bool PriorityQueue::isEmpty()
{
    if (vecPriorityQueue.size() - 1 == 0)
        return true;
    return false;
}

//private member functions
void PriorityQueue::bubbleUp() //when enque, adjust the heap using bubble-up
{
    int value = vecPriorityQueue.back();
    int valueIndex = vecPriorityQueue.size() - 1;
    int parentIndex = valueIndex / 2;
    while (true)
    {
        if (value < vecPriorityQueue[parentIndex] && parentIndex != 0)
        {
            int tmp = vecPriorityQueue[parentIndex];
            vecPriorityQueue[parentIndex] = value;
            vecPriorityQueue[valueIndex] = tmp;
            valueIndex = parentIndex;
            parentIndex = valueIndex / 2;
        }
        else
            break;
    }
}

void PriorityQueue::bubbleDown() //when deque, adjust the heap using bubble-down
{
    int valueIndex = 1;
    int childOneIndex = valueIndex * 2;
    int childTwoIndex = valueIndex * 2 + 1;
    while (vecPriorityQueue[valueIndex] > vecPriorityQueue[childOneIndex] || vecPriorityQueue[valueIndex] > vecPriorityQueue[childTwoIndex])
    {
        if ((vecPriorityQueue[childOneIndex] <= vecPriorityQueue[childTwoIndex] && childTwoIndex < vecPriorityQueue.size()) || (childOneIndex < vecPriorityQueue.size() && childTwoIndex >= vecPriorityQueue.size()))
        {
            int tmp = vecPriorityQueue[childOneIndex];
            vecPriorityQueue[childOneIndex] = vecPriorityQueue[valueIndex];
            vecPriorityQueue[valueIndex] = tmp;
            valueIndex = childOneIndex;
            childOneIndex = valueIndex * 2;
            childTwoIndex = valueIndex * 2 + 1;
        }
        else if (vecPriorityQueue[childTwoIndex] <= vecPriorityQueue[childOneIndex] && childTwoIndex < vecPriorityQueue.size())
        {
            int tmp = vecPriorityQueue[childTwoIndex];
            vecPriorityQueue[childTwoIndex] = vecPriorityQueue[valueIndex];
            vecPriorityQueue[valueIndex] = tmp;
            valueIndex = childTwoIndex;
            childOneIndex = valueIndex * 2;
            childTwoIndex = valueIndex * 2 + 1;
        }
        else
            break;
    }
}