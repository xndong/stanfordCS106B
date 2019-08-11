#ifndef _priorityqueue_h
#define _priorityqueue_h

#include <vector>
using namespace std;

class PriorityQueue
{
public:
    //constructor and destructor
    PriorityQueue();
    PriorityQueue(vector<int> vec);
    ~PriorityQueue();
    //member function
    void enqueue(int value);
    int dequeue();
    int peek();
    void printRawPQ();
    void printOrderedPQ();
    bool isEmpty();

private:
    vector<int> vecPriorityQueue;
    void bubbleUp();
    void bubbleDown();
};

#endif